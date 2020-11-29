#include <stdio.h>
#include "jam.h"

int main(){
    int konversi;
    Jam J,J2,J3;
    J = MakeJam(1,3); //bikin jam 01:03 (jam 1 lebih 3 menit);
    BacaJam(&J2); //buat jam J2 memakai prosedur BacaJam
    TulisJam(J); // tulis jam J
    TulisJam(J2);// Tulis Jam J2
    konversi = JamToDetik(J);
    printf("Jam ke detik dari jam J : %d\n", konversi);
    J3 = DetikToJam(konversi);
    TulisJam(J3); //J3 harusnya isinya sama dengan jam J
    TambahMenit(&J3,10);//menambahkan 10 menit pada jam J3
    TulisJam(J3); //J3 sekarang harusnya isinya sama dengan jam J ditambah 10 menit
    return 0; 
}