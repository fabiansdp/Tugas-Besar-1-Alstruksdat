#include<stdio.h>
#include<stdlib.h>
#include"listrek.h"

int main (){
    List asd = NULL;
    List heh = NULL;
    printf("apakah kosong %d\n",IsEmpty(asd));
    asd = Konso(99,asd);
    asd = Konso(10,asd);
    asd = Konso(20,asd);
    asd = Konso(23,asd);
    heh = KonsB(heh,45);
    heh = KonsB(heh,56);
    heh = KonsB(heh,77);
    heh = KonsB(heh,212);

    printf("apakah kosong %d\n",IsEmpty(asd));
    printf("apakah satuelemen %d\n",IsOneElmt(asd));
    printf("apakah kosong %d\n",IsEmpty(asd));
    printf("apakah satuelemen %d\n",IsOneElmt(asd));
    printf("jmlh elmen %d\n",NbElmtList(asd));
    PrintList(asd);
    printf("sekarang waktunya elemen heh\n");
    printf("jmlh elmen %d\n",NbElmtList(heh));
    PrintList(heh);
    List gab;
    gab = Concat(asd,heh);
    MConcat(asd,heh,&gab);
    printf("habis diapus listnya gan\n");
    PrintList(gab);
}