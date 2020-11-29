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

TabEl Resource;
int banyak;
int indeks_buy;
int x,y;

void build(ArrayWahana *W, COMMAND C, int * player_money)
{
    printf("haha ngebuild\n");
    BasisListWahana B;
    B = MakeUpgradeList();
    int x = Absis(Coordinate(C));
    int y = Ordinat(Coordinate(C))+1;

    // Cek wahana di lokasi atasnya ada wahana atau tidak
    POINT LokasiAtas = MakePOINT(x, y);

    // Fungsi build wahana
    Wahana WahanaBaru = SearchWahanaBase(B, Name(C));
    BinTree TreeBaru = SearchUList(B, Name(C));
    DetilWahana DetilBaru = DirikanWahanaBaru((*W).jumlahWahana, WahanaBaru, LokasiAtas, TreeBaru);
    PushNewWahana(W, DetilBaru);
    PrintAllWahana(*W);
    (*player_money) -= Gold(C);
}

void upgrade()
{
    printf("ini UPGRADE\n");
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
int * player_money)
{
    Stack exeStack;
    while (!IsEmptyStack(*S))
    {
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
            upgrade();
            switch (Map(C))
            {
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
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
