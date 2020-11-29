#include<stdio.h>
#include<stdlib.h>
#include"boolean.h"
#include"listrek.h"

//HAFID ABI DANISWARA
//13519028

address Alokasi (infotype X){
    ElmtList * Elis;
    Elis = (ElmtList *) malloc(sizeof(ElmtList));
    if(Elis==NULL){
      return NULL;
    }else{
      Info(Elis) = X;
      Next(Elis) = NULL;
      return Elis;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
    if(L==NULL){
        return 1;
    }else{
      return 0;
    }
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(List L){
  if (IsEmpty(L)==0){
    if(Next(L)==NULL){
      return 1;
    }else{
      return 0;
    }
  }else{
    return 0;
  }
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotype FirstElmt (List L){
  if (IsEmpty(L)==0){
    return Info(L);
  }else{
    return 0;
  }
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List TailList(List L){
  if(IsEmpty(L)==0){
    return Next(L);
  }else
  {
    return NULL;
  }
  
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(infotype e, List L){
      address ad = Alokasi(e);
      if(ad!=NULL && IsEmpty(L)==1){
        return ad;
      }else if(ad!=NULL){
        Next(ad) = L;
        return ad;
      }else{
        return L;
      }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List KonsB(List L, infotype e){
    address adr = Alokasi(e);
    if(L==NULL && adr!=NULL){
      L = adr;
      return L;
    }else if(adr!=NULL && Next(L)==NULL){
      Next(L) = adr;
      return L;
    }else if (adr!=NULL){
      List retrn = L;
      Next(retrn) = KonsB(Next(L),e);
      return retrn;
    }else{
      return L;
    }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* *** Operasi Lain *** */
List Copy (List L){
    if(L==NULL){
      return NULL;
    }else{
      List retlist = Konso(Info(L),Copy(Tail(L)));
      return retlist;
    }
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
void MCopy (List Lin, List *Lout){
  //List haha = Copy(Lin);
  //(*Lout) = haha;

  if(IsEmpty(Lin)){
    *Lout = NULL;
  }else{
    address asoy;
    MCopy(Next(Lin),&asoy);
    (*Lout) = Konso(Info(Lin),asoy);
  }
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
List Concat (List L1, List L2){
    if(L1==NULL && L2==NULL){
      return NULL;
    }else if(L1==NULL){
      return Konso(Info(L2),Concat(L1,Next(L2)));
    }else{
      return Konso(Info(L1),Concat(Next(L1),L2));
    }
    
}
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NULL */
void MConcat (List L1, List L2, List *LHsl){
    if(L1==NULL && L2==NULL){
      (*LHsl) = NULL;
    }else if(L1==NULL){
      address cekaja;
      MConcat(L1,Next(L2),&cekaja);
      (*LHsl) = Konso(Info(L2),cekaja);
    }else{
      address cekaja;
      MConcat(Next(L1),L2,&cekaja);
      (*LHsl) = Konso(Info(L1),cekaja);
      
    }
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (List L){
  if(L!=NULL){
    printf("%d\n",Info(L));
    PrintList(Next(L));
  }
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList (List L){
  if(IsEmpty(L)==1){
    return 0;
  }else{
    return 1+NbElmtList(Tail(L));
  }
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, infotype X){
  if(IsEmpty(L)==1){
    return false;
  }else if(FirstElmt(L)==X){
    return true;
  }else{
    return Search(Tail(L),X);
  }
    
}
/* Mengirim true jika X adalah anggota list, false jika tidak */

/*** Pencarian NULLai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L){
    infotype maks;
    maks = FirstElmt(L);
    L = Tail(L);
    while (L!=NULL)
    {
      if(FirstElmt(L)>maks){
        maks = FirstElmt(L);
      }
      L = Tail(L);
    }
    return maks;
}
/* Mengirimkan NULLai info(P) yang maksimum */

infotype MinList (List L){
  infotype mini;
    mini = FirstElmt(L);
    L = Tail(L);
    while (L!=NULL)
    {
      if(FirstElmt(L)<mini){
        mini = FirstElmt(L);
      }
      L = Tail(L);
    }
    return mini;
}
/* Mengirimkan NULLai info(P) yang minimum */

infotype SumList (List L){
  if(IsEmpty(L)==1){
    return 0;
  }else{
    return FirstElmt(L)+SumList(Tail(L));
  }
}
/* Mengirimkan total jumlah elemen List L */

float AverageList (List L){
  float nbel = (float) NbElmtList(L);
  float suml = (float) SumList(L);
  if(nbel>0){
    return suml/nbel;
  }else{
    return 0;
  }
}
/* Mengirimkan NULLai rata-rata elemen list L */

/*** Operasi-Operasi Lain ***/
List InverseList (List L){
  if(L==NULL){
      return NULL;
    }else{
      List retlist = KonsB(InverseList(Tail(L)),Info(L));
      return retlist;
    }
}
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void SplitPosNeg (List L, List *L1, List *L2){
    if(L==NULL){
      (*L1) = NULL;
      (*L2) = NULL;
    }else{
      address asw;
      if(FirstElmt(L)>=0){
        SplitPosNeg(Tail(L),&asw,L2);
        (*L1) = Konso(Info(L),asw);
      }else{
        SplitPosNeg(Tail(L),L1,&asw);
        (*L2) = Konso(Info(L),asw);
      }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */

void SplitOnX (List L, infotype X, List *L1, List *L2){
  if(L==NULL){
      (*L1) = NULL;
      (*L2) = NULL;
    }else{
      address asw;
      if(FirstElmt(L)<X){
        SplitPosNeg(Tail(L),&asw,L2);
        (*L1) = Konso(Info(L),asw);
      }else{
        SplitPosNeg(Tail(L),L1,&asw);
        (*L2) = Konso(Info(L),asw);
      }
    }
}
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */

int ListCompare (List L1, List L2){
  if(NbElmtList(L1)<NbElmtList(L2)){
    return -1;
  }else if(NbElmtList(L1)>NbElmtList(L2)){
    return 1;
  }else{
    if(MinList(L1)<MinList(L2)){
      return -1;
    }else if(MinList(L1)>MinList(L2)){
      return 1;
    }else{
      boolean flag = true;
      while (L1!=NULL && L2!=NULL && flag)
      {
        if(FirstElmt(L1)!=FirstElmt(L2)){
          flag = false;
        }else{
          L1 = Tail(L1); L2 = Tail(L2);
        }
      }

      if(flag){
        return 0;
      }else{
        if(MinList(L1)<MinList(L2)){
          return -1;
        }else if(MinList(L1)>MinList(L2)){
          return 1;
        }else if(MaxList(L1)>MaxList(L2)){
          return 1;
        }else{
          return -1;
        }
      
      }
  }
}
}
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */

boolean IsAllExist (List L1, List L2){
  boolean flag = true;
  while(L1!=NULL && flag){
    if(Search(L2,FirstElmt(L1))){
      L1 = Tail(L1);
    }else{
      flag = false;
    }
  }

  return flag;
}
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */