#include<stdio.h>
#include"matriks.h"

int main(){
    MATRIKS mat;
    MakeMATRIKS(10,10,&mat);

    for (int x=0;x<10;x++){
        for (int y=0;y<10;y++){
            ElmtM(mat,x,y) = (x+y)%10;
        }
    }

    TulisMATRIKS(mat);

    printf("\n======================================\n");

    MATRIKS m2 = TambahMATRIKS(mat,mat);

    TulisMATRIKS(m2);

    printf("\n");

    printf("Nb elmt matriks = %d\n",NBElmt(mat));
}