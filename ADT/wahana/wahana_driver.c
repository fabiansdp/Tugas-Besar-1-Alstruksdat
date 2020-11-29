#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../point/point.h"
#include "../listrek/listrek.h"
#include "../bintree/bintree.h" 
#include "../jam/jam.h"
#include "wahana.h"

int main(){
    BasisListWahana B;
    B = MakeUpgradeList();
    POINT p1,p2,p3;
    p1.X =2;p1.Y=5;
    p2.X =11;p2.Y=6;
    p3.X =12;p3.Y=9;

    PrintUpList(B);

    ArrayWahana ArrW;
    makeArrayWahana(&ArrW);
    DetilWahana detw;
    Wahana w1 = SearchWahanaBase(B,11);
    detw = DirikanWahanaBaru(1,SearchWahanaBase(B,11),p1,SearchUList(B,11));
    PushNewWahana(&ArrW,detw);
    detw = DirikanWahanaBaru(2,SearchWahanaBase(B,12),p2,SearchUList(B,12));
    PushNewWahana(&ArrW,detw);
    detw = DirikanWahanaBaru(3,SearchWahanaBase(B,12),p3,SearchUList(B,12));
    PushNewWahana(&ArrW,detw);

    PrintAllWahana(ArrW);

    ListHistoUpdate sejarahUpgrade=NULL;
    Jam j= MakeJam(10,20);
    DetilWahana d1 = ArrW.ArrayW[0];
    BinTree Bt = searchTree2(d1.upgradeTree,1102);
    PrintTree(Bt,4);
    InfoHis ihs = CreateNewHistoryInfo(1,j,d1.wahana.nama,Bt->detail);
    sejarahUpgrade = AddNewHistory(sejarahUpgrade,ihs,d1.id,Bt->info);

    

    j= MakeJam(11,50);
    d1 = ArrW.ArrayW[1];
    Bt = searchTree2(d1.upgradeTree,1202);
    PrintTree(Bt,4);
    ihs = CreateNewHistoryInfo(1,j,d1.wahana.nama,Bt->detail);
    sejarahUpgrade = AddNewHistory(sejarahUpgrade,ihs,d1.id,Bt->info);
    PrintAllHistory(sejarahUpgrade);
    printf("\nprint upgrade untuk id 1\n\n");
    PrintHistoryByID(sejarahUpgrade,1);
    return 0;
}