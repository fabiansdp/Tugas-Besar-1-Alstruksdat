#include<stdio.h>
#include"boolean.h"
#include"listlinier.h"
#include<stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return First(L)==NULL;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) =NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
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
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void Dealokasi (address *P){
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address adr;
	boolean flag;
	adr = First(L);
	flag = false;
	while(adr!=NULL && flag == false){
		if(Info(adr)==X){flag=true;}
		else{
			adr = Next(adr);
		}
	}
	if(flag){
		return adr;
	}else{
		return NULL;
	}
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
boolean FSearch (List L, address P){
    infotype X = Info(P);
    address a = Search(L,X);
    if(a!=NULL && a==P){
        return true;
    }else
    {
        return false;
    }
    
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
address SearchPrec (List L, infotype X){
    if(Info(First(L))==X || NbElmt(L)<=1){
        return NULL;
    }else
    {
        address a = First(L);
        boolean flag = false;
        while (Next(a)!=NULL && flag==false)
        {
            address b = Next(a);
            if(Info(b)==X){
                flag = true;
            }else{
                a = b;
            }
        }
        if(flag){
            return a;
        }else{
            return NULL;
        }
        
    }
    

}
/* Mengirimkan address elemen sebelum elemen yang NULLainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan NULL */
/* Jika P adalah elemen pertama, maka Prec=NULL */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address a = Alokasi(X);
	if(a!=NULL){
		Next(a) = First(*L);
		First(*L) = a;		
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address a = Alokasi(X);
	if(a!=NULL){
		InsertLast(L,a);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	if(First(*L)!=NULL){
		address x;
		DelFirst(L,&x);
		(*X) = Info(x);
	}
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	if(First(*L)!=NULL){
		address a1;
		DelLast(L,&a1);
		(*X) = Info(a1);
	}
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	First(*L) = P;
 }
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
	address a = First(*L);
	address b = First(*L);
	if (Search(*L,Info(Prec))!=NULL && NbElmt(*L)>0){
		while(a!=NULL && a!=Prec){
		a = Next(a);
		}
		Next(P) = Next(a);
		Next(a) = P;
	}
	

}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
	Next(P) = NULL;
	if(First(*L) ==NULL){
		First(*L) = P;
	}else{
		address a = First(*L);
		address b = First(*L);
		while (b!=NULL)
		{
			a=b;
			b = Next(b);
		}
		
		Next(a) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	if(First(*L)!=NULL){
		(*P) = First(*L);
		First(*L) = Next(First(*L));
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	if(NbElmt(*L)>1){
		if(Info(First(*L))==X){
			address ad = First(*L);
			First(*L) = Next(First(*L));
			Dealokasi(&ad);
		}else if(Search(*L,X)!=NULL){
			address ad = First(*L);
			address uy;
			while (ad!=Search(*L,X))
			{
				if(Next(ad)==Search(*L,X)){
					uy = ad;
				}
				ad = Next(ad);
			}
			Next(uy) = Next(Search(*L,X));
			Dealokasi(&ad);
			
		}
		
	}else if(NbElmt(*L)==1){
		if(Info(First(*L))==X){
			address ad = First(*L);
			First(*L) = NULL;
			Dealokasi(&ad);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNULLai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
	if(NbElmt(*L)>2){
		address a = First(*L);
		address b= Next(a);
		if(b==NULL){
			(*P) = a;
			First(*L) = NULL;
		}else{
			a = b;
			b = Next(a);
			while (b!=NULL)
			{
				if(Next(b)!=NULL){
					a = b;
					b = Next(a);
				}	else{
					b = Next(b);
				}
			}
			(*P) = Next(a);
			Next(a)= NULL;
			
		}
		
	}else if(NbElmt(*L)==2){
		address a;
		a = First(*L);
		(*P) = Next(a);
		Next(First(*L))=NULL;
	}else if(NbElmt(*L)==1){
		(*P) = First(*L);
		First(*L) = NULL;
	}

}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
	if(!IsEmpty(*L) && Search(*L,Info(Prec))!=NULL){
		address  a = First(*L);
		address b = Next(a);
		boolean flag = false;
		if(b!=NULL){
			if(a==Prec){
				(*Pdel) = Next(a);
				Next(a) = Next(b);
			}else{
				while (b!=NULL && flag==false)
				{
					a=b;
					b = Next(b);
					if(a==Prec){
						flag=true;
					}
				}

				if(flag && b!=NULL){
					(*Pdel) = Next(a);
					Next(a) = Next(b);
				}
			}
			
		}
		
		
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	address a = First(L);
	if(a==NULL){
		printf("[]");
	}else{
		printf("[");
		int c = 0;
		while(a!=NULL){
			c++;
			if(c==NbElmt(L)){
				printf("%d",Info(a));
			}else{
				printf("%d,",Info(a));
			}
			a = Next(a);
		}
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int NbElmt (List L){
	address a = First(L);
	if(a==NULL){
		return 0;
	}else{
		int c = 0;
		while(a!=NULL){
			c++;
			a = Next(a);
		}
		return c;
	}
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L){
	infotype max = 0;
	if(First(L)!=NULL){
		address a = First(L);
		max = Info(a);
		a = Next(a);
		while (a!=NULL)
		{
			if(Info(a)>=max){
				max = Info(a);
			}
			a = Next(a);
		}
		
	}
	return max;
}
/* Mengirimkan NULLai Info(P) yang maksimum */
address AdrMax (List L){
    if(NbElmt(L)>0){
        infotype x = Max(L);
        return Search(L,x);
    }else{
        return NULL;
    }
}
/* Mengirimkan address P, dengan info(P) yang berNULLai maksimum */
/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L){
	infotype min = 0;	
	if(First(L)!=NULL){
		address a = First(L);
		min = Info(a);
		a = Next(a);
		while(a!=NULL){
			if(Info(a)<=min){
				min = Info(a);
			}
			a = Next(a);
		}
	}
	return min;
}
/* Mengirimkan NULLai Info(P) yang minimum */
address AdrMin (List L){
    if(NbElmt(L)>0){
        infotype x = Min(L);
        return Search(L,x);
    }else{
        return NULL;
    }
}
/* Mengirimkan address P, dengan info(P) yang berNULLai minimum */
float Average (List L){
    infotype a = NbElmt(L);
    address x = First(L);
    infotype sum = 0;
    if(a>0){
        while (x!=NULL)
        {
            sum = sum + Info(x);
            x = Next(x);
        }
        float ret = (float)sum/(float)a;
        return ret;
    }else{
        return 0;
    }
}
/* Mengirimkan NULLai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L){
    int jmlh = NbElmt(*L);
    while (jmlh>0)
    {
        infotype max = Max(*L);
        DelP(L,max);
        jmlh = NbElmt(*L);
    }
    
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void InversList (List *L){
    List newlist;
    newlist = (*L);
    newlist = FInversList(newlist);
    First(*L) = First(newlist);
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

List FInversList (List L){
    List newlist;
    CreateEmpty(&newlist);
    address adr = First(L);
    while (adr!=NULL)
    {
        InsertFirst(&newlist,adr);
        adr = Next(adr);
    }
    
    return newlist;
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CopyList (List *L1, List *L2){
    CreateEmpty(L2);
    address a = First(*L1);
    while (a!=NULL)
    {
        InsertLast(L2,a);
        a = Next(a);
    }
    
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

List FCopyList (List L){
    List newlist;
    CreateEmpty(&newlist);
    address adr = First(L);
    while (adr!=NULL)
    {
        InsVLast(&newlist,Info(adr));
        adr = Next(adr);
    }
    
    return newlist;
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CpAlokList (List Lin, List *Lout){
    CreateEmpty(Lout);
    address a = First(Lin);
    while (a!=NULL)
    {
        InsVLast(Lout,Info(a));
        a =Next(a);
    }

    if(NbElmt(Lin)!=NbElmt(*Lout)){
        First(*Lout) = NULL;
    }
    

}
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=NULL dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

void Konkat (List L1, List L2, List * L3){
    CreateEmpty(L3);
	address a = First(L1);

	while (a!=NULL)
	{
		InsVLast(L3,Info(a));
		a=Next(a);
	}
	
	a = First(L2);
	while (a!=NULL)
	{
		InsVLast(L3,Info(a));
		a=Next(a);
	}
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=NULL*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus berNULLai NULL*/
/* dan semua elemen yang pernah dialokasi didealokasi */

void Konkat1 (List *L1, List *L2, List *L3){
	CreateEmpty(L3);
	address a = First(*L1);
	// while(a!=NULL){
	// 	InsertLast(L3,a);
	// 	a = Next(a);
	// }

	// a = First(*L2);
	// while(a!=NULL){
	// 	InsertLast(L3,a);
	// 	a = Next(a);
	// }

	while (a!=NULL)
	{
		InsVLast(L3,Info(a));
		a=Next(a);
	}
	
	a = First(*L2);
	while (a!=NULL)
	{
		InsVLast(L3,Info(a));
		a=Next(a);
	}

	First(*L1) = NULL;
	First(*L2) = NULL;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList (List *L1, List *L2, List L){
    address a = First(L);
    int mid = NbElmt(L)/2;
    if(NbElmt(L)==0){
         CreateEmpty(L1);CreateEmpty(L2);
    }else{
        CreateEmpty(L1);CreateEmpty(L2);
        while (NbElmt(*L1)<mid)
        {
            InsVLast(L1,Info(a));
            a=Next(a);
        }

        while (a!=NULL)
        {
            InsVLast(L2,Info(a));
            a=Next(a);
        }
    }
    
    
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
