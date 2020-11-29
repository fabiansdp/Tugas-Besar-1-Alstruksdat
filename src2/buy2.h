#ifndef buy2_H
#define buy2_H

#include "../ADT/boolean.h"
#include "../ADT/jam.h"
#include "../ADT/command.h"
#include "../ADT/arraypos.h"
#include "../ADT/mesinkar.h"
#include "../ADT/mesinkata.h"

#define MAXCHAR 100

char* RemoveDigits(char* string);
void BacaHarga(int x,TabEl *T,TabEl *Resource);
void BacaMaterial(int x,char mat[20][256]);
void BacaInput();
boolean EnoughMoney(int money,int banyak,TabEl *Resource);

#endif