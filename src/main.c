#include <stdio.h>
#include <stdlib.h>
//include ADT
#include "../ADT/boolean.h"
#include "../ADT/command.c"
#include "../ADT/stackt.c"
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkar.c"
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
Kata ck;
Kata start;
Kata new_line;

void read_kata_start()
{
    STARTKATA();
    ck=CKata;
    if (EndKata)
    {
        printf("Input kosong \n");
        start_loop=false;   
    }
    while(!EndKata)
    {
        if (IsKataSama(ck,start))
        {
            printf("Memulai permainan baru \n");
            start_loop=false;
        }
        else
        {
            printf("Input tidak valid \n");
            start_loop=false;
        }
        ADVKATA();
    }
}

int main()
{
    //menu awal
    printf("Welcome to Willy wangky's\n");
    printf("New game / load game / exit? \n");
    start.TabKata[0]='n';
    start.TabKata[1]='e';
    start.TabKata[2]='w';
    start.Length=3;
    start_loop=true;
    new_line.TabKata[0]='\n';
    new_line.Length=1;
    while (start_loop)   
    {
        read_kata_start();
    }
    
    //peta
    //set matriks tipe
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            tipe_point[i][j]=0;
        }
    }

    //set matriks peta
    MakeMATRIKS(10,20,&L);
    BacaPeta(1,&L);
    TulisPeta(1,L);
    TitikPeta(L,AP); //set titik pada peta

    //cek titik
    // for (i = 0; i <= 199; i++)
    // {
    //     if (AP.P[i].X!=0 && AP.P[i].Y!=0)
    //     {
    //         printf("%d ",AP.tipe[i]);
    //         printf("%f,",AP.P[i].X);
    //         printf("%f\n",AP.P[i].Y);
    //     }           
    // }

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
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            printf("%d",tipe_point[i][j]);
        }
        printf("\n");
    }
    //antrian
    MakeEmpty(&Q, MaxAntrian);
    while (!IsFullQueue(Q))
    {
        /*Inisialisasi infotype_pq*/
        srand(crntname); //lebih baik nanti pake ADT time
        Nama(temp)=Nama[crntname];
        Prio(temp)=crntname;
        Kesabaran(temp)=(rand()%3)+1;
        // Kesabaran(temp)=default_angka;
        /*Selama tidak full, bisa tambah antrian*/
        TambahAntrian(&Q,temp);
        /*Setiap bertambah waktu tambah antrian(not implemented)*/
        crntname++; /*Nama selanjutnya*/
        if (crntname==27)
        {
            crntname=0;
        }
    }
    printf("Antrian awal\n");
    PrintAntrian(Q);

    //Cek wahana yang ingin dinaiki
    int nama=0;
    char ch; 
    ch = Wahana(ElmtQ(Q,0),nama);
    printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,0)));
    while (ch !='.')
    {
        printf("%c",ch);
        nama++;
        ch = Wahana(ElmtQ(Q,0),nama);
    }
    printf("\n");

    nama=0;
    ch = Wahana(ElmtQ(Q,2),nama);
    printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,2)));
    while (ch !='.')
    {
        printf("%c",ch);
        nama++;
        ch = Wahana(ElmtQ(Q,2),nama);
    }
    printf("\n");
    printf("Antrian[%d/%d]",NBElmtQueue(Q),MaxAntrian);

    //Simulasi antrian habis dari penuh
    while (!IsEmptyQueue(Q))
    {
        KurangAntrian(&Q,&served);
        printf("Pelanggan %c dilayani\n",Nama(served));
        printf("Antrian[%d/%d]",NBElmtQueue(Q),MaxAntrian);
        if (!IsEmptyQueue(Q))
        {
            PrintAntrian(Q);
        }
    }
    //stack command
    Comm(comm1) = 1;
    Comm(comm2) = 2;
    Comm(comm3) = 3;
    Comm(comm4) = 4;
    Push(&S, comm1);
    Push(&S, comm2);
    Push(&S, comm3);
    Push(&S, comm4);
    execute(&S);
    return 0;
}