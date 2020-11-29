#include "../boolean.h"
#include "prioqueuechar.h"
#include "../wahana/wahana.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../point/point.h"
#include "../listrek/listrek.h"
#include "../bintree/bintree.h" 
#include "../jam/jam.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    //Inisialisasi elemen queue
    infotype_pq elemen;
    elemen.prio = 1;
    elemen.nama = 'A';
    elemen.kesabaran = 7;
    //elemen.wahana[100] = "Roller-Coaster";

    ArrayWahana Aw;
    makeArrayWahana(&Aw);

    PrioQueueChar Q;
    //membuat prioqueue kosong dengan 3 elemen
    MakeEmpty(&Q, 3);
    if (IsEmptyQueue(Q))
    {
        printf("Tabel LAGI KOSONG BOSQ\n");
    }

    //enqueue dengan 1 elemen 'elemen'
    Enqueue(&Q, elemen);

    //cek jumlah elemen queue
    printf("\nJumlah elemen dalam prioqueue setelah enqueue ada %d\n", NBElmtQueue(Q));
    // Print isi queue
    printf("\nPrint isi queue:\n");
    PrintAntrian(Q,Aw);
    // dequeue
    infotype_pq temp;
    Dequeue(&Q, &temp);
    printf("\nJumlah elemen dalam prioqueue setelah enqueue ada %d\n", NBElmtQueue(Q));

    return 0;
}