#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkar/mesinkar.h"
#include "../ADT/wahana/wahana.h"
#include "../ADT/point/point.h"
#include "../ADT/bintree/bintree.h"
#include "../ADT/listrek/listrek.h"
// ==================================Deklarasi
// ArrayWahana Map1, Map2, Map3, Map4;
// int crnt_map = 1; //asumsi player di map1
// DetilWahana vardetilwahana;
extern ArrayWahana Map1, Map2, Map3, Map4;
extern int crnt_map;
extern Jam crnt_jam,temp_jam;
extern ListHistoUpdate sejarahUpgrade;
DetilWahana vardetilwahana;

//===============================FUNGSI TAMBAHAN====================================================
int konvertKata(Kata K)
{
    int a = K.Length;
    int x;
    int res = 0;
    for (x = 0; x < K.Length; x++)
    {
        if (K.TabKata[x] >= '0' && K.TabKata[x] <= '9')
        {
            int pangkat = (int)pow(10, a - 1);
            int konvert = (int)K.TabKata[x];
            konvert = konvert - 48;
            res = res + (pangkat * (konvert));
            a = a - 1;
        }
    }
    return res;
}

void PrintHistoryUpgrade(BinTree P)
{
    if (!IsTreeEmpty(P))
    {
        if (P->isApplied)
        {
            int aha;
            for (aha = 0; aha < P->detail.Length; aha++)
            {
                printf("%c", P->detail.TabKata[aha]);
            }
            printkata(P->detail);
            printf("\n");
        }

        PrintHistoryUpgrade(Left(P));
        PrintHistoryUpgrade(Right(P));
    }
    else
    {
        printf("Wahana ini belum pernah di upgrade.\n");
    }
}

//===============================OFFICE COMMAND====================================================
void DetailsCommandOffice(ArrayWahana map)
{
    if (!map.jumlahWahana == 0)
    {
        printf("============================================\n");
        printf("     DAFTAR WAHANA YANG ADA DI MAP INI\n");
        printf("--------------------------------------------\n");

        //Print wahana yang ada dalam arraywahana tiap map
        for (int i = 0; i < map.jumlahWahana; i++)
        {
            printf("Input %d untuk wahana ", (i + 1));
            printkata(map.ArrayW[i].wahana.nama);
            printf("\n");
        }
        printf("============================================\n");

        //input user untuk memilih wahana
        printf("input: ");
        STARTKATA();
        printf("--------------------------------------------\n");
        int input = konvertKata(CKata);
        while (input <= 0 || input > map.jumlahWahana)
        {
            printf("input yang anda masukan salah, ulangi lagi!\n");
            printf("input: ");
            STARTKATA();
            printf("--------------------------------------------\n");
            input = konvertKata(CKata);
        }

        //Print detail wahana
        printf("Nama wahana      = ");
        printkata(map.ArrayW[input - 1].wahana.nama);
        printf("\n");
        printf("Harga wahana     = %d\n", map.ArrayW[input - 1].wahana.harga);
        printf("Lokasi wahana    = %.2f,%.2f\n", map.ArrayW[input - 1].lokasi.X, map.ArrayW[input - 1].lokasi.Y);
        printf("Deskripsi wahana = ");
        printkata(map.ArrayW[input - 1].wahana.deskripsi);
        printf("\n");
        printf("Kapasitas wahana = %d\n", map.ArrayW[input - 1].wahana.kapasitas);
        printf("Durasi wahana    = %d\n", map.ArrayW[input - 1].wahana.durasi);
        printf("History upgrade  =\n");
        PrintHistoryByID(sejarahUpgrade,map.ArrayW[input - 1].id);
        // PrintHistoryUpgrade(map.ArrayW[input - 1].upgradeTree);
        printf("============================================\n");
        TambahMenit(&crnt_jam,10);
        temp_jam = DetikToJam(JamToDetik(temp_jam) - 600);
    }
    else
    {
        printf("Belum ada wahana yang dibangun di map ini\n");
    }
}

void ReportCommandOffice(ArrayWahana map)
{
    if (!map.jumlahWahana == 0)
    {
        printf("============================================\n");
        printf("     DAFTAR WAHANA YANG ADA DI MAP INI\n");
        printf("--------------------------------------------\n");

        //Print wahana yang ada dalam arraywahana tiap map
        for (int i = 0; i < map.jumlahWahana; i++)
        {
            printf("Input %d untuk wahana ", (i + 1));
            printkata(map.ArrayW[i].wahana.nama);
            printf("\n");
        }
        printf("============================================\n");

        //input user untuk memilih wahana
        printf("input: ");
        STARTKATA();
        printf("--------------------------------------------\n");
        int input = konvertKata(CKata);
        while (input <= 0 || input > map.jumlahWahana)
        {
            printf("input yang anda masukan salah, ulangi lagi!\n");
            printf("input: ");
            STARTKATA();
            printf("--------------------------------------------\n");
            input = konvertKata(CKata);
        }

        //Print laporan wahana
        printf("Total penggunaan wahana           = %d\n", map.ArrayW[input - 1].laporan.naiktotal);
        printf("Total penghasilan wahana          = %d\n", map.ArrayW[input - 1].laporan.penghasilantotal);
        printf("Total penggunaan wahana hari ini  = %d\n", map.ArrayW[input - 1].laporan.naikharian);
        printf("Total penghasilan wahana hari ini = %d\n", map.ArrayW[input - 1].laporan.penghasilanharian);
        printf("============================================\n");
        TambahMenit(&crnt_jam,10);
        temp_jam = DetikToJam(JamToDetik(temp_jam) - 600);
    }
    else
    {
        printf("Belum ada wahana yang dibangun di map ini\n");
    }
}

void office()
{

    printf("================-----------================\n");
    printf("================OFFICE MODE================\n");
    printf("================-----------================\n");
    printf("              .SELAMAT DATANG.              \n");
    printf("Masukkan perintah (Details / Report / Exit):\n");

    // Set up kata yang ada di command office, beda sama yang ada di main
    Kata Detailscom, Reportcom, Exitcom;
    Detailscom.TabKata[0] = 'D';
    Detailscom.TabKata[1] = 'e';
    Detailscom.TabKata[2] = 't';
    Detailscom.TabKata[3] = 'a';
    Detailscom.TabKata[4] = 'i';
    Detailscom.TabKata[5] = 'l';
    Detailscom.TabKata[6] = 's';
    Detailscom.Length = 7;

    Reportcom.TabKata[0] = 'R';
    Reportcom.TabKata[1] = 'e';
    Reportcom.TabKata[2] = 'p';
    Reportcom.TabKata[3] = 'o';
    Reportcom.TabKata[4] = 'r';
    Reportcom.TabKata[5] = 't';
    Reportcom.Length = 6;

    Exitcom.TabKata[0] = 'E';
    Exitcom.TabKata[1] = 'x';
    Exitcom.TabKata[2] = 'i';
    Exitcom.TabKata[3] = 't';
    Exitcom.Length = 4;
    STARTKATA();
    while (!IsKataSama(CKata, Exitcom))
    {
        while (!IsKataSama(CKata, Detailscom) && !IsKataSama(CKata, Reportcom) && !IsKataSama(CKata, Exitcom))
        {
            printf("===================================================\n");
            printf("Maaf, command yang anda masukan salah, ulangi lagi!\n");
            printf(">>>Masukkan perintah (Details / Report / Exit)<<<\n");
            printf("===================================================\n");
            STARTKATA();
        }
        if (IsKataSama(CKata, Exitcom))
        {
            break;
        }
        else if (IsKataSama(CKata, Detailscom))
        {
            if (crnt_map == 1)
            {
                DetailsCommandOffice(Map1);
            }
            else if (crnt_map == 2)
            {
                DetailsCommandOffice(Map2);
            }
            else if (crnt_map == 3)
            {
                DetailsCommandOffice(Map3);
            }
            else if (crnt_map == 4)
            {
                DetailsCommandOffice(Map4);
            }
        }
        else if (IsKataSama(CKata, Reportcom))
        {
            if (crnt_map == 1)
            {
                ReportCommandOffice(Map1);
            }
            else if (crnt_map == 2)
            {
                ReportCommandOffice(Map2);
            }
            else if (crnt_map == 3)
            {
                ReportCommandOffice(Map3);
            }
            else if (crnt_map == 4)
            {
                ReportCommandOffice(Map4);
            }
        }
        printf("Masukkan perintah (Details / Report / Exit):\n");
        STARTKATA();
    }
    printf("================-----------================\n");
    printf("=============KELUAR OFFICE MODE============\n");
    printf("================-----------================\n");
}

// ==================================DETAIL COMMAND==========
void detail(DetilWahana W)
{
    printf("Nama wahana      = ");
    printkata(W.wahana.nama);
    printf("\n");
    printf("Harga wahana     = %d\n", W.wahana.harga);
    printf("Lokasi wahana    = %.2f,%.2f\n", W.lokasi.X, W.lokasi.Y);
    printf("Deskripsi wahana = ");
    printkata(W.wahana.deskripsi);
    printf("\n");
    printf("Kapasitas wahana = %d\n", W.wahana.kapasitas);
    printf("Durasi wahana    = %d\n", W.wahana.durasi);
    printf("History upgrade  =\n");
    PrintHistoryByID(sejarahUpgrade,W.id);
    TambahMenit(&crnt_jam,10);
    temp_jam = DetikToJam(JamToDetik(temp_jam) - 600);
}

//===============================TESTING====================================================
// int main()
// {
//     BasisListWahana B = MakeUpgradeList();
//     makeArrayWahana(&Map1);

//     // build Candy Crush
//     POINT LokasiAtas = MakePOINT(11, 24);
//     Wahana WahanaBaru = SearchWahanaBase(B, 11);
//     BinTree TreeBaru = SearchUList(B, 11);
//     DetilWahana DetilBaru = DirikanWahanaBaru((Map1).jumlahWahana, WahanaBaru, LokasiAtas, TreeBaru);
//     PushNewWahana(&Map1, DetilBaru);

//     // Build bombomcar
//     POINT LokasiAtas2 = MakePOINT(13, 24);
//     Wahana WahanaBaru2 = SearchWahanaBase(B, 13);
//     BinTree TreeBaru2 = SearchUList(B, 13);
//     DetilWahana DetilBaru2 = DirikanWahanaBaru((Map1).jumlahWahana, WahanaBaru2, LokasiAtas2, TreeBaru2);
//     PushNewWahana(&Map1, DetilBaru2);

//     // Build forest
//     POINT LokasiAtas3 = MakePOINT(13, 24);
//     Wahana WahanaBaru3 = SearchWahanaBase(B, 17);
//     BinTree TreeBaru3 = SearchUList(B, 17);
//     DetilWahana DetilBaru3 = DirikanWahanaBaru((Map1).jumlahWahana, WahanaBaru3, LokasiAtas3, TreeBaru3);
//     PushNewWahana(&Map1, DetilBaru3);

//     // ==========================================================
//     printf("Selamat datang di game!!\n");
//     printf("Masukan command!!\n");

//     Kata officecom, exitcom;

//     officecom.TabKata[0] = 'o';
//     officecom.TabKata[1] = 'f';
//     officecom.TabKata[2] = 'f';
//     officecom.TabKata[3] = 'i';
//     officecom.TabKata[4] = 'c';
//     officecom.TabKata[5] = 'e';
//     officecom.Length = 6;

//     exitcom.TabKata[0] = 'e';
//     exitcom.TabKata[1] = 'x';
//     exitcom.TabKata[2] = 'i';
//     exitcom.TabKata[3] = 't';
//     exitcom.Length = 4;

//     printf("===========================================\n");
//     printf("===========================================\n");
//     printf("================MAIN MODE==================\n");
//     printf("===========================================\n");
//     printf("===========================================\n");
//     printf("===========================================\n");
//     STARTKATA();
//     while (!IsKataSama(CKata, exitcom))
//     {
//         while (!IsKataSama(CKata, officecom) && !IsKataSama(CKata, exitcom))
//         {
//             printf("===========================================\n");
//             printf("===========================================\n");
//             printf("================MAIN MODE==================\n");
//             printf("===========================================\n");
//             printf("===========================================\n");
//             printf("===========================================\n");
//             printf("Maaf, command yang anda masukan salah, ulangi lagi!\n");
//             STARTKATA();
//         }
//         if (IsKataSama(CKata, officecom))
//         {
//             office();
//         }
//         printf("===========================================\n");
//         printf("===========================================\n");
//         printf("================MAIN MODE==================\n");
//         printf("===========================================\n");
//         printf("===========================================\n");
//         printf("===========================================\n");
//         STARTKATA();
//     }
//     if (IsKataSama(CKata, exitcom))
//     {
//         printf("Terimakasih sudah bermain!\n");
//     }

//     return 0;
// }