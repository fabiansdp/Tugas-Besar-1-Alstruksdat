/* Header File buat Wahana */

#ifndef wahana_H
#define wahana_H

#include "boolean.h"

/*  Kamus Umum */
#define IdxMax 99
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/
#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

/* Struktur Data Khusus buat Wahana */
typedef struct {
    int id, harga, kapasitas, durasi, status;
    char namaWahana[50];
    char deskripsi[100];
} Wahana;

typedef struct {
    Wahana TI[11];
} ArrayWahana;

#define ID(W) (W).id
#define Harga(W) (W).harga
#define Kapasitas(W) (W).kapasitas
#define Durasi(W) (W).durasi
#define Status(W) (W).status

// Baca dari teks file
void TeksWahana();

// Buat Wahana
void CreateWahana(Wahana *W, int id);

// Ambil ID Wahana
int idWahana(Wahana W);

// Ambil Harga Wahana
int hargaWahana(Wahana W);

// Ambil Kapasitas Wahana
int kapasitasWahana(Wahana W);

// Ambil Durasi Wahana
int durasiWahana(Wahana W);

// Ambil Status Wahana
int statusWahana(Wahana W);

// Ambil Detail Wahana
void detailWahana(Wahana W);

#endif

