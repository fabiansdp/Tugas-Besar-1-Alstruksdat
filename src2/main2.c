/*
gcc -o main2 main2.c ../ADT/arraypos.c ../ADT/wahana.c ../ADT/stackt.c ../ADT/prioqueuechar.c ../ADT/matriks.c ../ADT/bintree.c ../ADT/command.c ../ADT/graph.c ../ADT/listlinier.c ../ADT/listrek.c ../ADT/point.c ../ADT/mesinkar.c ../ADT/mesinkata.c ../ADT/jam.c maps2.c buy2.c antrian2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//include ADT
#include "../ADT/boolean.h"
#include "../ADT/arraypos.h"
#include "../ADT/wahana.h"
#include "../ADT/stackt.h"
#include "../ADT/prioqueuechar.h"
#include "../ADT/matriks.h"
#include "../ADT/bintree.h"
#include "../ADT/command.h"
#include "../ADT/graph.h"
#include "../ADT/listlinier.h"
#include "../ADT/listrek.h"
#include "../ADT/point.h"
#include "../ADT/mesinkar.h"
#include "../ADT/mesinkata.h"
#include "../ADT/jam.h"
//include from src
//#include "peta.c"
//#include "antrian.c"
//#include "buy.c"
#include "maps2.h"
#include "buy2.h"
#include "antrian2.h"
#include "function2.h"

Kata ck;
Kata start,exit_menu,player_name;
Kata com_W,com_A,com_S,com_D;
Kata com_build,com_upgrade,com_buy,com_undo,com_execute,com_main;
Kata com_serve,com_repair,com_detail,com_office,com_prepare;
Kata CandyCrush,ChocolateForest,BombomCar,LemonSplash,CandyVillage,CandySwing,BlackForestTornado;
boolean start_loop, prep_loop, main_loop;
extern ArrayWahana Map1,Map2,Map3,Map4;
ArrayWahana Map1,Map2,Map3,Map4;
Jam crnt_jam, jam_buka, jam_tutup, temp_jam, total_jam;
int crnt_day,crnt_map,tipe_point[10][20];
int total_uang,total_waktu,total_aksi;
int price;
int player_money;
Stack S;
MATRIKS L;
Arr_POINT AP;
COMMAND comm1,comm2,comm3;
POINT player_loc;
TabEl T,Resource;
Wahana W;
ListHistoUpdate sejarahUpgrade;
char mat[20][256];

int konvertKata(Kata K){
    int a = K.Length;
    int x;
    int res = 0;
    for(x=0;x<K.Length;x++){
        if(K.TabKata[x]>='0' && K.TabKata[x]<='9'){
            int pangkat = (int) pow(10,a-1);
            int konvert = (int) K.TabKata[x];
            konvert = konvert - 48;
            res = res+(pangkat*(konvert));
            a = a-1;
        }else{
            return -1;
        }
    }
    return res;
}

void PrintLegend()
{
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
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
    CandyCrush.TabKata[0] = 'C';
    CandyCrush.TabKata[1] = 'a';
    CandyCrush.TabKata[2] = 'n';
    CandyCrush.TabKata[3] = 'd';
    CandyCrush.TabKata[4] = 'y';
    CandyCrush.TabKata[5] = '-';
    CandyCrush.TabKata[6] = 'C';
    CandyCrush.TabKata[7] = 'r';
    CandyCrush.TabKata[8] = 'u';
    CandyCrush.TabKata[9] = 's';
    CandyCrush.TabKata[10] = 'h';
    CandyCrush.Length  = 11;

    ChocolateForest.TabKata[0] = 'C';
    ChocolateForest.TabKata[1] = 'h';
    ChocolateForest.TabKata[2] = 'o';
    ChocolateForest.TabKata[3] = 'c';
    ChocolateForest.TabKata[4] = 'o';
    ChocolateForest.TabKata[5] = 'l';
    ChocolateForest.TabKata[6] = 'a';
    ChocolateForest.TabKata[7] = 't';
    ChocolateForest.TabKata[8] = 'e';
    ChocolateForest.TabKata[9] = '-';
    ChocolateForest.TabKata[10] = 'F';
    ChocolateForest.TabKata[11] = 'o';
    ChocolateForest.TabKata[12] = 'r';
    ChocolateForest.TabKata[13] = 'e';
    ChocolateForest.TabKata[14] = 's';
    ChocolateForest.TabKata[15] = 't';
    ChocolateForest.Length = 16;
    
    BombomCar.TabKata[0] = 'B';
    BombomCar.TabKata[1] = 'o';
    BombomCar.TabKata[2] = 'm';
    BombomCar.TabKata[3] = 'b';
    BombomCar.TabKata[4] = 'o';
    BombomCar.TabKata[5] = 'm';
    BombomCar.TabKata[6] = '-';
    BombomCar.TabKata[7] = 'C';
    BombomCar.TabKata[8] = 'a';
    BombomCar.TabKata[9] = 'r';
    BombomCar.Length = 10;

    LemonSplash.TabKata[0] = 'L';
    LemonSplash.TabKata[1] = 'e';
    LemonSplash.TabKata[2] = 'm';
    LemonSplash.TabKata[3] = 'o';
    LemonSplash.TabKata[4] = 'n';
    LemonSplash.TabKata[5] = '-';
    LemonSplash.TabKata[6] = 'S';
    LemonSplash.TabKata[7] = 'p';
    LemonSplash.TabKata[8] = 'l';
    LemonSplash.TabKata[9] = 'a';
    LemonSplash.TabKata[10] = 's';
    LemonSplash.TabKata[11] = 'h';
    LemonSplash.Length = 12;

    CandyVillage.TabKata[0] = 'C';
    CandyVillage.TabKata[1] = 'a';
    CandyVillage.TabKata[2] = 'n';
    CandyVillage.TabKata[3] = 'd';
    CandyVillage.TabKata[4] = 'y';
    CandyVillage.TabKata[5] = '-';
    CandyVillage.TabKata[6] = 'V';
    CandyVillage.TabKata[7] = 'i';
    CandyVillage.TabKata[8] = 'l';
    CandyVillage.TabKata[9] = 'l';
    CandyVillage.TabKata[10] = 'a';
    CandyVillage.TabKata[11] = 'g';
    CandyVillage.TabKata[12] = 'e';
    CandyVillage.Length = 13;

    CandySwing.TabKata[0] = 'C';
    CandySwing.TabKata[1] = 'a';
    CandySwing.TabKata[2] = 'n';
    CandySwing.TabKata[3] = 'd';
    CandySwing.TabKata[4] = 'y';
    CandySwing.TabKata[5] = '-';
    CandySwing.TabKata[6] = 'S';
    CandySwing.TabKata[7] = 'w';
    CandySwing.TabKata[8] = 'i';
    CandySwing.TabKata[9] = 'n';
    CandySwing.TabKata[10] = 'g';
    CandySwing.Length = 11;

    BlackForestTornado.TabKata[0] = 'B';
    BlackForestTornado.TabKata[1] = 'l';
    BlackForestTornado.TabKata[2] = 'a';
    BlackForestTornado.TabKata[3] = 'c';
    BlackForestTornado.TabKata[4] = 'k';
    BlackForestTornado.TabKata[5] = 'f';
    BlackForestTornado.TabKata[6] = 'o';
    BlackForestTornado.TabKata[7] = 'r';
    BlackForestTornado.TabKata[8] = 'e';
    BlackForestTornado.TabKata[9] = 's';
    BlackForestTornado.TabKata[10] = 't';
    BlackForestTornado.TabKata[11] = '-';
    BlackForestTornado.TabKata[12] = 'T';
    BlackForestTornado.TabKata[13] = 'o';
    BlackForestTornado.TabKata[14] = 'r';
    BlackForestTornado.TabKata[15] = 'n';
    BlackForestTornado.TabKata[16] = 'a';
    BlackForestTornado.TabKata[17] = 'd';
    BlackForestTornado.TabKata[18] = 'o';
    BlackForestTornado.Length = 19;
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
    printf("Current time: %d.%d\n", Hour(jam_buka), Minute(jam_buka));
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

void PrepPhase()
{
    BasisListWahana B = MakeUpgradeList();
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
                Wahana W;
                if(Adjacency()!=5 && Adjacency()!=6)
                {
                    do
                    {
                        puts("Daftar wahana:");
                        printDaftarWahana(B);
                        puts("Mau bangun apa?");
                        STARTKATA();
                        while (!EndKata)
                        {
                            if (IsKataSama(CKata, CandyCrush))
                            {
                                id = 11;
                                puts("\nKamu pilih Candy Crush\n");
                            }
                            else if (IsKataSama(CKata, ChocolateForest))
                            {
                                id = 12;
                                puts("\nKamu pilih Chocolate Forest\n");
                            }
                            else if (IsKataSama(CKata, BombomCar))
                            {
                                id = 13;
                                puts("\nKamu pilih Bombom Car\n");
                            }
                            else if (IsKataSama(CKata, LemonSplash))
                            {
                                id = 14;
                                puts("\nKamu pilih Lemon Splash\n");
                            }
                            else if (IsKataSama(CKata, CandyVillage))
                            {
                                id = 15;
                                puts("\nKamu pilih Candy Village\n");
                            }
                            else if (IsKataSama(CKata, CandySwing))
                            {
                                id = 16;
                                puts("\nKamu pilih Candy Swing\n");
                            }
                            else if (IsKataSama(CKata, BlackForestTornado))
                            {
                                id = 17;
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
                    W = SearchWahanaBase(B, id);
                    harga = W.harga;
                    durasi = W.durasi;
                    total_uang += harga;

                    if (total_uang <= player_money) {
                        
                        comm1 = MakeCOMMAND(1, id, 0, harga, crnt_map, player_loc, durasi);
                        
                        Push(&S, comm1);
                        // edit peta
                        x=Absis(player_loc);
                        y=Ordinat(player_loc);
                        //ubah tipe
                        tipe_point[x-1][y]=5;
                        //ubah matriks peta
                        ElmtM(L,x-1,y)='W';
                        total_aksi++;
                        total_waktu += durasi;
                    } else {
                        puts("Uang tidak cukup!");
                        total_uang -= harga;
                    }
                }
                else
                {
                    puts("Jangan membangun di sebelah wahana");
                }
            }
            else if (IsKataSama(ck, com_upgrade))
            {
                if(crnt_day==1){
                    puts("Masih hari pertama cuy, bangunan aja belum ada");
                }else if(Adjacency()!=5){
                    puts("Tidak ada wahana di sekitarmu!");
                }else{
                    ArrayWahana awa;
                    if(crnt_map==1){ awa = Map1;}
                    else if(crnt_map==2){awa=Map2;}
                    else if(crnt_map==3){awa=Map3;}
                    else if(crnt_map==4){awa=Map4;}
                    x=Absis(player_loc);
                    y=Ordinat(player_loc);
                    int kemungkinan[4];
                    int posibility=0;
                    if(tipe_point[x+1][y]==5){
                        kemungkinan[posibility] = CariWahanaByLoc(awa,MakePOINT(x+1,y)).id;
                        //printf("ha = %d",kemungkinan[posibility]);
                        posibility++;
                    }

                    if(tipe_point[x-1][y]==5){
                        kemungkinan[posibility] = CariWahanaByLoc(awa,MakePOINT(x-1,y)).id;
                        //printf("hi = %d",kemungkinan[posibility]);
                        posibility++;
                    }

                    if(tipe_point[x][y+1]==5){
                        kemungkinan[posibility] = CariWahanaByLoc(awa,MakePOINT(x,y+1)).id;
                        //printf("hu = %d",kemungkinan[posibility]);
                        posibility++;
                    }

                    if(tipe_point[x][y-1]==5){
                        kemungkinan[posibility] = CariWahanaByLoc(awa,MakePOINT(x,y-1)).id;
                        //printf("he = %d",kemungkinan[posibility]);
                        posibility++;
                    }

                    
                    if(posibility>0){
                        printf("pilih wahana yang mau diupgrade: \n\n");
                        printf("ID Wahana      Nama Wahana \n");
                        for(int xxx=0;xxx<posibility;xxx++){
                        DetilWahana dwhn = CariWahanaByID(awa,kemungkinan[xxx]);
                        if(dwhn.id!=ValUndef){
                        printf("%d              ",dwhn.id);printkata(dwhn.wahana.nama);printf("\n");
                        }}
                        int upgradeeid;
                        boolean inputflag = false;
                        while (inputflag==false)
                        {
                            printf("masukkan id yang mau diupgrade = ");
                            STARTKATA();
                            while (!EndKata)
                            {
                                upgradeeid = konvertKata(CKata);
                                ADVKATA();
                            }  

                            if(upgradeeid!=-1){
                                for(int yoy = 0;yoy<posibility;yoy++){
                                    if(kemungkinan[yoy]==upgradeeid){
                                        inputflag=true;
                                    }
                                }
                            }

                            if(inputflag!=true){
                                printf("inputan salah atau id tidak tersedia, ulangi lagi \n");
                            }
                        }
                        DetilWahana dwhn = CariWahanaByID(awa,upgradeeid);
                        ShowAvailableUpgrade(awa,upgradeeid);
                        int spekupgrade;
                        inputflag = false;
                        while (inputflag==false)
                        {
                            printf("input upgrade yang mau di apply (by id upgrade, gunakan 9999 untuk batal) = ");
                            STARTKATA();
                            while (!EndKata)
                            {
                                spekupgrade = konvertKata(CKata);
                                ADVKATA();
                            }  
                            
                            if(spekupgrade==9999){
                                inputflag = true;
                            }else{
                                if(checkUpgradeAvail(dwhn.upgradeTree,spekupgrade)!=NULL){
                                    inputflag = true;
                                }
                            }

                            if(inputflag!=true){
                                printf("inputan salah atau id tidak tersedia, ulangi lagi \n");
                            }
                        }

                        if(spekupgrade!=9999){
                            BinTree asoy = checkUpgradeAvail(dwhn.upgradeTree,spekupgrade);
                            if(
                                player_money>=asoy->harga
                                && Resource.TI[0].value >= asoy->air
                                && Resource.TI[1].value >= asoy->kayu
                                && Resource.TI[2].value >= asoy->batu
                                && Resource.TI[3].value >= asoy->besi
                                )
                            {
                                comm2 = MakeCOMMAND(2, upgradeeid, spekupgrade, crnt_day, crnt_map, player_loc, JamToDetik(crnt_jam));
                                Push(&S,comm2);
                            }else{
                                printf("mohon maaf resource anda kurang\n");
                            }
                            
                        }else{
                            printf("upgrade dibatalkan\n");
                        }
                        
                    }else{
                        printf("Tidak ada wahana disini!\n");
                    }

                    
                    
                }
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
                crnt_jam = jam_buka;
                temp_jam = DetikToJam(43200);
                //main_loop = true;
                prep_loop = false;
                //execute()
                execute(
                    &S,
                    &Map1,
                    &Map2,
                    &Map3,
                    &Map4,
                    &player_money,
                    &Resource.TI[0].value,
                    &Resource.TI[1].value,
                    &Resource.TI[2].value,
                    &Resource.TI[3].value,
                    &sejarahUpgrade
                    );

                printf("Perintah diexecute\n");
            }
            else if (IsKataSama(ck, com_main))
            {
                printf("Input main\n");
                crnt_jam = jam_buka;
                temp_jam = DetikToJam(43200);
                //main_loop = true;
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
            crnt_jam = jam_buka;
            main_loop = true;
        }
        if (!main_loop&&prep_loop)
        {
            PrintPrep();
        }
    }
}

int main(){
    // Pembukaan Game
    makeArrayWahana(&Map1);
    makeArrayWahana(&Map2);
    makeArrayWahana(&Map3);
    makeArrayWahana(&Map4);
    printf("Welcome to Willy wangky's\n");
    printf("New game / load game / exit? \n");
    
    // Setup Kata
    SetupKata();

    start_loop = true;
    while (start_loop)
    {
        ReadKataStart();
        if(IsKataSama(ck,exit_menu))
        {
            printf("Terima kasih telah bermain \n");
            return 0;
        }
    }

    printf("Masukkan nama: \n");
    STARTKATA();
    player_name = CKata;

    //setup jam
    crnt_jam = MakeJam(21, 0);
    jam_buka = MakeJam(9, 0);
    jam_tutup = MakeJam(21, 0);
    crnt_day = 1;
    temp_jam = DetikToJam(abs(JamToDetik(jam_buka) - JamToDetik(crnt_jam)));
    total_jam = MakeJam(0, 0);
    
    /* SKEMA SETUP WAHANA DISINI NANTINYA*/

    /*== AKHIR SKEMA SETUP WAHANA ==*/
    //setup matriks tipe
    
    /* SETUP PETA DISINI*/
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 19; j++)
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
    player_money = 1000000;
    total_aksi = 0;
    total_waktu = 0;
    total_uang = 0;
    //setup buy
    MakeEmptyTabel(&T);
    MakeEmptyTabel(&Resource);

    Resource.TI[0].value = 100;
    Resource.TI[1].value = 100;
    Resource.TI[2].value = 100;
    Resource.TI[3].value = 100;

    /*Phase LOOP*/
    CreateEmptyStack(&S);
    prep_loop = true;
    main_loop = false;
    while (prep_loop||main_loop)
    {
        PrintPrep();
        PrepPhase();
        //PrintMain();
        //MainPhase();
        puts("Loop");
        crnt_day++;
        if(crnt_day>3){
            prep_loop=false;
            main_loop = false;
        }else{
            prep_loop=true;
        }
    }

    //DEBUGING
    /*
    PrintAllWahana(Map1);
    PrintAllWahana(Map2);
    PrintAllWahana(Map3);
    PrintAllWahana(Map4); */
    PrintAllHistory(sejarahUpgrade);



    return 0;
}