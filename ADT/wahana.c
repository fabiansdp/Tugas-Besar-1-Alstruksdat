#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "listrek.h"
#include "bintree.h" 
#include "jam.h"
#include "wahana.h"

int mystrlen2(char *str) {
    int len = 0;
    int i = 0;
    for (i=0; str[i] != 0; i++) 
    {
        len++;
    }
    return(len);
}

void printkata(Kata K){
    int x;
    for(x=0;x<K.Length;x++){
        printf("%c",K.TabKata[x]);
    }
}

Uaddress AlokUList (infotype X,BinTree Bt,Wahana W){
    BaseWahanalist * RetU;
    RetU = (BaseWahanalist*) malloc(sizeof(BaseWahanalist));
    if(RetU!=NULL){
        RetU->detailUpgrade = Bt;
        RetU->idWahana = X;
        RetU->nextt = NULL;
        RetU->wahana = W;
    }
    return RetU;
}

infotype FirstUID (BasisListWahana L){
    if(L!=NULL){
        return L->idWahana;
    }else{
        return -1;
    }
}
BinTree FirstBinU (BasisListWahana L){
    if(L!=NULL){
        return L->detailUpgrade;
    }else{return NULL;}
}
Wahana FirstWhnInfo (BasisListWahana L){
    if(L!=NULL){
        return L->wahana;
    }else{
        Wahana w;
        w.id = -1;
        w.deskripsi.Length=0;
        w.durasi = 0;
        w.harga = 0;
        w.kapasitas = 0;
        w.nama.Length=0;
        w.status = 0;
        return w;}
}
BasisListWahana UTail(BasisListWahana L){
    return L->nextt;
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
BasisListWahana UKonso(infotype e,BinTree B,Wahana W, BasisListWahana L){
    Uaddress ad = AlokUList(e,B,W);
    if(ad!=NULL && L==NULL){
        return ad;
    }else if(ad!=NULL){
        ad->nextt = L;
        return ad;
    }else{
        return L;
    }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
BasisListWahana UKonsB(BasisListWahana L, infotype e,Wahana W,BinTree B){
    Uaddress ad = AlokUList(e,B,W);
    if(L==NULL && ad!=NULL){
        L = ad;
        return L;
    }else if(ad!=NULL && L->nextt==NULL){
        L->nextt = ad;
        return L;
    }else if(ad!=NULL){
        BasisListWahana rett = L;
        rett->nextt = UKonsB(UTail(L),e,W,B);
        return rett;
    }else{
        return L;
    }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/*skema read file from file txt*/
BasisListWahana MakeUpgradeList(){
    FILE * FL = fopen("../wahana.txt","r");
    if(FL==NULL){
        printf("err while read file wahana\n");
        return NULL;
    }else{
        BasisListWahana baselist = NULL;
        char c[212];
        BinTree Bt,Bt2;
        int current_wahana=0;
        int cnt = 1;
        Wahana Whn;
        int arahgerak=0;
        int upgradeid;
        int id;
        while (fscanf(FL,"%s",c)!=EOF)
        {
            if(cnt==1){
                id = atoi(c);
                if(current_wahana!=id){
                    current_wahana = id;
                    Whn.id = id;
                    Bt = Tree(id,NULL,NULL);
                    Bt->isApplied = true;
                    arahgerak =0;
                    Whn.status = 0;
                }
            }else if(cnt==2){
                upgradeid = atoi(c);
            }else if(cnt==3){
                arahgerak = atoi(c);
                if(arahgerak>0){
                    Bt2 = Tree(upgradeid,NULL,NULL);
                    Bt2->isApplied = false;
                }
            }else if(cnt==4){
                if(arahgerak==0){
                    Whn.nama.Length = mystrlen2(c);
                    int jj;
                    for(jj=0;jj<mystrlen2(c);jj++){
                        Whn.nama.TabKata[jj] = c[jj];
                    }
                }
            }else if(cnt==5){
                int harga = atoi(c);
                if(arahgerak==0){
                    Whn.harga = harga;
                    Bt->harga = harga;
                }else{
                    Bt2->harga = harga;
                }
            }else if(cnt==6){
                int kapasitas = atoi(c);
                if(arahgerak==0){
                    Whn.kapasitas = kapasitas;
                    Bt->Kapasitas = kapasitas;
                }else{
                    Bt2->Kapasitas = kapasitas;
                }
            }else if(cnt==7){
                int durasi = atoi(c);
                if(arahgerak==0){
                    Bt->durasi=durasi;
                    Whn.durasi = durasi;
                }else{
                    Bt2->durasi=durasi;
                }
            }else if(cnt==8){
                if(arahgerak==0){
                    Whn.deskripsi.Length = mystrlen2(c);
                    Bt->detail.Length = mystrlen2(c);
                    int jj;
                    for(jj=0;jj<mystrlen2(c);jj++){
                        Whn.deskripsi.TabKata[jj] = c[jj];
                        Bt->detail.TabKata[jj] = c[jj];
                    }
                }else{
                    Bt2->detail.Length = mystrlen2(c);
                    int jj;
                    for(jj=0;jj<mystrlen2(c);jj++){
                        //Whn.deskripsi.TabKata[jj] = c[jj];
                        Bt2->detail.TabKata[jj] = c[jj];
                    } 
                }
            }else if(cnt==9){
                int air = atoi(c);
                if(arahgerak==0){
                    Whn.material.air = air;
                    Bt->air=air;
                }else{
                    Bt2->air = air;
                }
            }else if(cnt==10){
                int kayu = atoi(c);
                if(arahgerak==0){
                    Whn.material.kayu = kayu;
                    Bt->kayu = kayu;
                }else{
                    Bt2->kayu = kayu;
                }
            }else if(cnt==11){
                int batu = atoi(c);
                if(arahgerak==0){
                    Whn.material.batu = batu;
                    Bt->batu = batu;
                }else{
                    Bt2->batu = batu;
                }
            }else if(cnt==12){
                int besi = atoi(c);
                if(arahgerak==0){
                    Whn.material.besi = besi;
                    Bt->besi = besi;
                }else{
                    Bt2->besi = besi;
                }
            }

            if(cnt==12){
                if(arahgerak==0){
                    baselist =  UKonsB(baselist,id,Whn,Bt);
                }else if(arahgerak==1){
                    addDaunLeft(&Bt,Bt2);
                }else if(arahgerak==2){
                    addDaunRight(&Bt,Bt2);
                }
                cnt =1;
            }else{
                cnt++;
            }
        }
        return baselist;
    }
}

/*skema ngeprint buat debug*/
void PrintUpList(BasisListWahana L){
    if(L==NULL){

    }else{
        printf("ID Wahana = %d\n",L->idWahana);
        printf("nama wahana = ");printkata(L->wahana.nama);printf("\n");
        printf("desc wahana = ");printkata(L->wahana.deskripsi);printf("\n");
        printf("harga wahana = %d\n",L->wahana.harga);
        printf("pohon Upgrading\n");
        PrintTree(L->detailUpgrade,6);
        printf("=================================================\n\n");
        PrintUpList(UTail(L));
    }
}

/*tambahan*/
BinTree SearchUList(BasisListWahana L, infotype ID){
    if(L==NULL){
        return NULL;
    }else if(FirstUID(L)==ID){
        return L->detailUpgrade;
    }else{
        return SearchUList(UTail(L),ID);
    }
}
Wahana SearchWahanaBase(BasisListWahana L,infotype ID){
    if(L==NULL){
        Wahana w;
        w.id = -1;
        w.deskripsi.Length=0;
        w.durasi = 0;
        w.harga = 0;
        w.kapasitas = 0;
        w.nama.Length=0;
        w.status = 0;
        return w;
    }else if(FirstUID(L)==ID){
        return L->wahana;
    }else{
        return SearchWahanaBase(UTail(L),ID);
    }
}

void addDaunLeft(BinTree * Utama, BinTree tambahan){
    if(Left(*Utama)==NULL){
        Left(* Utama) = tambahan;
    }else{
        addDaunLeft(&Left(*Utama),tambahan);
    }
}
void addDaunRight(BinTree * Utama, BinTree tambahan){
    if(Right(*Utama)==NULL){
        Right(*Utama) = tambahan;
    }else{
        addDaunLeft(&Right(*Utama),tambahan);
    }
}

//==============================================================

//UNTUK KEPENTINGAN MATRIKS WAHANA
void makeArrayWahana (ArrayWahana * A){
    int x;
    for(x=0;x<IdxMax+1;x++){
        (*A).ArrayW[x].id = ValUndef;
        (*A).ArrayW[x].upgradeTree = NULL;
    }
    (*A).jumlahWahana = 0;
}

DetilWahana DirikanWahanaBaru(int id,Wahana BasisWahana, POINT Loc, BinTree skemaUpgrade){
    DetilWahana det;
    det.id = id;
    det.laporan.naikharian = 0;
    det.laporan.naiktotal = 0;
    det.laporan.penghasilanharian = 0;
    det.laporan.penghasilantotal = 0;
    det.lokasi = Loc;
    det.upgradeTree = skemaUpgrade;
    det.wahana = BasisWahana;

    return det;
}

void PushNewWahana (ArrayWahana * A, DetilWahana DW){
    if((*A).jumlahWahana < IdxMax+1){
        int temp =  (*A).jumlahWahana;
        (*A).ArrayW[temp] = DW;
        (*A).jumlahWahana++;
    }else{
        printf("Array Wahana Sudah Penuh boss !!! \n");
    }
    (*A).jumlahWahana = 0;
}

DetilWahana CariWahanaByID (ArrayWahana A, int ID){
    boolean f= false;
    int c = 0;
    while (c < A.jumlahWahana && f==false)
    {
        if(A.ArrayW[c].id==ID){
            f = true;
        }else{
            c++;
        }
    }

    if(f){
        return A.ArrayW[c];
    }else{
        DetilWahana d;
        d.id = ValUndef;
        d.upgradeTree = NULL;
        return d;
    }
    
}

DetilWahana CariWahanaByLoc (ArrayWahana A, POINT Loc){
    boolean f= false;
    int c = 0;
    while (c < A.jumlahWahana && f==false)
    {
        if(A.ArrayW[c].lokasi.X==Loc.X && A.ArrayW[c].lokasi.X==Loc.Y){
            f = true;
        }else{
            c++;
        }
    }

    if(f){
        return A.ArrayW[c];
    }else{
        DetilWahana d;
        d.id = ValUndef;
        d.upgradeTree = NULL;
        return d;
    }
}

void UpdateInfoWahana(ArrayWahana * A, int ID, Wahana newWahana){
    boolean f= false;
    int c = 0;
    while (c < (*A).jumlahWahana && f==false)
    {
        if((*A).ArrayW[c].id==ID){
            f = true;
        }else{
            c++;
        }
    }

    if(f){
        (*A).ArrayW[c].wahana = newWahana;
    }
}
void UpdateLaporanWahana(ArrayWahana * A, int ID, Laporan LaporanBaru){
    boolean f= false;
    int c = 0;
    while (c < (*A).jumlahWahana && f==false)
    {
        if((*A).ArrayW[c].id==ID){
            f = true;
        }else{
            c++;
        }
    }

    if(f){
        (*A).ArrayW[c].laporan = LaporanBaru;
    }
}

BinTree searchTree2 (BinTree T, int IDTree){
    if(T==NULL){
        return NULL;
    }else if(T->info == IDTree){
        return T;
    }else{
        if(SearchTree((Left(T)),IDTree)){
            return searchTree2(Left(T),IDTree);
        }else if(SearchTree((Right(T)),IDTree)){
            return searchTree2(Right(T),IDTree);
        }else{
            return NULL;
        }
    }
}

void helpShowAvailUpgrade(BinTree bt){
    if(bt!=NULL){
        if(bt->isApplied==false){
            printf("-> %d. %s <Biaya pembangunan = %d, Durasi pembangunan= %d",bt->info,bt->detail.TabKata,bt->harga,bt->durasi);
            printf(", Kapasitas = +%d, Kayu = -%d,",bt->Kapasitas,bt->kayu);
            printf(" Air = -%d, Besi = -%d, Batu = -%d>\n",bt->air,bt->besi,bt->batu);
        }else{
            helpShowAvailUpgrade(Left(bt));
            helpShowAvailUpgrade(Right(bt));
        }
    }
}
void ShowAvailableUpgrade(ArrayWahana A,int IDWahana){
    DetilWahana D = CariWahanaByID(A,IDWahana);
    if(D.id!=ValUndef){
        BinTree pohonUpgrade = D.upgradeTree;
        if(pohonUpgrade!=NULL){
            printf("upgrade available for %s (ID wahana = %d)\n",D.wahana.nama.TabKata,D.id);
            helpShowAvailUpgrade(pohonUpgrade);
        }
    }
}

boolean UpgradeWahana(ArrayWahana *A, int IDWahana, int IDUpgrade){
    boolean f= false;
    int c = 0;
    while (c < (*A).jumlahWahana && f==false)
    {
        if((*A).ArrayW[c].id==IDUpgrade){
            f = true;
        }else{
            c++;
        }
    }

    if(f){
        BinTree pohonUp = searchTree2((*A).ArrayW[c].upgradeTree,IDUpgrade);
        if(pohonUp!=NULL){
            pohonUp->isApplied = true;
           //(*A).ArrayW[c].wahana.durasi = pohonUp->durasi;
           //(*A).ArrayW[c].wahana.harga = pohonUp->harga;
           (*A).ArrayW[c].wahana.kapasitas = pohonUp->Kapasitas;
           //(*A).ArrayW[c].wahana.material.air = pohonUp->air;
           //(*A).ArrayW[c].wahana.material.kayu = pohonUp->kayu;
           //(*A).ArrayW[c].wahana.material.besi = pohonUp->besi;
           //(*A).ArrayW[c].wahana.material.batu = pohonUp->batu;
           return true;
        } else{return false;}
    }else{
        return false;
    }
}

//DEBUGGING PURPOSE
void PrintAllWahana(ArrayWahana A){
    int x;
    for(x=0;x<A.jumlahWahana;x++){
        printf("ID WAHANA = %d\n",A.ArrayW[x].id);
        printf("BASIS WAHANA = %d\n",A.ArrayW[x].wahana.id);
        printf("NAMA WAHANA = %s\n",A.ArrayW[x].wahana.nama);
        printf("HARGA WAHANA = %d\n",A.ArrayW[x].wahana.harga);
        printf("KAPASITAS WAHANA = %d\n",A.ArrayW[x].wahana.kapasitas);
        printf("LOKASI WAHANA = %.2f,%.2f\n",A.ArrayW[x].lokasi.X,A.ArrayW[x].lokasi.Y);
        printf("Keuntungan total wahana = %d\n",A.ArrayW[x].laporan.penghasilantotal);
        printf("pengunjung wahana total = %d\n",A.ArrayW[x].laporan.naiktotal);
        printf("pohon Upgrade Wahana\n");
        PrintTree(A.ArrayW[x].upgradeTree,6);
        printf("============================================\n");
    }
}

//UNTUK KEPENTINGAN UPGRADE HISTORY
InfoHis CreateNewHistoryInfo ( int day, Jam waktuUpgrade, Kata namaWhn, Kata namaUpgrade){
    InfoHis r;
    r.day = day;
    r.namaUpgrade = namaUpgrade;
    r.namaWahana = namaWhn;
    r.waktuUpgrade = waktuUpgrade;
    return r;
}

Haddress AlokHistoUpgrade(int idWahana,InfoHis detUpgrade){
    HistoryUpgrade * HU;
    HU = (HistoryUpgrade *) malloc (sizeof(HistoryUpgrade));
    if(HU!=NULL){
        HU->idWahana = idWahana;
        HU->InfoUpgrade = detUpgrade;
        HU->lanjut = NULL;
        HU->upgradeID = 0;
    }
    return HU;
}
int getFirstHistoryByIDUpgrade(ListHistoUpdate L){
    if(L!=NULL){
        return L->upgradeID;
    }else{
        return ValUndef;
    }
}

int getFirstHistoryByIDWahana(ListHistoUpdate L){
    if(L!=NULL){
        return L->idWahana;
    }else{
        return ValUndef;
    }
}

InfoHis getFirstHistoInfo(ListHistoUpdate L){
    if(L!=NULL){
        return L->InfoUpgrade;
    }else{
        InfoHis i;
        i.day = -1;
        i.waktuUpgrade.HH = 0;
        i.waktuUpgrade.MM = 0;
        i.namaUpgrade.Length = 0;
        i.namaWahana.Length = 0;
        return i;
    }
}

ListHistoUpdate HistoTail (ListHistoUpdate L){
    return L->lanjut;
}

ListHistoUpdate AddNewHistory(ListHistoUpdate L, InfoHis Info, int IdWahana, int upgradeID){
    Haddress h =  AlokHistoUpgrade(IdWahana,Info);
    if(L==NULL && h!=NULL){
        h->upgradeID = upgradeID;
        L = h;
        return L;
    }else if(h!=NULL && L->lanjut ==NULL){
        h->upgradeID = upgradeID;
        L->lanjut = h;
        return L;
    }else if(h!=NULL){
        ListHistoUpdate rett = L;
        rett->lanjut = AddNewHistory(rett->lanjut,Info,IdWahana,upgradeID);
        return rett;
    }else{
        return NULL;
    }
}

InfoHis SearchHistory (ListHistoUpdate L, int upgradeID){
    if(L==NULL){
        InfoHis i;
        i.day = -1;
        i.waktuUpgrade.HH = 0;
        i.waktuUpgrade.MM = 0;
        i.namaUpgrade.Length = 0;
        i.namaWahana.Length = 0;
        return i;
    }else if(L->upgradeID==upgradeID){
        return L->InfoUpgrade;
    }else{
        return SearchHistory(HistoTail(L),upgradeID);
    }
}

void PrintAllHistory (ListHistoUpdate L){
    ListHistoUpdate a = L;
    while (a!=NULL)
    {
        printf("Upgrade id              = %d\n",a->upgradeID);
        printf("Waktu Upgrade           = day-%d at %d:%d\n",a->InfoUpgrade.day,a->InfoUpgrade.waktuUpgrade.HH,a->InfoUpgrade.waktuUpgrade.MM);
        printf("Wahana yg di Upgrade    = ");printkata(a->InfoUpgrade.namaWahana);printf("\n");
        printf("Jenis/nama upgrade      = ");printkata(a->InfoUpgrade.namaUpgrade);printf("\n");
        printf("\n");
        a = HistoTail(a);
    }
    
}

void PrintHistoryByID (ListHistoUpdate L,int IDWahana){
    ListHistoUpdate a = L;
    while (a!=NULL)
    {
        if(a->idWahana==IDWahana){
            printf("Upgrade id              = %d\n",a->upgradeID);
            printf("Waktu Upgrade           = day-%d at %d:%d\n",a->InfoUpgrade.day,a->InfoUpgrade.waktuUpgrade.HH,a->InfoUpgrade.waktuUpgrade.MM);
            printf("Wahana yg di Upgrade    = ");printkata(a->InfoUpgrade.namaWahana);printf("\n");
        printf("Jenis/nama upgrade      = ");printkata(a->InfoUpgrade.namaUpgrade);printf("\n");
            printf("\n");
        }
        a = HistoTail(a);
    }
}

int NbElmtHistory (ListHistoUpdate L){
    if(L==NULL){
        return 0;
    }else{
        return 1 + NbElmtHistory(HistoTail(L));
    }
}