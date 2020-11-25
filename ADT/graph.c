#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"boolean.h"

//konstruktor
void CreateGraph(Graph * L,infotype X){
    First(*L) = AlokNode(X);
}

addrNode AlokNode(infotype X){
    Node * a;
    a = (Node *) malloc(sizeof(Node));
    if(a!=Nil){
        Id(a) = X;
        NPred(a) = 0;
        Trail(a) = Nil;
        Next(a) = Nil;  
    }
    return a;
}

void dealokNode(addrNode P){
    free(P);
}

addrSuccNode AlokSuccNode(addrNode Pn){
    SuccNode * s;
    s = (SuccNode *) malloc(sizeof(SuccNode));
    if(s!=Nil){
        Nexts(s) = Nil;
        Succ(s) = Pn;
    }
    return s;
}

void dealokSuccNode(addrSuccNode Pn){
    free(Pn);
}

//fungsilain
addrNode SearchNode(Graph G,infotype X){
    if(First(G)==Nil){
        return Nil;
    }else if(Id(First(G))==X){
        return First(G);
    }else{
        First(G) = Next(First(G));
        return SearchNode(G,X);
    }
}

addrSuccNode SearchEdge(Graph G, infotype prec, infotype succ){
    addrNode a = First(G);
    boolean flag = false;
    addrSuccNode retadr = Nil;
    while(a!=Nil && flag == false){
        addrSuccNode b = Trail(a);
        if(Id(a)==prec){
            while (b!=Nil && flag==false)
            {
                addrNode c = Succ(b);
                if(Id(c)==succ){
                    retadr = b;
                    flag=true;
                }else{
                    b = Nexts(b);
                }
            }
        }
        a = Next(a);
    }

    return retadr;
}

void InsertNode(Graph * G, infotype X, addrNode * Pn){
    if(First(*G)==Nil){
        (*Pn) = AlokNode(X);
        First(*G) = (*Pn);
    }else{
        addrNode a = First(*G);
        while (Next(a)!=Nil)
        {
            a = Next(a);
        }

        (*Pn) = AlokNode(X);
        Next(a) = (*Pn);
    }
}

void InsertEdge(Graph * G, infotype prec, infotype succ){
    if(SearchNode(*G,prec)!=Nil && SearchNode(*G,succ)!=Nil){
        addrNode lok =  SearchNode(*G,prec);
        addrNode tuj =  SearchNode(*G,succ);
        addrSuccNode c = Trail(lok);
        NPred(tuj)++;
        if(c==Nil){
            Trail(lok) = AlokSuccNode(tuj);
        }else{
            while(Nexts(c)!=Nil){
                c = Nexts(c);
            }
            Nexts(c) = AlokSuccNode(tuj);
        }
        
    }else if(SearchNode(*G,prec)!=Nil){
        addrNode p;
        InsertNode(G,succ,&p);
        addrNode lok =  SearchNode(*G,prec);
        NPred(p)++;
        addrSuccNode c = Trail(lok);
        if(c==Nil){
            Trail(lok) = AlokSuccNode(p);
        }else{
            while(Nexts(c)!=Nil){
                c = Nexts(c);
            }
            Nexts(c) = AlokSuccNode(p);
        }
    }else if(SearchNode(*G,succ)!=Nil){
        addrNode p;
        addrNode tuj =  SearchNode(*G,succ);
        InsertNode(G,prec,&p);
        Trail(p) = AlokSuccNode(tuj);
        NPred(tuj)++;
    }else{
        addrNode p,pp;
        InsertNode(G,prec,&p);
        InsertNode(G,succ,&pp);
        NPred(pp)++;
        Trail(p) = AlokSuccNode(pp);
    }
}

void PrintGraph(Graph G){
    addrNode a = First(G);
    while (a!=Nil)
    {
        printf("<%d> => ",Id(a));
        addrSuccNode b = Trail(a);
        while (b!=Nil)
        {
            addrNode c = Succ(b);
            printf("[%d] -> ",Id(c));
            b = Nexts(b);
        }
        
        printf("\n");
        a = Next(a);
    }
    
}