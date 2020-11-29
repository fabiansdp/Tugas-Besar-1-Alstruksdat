#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/listlinier.h"
#include "../ADT/wahana.h"
#include "../ADT/arraypos.h"
#include "../ADT/bintree.h"
#include "../ADT/listrek.h"
#include "function2.h"

//TabEl Resource;
int banyak;
int indeks_buy;
int x,y;

void build(ArrayWahana *W, COMMAND C, int * player_money)
{
    //printf("haha ngebuild\n");
    BasisListWahana B;
    B = MakeUpgradeList();
    int x = Absis(Coordinate(C)) - 1;
    int y = Ordinat(Coordinate(C));

    // Cek wahana di lokasi atasnya ada wahana atau tidak
    POINT LokasiAtas = MakePOINT(x, y);

    // Fungsi build wahana
    Wahana WahanaBaru = SearchWahanaBase(B, Name(C));
    BinTree TreeBaru = SearchUList(B, Name(C));
    DetilWahana DetilBaru = DirikanWahanaBaru((*W).jumlahWahana, WahanaBaru, LokasiAtas, TreeBaru);
    PushNewWahana(W, DetilBaru);
    //PrintAllWahana(*W);
    (*player_money) -= Gold(C);
}

void upgrade(ArrayWahana *W,
COMMAND C,
BinTree * bt, 
int * player_money, 
int * player_air, 
int * player_kayu, 
int * player_batu, 
int * player_besi,
ListHistoUpdate * ListHist)
{
    if((*player_money)>= (*bt)->harga
    && (*player_air)>= (*bt)->air 
    && (*player_kayu) >= (*bt)->kayu 
    && (*player_batu)>= (*bt)->batu  
    && (*player_besi)>= (*bt)->besi){
        //printf("otw diupgrade gess");
        //PrintAllWahana(*W);
        if(UpgradeWahana(W,Name(C),Amount(C))){
            (*player_money) = (*player_money) - (*bt)->harga;
            (*player_air)   = (*player_air) - (*bt)->air;
            (*player_kayu)  = (*player_kayu) - (*bt)->kayu;
            (*player_batu)  = (*player_batu) - (*bt)->batu;
            (*player_besi)  = (*player_besi) - (*bt)->besi;
            
            InfoHis ihis= CreateNewHistoryInfo(
                C.gold,
                DetikToJam(C.time),
                CariWahanaByID(*W,Name(C)).wahana.nama,
                (*bt)->detail
                );
            
            (*ListHist) = AddNewHistory((*ListHist),ihis,Name(C),Amount(C));
            
        }else{
            printf("Upgrade wahana %d gagal tiba-tiba",Name(C) );
        }
        //PrintAllWahana(*W);
    }else{
        printf("Gagal upgrade wahana dengan id %d karena kekurangan resources",Name(C));
    }
}

void buy()
{
    printf("Buy berhasil dilakukan\n");
}

void undo(Stack *S)
{
    // Melakukan Pop terhadap exeStack
    // dan mendelete element command
    COMMAND C;

    Pop(S, &C);
    // COMMAND MakeCOMMAND(int comm, int name, int amount, int map, POINT coordinate, int time);
    switch (Comm(C))
    {
    case 1:
        printf("Undo Build\n");
        //total_aksi--;
        //total_uang -= Gold(C);
        //total_waktu -= Time(C);
        //ubah tipe
        tipe_point[x-1][y]=0;
        //ubah matriks peta
        // ElmtM(L,x-1,y)='-';
        break;
    case 2:
        printf("Undo Upgrade\n");
        //total_aksi--;
        // total_uang-=Gold(C); harusnya ga jadi kurang material
        //total_waktu -= Time(C);
        break;
    case 3:
        printf("Undo Buy\n");
        //belum ada undo material
        printf("Id %d sebanyak %d batal dibayar\n", indeks_buy, banyak);
        Value(Resource, indeks_buy) -= banyak;
        //total_aksi--;
        //total_uang -= Gold(C);
        //total_waktu -= Time(C);
        break;
    case 4:
        printf("Undo Undo\n");
        break;
    default:
        break;
    }

    MakeEmptyCOMMAND(&C);
}

void execute(Stack *S, 
ArrayWahana * Map1,
ArrayWahana * Map2, 
ArrayWahana * Map3, 
ArrayWahana * Map4, 
int * player_money, 
int * player_air, 
int * player_kayu, 
int * player_batu, 
int * player_besi,
ListHistoUpdate * ListHist)
{
    //printf("aselole\n");
    Stack exeStack;
    CreateEmptyStack(&exeStack);
    while (!IsEmptyStack(*S))
    {
        //printf("haluu\n");
        COMMAND C;
        Pop(S, &C);
        Push(&exeStack, C);
    }
    while (!IsEmptyStack(exeStack))
    {
        //printf("lagi ekse bosqu\n");
        COMMAND C;
        Pop(&exeStack, &C);
        if (Comm(C) == 1)
        {
            switch (Map(C))
            {
                case 1:
                    build(Map1, C, player_money);
                    break;
                case 2:
                    build(Map2, C, player_money);
                    break;
                case 3:
                    build(Map3, C, player_money);
                    break;
                case 4:
                    build(Map4, C,player_money);
                    break;
                default:
                    break;
            }
        }
        else if (Comm(C) == 2)
        {
            switch (Map(C))
            {
                BinTree bt;
                case 1:
                    bt =  searchTree2(CariWahanaByID(*Map1,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                       upgrade(Map1,C,&bt,player_money,player_air,player_kayu,player_batu,player_besi,ListHist); 
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                case 2:
                    bt =  searchTree2(CariWahanaByID(*Map2,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                        upgrade(Map2,C,&bt,player_money,player_air,player_kayu,player_batu,player_besi,ListHist);
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                case 3:
                    bt =  searchTree2(CariWahanaByID(*Map3,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                        upgrade(Map3,C,&bt,player_money,player_air,player_kayu,player_batu,player_besi,ListHist);
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                case 4:
                    bt =  searchTree2(CariWahanaByID(*Map4,Name(C)).upgradeTree,Amount(C));
                    if(bt!=NULL){
                        upgrade(Map4,C,&bt,player_money,player_air,player_kayu,player_batu,player_besi,ListHist);
                    }else{
                        printf("ada kesalahan ketika upgrade wahana %d untuk upgrade %d\n",Name(C),Amount(C));
                    }
                    break;
                default:
                    break;
            }
            //dikurang material
            //upgrade ditambah
        }
        else if (Comm(C) == 3)
        {
            buy();
            (*player_money)-=Gold(C);
            // printf("Sisa uang setelah buy %d\n",player_money);
        }
        else if (Comm(C) == 4)
        {
            undo(&exeStack);
        }
    }
    printf("Sisa uang setelah execute %d\n",(*player_money));
}
