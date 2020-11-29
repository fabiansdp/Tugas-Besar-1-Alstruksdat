#include <stdio.h>
#include "../boolean.h"
#include "point.h"
#include <math.h>

int main()
{
    POINT P = MakePOINT(19, 99);
    //baca point dari input user
    printf("Make point (19,99):\n");
    printf("hasil fungsi MakePOINT: \n");
    TulisPOINT(P);

    //BACA POINT
    POINT P1;
    printf("Input point dengan fungsi BacaPOINT\n");
    BacaPOINT(&P1);
    printf("Hasil fungsi BacaPOINT: \n");
    TulisPOINT(P1);

    //isEQ
    if (EQ(P, P1))
    {
        printf("Kedua point tersebut sama\n");
    }
    else if (NEQ(P, P1)) //isNEQ
    {
        printf("Kedua point tersebut tidak sama\n");
    }

    return 0;
}