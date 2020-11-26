/* Header File buat Wahana */

#ifndef wahana_H
#define wahana_H

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"

/*  Kamus Umum */
#define IdxMax 99
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

/* Struktur buat Laporan Wahana*/
typedef struct
{
    int air;
    int kayu;
    int batu;
    int besi;
} UpgradeMaterial;

typedef struct
{
    int naiktotal;
    int penghasilantotal;
    int naikharian;
    int penghasilanharian;
} Laporan;

/* Struktur Data Khusus buat Detail Wahana */
typedef struct
{
    int id, harga, kapasitas, durasi, status;
    boolean isDibangun;
    POINT lokasi;
    Kata nama;
    Kata deskripsi;
    Laporan laporan;
    UpgradeMaterial material;
} Wahana;

typedef struct
{
    Wahana ArrayW[IdxMax + 1];
    int jumlahWahana;
} ArrayWahana;

#define ID(W, i) (W).ArrayW[(i)].id
#define Harga(W, i) (W).ArrayW[(i)].harga
#define Kapasitas(W, i) (W).ArrayW[(i)].kapasitas
#define Durasi(W, i) (W).ArrayW[(i)].durasi
#define Status(W, i) (W).ArrayW[(i)].status
#define NaikTotal(W, i) (W).ArrayW[(i)].laporan.naiktotal
#define TotalPenghasilan(W, i) (W).ArrayW[(i)].laporan.penghasilantotal
#define NaikHarian(W, i) (W).ArrayW[(i)].laporan.naikharian
#define PenghasilanHarian(W, i) (W).ArrayW[(i)].laporan.penghasilanharian
#define IsDibangun(W, i) (W).ArrayW[(i)].isDibangun
#define Air(W, i) (W).ArrayW[(i)].material.air
#define Kayu(W, i) (W).ArrayW[(i)].material.kayu
#define Batu(W, i) (W).ArrayW[(i)].material.batu
#define Besi(W, i) (W).ArrayW[(i)].material.besi
#define JumlahWahana(W) (W).jumlahWahana

// Baca dari teks file
void ListWahana();

// Buat Data Wahana Untuk Int
void CreateDataWahana(ArrayWahana *ArrayW);

// Buat Data wahana untuk Char
void CreateNamaWahana(ArrayWahana *W);

// Hitung panjang string
int mystrlen(char *str);

// Return Index
int searchID(ArrayWahana W, int id);

// Informasi Dasar Wahana by ID
void InfoWahana(ArrayWahana W, int id);

// Laporan Wahana by ID
void LaporanWahana(ArrayWahana W, int id);

void namaToID(Kata nama, int *idwahana);
/* I.S. nama wahana benar dan terdefinisi di wahana.txt */
/* F.S. idwahana berisi id dari nama*/

boolean searchNamaWahana(Kata nama);
/* Mengirimkan true jika terdapat nama di wahana.txt */

#endif
