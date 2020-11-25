#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"
// #include "../ADT/wahana.h"
extern int player_money;

void build()
{
    printf("Ingin Bangun Apa?\n");
    // ListWahana();
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
        }
        else if (Comm(C) == 2)
        {
            upgrade();
            //dikurang material
        }
        else if (Comm(C) == 3)
        {
            buy();
            player_money-=Gold(C);
        }
        else if (Comm(C) == 4)
        {
            undo(&exeStack);
        }
    }
}
