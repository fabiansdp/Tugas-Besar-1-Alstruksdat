#include "../ADT/boolean.h"
#include "../ADT/wahana.h"
#include "../ADT/prioqueuechar.h"
#include "antrian.c"
extern int crnt_map;
extern ArrayWahana MapX,Map1, Map2, Map3, Map4;
extern ArrWRide We,W1,W2,W3,W4; // ARRAY DARI SEMUA KAPASITAS WAHANA PER MAP
extern PrioQueueChar Q,Q1,Q2,Q3,Q4; // ANTRIAN PENGUNJUNG SETIAP MAP

void serve(PrioQueueChar Q)
{
    // Kata CandyCrush;
    // Kata ChocolateForest;
    // Kata BombomCar;
    // Kata LemonSplash;
    // Kata CandyVillage;
    // Kata CandySwing;
    // Kata BlackForestTornado;
    // CandyCrush.TabKata[0] = 'C';
    // CandyCrush.TabKata[1] = 'a';
    // CandyCrush.TabKata[2] = 'n';
    // CandyCrush.TabKata[3] = 'd';
    // CandyCrush.TabKata[4] = 'y';
    // CandyCrush.TabKata[5] = '-';
    // CandyCrush.TabKata[6] = 'C';
    // CandyCrush.TabKata[7] = 'r';
    // CandyCrush.TabKata[8] = 'u';
    // CandyCrush.TabKata[9] = 's';
    // CandyCrush.TabKata[10] = 'h';
    // CandyCrush.Length = 11;

    // ChocolateForest.TabKata[0] = 'C';
    // ChocolateForest.TabKata[1] = 'h';
    // ChocolateForest.TabKata[2] = 'o';
    // ChocolateForest.TabKata[3] = 'c';
    // ChocolateForest.TabKata[4] = 'o';
    // ChocolateForest.TabKata[5] = 'l';
    // ChocolateForest.TabKata[6] = 'a';
    // ChocolateForest.TabKata[7] = 't';
    // ChocolateForest.TabKata[8] = 'e';
    // ChocolateForest.TabKata[9] = '-';
    // ChocolateForest.TabKata[10] = 'F';
    // ChocolateForest.TabKata[11] = 'o';
    // ChocolateForest.TabKata[12] = 'r';
    // ChocolateForest.TabKata[13] = 'e';
    // ChocolateForest.TabKata[14] = 's';
    // ChocolateForest.TabKata[15] = 't';
    // ChocolateForest.Length = 16;

    // BombomCar.TabKata[0] = 'B';
    // BombomCar.TabKata[1] = 'o';
    // BombomCar.TabKata[2] = 'm';
    // BombomCar.TabKata[3] = 'b';
    // BombomCar.TabKata[4] = 'o';
    // BombomCar.TabKata[5] = 'm';
    // BombomCar.TabKata[6] = '-';
    // BombomCar.TabKata[7] = 'C';
    // BombomCar.TabKata[8] = 'a';
    // BombomCar.TabKata[9] = 'r';
    // BombomCar.Length = 10;

    // LemonSplash.TabKata[0] = 'L';
    // LemonSplash.TabKata[1] = 'e';
    // LemonSplash.TabKata[2] = 'm';
    // LemonSplash.TabKata[3] = 'o';
    // LemonSplash.TabKata[4] = 'n';
    // LemonSplash.TabKata[5] = '-';
    // LemonSplash.TabKata[6] = 'S';
    // LemonSplash.TabKata[7] = 'p';
    // LemonSplash.TabKata[8] = 'l';
    // LemonSplash.TabKata[9] = 'a';
    // LemonSplash.TabKata[10] = 's';
    // LemonSplash.TabKata[11] = 'h';
    // LemonSplash.Length = 12;

    // CandyVillage.TabKata[0] = 'C';
    // CandyVillage.TabKata[1] = 'a';
    // CandyVillage.TabKata[2] = 'n';
    // CandyVillage.TabKata[3] = 'd';
    // CandyVillage.TabKata[4] = 'y';
    // CandyVillage.TabKata[5] = '-';
    // CandyVillage.TabKata[6] = 'V';
    // CandyVillage.TabKata[7] = 'i';
    // CandyVillage.TabKata[8] = 'l';
    // CandyVillage.TabKata[9] = 'l';
    // CandyVillage.TabKata[10] = 'a';
    // CandyVillage.TabKata[11] = 'g';
    // CandyVillage.TabKata[12] = 'e';
    // CandyVillage.Length = 13;

    // CandySwing.TabKata[0] = 'C';
    // CandySwing.TabKata[1] = 'a';
    // CandySwing.TabKata[2] = 'n';
    // CandySwing.TabKata[3] = 'd';
    // CandySwing.TabKata[4] = 'y';
    // CandySwing.TabKata[5] = '-';
    // CandySwing.TabKata[6] = 'S';
    // CandySwing.TabKata[7] = 'w';
    // CandySwing.TabKata[8] = 'i';
    // CandySwing.TabKata[9] = 'n';
    // CandySwing.TabKata[10] = 'g';
    // CandySwing.Length = 11;

    // BlackForestTornado.TabKata[0] = 'B';
    // BlackForestTornado.TabKata[1] = 'l';
    // BlackForestTornado.TabKata[2] = 'a';
    // BlackForestTornado.TabKata[3] = 'c';
    // BlackForestTornado.TabKata[4] = 'k';
    // BlackForestTornado.TabKata[5] = 'f';
    // BlackForestTornado.TabKata[6] = 'o';
    // BlackForestTornado.TabKata[7] = 'r';
    // BlackForestTornado.TabKata[8] = 'e';
    // BlackForestTornado.TabKata[9] = 's';
    // BlackForestTornado.TabKata[10] = 't';
    // BlackForestTornado.TabKata[11] = '-';
    // BlackForestTornado.TabKata[12] = 'T';
    // BlackForestTornado.TabKata[13] = 'o';
    // BlackForestTornado.TabKata[14] = 'r';
    // BlackForestTornado.TabKata[15] = 'n';
    // BlackForestTornado.TabKata[16] = 'a';
    // BlackForestTornado.TabKata[17] = 'd';
    // BlackForestTornado.TabKata[18] = 'o';
    // BlackForestTornado.Length = 19;
    // STARTKATA();


/*
       
*/
    //     ----------------
    //KurangAntrian(&Q, &X); //keluarin pengunjung X
                           //^^^^ ini udah ada list wahana yang mau di kunjungi sama pengunjung X

    //     //apakah ada wahana id_wahana pada list wahana pengunjung X?
    // for (int i = 0; i < 20; i++)
    // {

    //     int tempindex = X.indexwahana[i];
    //     if (id_wahana == MapX.ArrayW[tempindex].id)
    //     { //id wahana input user sama kyk id awhana dari list wahana pengunjung X?
    //         // klo iya bener
    //         // cek WahanaRide Full
    //         if (We.ElP != 100)
    //         {
    //             //cek rusak ga
    //             if (MapX.ArrayW[tempindex].wahana.status == 0) //ga rusak
    //             {
    //                 //kondisi lulus semua cek
    //                 //masukin ke WRide si pengunjungnya
    //                 // ilangin wahana di list pengunjung
    //                 // tambah duit
    //                 // masuk lagi ke antrian.
    //             }
    //             else
    //             {
    //                 printf("Wahana rusak\n");
    //             }
    //         }
    //         else
    //         {
    //             printf("Wahana Penuh\n");
    //         }
    //     }
}