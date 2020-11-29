#include <stdio.h>
#include <stdlib.h>

#include "../ADT/prioqueuechar.h"
#include "../ADT/boolean.h"
#include "antrian2.h"

PrioQueueChar Q;
char Nama[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
int crntname = 0;
infotype_pq temp;
infotype_pq served;

void TambahAntrian(PrioQueueChar *Q, infotype_pq X)
/*I.S. Menambah antrian Q mungkin kosong*/
/*F.S. infotype_pq ditambahkan ke Q*/
{
    /*KamusLokal*/
    int n;
    int seed=crntname; //pseudorandom dengan seed tertentu
    /*Algoritma*/
    srand(seed); //lebih baik nanti pake ADT time
    n = (rand()%3)+1;
    switch (n)
    {
    case 1:
        Wahana(X,0)='C';
        Wahana(X,1)='o';
        Wahana(X,2)='a';
        Wahana(X,3)='s';
        Wahana(X,4)='t';
        Wahana(X,5)='e';
        Wahana(X,6)='r';
        Wahana(X,7)='.';
        break;
    case 2:
        Wahana(X,0)='M';
        Wahana(X,1)='o';
        Wahana(X,2)='b';
        Wahana(X,3)='i';
        Wahana(X,4)='l';
        Wahana(X,5)='.';
        break;
    case 3:
        Wahana(X,0)='C';
        Wahana(X,1)='a';
        Wahana(X,2)='r';
        Wahana(X,3)='o';
        Wahana(X,4)='s';
        Wahana(X,5)='e';
        Wahana(X,6)='l';
        Wahana(X,7)='.';
        break;
    default:
        Wahana(X,0)='T';
        Wahana(X,1)='o';
        Wahana(X,2)='r';
        Wahana(X,3)='n';
        Wahana(X,4)='a';
        Wahana(X,5)='d';
        Wahana(X,6)='o';
        Wahana(X,7)='.';
        break;
    }
    Enqueue(Q,X);
    seed++;
}

void KurangAntrian(PrioQueueChar *Q, infotype_pq *X)
/*I.S. Mengurangi antrian tidak mungkin kosong*/
/*F.S. Elemen dikurangi, kesabaran dikurangi*/
{
    /*Kamus Lokal*/
    int i,j,n;
    int i2,j2;
    int zcount;
    // infotype_pq swap;
    boolean loop,geser;
    /*Algoritma*/
    Dequeue(Q,X);
    // printf("Proses %c\n",Nama(*X));
    /*Kurangi kesabaran*/
    if (!IsEmptyQueue(*Q))
    {
        zcount=0;
        i = Head(*Q);   
        j = Tail(*Q);
        loop=true;    
        while (loop)
        {
            /*Jika kesabaran habis*/
            if (Kesabaran(ElmtQ(*Q,i)) == 0)
            {
                zcount++;
            }
            if (i==j)
            {
                loop=false;
            }
            i=(i+1)%MaxEl(*Q);
        }

        // printf("\nJumlah element zero %d\n",zcount);
        if (NBElmtQueue(*Q)==zcount)
        {
            Head(*Q)=Nil;
            Tail(*Q)=Nil;
        }
        else if (zcount!=0)
        {
            i = Head(*Q);   
            j = Tail(*Q);
            
            // printf("Sebelum preproses zero\n");
            // PrintAntrian(*Q);

            while (zcount>0) {
                //buang element ke-i bernilai 0 dari antrian    
                if (Kesabaran(ElmtQ(*Q,i)) == 0) {
                    geser=true;
                    i2=i;
                    j2=Tail(*Q);
                    // printf("Buang element zero %d\n",i);
                    // printf("Geser dari %d ke %d\n",i2,j2);
                    while (geser) //geser satu kali ke head
                    {
                        if (i2==j2)
                        {
                            geser=false;
                        }
                        else
                        {
                            ElmtQ(*Q,i2)=ElmtQ(*Q,(i2+1)%MaxEl(*Q));
                            i2=(i2+1)%MaxEl(*Q);
                        }
                    }                    
                    Tail(*Q)=(i2+MaxEl(*Q)-1)%MaxEl(*Q);
                    zcount--;
                }
                else
                {
                    i=(i+1)%MaxEl(*Q);
                }
            }
        }
        //kurangi kesabaran
        i = Head(*Q);   
        j = Tail(*Q);
        loop=true;    
        while (loop)
        {
            /*Jika kesabaran habis*/
            if (Kesabaran(ElmtQ(*Q,i)) != 0)
            {
                Kesabaran(ElmtQ(*Q,i)) -= 1;
            }
            if (i==j)
            {
                loop=false;
            }
            //tambah prio
            Prio(ElmtQ(*Q,i))++;
            i=(i+1)%MaxEl(*Q);
        }
    }
    /*Setiap kurangi waktu (not implemented)*/
}

//untuk testing

// int main()
// {
//     /*Kamus*/
//     /*Algoritma*/
//     MakeEmpty(&Q, MaxAntrian);
//     while (!IsFull(Q))
//     {
//         /*Inisialisasi infotype_pq*/
//         srand(crntname); //lebih baik nanti pake ADT time
//         Nama(temp)=Nama[crntname];
//         Prio(temp)=crntname;
//         Kesabaran(temp)=(rand()%3)+1;
//         // Kesabaran(temp)=default_angka;
//         /*Selama tidak full, bisa tambah antrian*/
//         TambahAntrian(&Q,temp);
//         /*Setiap bertambah waktu tambah antrian(not implemented)*/
//         crntname++; /*Nama selanjutnya*/
//         if (crntname==27)
//         {
//             crntname=0;
//         }
//     }
//     printf("Antrian awal\n");
//     PrintAntrian(Q);

//     //Cek wahana yang ingin dinaiki
//     int nama=0;
//     char ch; 
//     ch = Wahana(ElmtQ(Q,0),nama);
//     printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,0)));
//     while (ch !='.')
//     {
//         printf("%c",ch);
//         nama++;
//         ch = Wahana(ElmtQ(Q,0),nama);
//     }
//     printf("\n");

//     nama=0;
//     ch = Wahana(ElmtQ(Q,2),nama);
//     printf("Wahana pelanggan %c: \n",Nama(ElmtQ(Q,2)));
//     while (ch !='.')
//     {
//         printf("%c",ch);
//         nama++;
//         ch = Wahana(ElmtQ(Q,2),nama);
//     }
//     printf("\n");
//     printf("Antrian[%d/%d]",NBElmt(Q),MaxAntrian);

//     //Simulasi antrian habis dari penuh
//     while (!IsEmpty(Q))
//     {
//         KurangAntrian(&Q,&served);
//         printf("Pelanggan %c dilayani\n",Nama(served));
//         printf("Antrian[%d/%d]",NBElmt(Q),MaxAntrian);
//         if (!IsEmpty(Q))
//         {
//             PrintAntrian(Q);
//         }
//     }
    
//     return 0;
// }