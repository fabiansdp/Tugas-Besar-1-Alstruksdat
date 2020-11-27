#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"
// #include "../ADT/wahana.h"
extern int player_money;
extern TabEl Resource;
extern int banyak;
extern int indeks_buy;
extern ArrayWahana W;

void build(ArrayWahana *W, int ID, int Gold)
{
    if (player_money < Gold) {
        printf("Uang tidak cukup untuk membangun wahana ini!\n");
    } else {
        int index = searchID(*W, ID);
        player_money -= Gold;
        IsDibangun(*W,index) = true;
        printf("Wahana berhasil dibangun\n");
    }
}

void upgrade()
{
    printf("ini UPGRADE\n");
}

void buy()
{
    // printf("Welcome to the shop\n ");
    // printf("Material List :\n");
    // BacaMaterial(1,mat);
    // BacaHarga(1,&T,&Resource);
    // BacaInput();
    // boolean x;
    // x =EnoughMoney(1000,banyak,&Resource);
    // if(x == false){
    //     printf("Not enought money!\n");
    //     BacaInput();
    // }
    // else{
    //     // masuk ke stack
    //     // TambahMenit(&J,10);
    //     // TulisJam(J);
    // printf("BENER");
    printf("Buy berhasil dilakukan\n");
}

void undo(Stack *S)
{
    // Melakukan Pop terhadap exeStack
    // dan mendelete element command
    COMMAND C;

    Pop(S, &C);
    // COMMAND MakeCOMMAND(int comm, int name, int amount, int map, POINT coordinate, int time);
    switch (Comm(C)) {
        case 1:
            printf("Undo Build\n");
            total_aksi--;
            total_uang-=Gold(C);
            total_waktu-=Time(C);
            break;
        case 2:
            printf("Undo Upgrade\n");
            total_aksi--;
            // total_uang-=Gold(C); harusnya ga jadi kurang material
            total_waktu-=Time(C);
            break;
        case 3:
            printf("Undo Buy\n");
            //belum ada undo material
            printf("Id %d sebanyak %d batal dibayar\n",indeks_buy,banyak);
            Value(Resource,indeks_buy) -= banyak;
            total_aksi--;
            total_uang-=Gold(C);
            total_waktu-=Time(C);
            break;
        case 4:
            printf("Undo Undo\n");
            break;
        default:
            break;
    }

    MakeEmptyCOMMAND(&C);
}

void execute(Stack *S)
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
        COMMAND C;
        Pop(&exeStack, &C);
        if (Comm(C) == 1)
        {
            build(&W, Name(C), Gold(C));
        }
        else if (Comm(C) == 2)
        {
            upgrade();
            //dikurang material
            //upgrade ditambah
        }
        else if (Comm(C) == 3)
        {
            buy();
            player_money-=Gold(C);
            // printf("Sisa uang setelah buy %d\n",player_money);
        }
        else if (Comm(C) == 4)
        {
            undo(&exeStack);
        }
    }
    printf("Sisa uang setelah execute %d\n",player_money);
}

// int main() {
//     build(&W, 11, 10000);

//     return 0;
// }