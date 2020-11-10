#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"
#include "mesinkata.h"


void MakeEmpty (TabEl * T)
{
    IdxType i;
    for (i = IdxMin; i < IdxMax+1; i++)
    {
        Key(Elmt(*T,i))[0] = CharUndef;
        Value(Elmt(*T,i)) = ValUndef;
    }
    
}

int NbElmt (TabEl T)
{
    IdxType i = IdxMin;
    int Neff = 0;
    
    while ((Value(Elmt(T,i)) != ValUndef) && (i<=IdxMax))
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
            getchar();
            printf("Masukkan item: ");
            fgets(Key(Elmt(*T,i)), 50, stdin);
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
                printf("Key: ");
                for (int j=0; j<NMax; j++) {
                    printf("%c", Key(Elmt(T,i))[j]);
                }
                printf(",");
                printf(" Value: %d},\n", Value(Elmt(T,i)));
            } else {
                printf("{");
                printf("Key: %c,", *Key(Elmt(T,i)));
                printf(" Value: %d}", Value(Elmt(T,i)));
            }
        }
        printf("]");
    }
    
}

IdxType SearchKey (TabEl T, char X)
{
    IdxType i = GetFirstIdx(T);

    while ((i<=GetLastIdx(T))) {
        if (*Key(Elmt(T,i)) == X)
        {
            return i;
        } else {
            i++;
        }
    }

    return IdxUndef;
}

boolean SearchK (TabEl T, ElType X)
{
    return (SearchK(T,X) != IdxUndef);
}

int ValueOfKey (TabEl T, char X)
{
    if (SearchKey(T,X) == IdxUndef) {
        return ValUndef;
    } else {
        IdxType i = SearchKey(T,X);
        return Value(Elmt(T,i));
    }
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
        for (int i=0; i<NMax; i++) {
            Key(Elmt(*T,GetLastIdx(*T)))[i] = CharUndef;
        }
        Value(Elmt(*T,GetLastIdx(*T))) = ValUndef;
    }
}