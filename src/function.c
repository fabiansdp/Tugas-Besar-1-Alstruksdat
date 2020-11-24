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

    switch (Comm(C)) {
        case 1:
            printf("Undo Build");
            break;
        case 2:
            printf("Undo Upgrade");
            break;
        case 3:
            printf("Undo Buy");
            break;
        case 4:
            printf("Undo Undo");
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
            build(&exeStack);
        }
        else if (Comm(C) == 2)
        {
            upgrade();
        }
        else if (Comm(C) == 3)
        {
            buy();
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