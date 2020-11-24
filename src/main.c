#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.c"
#include "../ADT/stackt.c"
#include "function.c"
//test Furqon
#include "peta.c"
#include "antrian.c"

//kamus peta
extern MATRIKS L;
extern Arr_POINT AP;
// extern int tipe_point;
extern POINT player_loc; 
//kamus antrian
extern int MaxAntrian;
extern int default_angka;
PrioQueueChar Q;
// int jmlhWahana = 3;
extern char Nama[]; 
extern int crntname;
extern infotype_pq temp;
extern infotype_pq served;
//kamus peta_2
char input;
int i,j;
boolean loop;
int adjacent;
//kamus stack
Stack S;
COMMAND comm1, comm2, comm3, comm4;

int main()
{
    //peta
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            tipe_point[i][j]=0;
        }
    }

    MakeMATRIKS(10,20,&L);
    BacaPeta(1,&L);
    TulisPeta(1,L);
    TitikPeta(L,AP);
    for (i = 0; i <= 199; i++)
    {
        if (AP.P[i].X!=0 && AP.P[i].Y!=0)
        {
            printf("%d ",AP.tipe[i]);
            printf("%f,",AP.P[i].X);
            printf("%f\n",AP.P[i].Y);
        }           
        // printf("%f,",P[i].X);
        // printf("%f\n",P[i].Y);
    }

    printf("X untuk keluar\n");
    loop=true;    
    do
    {
        adjacent=Adjacency();
        printf("Nilai adjacent: %d\n",adjacent);
        printf("Masukkan arah pergerakan:\n");
        scanf("%c",&input);
        if (adjacent==5)
        {
            printf("Sebelah wahana\n");
        }
        else if (adjacent==3)
        {
            printf("Sebelah office\n");
        }

        if (input=='X')
        {
            loop=false;
        }
        else
        {
            Movement(input,&L);
            PrintPeta(L);
        }
    } while (loop);

    //cek tipe_point
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            printf("%d",tipe_point[i][j]);
        }
        printf("\n");
    }
    //antrian
    MakeEmpty(&Q, MaxAntrian);
    while (!IsFullQueue(Q))
    {
        /*Inisialisasi infotype_pq*/
        srand(crntname); //lebih baik nanti pake ADT time
        Nama(temp)=Nama[crntname];
        Prio(temp)=crntname;
        Kesabaran(temp)=(rand()%3)+1;
        // Kesabaran(temp)=default_angka;
        /*Selama tidak full, bisa tambah antrian*/
        TambahAntrian(&Q,temp);
        /*Setiap bertambah waktu tambah antrian(not implemented)*/
        crntname++; /*Nama selanjutnya*/
        if (crntname==27)
        {
            crntname=0;
        }
    }
    printf("Antrian awal\n");
    PrintAntrian(Q);

    //Cek wahana yang ingin dinaiki
    int nama=0;
    char ch; 
    ch = Wahana(ElmtQ(Q,0),nama);
    printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,0)));
    while (ch !='.')
    {
        printf("%c",ch);
        nama++;
        ch = Wahana(ElmtQ(Q,0),nama);
    }
    printf("\n");

    nama=0;
    ch = Wahana(ElmtQ(Q,2),nama);
    printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,2)));
    while (ch !='.')
    {
        printf("%c",ch);
        nama++;
        ch = Wahana(ElmtQ(Q,2),nama);
    }
    printf("\n");
    printf("Antrian[%d/%d]",NBElmtQueue(Q),MaxAntrian);

    //Simulasi antrian habis dari penuh
    while (!IsEmptyQueue(Q))
    {
        KurangAntrian(&Q,&served);
        printf("Pelanggan %c dilayani\n",Nama(served));
        printf("Antrian[%d/%d]",NBElmtQueue(Q),MaxAntrian);
        if (!IsEmptyQueue(Q))
        {
            PrintAntrian(Q);
        }
    }
    //stack
    Comm(comm1) = 1;
    Comm(comm2) = 2;
    Comm(comm3) = 3;
    Comm(comm4) = 4;
    Push(&S, comm1);
    Push(&S, comm2);
    Push(&S, comm3);
    Push(&S, comm4);
    execute(&S);
    return 0;
}