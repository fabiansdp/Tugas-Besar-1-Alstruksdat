/* M.Furqon 13519184 */
/* File : prioqueue.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#include "boolean.h"
#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */
{
    /* Kamus Lokal */
    /* Algoritma */
    return(Head(Q)==Nil && Tail(Q)==Nil);
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    /* Kamus Lokal */
    int el;
    /* Algoritma */
    el = ((Tail(Q)-Head(Q)+MaxEl(Q))%MaxEl(Q))+1;
    return(el == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    /* Kamus Lokal */
    int el;
    /* Algoritma */
    if (IsEmpty(Q))
    {
        el=0;
    }
    else
    {
        el = ((Tail(Q)-Head(Q)+MaxEl(Q))%MaxEl(Q))+1;
        
    }
    return(el); 
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    /* Kamus Lokal */
    /* Algoritma */
    (*Q).T = (infotype*) malloc((Max+1)*sizeof(infotype));
    if ((*Q).T != NULL)
    {
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
        MaxEl(*Q)=Max;
    }
    else
    {
        MaxEl(*Q)=0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    /* Kamus Lokal */
    /* Algoritma */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q)=0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    /* Kamus Lokal */
    address i,j;
    /* Algoritma */
    //kasus kosong
    if (Head(*Q)==Nil)
    {
        Head(*Q)=0;
    }
    Tail(*Q) = (Tail(*Q)+1) % MaxEl(*Q);
    InfoTail(*Q) =X;
    i = Tail(*Q);
    j = (i+MaxEl(*Q)-1)%MaxEl(*Q); 
    //cari posisi di queue
    while (i != Head(*Q) && Prio(Elmt(*Q,i))<Prio(Elmt(*Q,j)))
    {
        infotype temp = Elmt(*Q,i);
        Elmt(*Q,i) = Elmt (*Q,j);
        Elmt (*Q,j) = temp;
        i=j;
        j = (i+MaxEl(*Q)-1)%MaxEl(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    /* Kamus Lokal */
    /* Algoritma */
    *X = InfoHead(*Q);
    //head di ujung
    //menjadi kosong
    if (NBElmt(*Q)==1)
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else 
    {
        //circular buffer
        if (Head(*Q)==(MaxEl(*Q)-1))
        {
            Head(*Q) = 0;
        }
        else
        {
            Head(*Q)++;
        }
    }
}

/* Operasi Tambahan */
void PrintAntrian (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar antrian */
{
    /* Kamus Lokal */
    infotype x;
    /* Algoritma */
    printf("Antrian:\n");
    while (IsEmpty(Q)==false)
    {
        Dequeue(&Q,&x);
        printf("%c %d\n", x.nama, x.kesabaran);
    }
}