#include <stdio.h>
#include <stdlib.h>
/* Kamus */
char L[10][20];
/* Algoritma */
void BacaPeta(int x)
/*I.S.File peta terdefinisi parameter x menunjukkan peta tertentu F.S.Output peta ke layar*/
{
    /* Kamus Lokal*/
    FILE *fh;
    char ch;
    int i=0,j=0;
    puts("Cek file");
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
            L[i][j]=ch; //masukkan ke dalam matriks
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

    //printmatriks
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 19; j++)
        {
            printf("%c",L[i][j]);
        }
        printf("\n");
    }
    fclose(fh);
}

void TulisPeta(int x)
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
            fprintf(fh,"%c",L[i][j]);
        }
        fprintf(fh,"\n");
    }
    fclose(fh);
}

int main()
{
    BacaPeta(1);
    TulisPeta(1);
    return 0;
}

