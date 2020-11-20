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
void undo()
{

    printf("ini UNDO\n");
}

void execute(Stack *S)
{
    Stack exeStack;
    while (!IsEmpty(*S))
    {
        COMMAND ElementStack;
        Pop(S, &ElementStack);
        Push(&exeStack, ElementStack);
    }
    while (!IsEmpty(exeStack))
    {
        COMMAND ElementStack;
        Pop(&exeStack, &ElementStack);
        if (Comm(ElementStack) == 1)
        {
            build();
        }
        else if (Comm(ElementStack) == 2)
        {
            upgrade();
        }
        else if (Comm(ElementStack) == 3)
        {
            buy();
        }
        else if (Comm(ElementStack) == 4)
        {
            undo();
        }
    }
}
