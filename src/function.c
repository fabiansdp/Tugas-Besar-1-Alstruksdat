#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/listlinier.h"
#include "../ADT/wahana.h"
#include "../ADT/arraypos.h"
// #include "../ADT/listlinier.h"
#include "../ADT/bintree.h"
#include "../ADT/listrek.h"
// #include "../ADT/arraypos.h"

extern int player_money;
extern TabEl Resource;
extern int banyak;
extern int indeks_buy;
extern int x,y;
extern ArrayWahana Map1, Map2, Map3, Map4;
extern int tipe_point[10][20];
BasisListWahana B;
// ===================================================PREPARATION PHASE========================================================

void build(ArrayWahana *W, COMMAND C)
{
    int x = Absis(Coordinate(C))-1;
    int y = Ordinat(Coordinate(C));

    // Cek wahana di lokasi atasnya ada wahana atau tidak
    POINT LokasiAtas = MakePOINT(x, y);
    DetilWahana CekWahana = CariWahanaByLoc(*W, LokasiAtas);

    // Cek ada wahana, border, office, atau gerbang
    if ((CekWahana.id != ValUndef) && (tipe_point[x-1][y] != 6) && (tipe_point[x-1][y] != 3) && (tipe_point[x-1][y] != 4)) {
        Wahana WahanaBaru = SearchWahanaBase(B, Name(C));
        BinTree TreeBaru = SearchUList(B, Name(C));
        DetilWahana DetilBaru = DirikanWahanaBaru((*W).jumlahWahana, WahanaBaru, LokasiAtas, TreeBaru);
        PushNewWahana(W, DetilBaru);
        player_money -= Gold(C);

    } else {
        puts("Tidak bisa membangun di lokasi ini!");
    }
}

void upgrade()
{
    printf("ini UPGRADE\n");
}

void buy()
{
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
    while (!IsEmptyStack(*S))
    {
        COMMAND C;
        Pop(S, &C);
        Push(&exeStack, C);
    }
    while (!IsEmptyStack(exeStack))
    {
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
            upgrade();
            //dikurang material
            //upgrade ditambah
        }
        else if (Comm(C) == 3)
        {
            buy();
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