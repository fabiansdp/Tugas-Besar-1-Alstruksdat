#include <stdio.h>
#include <stdlib.h>
#include "ADT/boolean.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/point.h"
#include "ADT/listrek.h"
#include "ADT/bintree.h" 
#include "ADT/jam.h"
#include "ADT/wahana.h"
#include <math.h>

int konvertKata(Kata K){
    int a = K.Length;
    int x;
    int res = 0;
    for(x=0;x<K.Length;x++){
        if(K.TabKata[x]>='0' && K.TabKata[x]<='9'){
            int pangkat = (int) pow(10,a-1);
            int konvert = (int) K.TabKata[x];
            konvert = konvert - 48;
            res = res+(pangkat*(konvert));
            a = a-1;
        }
    }
    return res;
}

void Detail()
{
    
}

// int main(){
//     BasisListWahana B;
//     B = MakeUpgradeList();
    // POINT p1,p2,p3;
    // p1.X =2;p1.Y=5;
    // p2.X =11;p2.Y=6;
    // p3.X =12;p3.Y=9;

    // ArrayWahana ArrW;
    // makeArrayWahana(&ArrW);
    // DetilWahana detw;
    // Wahana w1 = SearchWahanaBase(B,11);
    // detw = DirikanWahanaBaru(1,SearchWahanaBase(B,11),p1,SearchUList(B,11));
    // PushNewWahana(&ArrW,detw);
    // detw = DirikanWahanaBaru(2,SearchWahanaBase(B,12),p2,SearchUList(B,12));
    // PushNewWahana(&ArrW,detw);
    // detw = DirikanWahanaBaru(3,SearchWahanaBase(B,12),p3,SearchUList(B,12));
    // PushNewWahana(&ArrW,detw);

    // PrintAllWahana(ArrW);

    // ListHistoUpdate sejarahUpgrade=NULL;
    // Jam j= MakeJam(10,20);
    // DetilWahana d1 = ArrW.ArrayW[0];
    // BinTree Bt = searchTree2(d1.upgradeTree,1102);
    // PrintTree(Bt,4);
    // InfoHis ihs = CreateNewHistoryInfo(1,j,d1.wahana.nama,Bt->detail);
    // sejarahUpgrade = AddNewHistory(sejarahUpgrade,ihs,d1.id,Bt->info);

    

    // j= MakeJam(11,50);
    // d1 = ArrW.ArrayW[1];
    // Bt = searchTree2(d1.upgradeTree,1202);
    // PrintTree(Bt,4);
    // ihs = CreateNewHistoryInfo(1,j,d1.wahana.nama,Bt->detail);
    // sejarahUpgrade = AddNewHistory(sejarahUpgrade,ihs,d1.id,Bt->info);
    // PrintAllHistory(sejarahUpgrade);

    // PrintHistoryByID(sejarahUpgrade,1);

    
// }

/*
gcc -o bacaup bacaupgrade.c ADT/mesinkar.c ADT/mesinkata.c ADT/point.c ADT/listrek.c ADT/bintree.c ADT/jam.c ADT/wahana2.c
*/