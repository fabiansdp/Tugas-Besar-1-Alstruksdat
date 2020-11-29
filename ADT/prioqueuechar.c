/* M.Furqon 13519184 */
/* File : prioqueue.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#include "boolean.h"
#include "prioqueuechar.h"
#include "wahana.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */
{
    /* Kamus Lokal */
    /* Algoritma */
    return(Head(Q)==Nil && Tail(Q)==Nil);
}

boolean IsFullQueue (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    /* Kamus Lokal */
    int el;
    /* Algoritma */
    el = ((Tail(Q)-Head(Q)+MaxEl(Q))%MaxEl(Q))+1;
    return(el == MaxEl(Q));
}

int NBElmtQueue (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    /* Kamus Lokal */
    int el;
    /* Algoritma */
    if (IsEmptyQueue(Q))
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
    (*Q).T = (infotype_pq*) malloc((Max+1)*sizeof(infotype_pq));
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
void DeAlokasiQueue(PrioQueueChar * Q)
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
void Enqueue (PrioQueueChar * Q, infotype_pq X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    /* Kamus Lokal */
    addr i,j;
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
    while (i != Head(*Q) && Prio(ElmtQ(*Q,i))<Prio(ElmtQ(*Q,j)))
    {
        infotype_pq temp = ElmtQ(*Q,i);
        ElmtQ(*Q,i) = ElmtQ (*Q,j);
        ElmtQ (*Q,j) = temp;
        i=j;
        j = (i+MaxEl(*Q)-1)%MaxEl(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, infotype_pq * X)
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
    if (NBElmtQueue(*Q)==1)
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
void PrintAntrian (PrioQueueChar Q, ArrayWahana W)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar antrian */
{
    /* Kamus Lokal */
    infotype_pq x;
    PrioQueueChar Qtemp;
    DetilWahana wahana_want;
    int name_length;
    /* Algoritma */
    Qtemp = Q;
    while (IsEmptyQueue(Q)==false)
    {
        printf("(");
        Dequeue(&Q,&x);
        for (int i = 0; i < W.jumlahWahana; i++)
        {
            wahana_want=CariWahanaByID(W,IndeksWahana(x,i));
            if (wahana_want.id!=ValUndef)
            {
                name_length=wahana_want.wahana.nama.Length;
                for (int j = 0; j < name_length; j++)
                {
                    printf("%c",wahana_want.wahana.nama.TabKata[j]);
                }
                if (i!=W.jumlahWahana-1)
                {
                    printf(",");
                }
            }
        }
        printf(")");
        // printf("priority: %d ",x.prio);
        printf("kesabaran: %d //Customer %c\n", x.kesabaran, x.nama);
    }
}
