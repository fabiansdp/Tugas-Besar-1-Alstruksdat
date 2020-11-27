#ifndef upgrade_H
#define upgrade_H

/* Definisi Type */
typedef int infotype;
typedef struct tUpdatelist *Uaddress;

#include "boolean.h"
#include "bintree.h"
#include "listrek.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"

typedef struct tUpdatelist { 
	infotype idWahana;
    BinTree detailUpgrade;
	Uaddress nextt;
} UList;

#define UID(X) (X)->idWahana
#define InfoUpgrade(X) (X)->detailUpgrade
#define Lanjut(X) (X)->nextt

typedef Uaddress ListUpdate;
/* Definisi list : */
/* List kosong : L = Nil */


Uaddress AlokUList (infotype X,BinTree Bt);

/* *** Selektor *** */
infotype FirstUID (ListUpdate L);
BinTree FirstBinU (ListUpdate L);
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
ListUpdate UTail(ListUpdate L);
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
ListUpdate UKonso(infotype e,BinTree B, ListUpdate L);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
ListUpdate UKonsB(ListUpdate L, infotype e,BinTree B);
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

ListUpdate MakeUpgradeList();
void PrintUpList(ListUpdate L);

BinTree SearchUList(ListUpdate L, infotype X);

void getUpgradeListTree(ListUpdate * L);

void addDaunLeft(BinTree * Utama, BinTree tambahan);
void addDaunRight(BinTree * Utama, BinTree tambahan);
#endif