/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#ifndef prioqueuechar_H
#define prioqueuechar_H

#include "boolean.h"

#define Nil -1
/* Konstanta untuk mendefinisikan addr tak terdefinisi */

/* Definisi elemen dan addr */
typedef struct {
    int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
    char nama;  /* nama pengunjung */
    char wahana[100]; /* nama wahana */ 
    int kesabaran; /* tingkatan kesabaran */ 
}infotype_pq;
typedef int addr;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype_pq * T;   /* tabel penyimpan elemen */
    addr HEAD;  /* alamat penghapusan */
    addr TAIL;  /* alamat penambahan */
    int MaxElQ;     /* Max elemen queue */
}PrioQueueChar;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype_pq dan Q adalah PrioQueueChar, maka akses elemen : */
#define Prio(e)     (e).prio
#define Nama(e)     (e).nama
#define Wahana(e,i) (e).wahana[i]
#define Kesabaran(e)(e).kesabaran
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxElQ
#define ElmtQ(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyQueue (PrioQueueChar Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (PrioQueueChar Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQueue (PrioQueueChar Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQueue(PrioQueueChar * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype_pq X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infotype_pq * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintAntrian (PrioQueueChar Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:*/

#endif
