#include "mesinkar.h"
#include <stdio.h>

int main()
{
    printf("Membaca karakter(input 2 karakter):");
    START();
    printf("Hasil baca input karakter = %c\n", CC);
    ADV();
    printf("Hasil baca input karakter  selanjutnya = %c\n", CC);
    return 0;
}