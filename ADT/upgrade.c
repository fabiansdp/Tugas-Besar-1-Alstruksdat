#include <stdio.h>
#include "boolean.h"
#include "bintree.h"
#include "listrek.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include"upgrade.h"
#include<stdlib.h>

int mystrlen2(char *str) {
    int len = 0;
    int i = 0;
    for (i=0; str[i] != 0; i++) 
    {
        len++;
    }
    return(len);
}

Uaddress AlokUList (infotype X,BinTree Bt){
    UList * RetU;
    RetU = (UList*) malloc(sizeof(UList));
    if(RetU!=NULL){
        InfoUpgrade(RetU) = Bt;
        UID(RetU) = X;
        Lanjut(RetU) = NULL;
    }
    return RetU;
}

/* *** Selektor *** */
infotype FirstUID (ListUpdate L){
    if(L!=NULL){
        return UID(L);
    }else{
        return 0;
    }
}
BinTree FirstBinU (ListUpdate L){
    return InfoUpgrade(L);
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
ListUpdate UTail(ListUpdate L){
    return Lanjut(L);
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
ListUpdate UKonso(infotype e,BinTree B, ListUpdate L){
    Uaddress ad = AlokUList(e,B);
    if(ad!=NULL && L==NULL){
        return ad;
    }else if(ad!=NULL){
        Lanjut(ad) = L;
        return ad;
    }else{
        return L;
    }
}
ListUpdate UKonsB(ListUpdate L, infotype e,BinTree B)
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
    Uaddress ad = AlokUList(e,B);
    if(L==NULL && ad!=NULL){
        L = ad;
        return L;
    }else if(ad!=NULL && Lanjut(L)==NULL){
        Lanjut(L) = ad;
        return L;
    }else if(ad!=NULL){
        ListUpdate rett = L;
        Lanjut(rett) = UKonsB(Lanjut(L),e,B);
    }else{
        return L;
    }
}

ListUpdate MakeUpgradeList(){
    FILE * FL = fopen("wahana.txt","r");
    if(FL==NULL){
        printf("eror while read file\n");
        return NULL;
    }else{
        ListUpdate retLU = NULL;
        int cnt = 1;
        char c[212];
        BinTree Bt;
        while (fscanf(FL,"%s",c)!=EOF)
        {
            if(cnt==1){
                int id = atoi(c);
                Bt = Tree(id,NULL,NULL);
                Bt->isApplied=true;
            }else if(cnt==2){
                Bt->detailLEN = mystrlen2(c);
                int jj;
                //printf("asd = %d\n",Bt->detailLEN);
                for (jj=0;jj<mystrlen2(c);jj++){
                    Bt->detail[jj] = c[jj];
                }
            }else if(cnt==3){
                int harga = atoi(c);
                Bt->harga = harga;
            }else if(cnt==4){
                int kapasitas = atoi(c);
                Bt->Kapasitas = kapasitas;
            }else if(cnt==5){
                int durasi = atoi(c);
                Bt->durasi = durasi;
            }else if(cnt==7){
                int air = atoi(c);
                Bt->air = air;
            }else if(cnt==8){
                int kayu = atoi(c);
                Bt->kayu = kayu;
            }else if(cnt==9){
                int batu = atoi(c);
                Bt->batu = batu;
            }else if(cnt==10){
                int besi = atoi(c);
                Bt->besi = besi;
            }
            //cnt++;
            if(cnt%10==0){
                retLU = UKonsB(retLU,Akar(Bt),Bt);
                cnt = 1;
            }else{
                cnt++;
            }
        }
       return retLU; 
    }
    
}

void getUpgradeListTree(ListUpdate * L){
    FILE * FL = fopen("upgrade.txt","r");
    if(FL==NULL){
        printf("eror while read file\n");
    }else{
        int cnt = 1;
        char c[212];
        BinTree Utama;
        BinTree Bt;
        int arahgerak;
        while (fscanf(FL,"%s",c)!=EOF)
        {               
            if(cnt==1){
                int idW = atoi(c);
                Utama = SearchUList(*L,idW);
            }else if(cnt==2){
                int idUp = atoi(c);
                Bt = Tree(idUp,NULL,NULL);
                Bt->isApplied = false;
                Bt->durasi = Utama->durasi;
            }else if(cnt==3){
                arahgerak = atoi(c);
            }else if(cnt==4){
                Bt->detailLEN = mystrlen2(c);
                int jj;
                printf("asd = %d\n",Bt->detailLEN);
                for (jj=0;jj<mystrlen2(c);jj++){
                    Bt->detail[jj] = c[jj];
                }
            }else if(cnt==5){
                int kenaikanKapasitas = atoi(c);
                Bt->Kapasitas = Utama->Kapasitas+kenaikanKapasitas;
            }else if(cnt==6){
                int kenaikanHarga = atoi(c);
                Bt->harga = Utama->harga+kenaikanHarga;
            }else if(cnt==7){
                int air = atoi(c);
                Bt->air = air;
            }else if(cnt==8){
                int kayu = atoi(c);
                Bt->kayu = kayu;
            }else if(cnt==9){
                int batu = atoi(c);
                Bt->batu = batu;
            }else if(cnt==10){
                int besi = atoi(c);
                Bt->besi = besi;
            }
            //cnt++;
            if(cnt%10==0){
                //printf("arahgerak %d\n",arahgerak);
                //PrintTree(Bt,4);
                if(arahgerak==0){
                    addDaunLeft(&Utama,Bt);
                }else if(arahgerak==1){
                    addDaunRight(&Utama,Bt);
                }
                cnt = 1;
            }else{
                cnt++;
            }
        }
    }
    //return L;
}

void PrintUpList(ListUpdate L){
    if(L==NULL){

    }else{
        printf("ID WAHANA = %d\n",UID(L));
        PrintTree(InfoUpgrade(L),8);
        PrintUpList(UTail(L));
    }
}

BinTree SearchUList(ListUpdate L, infotype X){
    if(L==NULL){
        return NULL;
    }else if(UID(L)==X){
        return InfoUpgrade(L);
    }else{
        return SearchUList(UTail(L),X);
    }
}

void addDaunLeft(BinTree * Utama, BinTree tambahan){
    if(Left(*Utama)==NULL){
        Left(* Utama) = tambahan;
    }else{
        addDaunLeft(&Left(*Utama),tambahan);
    }
}
void addDaunRight(BinTree * Utama, BinTree tambahan){
    if(Right(*Utama)==NULL){
        Right(*Utama) = tambahan;
    }else{
        addDaunLeft(&Right(*Utama),tambahan);
    }
}