#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/wahana.h"
#include "../ADT/arraypos.h"
// #include "../ADT/listlinier.h"
#include "../ADT/bintree.h"
#include "../ADT/listrek.h"
#include "../ADT/prioqueuechar.h"
// #include "../ADT/arraypos.h"

extern int player_money;
extern TabEl Resource;
extern int banyak; 
extern int indeks_buy;
int temporary_index;
extern int x,y;
extern ArrayWahana Map1, Map2, Map3, Map4;
extern int tipe_point[10][20];
extern int crnt_map;
extern ListHistoUpdate sejarahUpgrade;
BasisListWahana B;
ArrWRide W1,W2,W3,W4; //wahana untuk dinaiki
// ===================================================PREPARATION PHASE========================================================

void build(ArrayWahana *W, COMMAND C)
{
    int x = Absis(Coordinate(C))-1;
    int y = Ordinat(Coordinate(C));
    POINT LokasiAtas = MakePOINT(x, y);
    Wahana WahanaBaru = SearchWahanaBase(B, Name(C));
    BinTree TreeBaru = SearchUList(B, Name(C));
    DetilWahana DetilBaru = DirikanWahanaBaru((*W).jumlahWahana, WahanaBaru, LokasiAtas, TreeBaru);
    PushNewWahana(W, DetilBaru);
    player_money -= Gold(C);
    //tambah ke WahanaRide
    switch (crnt_map)
    {
    case 1:
        W1.ArrayW[W1.ElP].MaxP=WahanaBaru.kapasitas;
        W1.ArrayW[W1.ElP].isBuilt=true;
        W1.ElP++;
        break;
    case 2:
        W2.ArrayW[W2.ElP].MaxP=WahanaBaru.kapasitas;
        W2.ArrayW[W2.ElP].isBuilt=true;
        W2.ElP++;
        break;
    case 3:
        W3.ArrayW[W3.ElP].MaxP=WahanaBaru.kapasitas;
        W3.ArrayW[W3.ElP].isBuilt=true;
        W3.ElP++;
        break;
    case 4:
        W4.ArrayW[W4.ElP].MaxP=WahanaBaru.kapasitas;
        W4.ArrayW[W4.ElP].isBuilt=true;
        W4.ElP++;
        break;
    default:
        break;
    }

    // // Cek wahana di lokasi atasnya ada wahana atau tidak
    // POINT LokasiAtas = MakePOINT(x, y);
    // DetilWahana CekWahana = CariWahanaByLoc(*W, LokasiAtas);
    // // Cek ada wahana, border, office, atau gerbang
    // if ((tipe_point[x][y] != 6) && (tipe_point[x][y] != 3) && (tipe_point[x][y] != 4)) {
    //     Wahana WahanaBaru = SearchWahanaBase(B, Name(C));
    //     BinTree TreeBaru = SearchUList(B, Name(C));
    //     DetilWahana DetilBaru = DirikanWahanaBaru((*W).jumlahWahana, WahanaBaru, LokasiAtas, TreeBaru);
    //     PushNewWahana(W, DetilBaru);
    //     player_money -= Gold(C);
    // } else {
    //     puts("Tidak bisa membangun di lokasi ini!");
    // }
}

void upgrade(ArrayWahana *W,
COMMAND C,
BinTree * bt, 
int * player_money, 
int * player_air, 
int * player_kayu, 
int * player_batu, 
int * player_besi,
ListHistoUpdate * ListHist)
{
    if((*player_money)>= (*bt)->harga
    && (*player_air)>= (*bt)->air 
    && (*player_kayu) >= (*bt)->kayu 
    && (*player_batu)>= (*bt)->batu  
    && (*player_besi)>= (*bt)->besi){
        //printf("otw diupgrade gess");
        //PrintAllWahana(*W);
        if(UpgradeWahana(W,Name(C),Amount(C))){
            (*player_money) = (*player_money) - (*bt)->harga;
            (*player_air)   = (*player_air) - (*bt)->air;
            (*player_kayu)  = (*player_kayu) - (*bt)->kayu;
            (*player_batu)  = (*player_batu) - (*bt)->batu;
            (*player_besi)  = (*player_besi) - (*bt)->besi;
            
            InfoHis ihis= CreateNewHistoryInfo(
                C.gold,
                DetikToJam(C.time),
                CariWahanaByID(*W,Name(C)).wahana.nama,
                (*bt)->detail
                );
            
            (*ListHist) = AddNewHistory((*ListHist),ihis,Name(C),Amount(C));
            
        }else{
            printf("Upgrade wahana %d gagal tiba-tiba",Name(C) );
        }
        //PrintAllWahana(*W);
    }else{
        printf("Gagal upgrade wahana dengan id %d karena kekurangan resources",Name(C));
    }
}

void buy(TabEl *Resource, COMMAND C)
{
    //ditambah ke resource
    temporary_index = Name(C);
    Value(*Resource,temporary_index) += banyak;
    TulisIsiTab(*Resource);
    printf("Buy berhasil dilakukan\n");
}

void undo(Stack *S)
{
    // Melakukan Pop terhadap exeStack
    // dan mendelete element command
    COMMAND C;

    Pop(S, &C);
    // COMMAND MakeCOMMAND(int comm, int name, int amount, int map, POINT coordinate, int time);
    switch (Comm(C))
    {
    case 1:
        printf("Undo Build\n");
        total_aksi--;
        total_uang -= Gold(C);
        total_waktu -= Time(C);
        //ubah tipe
        tipe_point[x-1][y]=0;
        //ubah matriks peta
        ElmtM(L,x-1,y)='-';
        break;
    case 2:
        printf("Undo Upgrade\n");
        total_aksi--;
        // total_uang-=Gold(C); harusnya ga jadi kurang material
        total_waktu -= Time(C);
        break;
    case 3:
        printf("Undo Buy\n");
        //belum ada undo material
        printf("Id %d sebanyak %d batal dibayar\n", indeks_buy, banyak);
        Value(Resource, indeks_buy) -= banyak;
        total_aksi--;
        total_uang -= Gold(C);
        total_waktu -= Time(C);
        break;
    case 4:
        printf("Undo Undo\n");
        break;
    default:
        break;
    }

    MakeEmptyCOMMAND(&C);
}

void execute(Stack *S)
{
    Stack exeStack;
    CreateEmptyStack(&exeStack);
    while (!IsEmptyStack(*S))
    {
        COMMAND C;
        Pop(S, &C);
        Push(&exeStack, C);
    }
    while (!IsEmptyStack(exeStack))
    {
        int* player_air = &Value(Resource,0);
        int* player_kayu = &Value(Resource,1);
        int* player_batu = &Value(Resource,2);
        int* player_besi = &Value(Resource,3);
        COMMAND C;
        Pop(&exeStack, &C);
        if (Comm(C) == 1)
        {
            switch (Map(C))
            {
                case 1:
                    build(&Map1, C);
                    break;
                case 2:
                    build(&Map2, C);
                    break;
                case 3:
                    build(&Map3, C);
                    break;
                case 4:
                    build(&Map4, C);
                    break;
                default:
                    break;
            }
        }
        else if (Comm(C) == 2)
        {

            switch (Map(C))
            {
                BinTree bt;

                // int player_air = Resource.TI[0].value;
                // int player_kayu = Resource.TI[1].value;
                // int player_batu = Resource.TI[2].value;
                // int player_besi = Resource.TI[3].value;
                case 1:
                    bt =  searchTree2(CariWahanaByID(Map1,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                       upgrade(&Map1,C,&bt,&player_money,player_air,player_kayu,player_batu,player_besi,&sejarahUpgrade); 
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                case 2:
                    bt =  searchTree2(CariWahanaByID(Map2,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                        upgrade(&Map2,C,&bt,&player_money,player_air,player_kayu,player_batu,player_besi,&sejarahUpgrade);
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                case 3:
                    bt =  searchTree2(CariWahanaByID(Map3,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                        upgrade(&Map3,C,&bt,&player_money,player_air,player_kayu,player_batu,player_besi,&sejarahUpgrade);
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                case 4:
                    bt =  searchTree2(CariWahanaByID(Map4,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                        upgrade(&Map4,C,&bt,&player_money,player_air,player_kayu,player_batu,player_besi,&sejarahUpgrade);
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                default:
                    break;
            }
            //dikurang material
            //upgrade ditambah
        }
        else if (Comm(C) == 3)
        {
            buy(&Resource,C);
            player_money-=Gold(C);
            // printf("Sisa uang setelah buy %d\n",player_money);
        }
        else if (Comm(C) == 4)
        {
            undo(&exeStack);
        }
    }
    printf("Sisa uang setelah execute %d\n",player_money);
}

// ==============================================================MAIN PHASE==========================================================

// void Serve()
// {
    
// }


// ========================office=============================================
// void DetailsCommandOffice(List map)
// {
//     if (!IsEmpty(map))
//     {
//         printf("DAFTAR WAHANA YANG ADA DI MAP INI");

//         //definisi dari wahana.txt ke array wahana
//         ArrayWahana W;
//         CreateDataWahana(&W);
//         CreateNamaWahana(&W);

//         //Print Wahana dalam list map
//         address now = First(map);
//         int urutan = 1;
//         printf("===================================\n");
//         while (now != Nil)
//         {
//             int i = searchID(W, Info(now));
//             printf("%d. ", urutan);
//             printf("%s\n", &W.ArrayW[i].nama.TabKata);
//             urutan++;
//             now = Next(now);
//         }
//         printf("===================================\n");

//         printf("inputkan nama wahana: ");
//         STARTKATA();

//         //validasi jika input tidak sesuai nama wahana
//         int indeksId;
//         namaToID(CKata, &indeksId);
//         while (!searchNamaWahana(CKata) || !Search(map, indeksId))
//         {
//             printf("input yang anda masukan salah, ulangi lagi!\n");
//             printf("inputkan nama wahana: ");
//             STARTKATA();
//             namaToID(CKata, &indeksId);
//         }

//         //print detail wahana
//         InfoWahana(W, indeksId);
//     }
//     else
//     {
//         printf("Belum ada wahana yang dibangun di map ini\n");
//     }
// }

// void ReportCommandOffice(List map)
// {
//     if (!IsEmpty(map))
//     {
//         printf("DAFTAR WAHANA YANG ADA DI MAP INI");

//         //definisi dari wahana.txt ke array wahana
//         ArrayWahana W;
//         CreateDataWahana(&W);
//         CreateNamaWahana(&W);

//         //Print Wahana dalam list map
//         address now = First(map);
//         int urutan = 1;
//         printf("===================================\n");
//         while (now != Nil)
//         {
//             int i = searchID(W, Info(now));
//             printf("%d. ", urutan);
//             printf("%s\n", &W.ArrayW[i].nama.TabKata);
//             urutan++;
//             now = Next(now);
//         }
//         printf("===================================\n");

//         printf("inputkan nama wahana: ");
//         STARTKATA();

//         //validasi jika input tidak sesuai nama wahana
//         int indeksId;
//         namaToID(CKata, &indeksId);
//         while (!searchNamaWahana(CKata) || !Search(map, indeksId))
//         {
//             printf("input yang anda masukan salah, ulangi lagi!\n");
//             printf("inputkan nama wahana: ");
//             STARTKATA();
//             namaToID(CKata, &indeksId);
//         }

//         //print laporan wahana
//         LaporanWahana(W, indeksId);
//     }
//     else
//     {
//         printf("Belum ada wahana yang dibangun di map ini\n");
//     }
// }

// void office()
// {
//     printf("================-----------================\n");
//     printf("================OFFICE MODE================\n");
//     printf("================-----------================\n");
//     printf("Masukkan perintah (Details / Report / Exit):\n");

//     // Set up kata yang ada di command office, beda sama yang ada di main
//     Kata Detailscom, Reportcom, Exitcom;
//     Detailscom.TabKata[0] = 'D';
//     Detailscom.TabKata[1] = 'e';
//     Detailscom.TabKata[2] = 't';
//     Detailscom.TabKata[3] = 'a';
//     Detailscom.TabKata[4] = 'i';
//     Detailscom.TabKata[5] = 'l';
//     Detailscom.TabKata[6] = 's';
//     Detailscom.Length = 7;

//     Reportcom.TabKata[0] = 'R';
//     Reportcom.TabKata[1] = 'e';
//     Reportcom.TabKata[2] = 'p';
//     Reportcom.TabKata[3] = 'o';
//     Reportcom.TabKata[4] = 'r';
//     Reportcom.TabKata[5] = 't';
//     Reportcom.Length = 6;

//     Exitcom.TabKata[0] = 'E';
//     Exitcom.TabKata[1] = 'x';
//     Exitcom.TabKata[2] = 'i';
//     Exitcom.TabKata[3] = 't';
//     Exitcom.Length = 4;
//     STARTKATA();
//     while (!IsKataSama(CKata, Exitcom))
//     {
//         while (!IsKataSama(CKata, Detailscom) && !IsKataSama(CKata, Reportcom) && !IsKataSama(CKata, Exitcom))
//         {
//             printf("===================================================\n");
//             printf("Maaf, command yang anda masukan salah, ulangi lagi!\n");
//             printf(">>>Masukkan perintah (Details / Report / Exit):<<<\n");
//             printf("===================================================\n");
//             STARTKATA();
//         }
//         if (IsKataSama(CKata, Exitcom))
//         {
//             break;
//         }
//         else if (IsKataSama(CKata, Detailscom))
//         {
//             if (crnt_map == 1)
//             {
//                 DetailsCommandOffice(listWahanaMap1);
//             }
//             else if (crnt_map == 2)
//             {
//                 DetailsCommandOffice(listWahanaMap2);
//             }
//             else if (crnt_map == 3)
//             {
//                 DetailsCommandOffice(listWahanaMap3);
//             }
//             else if (crnt_map == 4)
//             {
//                 DetailsCommandOffice(listWahanaMap4);
//             }
//         }
//         else if (IsKataSama(CKata, Reportcom))
//         {
//             if (crnt_map == 1)
//             {
//                 ReportCommandOffice(listWahanaMap1);
//             }
//             else if (crnt_map == 2)
//             {
//                 ReportCommandOffice(listWahanaMap2);
//             }
//             else if (crnt_map == 3)
//             {
//                 ReportCommandOffice(listWahanaMap3);
//             }
//             else if (crnt_map == 4)
//             {
//                 ReportCommandOffice(listWahanaMap4);
//             }
//         }
//         printf("Masukkan perintah (Details / Report / Exit):\n");
//         STARTKATA();
//     }
//     printf("================-----------================\n");
//     printf("=============KELUAR OFFICE MODE============\n");
//     printf("================-----------================\n");
// }
// ========================================================================