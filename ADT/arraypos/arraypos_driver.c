#include <stdio.h>
#include "arraypos.c"
#include "../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkar/mesinkar.h"

int main()
{
    TabEl T;
    MakeEmptyTabel(&T);

    if (IsKosong(T))
    {
        printf("Tabel LAGI KOSONG BOSQ\n");
    }

    printf("\nMaksimal elemen tabel ada %d\n", MaxNbEl(T));

    BacaIsi(&T);
    printf("\nIsi tabel: \n");
    TulisIsiTab(T);

    printf("\nBanyak elemen tabel ada %d\n", NbElmtTabel(T));

    //menambahkan last el dengan id = y value = 7
    ElTypeApos elemen;
    elemen.id = 7;
    elemen.value = 7;
    AddAsLastEl(&T, elemen);
    printf("\nHasil tabel setelah penambahan elemen dengan id = 7 dan value = 7\n");
    TulisIsiTab(T);

    //valueofID
    printf("\nvalue dari id 7 adalah %d\n", ValueOfId(T, 7));
    // penghapusan last el
    ElTypeApos temp;
    DelLastEl(&T, &temp);
    printf("\nHasil tabel setelah pengurangan elemen terakhir adalah\n");
    TulisIsiTab(T);

    //searchID
    // mencari apakah ada elemen yang berID 7
    if (SearchId(T, 7))
    {
        printf("\n\nada elemen yang berID 7\n");
    }
    else
    {
        printf("\ntidak ada elemen yang berID 7\n");
    }

    //searchK
    // mencari apakah ada elemen yang ber key 7
    if (SearchK(T, 7))
    {
        printf("\nada elemen yang berkey 7\n");
    }
    else
    {
        printf("\ntidak ada elemen yang berkey 7\n");
    }

    return 0;
}