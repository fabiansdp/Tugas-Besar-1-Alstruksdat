#include "../ADT/wahana.h"
#include <stdlib.h>
#include <stdio.h>

int random_number_range(int lower, int upper) { // generate number between lower and upper
   int i,random_num;
   for (i = 0; i < 1; i++) {
      int random_num = (rand() % (upper - lower + 1)) + lower;
   }
   return random_num;
}

void Broken(ArrayWahana W){
    
    //pengunjung yang lagi naik wahana bakal balik ngantri tapi prioritasnya tinggi
    //kalau antrian penuh, pengunjung keluar dari wahana
    //kalau rusak ga bisa digunain
    // pemain bisa memperbaiki wahana kalau ada di deket wahana
}
void Repair(ArrayWahana *W, int broken_number){
    //ubah status wahana menjadi bisa dipakai
    (*W).ArrayW[broken_number].wahana.status = 1;
}