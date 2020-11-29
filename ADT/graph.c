#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"boolean.h"

//konstruktor
void CreateGraph(Graph * L,infotypeG Id,infotypeG X,infotypeG Y){
    FirstGraf(*L) = GrafAlokNode(Id,X,Y);
}

gaddrNode GrafAlokNode(infotypeG Id,infotypeG X,infotypeG Y){
    GrafNode * a;
    a = (GrafNode *) malloc(sizeof(GrafNode));
    if(a!=NULL){
        IdGraf(a) = Id;
        NPred(a) = 0;
        Trail(a) = NULL;
        NextGraf(a) = NULL;
        Xref(a) = X;
        Yref(a) = Y;  
    }
    return a;
}

void GrafDealokNode(gaddrNode P){
    free(P);
}

addrSuccNode AlokSuccNode(gaddrNode Pn){
    SuccNode * s;
    s = (SuccNode *) malloc(sizeof(SuccNode));
    if(s!=NULL){
        Nexts(s) = NULL;
        Succ(s) = Pn;
    }
    return s;
}

void dealokSuccNode(addrSuccNode Pn){
    free(Pn);
}

//fungsilain
gaddrNode SearchNode(Graph G,infotypeG X){
    if(FirstGraf(G)==NULL){
        return NULL;
    }else if(IdGraf(FirstGraf(G))==X){
        return FirstGraf(G);
    }else{
        FirstGraf(G) = NextGraf(FirstGraf(G));
        return SearchNode(G,X);
    }
}

addrSuccNode SearchEdge(Graph G, infotypeG prec, infotypeG succ){
    gaddrNode a = FirstGraf(G);
    boolean flag = false;
    addrSuccNode retadr = NULL;
    while(a!=NULL && flag == false){
        addrSuccNode b = Trail(a);
        if(IdGraf(a)==prec){
            while (b!=NULL && flag==false)
            {
                gaddrNode c = Succ(b);
                if(IdGraf(c)==succ){
                    retadr = b;
                    flag=true;
                }else{
                    b = Nexts(b);
                }
            }
        }
        a = NextGraf(a);
    }

    return retadr;
}

void InsertNode(Graph * G, infotypeG Id,infotypeG X,infotypeG Y, gaddrNode * Pn){
    if(FirstGraf(*G)==NULL){
        (*Pn) = GrafAlokNode(Id,X,Y);
        FirstGraf(*G) = (*Pn);
    }else{
        gaddrNode a = FirstGraf(*G);
        while (NextGraf(a)!=NULL)
        {
            a = NextGraf(a);
        }

        gaddrNode gg = GrafAlokNode(Id,X,Y);
        NextGraf(a) = gg;
        (*Pn) = gg;
    }
}

void InsertEdge(Graph * G, infotypeG prec, infotypeG succ){
    if(SearchNode(*G,prec)!=NULL && SearchNode(*G,succ)!=NULL){
        gaddrNode lok =  SearchNode(*G,prec);
        gaddrNode tuj =  SearchNode(*G,succ);
        addrSuccNode c = Trail(lok);
        NPred(tuj)++;
        if(c==NULL){
            Trail(lok) = AlokSuccNode(tuj);
        }else{
            while(Nexts(c)!=NULL){
                c = Nexts(c);
            }
            Nexts(c) = AlokSuccNode(tuj);
        }
        
    }else if(SearchNode(*G,prec)!=NULL){
        gaddrNode p;
        InsertNode(G,succ,0,0,&p);
        gaddrNode lok =  SearchNode(*G,prec);
        NPred(p)++;
        addrSuccNode c = Trail(lok);
        if(c==NULL){
            Trail(lok) = AlokSuccNode(p);
        }else{
            while(Nexts(c)!=NULL){
                c = Nexts(c);
            }
            Nexts(c) = AlokSuccNode(p);
        }
    }else if(SearchNode(*G,succ)!=NULL){
        gaddrNode p;
        gaddrNode tuj =  SearchNode(*G,succ);
        InsertNode(G,prec,0,0,&p);
        Trail(p) = AlokSuccNode(tuj);
        NPred(tuj)++;
    }else{
        gaddrNode p,pp;
        InsertNode(G,prec,0,0,&p);
        InsertNode(G,succ,0,0,&pp);
        NPred(pp)++;
        Trail(p) = AlokSuccNode(pp);
    }
}

void PrintGraph(Graph G){
    gaddrNode a = FirstGraf(G);
    while (a!=NULL)
    {
        printf("<%d (%d,%d)> => ",IdGraf(a),Xref(a),Yref(a));
        addrSuccNode b = Trail(a);
        while (b!=NULL)
        {
            gaddrNode c = Succ(b);
            printf("[%d] -> ",IdGraf(c));
            b = Nexts(b);
        }
        
        printf("\n");
        a = NextGraf(a);
    }
    
}