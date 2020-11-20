#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/command.c"
#include "../ADT/stackt.c"
#include "function.c"

int main()
{
    Stack S;
    COMMAND comm1, comm2, comm3, comm4;
    Comm(comm1) = 1;
    Comm(comm2) = 2;
    Comm(comm3) = 3;
    Comm(comm4) = 4;
    Push(&S, comm1);
    Push(&S, comm2);
    Push(&S, comm3);
    Push(&S, comm4);
    execute(&S);
    return 0;
}