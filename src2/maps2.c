#include <stdio.h>
#include <stdlib.h>
#include"maps2.h"
#include "../ADT/boolean.h"
#include "../ADT/matriks.h"
#include "../ADT/point.h"

MATRIKS L;
Arr_POINT AP;
int tipe_point[10][20];
POINT player_loc; 

/* Algoritma */
void BacaPeta(int x, MATRIKS *L)
/*I.S.File peta terdefinisi parameter x menunjukkan peta tertentu F.S.Output peta ke layar*/
{
    /* Kamus Lokal*/
    FILE *fh;
    char ch;
    int i=0,j=0;
    // puts("Cek file");
    /* Algoritma */
    switch (x)
    {
    case 1:
        fh=fopen("map1.txt","r");
        break;
    case 2:
        fh=fopen("map2.txt","r");
        break;
    case 3:
        fh=fopen("map3.txt","r");
        break;
    case 4:
        fh=fopen("map4.txt","r");
        break;
    default:
        fh=fopen("map1.txt","r"); //asumsi file tidak kosong
        break;
    }
    while ((ch=fgetc(fh))!=EOF)
    {   
        if(i<=9 && j<=19)
        {
            // L[i][j]=ch;
            ElmtM(*L,i,j)=ch; 
            //masukkan ke dalam matriks
        }
        // printf("%c",L[i][j]);
        j++;
        if (j>19)
        {
            j=0;
            i++;
            fgetc(fh); //enter diskip
        }
        //putchar(ch);
    }
    fclose(fh);
}


void TulisPeta(int x, MATRIKS L)
{
    /* Kamus Lokal*/
    FILE *fh;
    char ch;
    int i=0,j=0;
    puts("Tulis file");
    /* Algoritma */
    switch (x)
    {
    case 1:
        fh=fopen("test.txt","w+");
        break;
    case 2:
        fh=fopen("test.txt","w+");
        break;
    case 3:
        fh=fopen("test.txt","w+");
        break;
    case 4:
        fh=fopen("test.txt","w+");
        break;
    default:
        fh=fopen("test.txt","w+"); //asumsi file tidak kosong
        break;
    }
    //tulismatriks
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            fprintf(fh,"%c",ElmtM(L,i,j));
            // fprintf(fh,"%c",L[i][j]);
        }
        fprintf(fh,"\n");
    }
    fclose(fh);
}



void TitikPeta(MATRIKS L, Arr_POINT AP)
{
    /* Kamus Lokal*/
    int i,j;
    char temp;
    int count;
    /* Algoritma */
    count=0;
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            temp=ElmtM(L,i,j);
            // printf("%c",temp);
            if (temp =='A')
            {
                // printf("Antrian\n");
                // P[(i*20)+j]=MakePOINT(i,j);
                AP.P[count]=MakePOINT(i,j);
                AP.tipe[count]=1;
                count++;
                tipe_point[i][j]=1;
            }
            else if(temp =='P')
            {
                printf("Player di titik %d,%d\n",i,j);
                player_loc=MakePOINT(i,j);
                AP.P[count]=MakePOINT(i,j);
                AP.tipe[count]=2;
                count++;
                tipe_point[i][j]=2;
            }
            else if(temp =='O')
            {
                // printf("Office\n");
                AP.P[count]=MakePOINT(i,j);
                AP.tipe[count]=3;
                count++;
                tipe_point[i][j]=3;
            }
            else if(temp =='V' || temp =='>' || temp =='<' || temp =='^')
            { 
                // printf("Gerbang\n");
                AP.P[count]=MakePOINT(i,j);
                AP.tipe[count]=4;
                count++;
                tipe_point[i][j]=4;
            }
            else if (temp == 'W')
            {
                // printf("Wahana\n");
                AP.P[count]=MakePOINT(i,j);
                AP.tipe[count]=5;
                count++;
                tipe_point[i][j]=5;
            }
            else if (temp == '*')
            {
                // printf("Dinding\n");
                AP.P[count]=MakePOINT(i,j);
                AP.tipe[count]=6;
                count++;
                tipe_point[i][j]=6;
            }
            /*1.Antrian, 2.Player, 3.Office, 4.Gerbang, 5.Wahana, 6.Dinding*/
        }
    }
}


void Movement(char ch, MATRIKS *L)
{
    /* Kamus Lokal*/
    int i,j;
    // POINT pos;
    int x,y;
    // puts("Cek file");
    /* Algoritma */
    x=Absis(player_loc);
    y=Ordinat(player_loc);
    switch (ch)
    {
    case 'W':
        // printf("Test atas\n");
        if (tipe_point[x-1][y]==0 || tipe_point[x-1][y]==3)
        {
            //ubah tipe
            tipe_point[x-1][y]=2;
            printf("Player di titik %d,%d\n",x-1,y);
            Absis(player_loc)-=1;
            tipe_point[x][y]=0;
            //ubah matriks peta
            ElmtM(*L,x-1,y)=ElmtM(*L,x,y);
            ElmtM(*L,x,y)='-';
            if (x==7&&y==15)
            {
                ElmtM(*L,x,y)='O';
            }
            else
            {
                ElmtM(*L,x,y)='-';
            }
        }
        break;
    case 'A':
        // printf("Test kiri\n");
        if (tipe_point[x][y-1]==0 || tipe_point[x-1][y]==3)
        {
            //ubah tipe
            tipe_point[x][y-1]=2;
            printf("Player di titik %d,%d\n",x,y-1);
            Ordinat(player_loc)-=1;
            tipe_point[x][y]=0;
            //ubah matriks peta
            ElmtM(*L,x,y-1)=ElmtM(*L,x,y);
            if (x==7&&y==15)
            {
                ElmtM(*L,x,y)='O';
            }
            else
            {
                ElmtM(*L,x,y)='-';
            }
        }
        break;
    case 'S':
        // printf("Test bawah\n");
        if (tipe_point[x][y-1]==0 || tipe_point[x-1][y]==3)
        {
            //ubah tipe
            tipe_point[x+1][y]=2;
            printf("Player di titik %d,%d\n",x+1,y);
            Absis(player_loc)+=1;
            tipe_point[x][y]=0;
            //ubah matriks peta
            ElmtM(*L,x+1,y)=ElmtM(*L,x,y);
            if (x==7&&y==15)
            {
                ElmtM(*L,x,y)='O';
            }
            else
            {
                ElmtM(*L,x,y)='-';
            }
        }
        break;
    case 'D':
        // printf("Test kanan\n");
        if (tipe_point[x][y-1]==0 || tipe_point[x-1][y]==3)
        {
            //ubah tipe
            tipe_point[x][y+1]=2;
            printf("Player di titik %d,%d\n",x,y+1);
            Ordinat(player_loc)+=1;
            tipe_point[x][y]=0;
            //ubah matriks peta
            ElmtM(*L,x,y+1)=ElmtM(*L,x,y);
            if (x==7&&y==15)
            {
                ElmtM(*L,x,y)='O';
            }
            else
            {
                ElmtM(*L,x,y)='-';
            }
        }
        break;
    default:
        printf("Tidak terdeteksi\n"); //asumsi kalau input salah
        break;
    }
}


int SearchPoint(POINT P[], POINT Pcari)
{
    /* Kamus Lokal*/
    int i=0;
    // int j=0;
    boolean found;
    /* Algoritma */
    found=false;
    while (i!=200 && Absis(P[i])!=0 && Ordinat(P[i])!=0 && !found)
    {
        if (Absis(Pcari)==Absis(P[i]) && Ordinat(Pcari)==Ordinat(P[i]))
        {
            found==true;
        }
        else
        {
            i++;
        }
    }
    return i;
}


void PrintPeta(MATRIKS L)
{
    int i,j;
    //cek peta
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            printf("%c",ElmtM(L,i,j));
        }
        printf("\n");
    }
}

int Adjacency()
{
    /* Kamus Lokal */
    int x,y;
    /* Algoritma */
    x=Absis(player_loc);
    y=Ordinat(player_loc);
    /*1.Antrian, 2.Player, 3.Office, 4.Gerbang, 5.Wahana, 6.Dinding*/
    //sebelah wahana
    if (tipe_point[x-1][y]==5 || tipe_point[x][y-1]==5 ||tipe_point[x+1][y]==5 || tipe_point[x][y+1]==5)
    {
        return(5);
    }
    //sebelah office
    else if (tipe_point[x-1][y]==3 || tipe_point[x][y-1]==3 ||tipe_point[x+1][y]==3 || tipe_point[x][y+1]==3)
    {
        return(3);
    }
    //sebelah border
    else if (tipe_point[x-1][y]==6 || tipe_point[x][y-1]==6 ||tipe_point[x+1][y]==6 || tipe_point[x][y+1]==6)
    {
        return(6);
    }
    //default 0
    return 0;
}
