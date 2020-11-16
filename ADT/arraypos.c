#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"
#include "mesinkata.h"


void MakeEmpty (TabEl * T)
{
    IdxType i;
    for (i = IdxMin; i < IdxMax+1; i++)
    {
        Id(Elmt(*T,i)) = ValUndef;
        Value(Elmt(*T,i)) = ValUndef;
    }
    
}

int NbElmt (TabEl T)
{
    IdxType i = IdxMin;
    int Neff = 0;
    
    while ((Id(Elmt(T,i)) != ValUndef) && (i<=IdxMax))
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
    return (NbElmt(T)-1);
}

int MaxNbEl (TabEl T)
{
    return (IdxMax - IdxMin + 1);
}

boolean IsIdxValid (TabEl T, IdxType i)
{
    return ((i>=IdxMin) && (i<=IdxMax));
}

boolean IsIdxEff (TabEl T, IdxType i)
{
    return ((i>=GetFirstIdx(T))&&(i<=GetLastIdx(T)));
}

boolean IsEmpty (TabEl T)
{
    return (NbElmt(T) == 0);
}

boolean IsFull (TabEl T)
{
    return (NbElmt(T) == MaxNbEl(T));
}

void BacaIsi (TabEl * T)
{
    IdxType i;
    int N;
    MakeEmpty(T);

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
            scanf("%d", &Id(Elmt(*T,i)));
            printf("Masukkan nilai: ");
            scanf("%d", &Value(Elmt(*T,i)));
        }
    }
}

void TulisIsiTab (TabEl T)
{
    IdxType i;

    if (IsEmpty(T)) {
        printf("[]");
    } else
    {
        printf("[");
        for (i = IdxMin; i <= GetLastIdx(T); i++)
        {
            if (i!=GetLastIdx(T)) {
                printf("{");
                printf("ID: %d,", Id(Elmt(T,i)));
                printf(" Value: %d},\n", Value(Elmt(T,i)));
            } else {
                printf("{");
                printf("ID: %d,", Id(Elmt(T,i)));
                printf(" Value: %d}", Value(Elmt(T,i)));
            }
        }
        printf("]");
    }
    
}

IdxType SearchId (TabEl T, int X)
{
    IdxType i = GetFirstIdx(T);

    while ((i<=GetLastIdx(T))) {
        if (Id(Elmt(T,i)) == X)
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

    return Value(Elmt(T,i));
}

void AddAsLastEl (TabEl * T, ElType X)
{
    if (!IsFull(*T)) {
        Elmt(*T,GetLastIdx(*T) + 1) = X;
    }
}

void DelLastEl (TabEl * T, ElType * X)
{
    if (!IsEmpty(*T)) {
        *X = Elmt(*T,GetLastIdx(*T));
        Id(Elmt(*T,GetLastIdx(*T))) = ValUndef;
        Value(Elmt(*T,GetLastIdx(*T))) = ValUndef;
    }
}