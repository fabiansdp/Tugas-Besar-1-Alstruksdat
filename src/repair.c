#include "../ADT/wahana/wahana.h"
#include <stdlib.h>


//wahanaya rusak random


void Broken(Wahana *W){
    W->status = 1;
}
void Repair(Wahana *W){
    W->status = 0;
}
    //ubah status wahana menjadi bisa dipakai
   