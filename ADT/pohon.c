#include<stdio.h>
#include<stdlib.h>
#include"boolean.h"
#include"listrek.h"
#include"pohon.h"

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
   Node * pohon;
   pohon = (Node *) malloc(sizeof(Node));

   if(pohon!=NULL){
      Left(pohon) = L;
      Right(pohon) = R;
      Akar(pohon) = Akar;
      return pohon;
   } else{
      return NULL;
   }
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
   (*P) = Tree(Akar,L,R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
BinTree BuildBalanceTree(int n){
   if(n==0){
      return Nil;
   }else{
      int aselole;
      scanf("%d",&aselole);
      addrNode nod = AlokNode(aselole);
      if(nod==Nil){
         return Nil;
      }else{
         BinTree kanan = BuildBalanceTree(n/2);
         BinTree kiri = BuildBalanceTree(n-((n/2)+1));
         Left(nod) = kiri;
         Right(nod) = kanan;
         return nod;
      }
   }
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Jika n == 0, kembalikan Nil.
   Mula-mula, baca nilai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin). 
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
   Node * N;
   N = (Node *) malloc(sizeof(Node));
   if(N!=NULL){
      Akar(N) = X;
      Left(N) = NULL;
      Right(N) = Left(N);
      return N;
   }else{
      return NULL;
   }
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
   free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
   return P==NULL;
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
   return P!=NULL && Right(P)==NULL && Left(P)==NULL;
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
   if(IsTreeEmpty(P) || IsTreeOneElmt(P) || Right(P)!=NULL){
      return false;
   }else if(Left(P)!=Nil && Right(P)==Nil && IsTreeOneElmt(Left(P))){
      return true;
   }else{
      return IsUnerLeft(Left(P));
   }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
   if(IsTreeEmpty(P) || IsTreeOneElmt(P) || Left(P)!=NULL){
      return false;
   }else if(Left(P)==Nil && Right(P)!=Nil && IsTreeOneElmt(Right(P))){
      return true;
   }else{
      return IsUnerRight(Right(P));
   }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
   if(IsTreeEmpty(P) || IsTreeOneElmt(P) || Right(P)==NULL ||Left(P)==NULL){
      return false;
   }else if(IsTreeOneElmt(Left(P)) && IsTreeOneElmt(Right(P))){
      return true;
   }else{
      return IsBiner(Left(P)) && IsBiner(Right(P)) ;
   }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder(BinTree P){
   if(IsTreeEmpty(P)){
      printf("()");
   }else{
      printf("(%d",Akar(P));
      PrintPreorder(Left(P));
      PrintPreorder(Right(P));
      printf(")");
   }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
   if(IsTreeEmpty(P)){
      printf("()");
   }else{
      printf("(");
      PrintPostorder(Left(P));
      printf("%d",Akar(P));
      PrintPostorder(Right(P));
      printf(")");
   }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
   if(IsTreeEmpty(P)){
      printf("()");
   }else{
      printf("(");
      PrintPostorder(Left(P));
      PrintPostorder(Right(P));
      printf("%d)",Akar(P));
   }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree(BinTree P, int h){
   if(!IsTreeEmpty(P)){
      int x;
      for(x=0;x<h;x++){
         printf(" ");
      }
      printf("%d\n",Akar(P));
      PrintTree(Left(P),h+1);
      PrintTree(Right(P),h+1);
   }
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
   if(IsTreeEmpty(P)){
      return false;
   }else if(Akar(P)==X){
      return true;
   }else{
      return SearchTree(Left(P),X)||SearchTree(Right(P),X);
   }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
   if(IsTreeEmpty(P)){
      return 0;
   }else if(IsTreeOneElmt(P)){
      return 1;
   }else{
      return 1+NbElmt(Right(P))+NbElmt(Left(P));
   }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
   if(IsTreeEmpty(P)){
      return 0;
   }else if(IsTreeOneElmt(P)){
      return 1;
   }else{
      return NbElmt(Right(P))+NbElmt(Left(P));
   }
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
   if(IsTreeEmpty(P)){
      return true;
   }else if(IsUnerRight(P) || IsBiner(P)){
      return false;
   }else{
      return IsSkewLeft(Left(P));
   }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
   if(IsTreeEmpty(P)){
      return true;
   }else if(IsUnerLeft(P) || IsBiner(P)){
      return false;
   }else{
      return IsSkewRight(Right(P));
   }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X){
   if(IsTreeOneElmt(P) && Akar(P)==X){
      return 1;
   }else if(IsTreeOneElmt(P)){
      return 0;
   }else{
      if(SearchTree(Left(P),X)){
         return 1+Level(Left(P),X);
      }else{
         return 1+Level(Right(P),X);
      }
   }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
   if(IsTreeEmpty(P)){
      return 0;
   }else{
      int a= Tinggi(Left(P));
      int b = Tinggi(Right(P));
      if(a>=b){
         return 1+a;
      }else{
         return 1+b;
      }
   }
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){
   if(IsTreeEmpty(*P)){
      (*P) = AlokNode(X);
   }else{
      BinTree A = Left(*P);
      AddDaunTerkiri(&A,X);
      Left(*P) = A;
   }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
   if(!IsTreeEmpty(*P) && Kiri){
      if(IsTreeOneElmt(*P)){
            BinTree b = AlokNode(Y);
            Left(*P) = b;
      }else{
         if(SearchTree(Left(*P),X)){
            BinTree asd = Left(*P);
            AddDaun(&asd,X,Y,Kiri);
            (*P) =  asd;
         }else{
            BinTree asd = Right(*P);
            AddDaun(&asd,X,Y,Kiri);
            (*P) =  asd;
         }
      }
      
   }else if(!IsTreeEmpty(*P)){
      if(IsTreeOneElmt(*P)){
            BinTree b = AlokNode(Y);
            Right(*P) = b;
      }else{
         if(SearchTree(Left(*P),X)){
            BinTree asd = Left(*P);
            AddDaun(&asd,X,Y,Kiri);
            (*P) =  asd;
         }else{
            BinTree asd = Right(*P);
            AddDaun(&asd,X,Y,Kiri);
            (*P) =  asd;
         }
      }
   }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X){
   if(!IsTreeOneElmt(*P) && IsTreeOneElmt(Left(*P))){
      BinTree asd = Left(*P);
      Left(*P) = Nil;
      (*X) = Akar(asd);
      DealokNode(asd);
   }else if(!IsTreeOneElmt(*P) && Left(*P)== Nil &&IsTreeOneElmt(Right(*P)))
   {
      BinTree asd = Right(*P);
      Right(*P) = Nil;
      (*X) = Akar(asd);
      DealokNode(asd);
   }else{
      if(Left(*P)==Nil){
         BinTree asd = Right(*P);
         DelDaunTerkiri(&asd,X);
         (*P) = asd;
      }else{
         BinTree asd = Left(*P);
         DelDaunTerkiri(&asd,X);
         (*P) = asd;
      }
   }
   
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X){
   if(!IsTreeEmpty(*P)&&IsTreeOneElmt(*P)&&Akar(*P)==X){
      *P = Nil;
   }else if(!IsTreeEmpty(*P) && IsTreeOneElmt(Left(*P))&&Akar(Left(*P))==X){
      Left(*P) = Nil;
   }else if(!IsTreeEmpty(*P) && IsTreeOneElmt(Right(*P))&&Akar(Right(*P))==X){
      Right(*P) = Nil;
   }else if(!IsTreeEmpty(*P)){
      BinTree asd = Right(*P);
      BinTree ase = Left(*P);
      DelDaun(&asd,X);
      DelDaun(&ase,X);
      Right(*P) = asd;
      Left(*P) = ase;
   }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
List MakeListDaun(BinTree P){
   if(IsTreeEmpty(P)){
      return Nil;
   }else if(IsTreeOneElmt(P)){
      return Alokasi(Akar(P));
   }else{
      return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
      //return Concat(Konso(Akar(P),MakeListDaun(Left(P))),Konso(Akar(P),MakeListDaun(Right(P))));
   }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P){
   if(IsTreeEmpty(P)){
      return Nil;
   }else if(IsTreeOneElmt(P)){
      return Alokasi(Akar(P));
   }else{
      //return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
      return Concat(Konso(Akar(P),MakeListDaun(Left(P))),Konso(Akar(P),MakeListDaun(Right(P))));
   }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListLevel(BinTree P, int N){
   if(IsTreeEmpty(P)){
      return Nil;
   }else if(!IsTreeEmpty(P)&&N==1){
      return Alokasi(Akar(P));
   }else{
      return Concat(MakeListLevel(Left(P),N-1),MakeListLevel(Right(P),N-1));
   }  
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X){
   if(IsTreeEmpty(P)){
      return false;
   }else if(Akar(P)==X){
      return true;
   }else{
      if(Akar(P)>X){
         return BSearch(Left(P),X);
      }else{
         return BSearch(Right(P),X);
      }
   }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X){
   
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

void DelBtree(BinTree *P, infotype X){
   
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */