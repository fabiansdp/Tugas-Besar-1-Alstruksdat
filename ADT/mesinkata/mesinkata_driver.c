#include <stdio.h>
#include "mesinkata.h"
#include "../mesinkar/mesinkar.h"

int main()
{
    printf("Input 2 kata dipisah spasi: ");
    STARTKATA();
    printf("Print hasil pembacaan kata pertama= %s", CKata.TabKata);
    ADVKATA();
    printf("Print hasil pembacaan kata kedua = %s", CKata.TabKata);

    //IskataSama
    printf("Membandingkan kata dengan iskatasama:\n");
    Kata Exitcom;
    Exitcom.TabKata[0] = 'E';
    Exitcom.TabKata[1] = 'x';
    Exitcom.TabKata[2] = 'i';
    Exitcom.TabKata[3] = 't';
    Exitcom.Length = 4;
    printf("Input kata untuk dibandingkan dengan kata 'Exit'\n");
    STARTKATA();
    if (IsKataSama(CKata, Exitcom))
    {
        printf("Input anda adalah 'Exit'\n");
    }
    else
    {
        printf("Input anda bukan 'Exit'\n");
    }

    return 0;
}