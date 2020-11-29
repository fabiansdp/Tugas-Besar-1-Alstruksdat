#ifndef function2_H
#define function2_H

#include "../ADT/boolean.h"
#include "../ADT/command.h"
#include "../ADT/stackt.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/listlinier.h"
#include "../ADT/wahana.h"
#include "../ADT/arraypos.h"
#include "../ADT/bintree.h"
#include "../ADT/listrek.h"

extern int player_money;
extern TabEl Resource;
extern int banyak;
extern int indeks_buy;
extern int x,y;
extern ArrayWahana Map1, Map2, Map3, Map4;
int tipe_point[10][20];

void build(ArrayWahana *W, COMMAND C);

void upgrade();

void buy();

void undo(Stack *S);

void execute(Stack *S);

void DetailsCommandOffice(List map);

void ReportCommandOffice(List map);

void office();
#endif