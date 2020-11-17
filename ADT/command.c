#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"
#include "command.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk COMMAND *** */
COMMAND MakeCOMMAND(int comm, int name, int amount, int map, POINT coordinate, int time)
/* Membentuk sebuah COMMAND dari komponen-komponennya */
{
    COMMAND C;
    Comm(C) = comm;
    Name(C) = name;
    Amount(C) = amount;
    Map(C) = map;
    Coordinate(C) = coordinate;
    Time(C) = time;

    return C;
}

void TulisCOMMAND(COMMAND C)
/* Nilai C ditulis ke layar dengan format "(comm,name,amount,map,(X,Y),time)"*/
/* I.S. C terdefinisi */
/* F.S. C tertulis di layar dengan format "(comm,name,amount,map,(X,Y),time)" */
{
    printf("(%d,%d,%d,%d,(%.2f,%.2f),%d)\n", Comm(C), Name(C), Amount(C), Map(C), Absis(Coordinate(C)), Ordinat(Coordinate(C)), Time(C));
}