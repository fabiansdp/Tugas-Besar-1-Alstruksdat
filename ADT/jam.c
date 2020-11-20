#include "boolean.h"
#include "jam.h"
#include <stdio.h>

/*****Konstuktor *****/
Jam MakeJam(int H,int M)
/* Membentuk Jam dari H, M, S yang valid */
{
    Jam J;
    Hour(J) = H;
    Minute(J) = M;
    return J;
}
/*------------validator jam------------*/
boolean IsJValid(int H,int M)
/* Mengirim true jika H,M,S dapat membentuk Jam yang valid */
{
    return((0<= H && H <=23) && (0<= M && M <= 59));
}
/*------------Baca & Tulisjam-----------*/
void BacaJam(Jam *J)
/* I.S. : J tak terdefinisi*/
/* F.S. : J terdefinisi dan merupakan jam valid */
/* Proses : mengulang baca komponen H,M,S sehingga membentuk J yang valid */
{
    int H,M;
    do{
        printf("Masukkan jam (tanpa 0 jika <10): ");
        scanf("%d",&H);
        printf("Masukkan menit (tanpa 0 jika <10): ");
        scanf("%d",&M);
    }while(!(IsJValid(H,M)));
    //jam detik menit valid
    *J = MakeJam(H,M);
    
}
void TulisJam(Jam J)
/* I.S. : J sembarang*/
/* F.S. : J ditulis ke layar dengan format HH:MM:SS */
/* Proses : Menulis ke layar*/
{
    if(Hour(J) <10 && Minute(J) <10){
        printf("0%d:0%d",Hour(J),Minute(J));    
    }else
    {
        if(Hour(J) < 10){
            printf("0%d:%d",Hour(J),Minute(J));
        }
        if(Minute(J)<10){
            printf("%d:0%d",Hour(J),Minute(J));
        }
        if(Hour(J) > 10 && Minute(J)>10){
            printf("%d:%d",Hour(J),Minute(J));
        }
    }
    
    
}
int JamToDetik(Jam J)
/* Konversi Jam menjadi detik*/

{
    return(Hour(J)*3600 + Minute(J)*60);
}

Jam DetikToJam(int N)
/* KonversidetikkeJam */
{
    int remainder;
    Jam J;
    N = N %86400; //agar valid harus dibagi 24 jam * 3600 detik
    Hour(J) = N/3600;
    remainder = N%3600;
    Minute(J) = remainder/60;
    return J;
}

void TambahMenit(Jam *J, int X)
{
	int detik;
	int detikdarijam;
	detik = X*60;
	detikdarijam =JamToDetik(*J) + detik;
	*J = DetikToJam(detikdarijam);	
}
