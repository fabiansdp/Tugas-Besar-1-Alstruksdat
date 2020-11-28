#include <stdio.h>
#include <stdlib.h>
//include ADT
#include "../ADT/boolean.h"
#include "../ADT/command.c"
#include "../ADT/stackt.c"
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkar.c"
#include "../ADT/jam.c"
#include "../ADT/wahana2.c"

#include "../ADT/arraypos.c"
// #include "../ADT/listlinier.c"
//include from src
#include "peta.c"
#include "antrian.c"
#include "function.c"
#include "buy.c"

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
int i, j;
boolean loop;
int adjacent;
//kamus stack
Stack S;
COMMAND comm1, comm2, comm3, comm4;
//kamus di command
extern int total_aksi;
extern int total_waktu;
extern int total_uang;
//Kamus di buy
extern char mat[20][256];
extern int banyak;
extern TabEl T, Resource;
extern Kata CKata, Air, Kayu, Batu, Besi;
extern int price;
extern int indeks_buy;
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
//part2
Kata com_serve;
Kata com_repair;
Kata com_detail;
Kata com_office;
Kata com_prepare;
//kamus main,jam
Jam crnt_jam;
Jam buka;
Jam tutup;
Jam temp_jam;
Jam total_jam;
//kamus main,wahana
ArrayWahana W;
Kata CandyCrush;
Kata ChocolateForest;
Kata BombomCar;
Kata LemonSplash;
Kata CandyVillage;
Kata CandySwing;
Kata BlackForestTornado;
// List listWahanaMap1;
// List listWahanaMap2;
// List listWahanaMap3;
// List listWahanaMap4;
//kamus main,int
int crnt_day;
int crnt_map;
int player_money;
int x,y;

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
    printf("Preparation phase day %d\n", crnt_day);
    PrintPeta(L);
    PrintLegend();
    printf("\n");
    printf("Name: ");
    for (int i = 0; i < player_name.Length; i++)
    {
        printf("%c", player_name.TabKata[i]);
    }
    printf("\n");
    printf("Money: %d\n", player_money);
    printf("Current time: %d.%d\n", Hour(crnt_jam), Minute(crnt_jam));
    printf("Current time: %d.%d\n", Hour(buka), Minute(buka));
    printf("Time Remaining: ");
    if (Hour(temp_jam) > 0)
        printf(" %d hour(s)", Hour(temp_jam));
    if (Minute(temp_jam) > 0)
        printf(" %d minute(s)", Minute(temp_jam));
    printf("\n");
    printf("Total aksi yang akan dilakukan: %d\n", total_aksi);
    total_jam = DetikToJam(total_waktu);
    printf("Total waktu yang dibutuhkan: ");
    if (Hour(total_jam) > 0)
        printf(" %d hour(s)", Hour(total_jam));
    printf(" %d minute(s)", Minute(total_jam));
    printf("\n");
    printf("Total uang yang dibutuhkan: %d\n", total_uang);
    printf("\n");
    printf("Masukkan Perintah: ");
}

void PrintMain()
{
    /* Kamus Lokal */
    /* Algoritma */
    printf("Main phase day %d\n", crnt_day);
    PrintPeta(L);
    PrintLegend();
    printf("\n");
    printf("Name: ");
    for (int i = 0; i < player_name.Length; i++)
    {
        printf("%c", player_name.TabKata[i]);
    }
    printf("\n");
    printf("Money: %d\n", player_money);
    printf("Current time: %d.%d\n", Hour(crnt_jam), Minute(crnt_jam));
    printf("Current time: %d.%d\n", Hour(buka), Minute(buka));
    printf("Time Remaining: ");
    if (Hour(temp_jam) > 0)
        printf(" %d hour(s)", Hour(temp_jam));
    if (Minute(temp_jam) > 0)
        printf(" %d minute(s)", Minute(temp_jam));
    printf("\n");
    // print antrian
    // printf("Total aksi yang akan dilakukan: %d\n", total_aksi);
    printf("Masukkan Perintah: ");    
}

void SetupKata()
{
    //setup kata start
    start.TabKata[0] = 'n';
    start.TabKata[1] = 'e';
    start.TabKata[2] = 'w';
    start.Length = 3;
    exit_menu.TabKata[0] = 'e';
    exit_menu.TabKata[1] = 'x';
    exit_menu.TabKata[2] = 'i';
    exit_menu.TabKata[3] = 't';
    exit_menu.Length = 4;
    //setup kata command prep
    com_W.TabKata[0] = 'w';
    com_W.Length = 1;
    com_A.TabKata[0] = 'a';
    com_A.Length = 1;
    com_S.TabKata[0] = 's';
    com_S.Length = 1;
    com_D.TabKata[0] = 'd';
    com_D.Length = 1;
    com_build.TabKata[0] = 'b';
    com_build.TabKata[1] = 'u';
    com_build.TabKata[2] = 'i';
    com_build.TabKata[3] = 'l';
    com_build.TabKata[4] = 'd';
    com_build.Length = 5;
    com_upgrade.TabKata[0] = 'u';
    com_upgrade.TabKata[1] = 'p';
    com_upgrade.TabKata[2] = 'g';
    com_upgrade.TabKata[3] = 'r';
    com_upgrade.TabKata[4] = 'a';
    com_upgrade.TabKata[5] = 'd';
    com_upgrade.TabKata[6] = 'e';
    com_upgrade.Length = 7;
    com_buy.TabKata[0] = 'b';
    com_buy.TabKata[1] = 'u';
    com_buy.TabKata[2] = 'y';
    com_buy.Length = 3;
    com_undo.TabKata[0] = 'u';
    com_undo.TabKata[1] = 'n';
    com_undo.TabKata[2] = 'd';
    com_undo.TabKata[3] = 'o';
    com_undo.Length = 4;
    com_execute.TabKata[0] = 'e';
    com_execute.TabKata[1] = 'x';
    com_execute.TabKata[2] = 'e';
    com_execute.TabKata[3] = 'c';
    com_execute.TabKata[4] = 'u';
    com_execute.TabKata[5] = 't';
    com_execute.TabKata[6] = 'e';
    com_execute.Length = 7;
    com_main.TabKata[0] = 'm';
    com_main.TabKata[1] = 'a';
    com_main.TabKata[2] = 'i';
    com_main.TabKata[3] = 'n';
    com_main.Length = 4;
    com_serve.TabKata[0] = 's';
    com_serve.TabKata[1] = 'e';
    com_serve.TabKata[2] = 'r';
    com_serve.TabKata[3] = 'v';
    com_serve.TabKata[4] = 'e';
    com_serve.Length = 5;
    com_repair.TabKata[0] = 'r';
    com_repair.TabKata[1] = 'e';
    com_repair.TabKata[2] = 'p';
    com_repair.TabKata[3] = 'a';
    com_repair.TabKata[4] = 'i';
    com_repair.TabKata[5] = 'r';
    com_repair.Length = 6;
    com_detail.TabKata[0] = 'd';
    com_detail.TabKata[1] = 'e';
    com_detail.TabKata[2] = 't';
    com_detail.TabKata[3] = 'a';
    com_detail.TabKata[4] = 'i';
    com_detail.TabKata[5] = 'l';
    com_detail.Length = 6;
    com_office.TabKata[0] = 'o';
    com_office.TabKata[1] = 'f';
    com_office.TabKata[2] = 'f';
    com_office.TabKata[3] = 'i';
    com_office.TabKata[4] = 'c';
    com_office.TabKata[5] = 'e';
    com_office.Length = 6;
    com_prepare.TabKata[0] = 'p';
    com_prepare.TabKata[1] = 'r';
    com_prepare.TabKata[2] = 'e';
    com_prepare.TabKata[3] = 'p';
    com_prepare.TabKata[4] = 'a';
    com_prepare.TabKata[5] = 'r';
    com_prepare.TabKata[6] = 'e';
    com_prepare.Length = 7;
    // Setup Wahana
    CandyCrush = W.ArrayW[0].nama;
    ChocolateForest = W.ArrayW[1].nama;
    BombomCar = W.ArrayW[2].nama;
    LemonSplash = W.ArrayW[3].nama;
    CandyVillage = W.ArrayW[4].nama;
    CandySwing = W.ArrayW[5].nama;
    BlackForestTornado = W.ArrayW[6].nama;
}

void ReadKataStart()
{
    /* Kamus Lokal */
    /* Algoritma */
    STARTKATA();
    ck = CKata;
    if (EndKata)
    {
        printf("Input kosong \n");
        ADVKATA();
    }
    while (!EndKata)
    {
        if (IsKataSama(ck, start))
        {
            printf("Memulai permainan baru \n");
            start_loop = false;
        }
        else if (IsKataSama(ck, exit_menu))
        {
            printf("Input keluar \n");
            start_loop = false;
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
    while (prep_loop)
    {
        STARTKATA();
        ck = CKata;
        if (EndKata)
        {
            printf("Input kosong \n");
            ADVKATA();
        }
        while (!EndKata)
        {
            if (IsKataSama(ck, com_W))
            {
                printf("Input w\n");
                Movement('W', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_A))
            {
                printf("Input a\n");
                Movement('A', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_S))
            {
                printf("Input s\n");
                Movement('S', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_D))
            {
                printf("Input d\n");
                Movement('D', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            // COMMAND MakeCOMMAND(int comm, int name, int amount, int gold, int map, POINT coordinate, int time);
            else if (IsKataSama(ck, com_build))
            {
                // // Minta input
                int id, harga, durasi;
                if(Adjacency()!=5 && Adjacency()!=6)
                {
                    do
                    {
                        ListWahana();
                        puts("Mau bangun apa?");
                        STARTKATA();
                        while (!EndKata)
                        {
                            if (IsKataSama(CKata, CandyCrush))
                            {
                                id = 11;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Candy Crush\n");
                            }
                            else if (IsKataSama(CKata, ChocolateForest))
                            {
                                id = 12;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Chocolate Forest\n");
                            }
                            else if (IsKataSama(CKata, BombomCar))
                            {
                                id = 13;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Bombom Car\n");
                            }
                            else if (IsKataSama(CKata, LemonSplash))
                            {
                                id = 14;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Lemon Splash\n");
                            }
                            else if (IsKataSama(CKata, CandyVillage))
                            {
                                id = 15;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Candy Village\n");
                            }
                            else if (IsKataSama(CKata, CandySwing))
                            {
                                id = 16;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Candy Swing\n");
                            }
                            else if (IsKataSama(CKata, BlackForestTornado))
                            {
                                id = 17;
                                int index = searchID(W, id);
                                harga = Harga(W, index);
                                durasi = Durasi(W, index);
                                puts("\nKamu pilih Black Forest Tornado\n");
                            }
                            else
                            {
                                puts("Tidak ada nama wahana seperti itu!");
                            }
                            ADVKATA();
                        }
                    } while (!IsKataSama(CKata, CandyCrush) && !IsKataSama(CKata, ChocolateForest) && !IsKataSama(CKata, BombomCar) && !IsKataSama(CKata, LemonSplash) && !IsKataSama(CKata, CandyVillage) && !IsKataSama(CKata, CandySwing) && !IsKataSama(CKata, BlackForestTornado));
                    // MakeCommand(idComm, idWahana, JmlhMaterial, Gold, Map, Lokasi, Durasi)
                    comm1 = MakeCOMMAND(1, id, 0, harga, crnt_map, player_loc, durasi);
                    Push(&S, comm1);
                    // edit peta
                    x=Absis(player_loc);
                    y=Ordinat(player_loc);
                    //ubah tipe
                    tipe_point[x-1][y]=5;
                    printf("Cek tipe_point di atas player: %d",tipe_point[x-1][y]);
                    //ubah matriks peta
                    ElmtM(L,x-1,y)='W';
                    PrintPeta(L);
                    total_aksi++;
                    total_uang += harga;
                    total_waktu += durasi;
                }
                else
                {
                    puts("Jangan membangun di sebelah wahana");
                }
            }
            else if (IsKataSama(ck, com_upgrade))
            {
                //uang sejumlah harga upgrade
                comm2 = MakeCOMMAND(2, 0, 20, 0, crnt_map, player_loc, 3600);
                Push(&S, comm2);
                printf("Input upgrade\n");
                total_aksi++;
                // total_uang+=50000;
                total_waktu += 3600;
                // upgrade();
            }
            else if (IsKataSama(ck, com_buy))
            {
                printf("Welcome to the shop\n ");
                printf("Material List :\n");
                BacaMaterial(1, mat);
                BacaHarga(1, &T, &Resource);
                BacaInput();
                if (!EnoughMoney(player_money, banyak, &Resource))
                {
                    printf("Not enought money!\n");
                }
                else
                {
                    comm3 = MakeCOMMAND(3, 0, 0, price, crnt_map, player_loc, 3600);
                    Push(&S, comm3);
                    // printf("Input buy\n");
                    total_aksi++;
                    total_uang += price;
                    total_waktu += 3600;
                }
                // buy();
            }
            else if (IsKataSama(ck, com_undo))
            {
                printf("Input undo\n");
                undo(&S);
            }
            else if (IsKataSama(ck, com_execute))
            {
                crnt_jam = buka;
                temp_jam = DetikToJam(43200);
                main_loop = true;
                prep_loop = false;
                
                execute(&S);
                printf("Perintah diexecute\n");
            }
            else if (IsKataSama(ck, com_main))
            {
                printf("Input main\n");
                crnt_jam = buka;
                temp_jam = DetikToJam(43200);
                main_loop = true;
                prep_loop = false;
            }
            else if (IsKataSama(ck, exit_menu))
            {
                printf("Input exit\n");
                prep_loop = false;
            }
            else
            {
                printf("Input tidak valid \n");
            }
            ADVKATA();
        }
        if (JamToDetik(temp_jam) <= 0)
        {
            prep_loop = false;
            crnt_jam = buka;
            main_loop = true;
        }
        if (!main_loop&&prep_loop)
        {
            PrintPrep();
        }
    }
}

void MainPhase()
{
    //prep phase loop
    while (main_loop)
    {
        STARTKATA();
        ck = CKata;
        if (EndKata)
        {
            printf("Input kosong \n");
            ADVKATA();
        }
        while (!EndKata)
        {
            //cek office
            if (IsKataSama(ck, com_W))
            {
                printf("Input w\n");
                Movement('W', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_A))
            {
                printf("Input a\n");
                Movement('A', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_S))
            {
                printf("Input s\n");
                Movement('S', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_D))
            {
                printf("Input d\n");
                Movement('D', &L);
                TambahMenit(&crnt_jam, 5);
                temp_jam = DetikToJam(JamToDetik(temp_jam) - 300);
            }
            else if (IsKataSama(ck, com_serve))
            {
                printf("Input serve\n");
            }
            else if (IsKataSama(ck, com_repair))
            {
                printf("Input repair\n");
            }
            else if (IsKataSama(ck, com_detail))
            {
                printf("Input repair\n");
            }
            else if (IsKataSama(ck, com_office))
            {
                printf("Input repair\n");
            }
            else if (IsKataSama(ck, com_prepare))
            {
                printf("Input prepare\n");
                main_loop = false;
                prep_loop = true;
                total_aksi = 0;
                total_jam = DetikToJam(0);
                total_uang = 0;
                total_waktu = 0;
            }
            else if (IsKataSama(ck, exit_menu))
            {
                printf("Input exit\n");
                main_loop = false;
            }
            else
            {
                printf("Input tidak valid \n");
            }
            ADVKATA();
        }
        if (JamToDetik(temp_jam) <= 0)
        {
            prep_loop = false;
            crnt_jam = buka;
            main_loop = true;
        }
        if (main_loop&&!prep_loop)
        {
            PrintMain();
        }
    }    
}

int main()
{
    CreateDataWahana(&W);
    CreateNamaWahana(&W);
    //menu awal
    printf("Welcome to Willy wangky's\n");
    printf("New game / load game / exit? \n");
    SetupKata();

    //menu awal
    start_loop = true;
    while (start_loop)
    {
        ReadKataStart();
        if (IsKataSama(ck, exit_menu))
        {
            printf("Terima kasih telah bermain \n");
            return 0;
        }
    }

    //input nama
    printf("Masukkan nama: \n");
    STARTKATA();
    player_name = CKata;

    //setup jam
    crnt_jam = MakeJam(21, 0);
    buka = MakeJam(9, 0);
    tutup = MakeJam(21, 0);
    crnt_day = 1;
    temp_jam = DetikToJam(abs(JamToDetik(buka) - JamToDetik(crnt_jam)));
    total_jam = MakeJam(0, 0);

    //setup wahana
    // CreateDataWahana(&W);
    // CreateNamaWahana(&W);
    //cek wahana
    // if (!IsDibangun(W,2)) {
    //     puts("NotBuild");
    // }
    // printf("%d\n", Air(W,1));
    // InfoWahana(W, 13);

    /*peta*/
    //setup matriks tipe
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            tipe_point[i][j] = 0;
        }
    }
    //setup matriks peta
    crnt_map = 1;
    MakeMATRIKS(10, 20, &L);
    BacaPeta(crnt_map, &L);
    TitikPeta(L, AP); //set titik pada peta

    //setup & PrintPrep
    player_money = 100000;
    total_aksi = 0;
    total_waktu = 0;
    total_uang = 0;
    //setup buy
    MakeEmptyTabel(&T);
    MakeEmptyTabel(&Resource);

    // //Jam J;
    // //BacaJam(&J);

    // printf("Welcome to the shop\n ");
    // printf("Material List :\n");
    // BacaMaterial(1,mat);
    // BacaHarga(1,&T,&Resource);
    // BacaInput();
    // boolean x;
    // x =EnoughMoney(1000,banyak,&Resource);
    // if(x == false){
    //     printf("Not enought money!\n");
    //     BacaInput();
    // }
    // else{
    //     // masuk ke stack
    //     // TambahMenit(&J,10);
    //     // TulisJam(J);
    // printf("BENER");
    // }

    /*prep phase loop*/
    CreateEmptyStack(&S);
    prep_loop = true;
    main_loop = false;
    while (prep_loop||main_loop)
    {
        PrintPrep();
        PrepPhase();
        PrintMain();
        MainPhase();
        puts("Loop");
        crnt_day++;
    }
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

    /*antrian*/
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