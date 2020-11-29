#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkar.c"

void Details()
{
    printf("===================================\n");
    printf("|| Tekan 1 untuk detail wahana x ||\n");
    printf("|| Tekan 2 untuk detail wahana x ||\n");
    printf("===================================\n");
    int id;
    scanf("%d", &id);
    while (CC != MARK)
        ;
    {
        printf("INI DETAIL WAHANA =====> %d\n", id);
        printf("Tekan Enter untuk kembali\n");
        START();
    }
}

void Report()
{
    printf("===================================\n");
    printf("|| Tekan 1 untuk laporan wahana x ||\n");
    printf("|| Tekan 2 untuk laporan wahana x ||\n");
    printf("===================================\n");
    int id;
    scanf("%d", &id);
    printf("%d\n", id);
}

void office()
{
    printf("//OFFICE MODE//\n");
    printf("Masukkan perintah (Details / Report / Exit):\n");

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
            printf("Maaf, command yang anda masukan salah, ulangi lagi!\n");
            printf("Masukkan perintah (Details / Report / Exit):\n");
            STARTKATA();
        }

        if (IsKataSama(CKata, Detailscom))
        {
            Details();
        }
        else if (IsKataSama(CKata, Reportcom))
        {
            Report();
        }
        STARTKATA();
    }
    printf("//KELUAR DARI OFFICE MODE//\n");
}

int main()
{
    printf("Selamat datang di game!!\n");
    printf("Masukan command!!\n");

    Kata officecom, exitcom;

    officecom.TabKata[0] = 'o';
    officecom.TabKata[1] = 'f';
    officecom.TabKata[2] = 'f';
    officecom.TabKata[3] = 'i';
    officecom.TabKata[4] = 'c';
    officecom.TabKata[5] = 'e';
    officecom.Length = 6;

    exitcom.TabKata[0] = 'e';
    exitcom.TabKata[1] = 'x';
    exitcom.TabKata[2] = 'i';
    exitcom.TabKata[3] = 't';
    exitcom.Length = 4;

    printf("===========================================\n");
    printf("===========================================\n");
    printf("================GAME MODE==================\n");
    printf("===========================================\n");
    printf("===========================================\n");
    printf("===========================================\n");
    STARTKATA();
    while (!IsKataSama(CKata, exitcom))
    {
        while (!IsKataSama(CKata, officecom) && !IsKataSama(CKata, exitcom))
        {
            printf("===========================================\n");
            printf("===========================================\n");
            printf("================GAME MODE==================\n");
            printf("===========================================\n");
            printf("===========================================\n");
            printf("===========================================\n");
            printf("Maaf, command yang anda masukan salah, ulangi lagi!\n");
            STARTKATA();
        }
        if (IsKataSama(CKata, officecom))
        {
            office();
        }
        printf("===========================================\n");
        printf("===========================================\n");
        printf("================GAME MODE==================\n");
        printf("===========================================\n");
        printf("===========================================\n");
        printf("===========================================\n");
        STARTKATA();
    }
    if (IsKataSama(CKata, exitcom))
    {
        printf("Terimakasih sudah bermain!\n");
    }

    return 0;
}