#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.c"
#include "../ADT/stackt.c"
#include "../ADT/wahana.c"
#include "../ADT/mesinkar.c"
#include "../ADT/mesinkata.c"

Kata CKata;

void build(Stack *S)
{
    ArrayWahana W;
    // Inisialisasi Database Wahana
    CreateDataWahana(&W);
    CreateNamaWahana(&W);

    // Inisialisasi Kata
    Kata CandyCrush = W.ArrayW[0].nama;
    Kata ChocolateForest = W.ArrayW[1].nama;
    Kata BombomCar = W.ArrayW[2].nama;
    Kata LemonSplash = W.ArrayW[3].nama;
    Kata CandyVillage = W.ArrayW[4].nama;
    Kata CandySwing = W.ArrayW[5].nama;
    Kata BlackForest = W.ArrayW[6].nama;

    // Tampilkan list wahana untuk dibangun
    ListWahana();

    // Minta Input
    printf("Ingin Bangun Apa?\n");
    puts(W.ArrayW[0].nama.TabKata);
    STARTKATA();

    if (IsKataSama(CKata, CandyCrush)) {
        printf("Kamu pilih Candy Crush!\n");
    } else if (IsKataSama(CKata, ChocolateForest)) {
        printf("Kamu pilih Chocolate Forest!\n");
    } else if (IsKataSama(CKata, BombomCar)) {
        printf("Kamu pilih Bombom Car!\n");
    } else if (IsKataSama(CKata, LemonSplash)) {
        printf("Kamu pilih Lemon Splash!\n");
    } else if (IsKataSama(CKata, CandyVillage)) {
        printf("Kamu pilih Candy Village!\n");
    } else if (IsKataSama(CKata, CandySwing)) {
        printf("Kamu pilih Candy Swing!\n");
    } else if (IsKataSama(CKata, BlackForest)) {
        printf("Kamu pilih Black Forest Tornado!\n");
    } else {
        printf("Tidak ada nama bangunan itu!\n");
    }
}

void upgrade()
{
    printf("ini UPGRADE\n");
}

void buy()
{
    printf("ini BUY\n");
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
            build();
            player_money-=Gold(C);
            printf("Sisa uang setelah build %d\n",player_money);
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
            printf("Sisa uang setelah buy %d\n",player_money);
        }
        else if (Comm(C) == 4)
        {
            undo(&exeStack);
        }
    }
}

int main() {
    Stack S;
    puts("Jancok");
    build(&S);

    return 0;
}