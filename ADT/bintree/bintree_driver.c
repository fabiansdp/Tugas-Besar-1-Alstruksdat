#include<stdio.h>
#include<stdlib.h>
#include "../listrek/listrek.h"
#include "../boolean.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "bintree.h"

int main(){
    Kata K;
    K.TabKata[0]='H';K.TabKata[1]='A';K.TabKata[2]='L';K.TabKata[3]='O';
    K.Length=4;

    BinTree B;
    B = Tree(1,NULL,NULL);
    B->air = 1;
    B->batu = 2;
    B->besi = 3;
    B->detail = K;
    B->durasi = 100;
    B->harga = 120;
    B->isApplied = false;
    B->Kapasitas = 12;

    int x;
    BinTree Temp = B;
    for(x=0;x<5;x++){
        BinTree C;
        C = Tree(1,NULL,NULL);
        C->air = 1+(x*2);
        C->batu = 2+x;
        C->besi = (3+(x*8))%5;
        C->detail = K;
        C->durasi = 100-((6*x)%12);
        C->harga = 120+x;
        C->isApplied = false;
        C->Kapasitas = 12*x;

        Left(Temp) = C;
        Temp= Left(Temp);
    }

    Temp = B;
    for(x=0;x<5;x++){
        BinTree C;
        C = Tree(1,NULL,NULL);
        C->air = 1+(x*2);
        C->batu = 2+x;
        C->besi = (3+(x*8))%5;
        C->detail = K;
        C->durasi = 100-((6*x)%12);
        C->harga = 120+x;
        C->isApplied = false;
        C->Kapasitas = 12*x;

        Right(Temp) = C;
        Temp= Right(Temp);
    }

    PrintTree(B,4);

}