/* ADT Wahana dengan membaca file wahana.txt */

#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

// Print Daftar Wahana
void ListWahana()
{
    FILE *fh = fopen("../wahana.txt", "r");
    char c[1000];

    if (fh == NULL) {
        printf("File Tidak Bisa Dibuka!\n");
    } else {
        int count = 1; // Hitung urutan kata ke-berapa
        int number = 1; // Hitung jumlah wahana

        // Print Nama Wahana
        // Gini aja aku bingung banget
        puts("List Wahana yang Tersedia: ");
        while (fscanf(fh, "%s", c) != EOF) {
            if (count == 2) {
                printf("%d. %s\n", number, c);
                number += 1;
            }

            count += 1;

            if (count == 7) {
                count = 1;
            }
        }
        puts("");
        fclose(fh);
    }
}

// Buat Wahana
void CreateDatabaseWahana(ArrayWahana *ArrayW)
{
    
}

// Ambil ID Wahana
int idWahana(Wahana W)
{
    return ID(W);
}

// Ambil Harga Wahana
int hargaWahana(Wahana W)
{
    return Harga(W);
}

// Ambil Kapasitas Wahana
int kapasitasWahana(Wahana W)
{
    return Kapasitas(W);
}

// Ambil Durasi Wahana
int durasiWahana(Wahana W)
{
    return Durasi(W);
}

// Ambil Status Wahana
int statusWahana(Wahana W)
{
    return statusWahana(W);
}

// Ambil Detail Wahana
void detailWahana(Wahana W)
{

}

int main() {
    ArrayWahana ArrayW;
    TeksWahana();
    
    CreateDatabaseWahana(&ArrayW);
    return 0;
}