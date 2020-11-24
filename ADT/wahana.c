/* ADT Wahana dengan membaca file wahana.txt */

#include <stdio.h>
#include <stdlib.h>
#include "wahana.h"

// Print Daftar Wahana
void ListWahana()
{
    FILE *fh = fopen("../wahana.txt", "r");
    char c[500];

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
void CreateDataWahana(ArrayWahana *W)
{
    FILE *fh = fopen("../wahana.txt", "r");
    char c[500];

    if (fh == NULL) {
        printf("File Tidak Bisa Dibuka!\n");
    } else {
        int count = 1; // Hitung urutan kata ke-berapa
        int number = 0;

        // Gini aja aku bingung banget
        while (fscanf(fh, "%s", c) != EOF) {
            JumlahWahana(*W) = number;
            if (count == 1) {
                int id = atoi(c);
                ID(*W, number) = id;
                NaikTotal(*W,number) = 0;
                TotalPenghasilan(*W,number) = 0;
                NaikHarian(*W,number) = 0;
                PenghasilanHarian(*W,number) = 0;
            }

            if (count == 3) {
                int harga = atoi(c);
                Harga(*W, number) =  harga;
            }

            if (count == 4) {
                int kapasitas = atoi(c);
                Kapasitas(*W, number) = kapasitas;
            }

            if (count == 5) {
                int durasi = atoi(c);
                Durasi(*W, number) = durasi;
            }

            count += 1;

            if (count == 7) {
                Status(*W, number) = 1;
                count = 1;
                number += 1;
            }
        }
        puts("");
        fclose(fh);
    }
}

int mystrlen(char *str) {
    int len = 0;
    int i = 0;
    for (i=0; str[i] != 0; i++) 
    {
        len++;
    }
    return(len);
}

void CreateNamaWahana(ArrayWahana *W)
{
    FILE *fh = fopen("../wahana.txt", "r");
    char c[30];

    if (fh == NULL) {
        printf("File Tidak Bisa Dibuka!\n");
    } else {
        int count = 1; // Hitung urutan kata ke-berapa
        int number = 0;

        // Gini aja aku bingung banget
        while (fscanf(fh, "%s", c) != EOF) {
            if (count == 2) {
                (*W).ArrayW[number].nama.Length = mystrlen(c);
                for (int j = 0; j<mystrlen(c); j++) {
                    (*W).ArrayW[number].nama.TabKata[j] = c[j];
                }
            }

            if (count == 6) {
                (*W).ArrayW[number].deskripsi.Length = mystrlen(c);
                for (int j = 0; j<mystrlen(c); j++) {
                    (*W).ArrayW[number].deskripsi.TabKata[j] = c[j];
                }
            }

            count += 1;

            if (count == 7) {
                Status(*W, number) = 1;
                count = 1;
                number += 1;
            }
        }
        printf("%d\n", (*W).ArrayW[4].nama.Length);
        fclose(fh);
    }
}

// Return Index dimana ada ID
int searchID(ArrayWahana W, int id)
{
    int index = 0;
    boolean found = false;

    while ((index < JumlahWahana(W)) && !found) {
        if (ID(W,index) == id) {
            found = true;
        } else {
            index += 1;
        }
    }

    if (found) {
        return index;
    } else {
        return -1;
    }
}


// Ambil Info Wahana
void InfoWahana(ArrayWahana W, int id)
{
    int i = searchID(W,id);
    printf("==== Detail Wahana ====\n");
    printf("Nama Wahana: ");
    puts(W.ArrayW[i].nama.TabKata);
    printf("Deskripsi Wahana: ");
    puts(W.ArrayW[i].deskripsi.TabKata);
    printf("Harga Wahana: %d\n", Harga(W, i));
    printf("Kapasitas Wahana: %d\n", Kapasitas(W, i));
    printf("Durasi Wahana: %d\n", Durasi(W, i));
    printf("Status: ");
    if (Status(W, i) == 0) {
        printf("Rusak\n");
    } else {
        printf("Normal\n");
    }
    printf("\n");
}

void LaporanWahana(ArrayWahana W, int id)
{
    int i = searchID(W,id);
    printf("==== Laporan Wahana ====\n");
    printf("Total Dinaiki: %d\n", NaikTotal(W,i));
    printf("Dinaiki hari ini: %d\n", NaikHarian(W,i));
    printf("Penghasilan Total: %d\n", TotalPenghasilan(W,i));
    printf("Penghasilan Hari Ini: %d\n\n", PenghasilanHarian(W,i));
}