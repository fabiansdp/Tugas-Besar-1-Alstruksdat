#ifndef graph_H
#define graph_H

#include "boolean.h"

#define Nil NULL

typedef struct tNode *addrNode;
typedef struct tSuccNode *addrSuccNode;
typedef struct tNode
{
    int id;
    int NPred;
    addrNode Next;
    addrSuccNode Trail;

}Node;

typedef struct tSuccNode
{
    addrNode Succ;
    addrSuccNode Nexts;
}SuccNode;

typedef struct tGraph
{
    addrNode First;
}Graph;

typedef int infotype;

#define First(G) (G).First
#define Id(Pn) (Pn)->id
#define Trail(Pn) (Pn)->Trail
#define Succ(Pt) (Pt)->Succ
#define NPred(Pn) (Pn)->NPred
#define Next(Pn) (Pn)->Next
#define Nexts(Pt) (Pt)->Nexts

//konstruktor
void CreateGraph(Graph * L,infotype X);

addrNode AlokNode(infotype X);

void dealokNode(addrNode P);

addrSuccNode AlokSuccNode(addrNode Pn);

void dealokSuccNode(addrSuccNode Pn);

//fungsilain
addrNode SearchNode(Graph G,infotype X);

addrSuccNode SearchEdge(Graph G, infotype prec, infotype succ);

void InsertNode(Graph * G, infotype X, addrNode * Pn);

void InsertEdge(Graph * G, infotype prec, infotype succ);

void PrintGraph(Graph G);

#endif