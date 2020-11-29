#include <stdio.h>
#include "arraypos.h"
#include "../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkar/mesinkar.h"


void MakeEmptyTabel (TabEl * T) 
{
    IdxType i;
    for (i = IdxMin; i < IdxMax+1; i++)
    {
        Id(*T,i) = ValUndef;
        Value(*T,i) = ValUndef;
    }
    
}

int NbElmtTabel (TabEl T)
{
    IdxType i = IdxMin;
    int Neff = 0;
    
    while ((Id(T,i) != ValUndef) && (i<=IdxMax))
    {
        Neff+=1;
        i++;
    }
    
    return Neff;
}

IdxType GetFirstIdx (TabEl T)
{
    return IdxMin;
}

IdxType GetLastIdx (TabEl T)
{
    return (NbElmtTabel(T)-1);
}

int MaxNbEl (TabEl T)
{
    return (IdxMax - IdxMin + 1);
}

boolean IsIdxValidTabel (TabEl T, IdxType i)
{
    return ((i>=IdxMin) && (i<=IdxMax));
}

boolean IsIdxEffTabel (TabEl T, IdxType i)
{
    return ((i>=GetFirstIdx(T))&&(i<=GetLastIdx(T)));
}

boolean IsKosong (TabEl T)
{
    return (NbElmtTabel(T) == 0);
}

boolean IsFull (TabEl T)
{
    return (NbElmtTabel(T) == MaxNbEl(T));
}

void BacaIsi (TabEl * T)
{
    IdxType i;
    int N;
    MakeEmptyTabel(T);

    do {
        printf("Berapa banyak elemen yang ingin diinput?\n");
        scanf("%d", &N);
    } while (!((N >= 0) && (N <= MaxNbEl(*T))));

    if (N==0) {
        return;
    } else
    {
        for (i=IdxMin; i<=N-1; i++) {
            printf("Elemen ke-%d\n", i+1);
            printf("Masukkan ID item: ");
            scanf("%d", &Id(*T,i));
            printf("Masukkan nilai: ");
            scanf("%d", &Value(*T,i));
        }
    }
}

void TulisIsiTab (TabEl T)
{
    IdxType i;

    if (IsKosong(T)) {
        printf("[]");
    } else
    {
        printf("[");
        for (i = IdxMin; i <= GetLastIdx(T); i++)
        {
            if (i!=GetLastIdx(T)) {
                printf("{");
                printf("ID: %d,", Id(T,i));
                printf(" Value: %d},\n", Value(T,i));
            } else {
                printf("{");
                printf("ID: %d,", Id(T,i));
                printf(" Value: %d}", Value(T,i));
            }
        }
        printf("]");
    }
    
}

IdxType SearchId (TabEl T, int X)
{
    IdxType i = GetFirstIdx(T);

    while ((i<=GetLastIdx(T))) {
        if (Id(T,i) == X)
        {
            return i;
        } else {
            i++;
        }
    }

    return IdxUndef;
}

boolean SearchK (TabEl T, int X)
{
    return (SearchId(T,X) != IdxUndef);
}

int ValueOfId (TabEl T, int X)
{
    IdxType i = SearchId(T,X);

    return Value(T,i);
}

void AddAsLastEl (TabEl * T, ElTypeApos X)
{
    if (!IsFull(*T)) {
        Elmt(*T,GetLastIdx(*T) + 1) = X;
    }
}

void DelLastEl (TabEl * T, ElTypeApos * X)
{
    if (!IsKosong(*T)) {
        *X = Elmt(*T,GetLastIdx(*T));
        Id(*T,GetLastIdx(*T)) = ValUndef;
        Value(*T,GetLastIdx(*T)) = ValUndef;
    }
}