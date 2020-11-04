/*File : jam.h*/

/* spesifikasi ADT Jam*/
#ifndef jam_H
#define jam_H
#include "boolean.h"

/*Notasi Akses*/
#define Hour(J) (J).HH
#define Minute(J) (J).MM

typedef struct{
    int HH;
    int MM;  
}Jam;

/*****Konstuktor *****/
Jam MakeJam(int H,int M);
/* Membentuk Jam dari H, M, S yang valid */

/*------------validator jam------------*/
boolean IsJValid(int H,int M);
/* Mengirim true jika H,M,S dapat membentuk Jam yang valid */

/*------------Baca & Tulisjam-----------*/
void BacaJam(Jam *J);
/* I.S. : J tak terdefinisi*/
/* F.S. : J terdefinisi dan merupakan jam valid */
/* Proses : mengulang baca komponen H,M sehingga membentuk J yang valid */

void TulisJam(Jam J);
/* I.S. : J sembarang*/
/* F.S. : J ditulis ke layar dengan format HH:MM*/
/* Proses : Menulis ke layar*/

int JamToDetik(Jam J);
/* Konversi Jam menjadi detik*/

Jam DetikToJam(int N);
/* Konversi detik ke Jam */

void TambahMenit(Jam J, int X);
/*Nambah X menit ke current time*/

#endif
