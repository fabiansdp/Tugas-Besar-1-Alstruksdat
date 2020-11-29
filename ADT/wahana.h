#ifndef wahana_H
#define wahana_H


#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "listrek.h"
#include "bintree.h" 
#include "jam.h"
#define IdxMax 99
/* Indeks maksimum array */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

typedef struct
{
    int naiktotal;
    int penghasilantotal;
    int naikharian;
    int penghasilanharian;
} Laporan;

typedef struct
{
    int air;
    int kayu;
    int batu;
    int besi;
} UpgradeMaterial;

typedef struct
{
    int id, harga, kapasitas, durasi, status;
    Kata nama;
    Kata deskripsi;
    UpgradeMaterial material;
} Wahana;

typedef struct
{
    int id;
    Wahana wahana;
    Laporan laporan;
    POINT lokasi;
    BinTree upgradeTree;
} DetilWahana;

typedef struct
{
    DetilWahana ArrayW[IdxMax + 1];
    int jumlahWahana;
} ArrayWahana;

typedef int infotype;
typedef struct tBaseWahanalist *Uaddress;
typedef struct tHistoryUpgrade *Haddress;
typedef struct tBaseWahanalist { 
	infotype idWahana;
    Wahana wahana;
    BinTree detailUpgrade;
	Uaddress nextt;
} BaseWahanalist;

typedef struct tInfoHis{
    int day;
    Jam waktuUpgrade;
    Kata namaWahana;
    Kata namaUpgrade;
}InfoHis;

typedef struct tHistoryUpgrade
{
    int upgradeID;
    int idWahana;
    InfoHis InfoUpgrade;
    Haddress lanjut;
}HistoryUpgrade;

typedef Haddress ListHistoUpdate;
typedef Uaddress BasisListWahana;

void printkata(Kata K);
//UNTUK KEPENTINGAN INISIALISASI WAHANA
Uaddress AlokUList (infotype X,BinTree Bt,Wahana W);

infotype FirstUID (BasisListWahana L);

BinTree FirstBinU (BasisListWahana L);

Wahana FirstWhnInfo (BasisListWahana L);

BasisListWahana UTail(BasisListWahana L);
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
BasisListWahana UKonso(infotype e,BinTree B,Wahana W, BasisListWahana L);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
BasisListWahana UKonsB(BasisListWahana L, infotype e,Wahana W,BinTree B);
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/*skema read file from file txt*/
BasisListWahana MakeUpgradeList();

/*skema ngeprint buat debug*/
void PrintUpList(BasisListWahana L);

/*tambahan*/
BinTree SearchUList(BasisListWahana L, infotype ID);

Wahana SearchWahanaBase(BasisListWahana L,infotype ID);

void addDaunLeft(BinTree * Utama, BinTree tambahan);

void addDaunRight(BinTree * Utama, BinTree tambahan);

//==============================================================

//UNTUK KEPENTINGAN ARRAY WAHANA
void makeArrayWahana (ArrayWahana * A);

void printDaftarWahana (BasisListWahana L);

DetilWahana DirikanWahanaBaru(int id, Wahana BasisWahana, POINT Loc, BinTree skemaUpgrade);

void PushNewWahana (ArrayWahana * A, DetilWahana DW);

DetilWahana CariWahanaByID (ArrayWahana A, int ID);

DetilWahana CariWahanaByLoc (ArrayWahana A, POINT Loc);

BinTree searchTree2 (BinTree T, int IDTree);

BinTree checkUpgradeAvail(BinTree T, int IDUpgrade);

void UpdateInfoWahana(ArrayWahana * A, int ID, Wahana newWahana);

void UpdateLaporanWahana(ArrayWahana * A, int ID, Laporan LaporanBaru);

void ShowAvailableUpgrade(ArrayWahana A,int IDWahana);

boolean UpgradeWahana(ArrayWahana *A, int IDWahana, int IDUpgrade);

//DEBUGGING PURPOSE
void PrintAllWahana(ArrayWahana A);

//==============================================================

//UNTUK KEPENTINGAN UPGRADE HISTORY
InfoHis CreateNewHistoryInfo ( int day, Jam waktuUpgrade, Kata namaWhn, Kata namaUpgrade);

Haddress AlokHistoUpgrade(int idWahana, InfoHis detUpgrade);

int getFirstHistoryByIDWahana(ListHistoUpdate L);

int getFirstHistoryByIDUpgrade(ListHistoUpdate L);

InfoHis getFirstHistoInfo(ListHistoUpdate L);

ListHistoUpdate HistoTail (ListHistoUpdate L);

ListHistoUpdate AddNewHistory(ListHistoUpdate L, InfoHis Info, int IdWahana, int upgradeID);

InfoHis SearchHistory (ListHistoUpdate L, int IdWahana);

void PrintAllHistory (ListHistoUpdate L);

void PrintHistoryByID (ListHistoUpdate L,int IDWahana);

int NbElmtHistory (ListHistoUpdate L);

#endif