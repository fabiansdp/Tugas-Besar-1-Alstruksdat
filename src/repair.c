#include "wahana.h"
#include <stdlib.h>
//wahanaya rusak random
int random_number_range(int lower, int upper) { // generate number between lower and upper
   int i,random_num;
   for (i = 0; i < 1; i++) {
      int random_num = (rand() % (upper - lower + 1)) + lower;
   }
   return random_num;
}

void broken(ArrayWahana W){
    
    //pengunjung yang lagi naik wahana bakal balik ngantri tapi prioritasnya tinggi
    //kalau antrian penuh, pengunjung keluar dari wahana
    //kalau rusak ga bisa digunain
    // pemain bisa memperbaiki wahana kalau ada di deket wahana
}
void repair(ArrayWahana W, int broken_number){
    //ubah status wahana menjadi bisa dipakai
    Status(W,broken_number) = 1;
}

int main(){
    int broken_number;
    ArrayWahana W;
    broken_number = random_number_range(0,6);//random 1 sampe 6 buat rusakin wahana
    Status(W,broken_number) = 0;
}