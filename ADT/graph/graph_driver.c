#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"../boolean.h"

int main(){
    Graph asd;
    CreateGraph(&asd,11,32,21);
    gaddrNode gd;
    InsertNode(&asd,12,11,10,&gd);
    InsertNode(&asd,21,21,13,&gd);
    InsertNode(&asd,22,11,16,&gd);
    InsertNode(&asd,31,10,17,&gd);
    InsertNode(&asd,32,14,18,&gd);
    InsertNode(&asd,41,15,19,&gd);
    InsertNode(&asd,42,15,19,&gd);
    PrintGraph(asd);

    printf("\n");

    InsertEdge(&asd,11,31);
    InsertEdge(&asd,12,21);
    InsertEdge(&asd,21,12);
    InsertEdge(&asd,22,41);
    InsertEdge(&asd,31,11);
    InsertEdge(&asd,32,42);
    InsertEdge(&asd,41,22);
    InsertEdge(&asd,42,32);

    PrintGraph(asd);
}