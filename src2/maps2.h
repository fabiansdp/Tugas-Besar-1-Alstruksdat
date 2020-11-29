#ifndef maps2_H
#define maps2_H

#include "../ADT/boolean.h"
#include "../ADT/matriks.h"
#include "../ADT/point.h"

typedef struct {
	POINT P[200];
    int tipe[200];
} Arr_POINT;

void BacaPeta(int x, MATRIKS * L);
void TulisPeta(int x, MATRIKS L);
void TitikPeta(MATRIKS L, Arr_POINT AP);
void Movement(char ch, MATRIKS *L);
int SearchPoint(POINT P[], POINT Pcari);
void PrintPeta(MATRIKS L);
int Adjacency();

#endif