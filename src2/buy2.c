#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/boolean.h"
#include "../ADT/jam.h"
#include "../ADT/command.h"
#include "../ADT/arraypos.h"
#include "../ADT/mesinkar.h"
#include "../ADT/mesinkata.h"
#include "buy2.h"

//GLOBAL VARIABLE
char mat [20][256];
int banyak;
TabEl T,Resource;
Kata CKata,Air,Kayu,Batu,Besi;
int price;
int indeks_buy;

// HILANGIN ANGKA DARI FILE
char* RemoveDigits(char* string)
{
    char* hasil = string;
    char* before = string;

    while(*before)
    {
        if (*before >= '0' && *before <= '9'){ 
            before++; 
            continue; 
        }
        if(*before == ' '){
            before++; 
            continue; 
        }
        *hasil++ = *before++;
    }
    *hasil = '\0';
    return string;
}

// BACA HARGA
void BacaHarga(int x,TabEl *T,TabEl *Resource)
{
    FILE *fp;
    char str[MAXCHAR];
    int k;
    int i =0;
    switch(x)
    {
    case 1:
        fp=fopen("material.txt","r");
        break;
    default:
        fp=fopen("material.txt","r"); //asumsi file tidak kosong
        break;
    }
    while (fgets(str,MAXCHAR,fp) != NULL){
        //masukin harga ke array
        k = atoi(str);
        Id(*T,i) = i;
        Value(*T,i) = k;
        Id(*Resource,i) = i;
        Value(*Resource,i) = 0;
        i++;
    }
    fclose(fp);
}

//BACA MATERIAL 
void BacaMaterial(int x,char mat[20][256]){
    FILE *fp;
    char str[MAXCHAR];
    int j,i = 0;
    int k;
    switch(x)
    {
    case 1:
        fp=fopen("material.txt","r");
        break;
    default:
        fp=fopen("material.txt","r"); //asumsi file tidak kosong
        break;
    }
    while (fgets(str, sizeof(str), fp)){
        RemoveDigits(str);
        strcpy(mat[i], str);
        printf("- %s",mat[i]);
        i++;
    }
    printf("\n");
    printf("format: mount material (ex: 10 besi)\n");
    fclose(fp);
}

// BACA INPUT
void BacaInput(){
    printf("What do you want to buy? ");
    scanf("%d",&banyak);
    STARTKATA();
    Air.TabKata[0] = 'a';
    Air.TabKata[1] = 'i';
    Air.TabKata[2] = 'r';
    Air.Length = 3;
    Kayu.TabKata[0] = 'k';
    Kayu.TabKata[1] = 'a';
    Kayu.TabKata[2] = 'y';
    Kayu.TabKata[3] = 'u';
    Kayu.Length = 4;
    Batu.TabKata[0] = 'b';
    Batu.TabKata[1] = 'a';
    Batu.TabKata[2] = 't';
    Batu.TabKata[3] = 'u';
    Batu.Length = 4;
    Besi.TabKata[0] = 'b';
    Besi.TabKata[1] = 'e';
    Besi.TabKata[2] = 's';
    Besi.TabKata[3] = 'i';
    Besi.Length = 4;
    while(!IsKataSama(CKata,Air) && !IsKataSama(CKata,Kayu) && !IsKataSama(CKata,Batu) && !IsKataSama(CKata,Besi)){
        printf("Material is not available, please try again\n");
        printf("What do you want to buy? ");
        scanf("%d",&banyak);
        STARTKATA();
    }
}

//CEK UANG CUKUP
boolean EnoughMoney(int money,int banyak,TabEl *Resource){
    int i;
    Air.TabKata[0] = 'a';
    Air.TabKata[1] = 'i';
    Air.TabKata[2] = 'r';
    Air.Length = 3;
    Kayu.TabKata[0] = 'k';
    Kayu.TabKata[1] = 'a';
    Kayu.TabKata[2] = 'y';
    Kayu.TabKata[3] = 'u';
    Kayu.Length = 4;
    Batu.TabKata[0] = 'b';
    Batu.TabKata[1] = 'a';
    Batu.TabKata[2] = 't';
    Batu.TabKata[3] = 'u';
    Batu.Length = 4;
    Besi.TabKata[0] = 'b';
    Besi.TabKata[1] = 'e';
    Besi.TabKata[2] = 's';
    Besi.TabKata[3] = 'i';
    Besi.Length = 4;
    if(IsKataSama(CKata,Air)){
        i = 0;
    }
    if(IsKataSama(CKata,Kayu)){
        i = 1;
    }
    if(IsKataSama(CKata,Batu)){
        i = 2;
    }
    if(IsKataSama(CKata,Besi)){
        i = 3;
    }
    if((money - banyak*Value(T,i)) < 0){
        return false;
    }
    else{
        price=banyak*Value(T,i);
        indeks_buy=i;
        //ditambah ke resource
        Value(*Resource,i) += banyak;
        return true;
    }
}