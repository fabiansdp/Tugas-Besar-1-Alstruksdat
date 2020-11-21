/* *** Definisi ABSTRACT DATA TYPE COMMAND *** */

#ifndef COMMAND_H
#define COMMAND_H

#include "boolean.h"
#include "point.h"

#define Nil -1
typedef struct
{
    /*
    BUILD   = 1
    UPGRADE = 2
    BUY     = 3
    UNDO    = 4
    */
    int comm;
    /*
    ID WAHANA
    "Candy Crush"           = 11
    "Chocolate Forest"      = 12
    "Bombom car"            = 13
    "Lemon Splash"          = 14
    "Candy Village"         = 15
    "Candy Swing"           = 16
    "Blackforest Tornado"   = 17

    ID MATERIAL
    air     = 21
    kayu    = 22
    batu    = 23
    besi    = 24
    */
    int name;
    int amount;       /* Diisi jumlah material yang dibutuhkan, isi Nil jika tidak membutuhkan komponen ini */
    int map;          /* Diisi peta 1/2/3/4, isi Nil jika tidak membutuhkan komponen ini */
    POINT coordinate; /* Diisi koordinat dalam peta dengan selektor di adt point, isi Nil jika tidak membutuhkan komponen ini */
    int time;         /* Diisi waktu yang dibutuhkan dalam command yang digunakan, isi Nil jika tidak membutuhkan komponen ini */
} COMMAND;

/* *** Notasi Akses: Selektor COMMAND *** */
#define Comm(C) (C).comm
#define Name(C) (C).name
#define Amount(C) (C).amount
#define Map(C) (C).map
#define Coordinate(C) (C).coordinate
#define Time(C) (C).time

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk COMMAND *** */
COMMAND MakeCOMMAND(int comm, int name, int amount, int map, POINT coordinate, int time);
/* Membentuk sebuah COMMAND dari komponen-komponennya */

void MakeEmptyCOMMAND(COMMAND *C);
/* Membentuk sebuah COMMAND yang komponenya nil */

void TulisCOMMAND(COMMAND C);
/* Nilai C ditulis ke layar dengan format "(comm,name,amount,map,(X,Y),time)"*/
/* I.S. C terdefinisi */
/* F.S. C tertulis di layar dengan format "(comm,name,amount,map,(X,Y),time)" */
#endif