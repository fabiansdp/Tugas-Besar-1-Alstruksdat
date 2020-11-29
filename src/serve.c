#include "../ADT/boolean.h"
#include "../ADT/wahana.h"
#include "../ADT/prioqueuechar.h"
#include "antrian.c"
extern int crnt_map;
extern ArrayWahana MapX,Map1, Map2, Map3, Map4;
extern ArrWRide We,W1,W2,W3,W4;
void serve(int id_wahana){    
     PrioQueueChar Q;
     infotype_pq X;
     boolean found = false;
       if(crnt_map == 1)
       {
         MapX = Map1;
         We = W1;
       }
      else if (crnt_map == 2)
        {
            MapX = Map2;
            We = W2;
        }
        else if(crnt_map == 3)
        {
            MapX = Map3;
            We = W3; 
        }
        else if(crnt_map == 4){
            MapX = Map4;
            We = W4;
        }

//     ----------------
     KurangAntrian(&Q,&X);           //keluarin pengunjung X
//     //apakah ada wahana id_wahana pada list wahana pengunjung X?
        for(int i = 0; i <20;i++){
        
            int tempindex =X.indexwahana[i];

            if(id_wahana == MapX.ArrayW[tempindex].id){//id wahana input user sama kyk id awhana dari list wahana pengunjung X?
                // klo iya bener
                // cek WahanaRide Full
                if(We.ElP != 100){
                    //cek rusak ga
                    if(MapX.ArrayW[tempindex].wahana.status == 0)//ga rusak
                    {
                              //kondisi lulus semua cek
                            //masukin ke WRide si pengunjungnya
                            // ilangin wahana di list pengunjung
                            // tambah duit
                            // masuk lagi ke antrian.
                    }
                    else
                    {
                        printf("Wahana rusak\n");
                    }
                }
                else
                {
                    printf("Wahana Penuh\n");
                }

            }
        
        }