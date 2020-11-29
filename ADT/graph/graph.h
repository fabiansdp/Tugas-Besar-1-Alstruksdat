#ifndef graph_H
#define graph_H

#include "../boolean.h"


typedef struct gNode *gaddrNode;
typedef struct tSuccNode *addrSuccNode;
typedef struct gNode
{
    int id;
    int X;
    int Y;
    int NPred;
    gaddrNode Next;
    addrSuccNode Trail;

}GrafNode;

typedef struct tSuccNode
{
    gaddrNode Succ;
    addrSuccNode Nexts;
}SuccNode;

typedef struct tGraph
{
    gaddrNode First;
}Graph;

typedef int infotype;

#define FirstGraf(G) (G).First
#define IdGraf(Pn) (Pn)->id
#define Trail(Pn) (Pn)->Trail
#define Succ(Pt) (Pt)->Succ
#define NPred(Pn) (Pn)->NPred
#define NextGraf(Pn) (Pn)->Next
#define Nexts(Pt) (Pt)->Nexts
#define Xref(Pn) (Pn)->X
#define Yref(Pn) (Pn)->Y
//konstruktor
void CreateGraph(Graph * L,infotype Id,infotype X,infotype Y);

gaddrNode GrafAlokNode(infotype Id,infotype X,infotype Y);

void GrafDealokNode(gaddrNode P);

addrSuccNode AlokSuccNode(gaddrNode Pn);

void dealokSuccNode(addrSuccNode Pn);

//fungsilain
gaddrNode SearchNode(Graph G,infotype X);

addrSuccNode SearchEdge(Graph G, infotype prec, infotype succ);

void InsertNode(Graph * G, infotype Id,infotype X,infotype Y, gaddrNode * Pn);

void InsertEdge(Graph * G, infotype prec, infotype succ);

void PrintGraph(Graph G);

#endif