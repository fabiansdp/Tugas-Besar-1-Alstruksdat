#include "boolean.h"
#include "point.h"
#include "command.h"
#include"stackt.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    Stack S;
    CreateEmptyStack(&S);
    if(IsEmptyStack(S)){
        printf("STACK LAGI KOSONG BOSQ\n");
    }

    int x;
    for(x=0;x<MaxElS;x++){
        COMMAND N = MakeCOMMAND(x,x+1,x+2,x+3,x+4,MakePOINT(12+x,12-(x%4)),3600*(x%7));
        Push(&S,N);
    }
    if(IsFullStack(S)){
        printf("STACK UDAH DIISI FULL BOSQ\n");
    }
    

    printf("tampilkan semua isi stack\n");
    for(x=0;x<MaxElS;x++){
        COMMAND N;
        Pop(&S,&N);
        printf("Name(C) = %d\n",Name(N));
        printf("Comm(C) = %d\n",Comm(N));
        printf("Amount(C) = %d\n",Amount(N));
        printf("Gold(C) = %d\n",Gold(N));
        printf("Time(C) = %d\n",Time(N));
        printf("Map(C) = %d\n",Map(N));
        printf("Coordinate(C).X = %.2f\n",Coordinate(N).X);
        printf("Coordinate(C).Y = %.2f\n",Coordinate(N).Y);
        printf("=============================\n");
    }
}