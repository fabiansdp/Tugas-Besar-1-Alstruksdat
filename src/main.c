#include <stdio.h>
#include <stdlib.h>
//include ADT
#include "../ADT/boolean.h"
#include "../ADT/command.c"
#include "../ADT/stackt.c"
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkar.c"
#include "../ADT/jam.c"
//include from src
#include "peta.c"
#include "antrian.c"
#include "function.c"

//kamus peta
extern MATRIKS L;
extern Arr_POINT AP;
// extern int tipe_point;
extern POINT player_loc; 
//kamus antrian
extern int MaxAntrian;
extern int default_angka;
PrioQueueChar Q;
// int jmlhWahana = 3;
extern char Nama[]; 
extern int crntname;
extern infotype_pq temp;
extern infotype_pq served;
//kamus peta_2
char input;
int i,j;
boolean loop;
int adjacent;
//kamus stack
Stack S;
COMMAND comm1, comm2, comm3, comm4;
//kamus main
boolean start_loop;
boolean prep_loop;
boolean main_loop;
//kamus main,kata
Kata ck;
Kata start;
Kata exit_menu;
Kata player_name;
//kamus main,command
Kata com_W;
Kata com_A;
Kata com_S;
Kata com_D;
Kata com_build;
Kata com_upgrade;
Kata com_buy;
Kata com_undo;
Kata com_execute;
Kata com_main;
//kamus main,jam
Jam crnt_jam;
Jam buka;
Jam tutup;
Jam temp_jam;
//kamus main,int
int crnt_day;
int crnt_map;
int player_money;
int total_aksi;
int total_waktu;
int total_uang;

void PrintLegend()
{
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
}

void PrintPrep()
{
    /* Kamus Lokal */
    /* Algoritma */
    printf("Preparation phase day %d\n",crnt_day);
    PrintPeta(L);
    PrintLegend();
    printf("\n");
    printf("Name: ");
    for (int i = 0; i < player_name.Length; i++)
    {
        printf("%c",player_name.TabKata[i]);
    }
    printf("\n");
    temp_jam=DetikToJam(abs(JamToDetik(buka)-JamToDetik(crnt_jam)));
    printf("Current time: %d.%d\n",Hour(crnt_jam),Minute(crnt_jam));
    printf("Current time: %d.%d\n",Hour(buka),Minute(buka));
    if(Hour(temp_jam)>0) printf("Time Remaining: %d hour(s)",Hour(temp_jam));
    if(Minute(temp_jam)>0) printf(" %d minute(s)",Minute(temp_jam));
    printf("\n");
    printf("Total aksi yang akan dilakukan: %d\n",total_aksi);
    printf("Total waktu yang dibutuhkan: %d\n",total_waktu);
    printf("Total uang yang dibutuhkan: %d\n",total_uang);
    printf("\n");
    printf("Masukkan Perintah: ");
}

void SetupKata()
{
    //setup kata start
    start.TabKata[0]='n';
    start.TabKata[1]='e';
    start.TabKata[2]='w';
    start.Length=3;
    exit_menu.TabKata[0]='e';
    exit_menu.TabKata[1]='x';
    exit_menu.TabKata[2]='i';
    exit_menu.TabKata[3]='t';
    exit_menu.Length=4;
    //setup kata command prep
    com_W.TabKata[0]='w';
    com_W.Length=1;
    com_A.TabKata[0]='a';
    com_A.Length=1;
    com_S.TabKata[0]='s';
    com_S.Length=1;
    com_D.TabKata[0]='d';
    com_D.Length=1;
    com_build.TabKata[0]='b';
    com_build.TabKata[1]='u';
    com_build.TabKata[2]='i';
    com_build.TabKata[3]='l';
    com_build.TabKata[4]='d';
    com_build.Length=5;
    com_upgrade.TabKata[0]='u';
    com_upgrade.TabKata[1]='p';
    com_upgrade.TabKata[2]='g';
    com_upgrade.TabKata[3]='r';
    com_upgrade.TabKata[4]='a';
    com_upgrade.TabKata[5]='d';
    com_upgrade.TabKata[6]='e';
    com_upgrade.Length=7;
    com_buy.TabKata[0]='b';
    com_buy.TabKata[1]='u';
    com_buy.TabKata[2]='y';
    com_buy.Length=3;
    com_undo.TabKata[0]='u';
    com_undo.TabKata[1]='n';
    com_undo.TabKata[2]='d';
    com_undo.TabKata[3]='o';
    com_undo.Length=4;
    com_execute.TabKata[0]='e';
    com_execute.TabKata[1]='x';
    com_execute.TabKata[2]='e';
    com_execute.TabKata[3]='c';
    com_execute.TabKata[4]='u';
    com_execute.TabKata[5]='t';
    com_execute.TabKata[6]='e';
    com_execute.Length=7;
    com_main.TabKata[0]='m';
    com_main.TabKata[1]='a';
    com_main.TabKata[2]='i';
    com_main.TabKata[3]='n';
    com_main.Length=4;
}

void ReadKataStart()
{
    /* Kamus Lokal */
    /* Algoritma */    
    STARTKATA();
    ck=CKata;
    if (EndKata)
    {
        printf("Input kosong \n");
        ADVKATA(); 
    }
    while(!EndKata)
    {
        if (IsKataSama(ck,start))
        {
            printf("Memulai permainan baru \n");
            start_loop=false;
        }
        else if (IsKataSama(ck,exit_menu))
        {
            printf("Input keluar \n");
            start_loop=false;
        }
        else
        {
            printf("Input tidak valid \n");
        }
        ADVKATA();
    }
}

void PrepPhase()
{
    //prep phase loop
    prep_loop=true;
    while (prep_loop)   
    {
        STARTKATA();
        ck=CKata;
        if (EndKata)
        {
            printf("Input kosong \n");
            ADVKATA(); 
        }
        while(!EndKata)
        {
            if (IsKataSama(ck,com_W))
            {
                printf("Input w\n");
                Movement('W',&L);
            }
            else if (IsKataSama(ck,com_A))
            {
                printf("Input a\n");
                Movement('A',&L);
            }
            else if (IsKataSama(ck,com_S))
            {
                printf("Input s\n");
                Movement('S',&L);
            }
            else if (IsKataSama(ck,com_D))
            {
                printf("Input d\n");
                Movement('D',&L);
            }
            else if (IsKataSama(ck,com_build))
            {
                printf("Input build\n");
            }
            else if (IsKataSama(ck,com_upgrade))
            {
                printf("Input upgrade\n");
            }
            else if (IsKataSama(ck,com_buy))
            {
                printf("Input buy\n");
            }
            else if (IsKataSama(ck,com_undo))
            {
                printf("Input undo\n");
            }
            else if (IsKataSama(ck,com_execute))
            {
                printf("Input execute\n");
                prep_loop=false;
                main_loop=true;
            }
            else if (IsKataSama(ck,com_main))
            {
                printf("Input main\n");
                prep_loop=false;
                main_loop=true;
            }
            else
            {
                printf("Input tidak valid \n");
            }
            ADVKATA();
        }
        if (!main_loop)
        {
            PrintPrep();
        }
    }
}

int main()
{
    //menu awal
    printf("Welcome to Willy wangky's\n");
    printf("New game / load game / exit? \n");
    SetupKata();

    //menu awal
    start_loop=true;
    while (start_loop)   
    {
        ReadKataStart();
        if (IsKataSama(ck,exit_menu))
        {
            printf("Terima kasih telah bermain \n");
            return 0;
        }
    }

    //input nama
    printf("Masukkan nama: \n");
    STARTKATA();
    player_name=CKata;

    //setup jam
    crnt_jam=MakeJam(21,0);
    buka=MakeJam(9,0);
    tutup=MakeJam(21,0);
    crnt_day=1;

    //peta
    //setup matriks tipe
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            tipe_point[i][j]=0;
        }
    }
    //setup matriks peta
    crnt_map=1;
    MakeMATRIKS(10,20,&L);
    BacaPeta(crnt_map,&L);
    TitikPeta(L,AP); //set titik pada peta
    
    //setup & PrintPrep
    player_money=1000;
    total_aksi=0;
    total_waktu=0;
    total_uang=0;
    PrintPrep();

    //prep phase loop
    PrepPhase();

    // printf("X untuk keluar\n");
    // loop=true;    
    // do
    // {
    //     adjacent=Adjacency();
    //     printf("Nilai adjacent: %d\n",adjacent);
    //     printf("Masukkan arah pergerakan:\n");
    //     scanf("%c",&input);
    //     if (adjacent==5)
    //     {
    //         printf("Sebelah wahana\n");
    //     }
    //     else if (adjacent==3)
    //     {
    //         printf("Sebelah office\n");
    //     }
    //     if (input=='X')
    //     {
    //         loop=false;
    //     }
    //     else if (input=='W'||input=='A'||input=='S'||input=='D')
    //     {
    //         Movement(input,&L);
    //         PrintPeta(L);
    //     }
    // } while (loop);

    //cek tipe_point
    // for (i = 0; i <= 9; i++)
    // {
    //     for (j = 0; j <= 19; j++)
    //     {
    //         printf("%d",tipe_point[i][j]);
    //     }
    //     printf("\n");
    // }

    //antrian
    // MakeEmpty(&Q, MaxAntrian);
    // while (!IsFullQueue(Q))
    // {
    //     /*Inisialisasi infotype_pq*/
    //     srand(crntname); //lebih baik nanti pake ADT time
    //     Nama(temp)=Nama[crntname];
    //     Prio(temp)=crntname;
    //     Kesabaran(temp)=(rand()%3)+1;
    //     // Kesabaran(temp)=default_angka;
    //     /*Selama tidak full, bisa tambah antrian*/
    //     TambahAntrian(&Q,temp);
    //     /*Setiap bertambah waktu tambah antrian(not implemented)*/
    //     crntname++; /*Nama selanjutnya*/
    //     if (crntname==27)
    //     {
    //         crntname=0;
    //     }
    // }

    // printf("Antrian awal\n");
    // PrintAntrian(Q);

    // //Cek wahana yang ingin dinaiki
    // int nama=0;
    // char ch; 
    // ch = Wahana(ElmtQ(Q,0),nama);
    // printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,0)));
    // while (ch !='.')
    // {
    //     printf("%c",ch);
    //     nama++;
    //     ch = Wahana(ElmtQ(Q,0),nama);
    // }
    // printf("\n");

    // nama=0;
    // ch = Wahana(ElmtQ(Q,2),nama);
    // printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,2)));
    // while (ch !='.')
    // {
    //     printf("%c",ch);
    //     nama++;
    //     ch = Wahana(ElmtQ(Q,2),nama);
    // }
    // printf("\n");
    // printf("Antrian[%d/%d]",NBElmtQueue(Q),MaxAntrian);

    // //Simulasi antrian habis dari penuh
    // while (!IsEmptyQueue(Q))
    // {
    //     KurangAntrian(&Q,&served);
    //     printf("Pelanggan %c dilayani\n",Nama(served));
    //     printf("Antrian[%d/%d]",NBElmtQueue(Q),MaxAntrian);
    //     if (!IsEmptyQueue(Q))
    //     {
    //         PrintAntrian(Q);
    //     }
    // }
    // //stack command
    // Comm(comm1) = 1;
    // Comm(comm2) = 2;
    // Comm(comm3) = 3;
    // Comm(comm4) = 4;
    // Push(&S, comm1);
    // Push(&S, comm2);
    // Push(&S, comm3);
    // Push(&S, comm4);
    // execute(&S);
    return 0;
}