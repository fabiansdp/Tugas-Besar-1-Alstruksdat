#include<stdio.h>
#include<stdlib.h>
#include"../boolean.h"
#include"../listrek/listrek.h"
#include"bintree.h"


//Hafid Abi Daniswara
//13519028

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NULL) jika alokasi gagal */
   {Node * pohon;
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

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = NULL jika alokasi gagal. */
{
   (*P) = Tree(Akar,L,R);
}

BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, NULLai setiap node dibaca */
/* Jika n == 0, kembalikan NULL.
   Mula-mula, baca NULLai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin). 
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */
{
   addrNode nod;
   int aselole;
   if(n==0){
      return NULL;
   }else{
      scanf("%d",&aselole);
      nod = AlokNode(aselole);
      if(nod==NULL){
         return NULL;
      }else{
         int L = n/2;
         int R = n - L -1;

         BinTree kiri = BuildBalanceTree(L);
         BinTree kanan = BuildBalanceTree(R);
         
         Left(nod) = kiri;
         Right(nod) = kanan;
         return nod;
      }
   }
}

/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NULL, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = NULL, Right(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
   Node * N;
   N = (Node *) malloc(sizeof(Node));
   if(N!=NULL){
      Akar(N) = X;
      Left(N) = NULL;
      Right(N) = NULL;
      return N;
   }else{
      return NULL;
   }
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
   free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
   return P==NULL;
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
   return P!=NULL && Right(P)==NULL && Left(P)==NULL;
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
   return !IsTreeEmpty(P) && Right(P)==NULL && Left(P)!=NULL;
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
   return !IsTreeEmpty(P) && Right(P)!=NULL && Left(P)==NULL;
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
   return !IsTreeEmpty(P) && Right(P)!= NULL && Left(P)!=NULL;
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
   if(IsTreeEmpty(P)){
      printf("()");
   }else{
      printf("(%d",Akar(P));
      PrintPreorder(Left(P));
      PrintPreorder(Right(P));
      printf(")");
   }
}

void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
   if(IsTreeEmpty(P)){
      printf("()");
   }else{
      printf("(");
      PrintInorder(Left(P));
      printf("%d",Akar(P));
      PrintInorder(Right(P));
      printf(")");
   }
}

void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
   if(IsTreeEmpty(P)){
      printf("()");
   }else{
      printf("(");
      PrintPostorder(Left(P));
      PrintPostorder(Right(P));
      printf("%d)",Akar(P));
   }
}

void HelpPT(BinTree P, int h, int c){
   if(!IsTreeEmpty(P)){
      int x;
      for(x=0;x<h*c;x++){
         printf(" ");
      }
      printf("%d %d %d %d",Akar(P),P->harga,P->Kapasitas,P->durasi);
      if(P->isApplied){
         printf(" ACTIVE ");
      }else{
         printf(" NOT-ACT ");
      }
      int aha;
      for(aha=0;aha<P->detail.Length;aha++){
         printf("%c",P->detail.TabKata[aha]);
      }
      printf("\n");
      
      HelpPT(Left(P),h,c+1);
      HelpPT(Right(P),h,c+1);
   }
}

void PrintTree(BinTree P, int h)
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
{
   HelpPT(P,h,0);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang berNULLai X */
{
   if(IsTreeEmpty(P)){
      return false;
   }else if(Akar(P)==X){
      return true;
   }else{
      return SearchTree(Left(P),X)|SearchTree(Right(P),X);
   }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
   if(IsTreeEmpty(P)){
      return 0;
   }else if(IsTreeOneElmt(P)){
      return 1;
   }else{
      return 1+NbElmt(Right(P))+NbElmt(Left(P));
   }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
{
   if(IsTreeEmpty(P)){
      return 0;
   }else if(IsTreeOneElmt(P)){
      //printf("%d ",Akar(P));
      return 1;
   }else{
      return NbDaun(Right(P))+NbDaun(Left(P));
   }
}

/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
   if(IsTreeEmpty(P)){
      return true;
   }else if(IsUnerRight(P) | IsBiner(P)){
      return false;
   }else{
      return IsSkewLeft(Left(P));
   }
}

boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
   if(IsTreeEmpty(P)){
      return true;
   }else if(IsUnerLeft(P) | IsBiner(P)){
      return false;
   }else{
      return IsSkewRight(Right(P));
   }
}

int Level(BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
   if(Akar(P)==X){
      return 1;
   }else{
      if(SearchTree(Left(P),X)){
         return 1+Level(Left(P),X);
      }else{
         return 1+Level(Right(P),X);
      }
   }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
   if(IsTreeEmpty(P)){
      return 0;
   }else{
      if(Tinggi(Left(P))>=Tinggi(Right(P))){
         return 1+Tinggi(Left(P));
      }else{
         return 1+Tinggi(Right(P));
      }
   }
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
   if(IsTreeEmpty(*P)){
      (*P) =  Tree(X,NULL,NULL);
   }else{
      AddDaunTerkiri(&Left(*P),X);
   }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun berNULLai X, diambil daun yang paling kiri */
{
   if(IsTreeOneElmt(*P)){
      if(!Kiri){
         Right(*P) = Tree(Y,NULL,NULL);
      }else{
         Left(*P) = Tree(Y,NULL,NULL);
      }
   }else{
      if(SearchTree(Left(*P),X)){
         AddDaun(&Left(*P),X,Y,Kiri);
      }else{
         AddDaun(&Right(*P),X,Y,Kiri);
      }
   }
}

void DelDaunTerkiri(BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
   if(IsTreeOneElmt(*P)){
      (*X) = Akar(*P);
      (*P) = NULL;
      addrNode d = (*P);
      DealokNode(d);
   }else if (IsUnerRight(*P)){
      DelDaunTerkiri(&Right(*P),X);
   }else{
      DelDaunTerkiri(&Left(*P),X);
   }
   
}

void DelDaun(BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun berNULLai X. */
/* F.S. Semua daun berNULLai X dihapus dari P. */
{
   if(!IsTreeEmpty(*P) && IsTreeOneElmt(*P) && Akar(*P)==X){
      (*P) =NULL;
   }else if (!IsTreeEmpty(*P)){
      if(SearchTree(Left(*P),X)){
         DelDaun(&Left(*P),X);
      }
      if(SearchTree(Right(*P),X)){
         DelDaun(&Right(*P),X);
      }
   }
}

List MakeListDaun(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
   if(IsTreeEmpty(P)){
      return NULL;
   }else if(IsTreeOneElmt(P)){
      return Alokasi(Akar(P));
   }else{
      return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
      //return Concat(Konso(Akar(P),MakeListDaun(Left(P))),Konso(Akar(P),MakeListDaun(Right(P))));
   }
}

List MakeListPreorder(BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
   if(IsTreeEmpty(P)){
      return NULL;
   }else{
      //return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
      return Concat(Konso(Akar(P),MakeListPreorder(Left(P))),MakeListPreorder(Right(P)));
   }
}

List MakeListLevel(BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
   if(IsTreeEmpty(P)){
      return NULL;
   }else if(!IsTreeEmpty(P)&&N==1){
      return Alokasi(Akar(P));
   }else{
      return Concat(MakeListLevel(Left(P),N-1),MakeListLevel(Right(P),N-1));
   }  
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang berNULLai X */
{
   if(Akar(P)==X){
      return true;
   }else{
      return SearchTree(Left(P),X)|SearchTree(Right(P),X);
   }
}


void InsSearch(BinTree *P, infotype X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang berNULLai X. */
{
   if (IsTreeEmpty(*P)){
      MakeTree(X,NULL,NULL,P);
   }else if(X<Akar(*P)){
      InsSearch(&Left(*P),X);
   }else{
      InsSearch(&Right(*P),X);
   }
}

void DnD(BinTree * P){
   if(!IsTreeEmpty(Right(*P))){
      DnD(&Right(*P));
   }else{
      addrNode asd;
      asd = (*P);
      (*P) = Left(*P);
   }
}

void DelBtree(BinTree *P, infotype X)
/* I.S. Pohon P tidak  kosong */
/* F.S. NULLai X yang dihapus pasti ada */
/* Sebuah node dengan NULLai X dihapus */
{
   addrNode AAA;
   if(Akar(*P)>X){
      DelBtree(&Left(*P),X);
   }else if(Akar(*P)<X){
      DelBtree(&Right(*P),X);
   }else{
      addrNode q = Tree(Akar(*P),Left(*P),Right(*P));
      if(IsTreeOneElmt(*P)){
         (*P) = NULL;
      }else if(IsUnerLeft(*P)){
         (*P) = Left(*P);
      }else if(IsUnerRight(*P)){
         (*P) = Right(*P);
      }else if(IsBiner(*P)){
         AAA = *P;
         *P = Left(AAA);
         Right(*P) = Right(AAA);
      }
   }
}
