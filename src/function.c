#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"

void build()
{
    printf("ini BUILD\n");
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
            build();
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
