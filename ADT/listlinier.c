#include<stdio.h>
#include"boolean.h"
#include"listlinier.h"
#include<stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL (ListLL L){
	return FirstLL(L)==NULL;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLL (ListLL *L){
	FirstLL(*L) =NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address1 AlokasiLL (infotype X){
	LLElmtList * Elis;
	Elis = (LLElmtList *) malloc(sizeof(LLElmtList));
	if(Elis==NULL){
		return NULL;
	}else{
		InfoLL(Elis) = X;
		NextLL(Elis) = NULL;
		return Elis;
	}
	
}
/* Mengirimkan address1 hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address1 tidak NULL, dan misalnya */
/* menghasilkan P, maka InfoLL(P)=X, NextLL(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void DealokasiLL (address1 *P){
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address1 P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address1 SearchLL (ListLL L, infotype X){
	address1 adr;
	boolean flag;
	adr = FirstLL(L);
	flag = false;
	while(adr!=NULL && flag == false){
		if(InfoLL(adr)==X){flag=true;}
		else{
			adr = NextLL(adr);
		}
	}
	if(flag){
		return adr;
	}else{
		return NULL;
	}
}
/* Mencari apakah ada elemen list dengan InfoLL(P)= X */
/* Jika ada, mengirimkan address1 elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
boolean FSearch (ListLL L, address1 P){
    infotype X = InfoLL(P);
    address1 a = SearchLL(L,X);
    if(a!=NULL && a==P){
        return true;
    }else
    {
        return false;
    }
    
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
address1 SearchPrec (ListLL L, infotype X){
    if(InfoLL(FirstLL(L))==X || NbElmtLL(L)<=1){
        return NULL;
    }else
    {
        address1 a = FirstLL(L);
        boolean flag = false;
        while (NextLL(a)!=NULL && flag==false)
        {
            address1 b = NextLL(a);
            if(InfoLL(b)==X){
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
/* Mengirimkan address1 elemen sebelum elemen yang NULLainya=X */
/* Mencari apakah ada elemen list dengan InfoLL(P)=X */
/* Jika ada, mengirimkan address1 Prec, dengan NextLL(Prec)=P dan InfoLL(P)=X. */
/* Jika tidak ada, mengirimkan NULL */
/* Jika P adalah elemen pertama, maka Prec=NULL */
/* SearchLL dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah SearchLL akan dilakukan operasi lain */

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListLL *L, infotype X){
	address1 a = AlokasiLL(X);
	if(a!=NULL){
		NextLL(a) = FirstLL(*L);
		FirstLL(*L) = a;		
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
void InsVLast (ListLL *L, infotype X){
	address1 a = AlokasiLL(X);
	if(a!=NULL){
		InsertLast(L,a);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListLL *L, infotype *X){
	if(FirstLL(*L)!=NULL){
		address1 x;
		DelFirst(L,&x);
		(*X) = InfoLL(x);
	}
}
/* I.S. ListLL L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListLL *L, infotype *X){
	if(FirstLL(*L)!=NULL){
		address1 a1;
		DelLast(L,&a1);
		(*X) = InfoLL(a1);
	}
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListLL *L, address1 P){
	NextLL(P) = FirstLL(*L);
	FirstLL(*L) = P;
 }
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address1 P sebagai elemen pertama */
void InsertAfter (ListLL *L, address1 P, address1 Prec){
	address1 a = FirstLL(*L);
	address1 b = FirstLL(*L);
	if (SearchLL(*L,InfoLL(Prec))!=NULL && NbElmtLL(*L)>0){
		while(a!=NULL && a!=Prec){
		a = NextLL(a);
		}
		NextLL(P) = NextLL(a);
		NextLL(a) = P;
	}
	

}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (ListLL *L, address1 P){
	NextLL(P) = NULL;
	if(FirstLL(*L) ==NULL){
		FirstLL(*L) = P;
	}else{
		address1 a = FirstLL(*L);
		address1 b = FirstLL(*L);
		while (b!=NULL)
		{
			a=b;
			b = NextLL(b);
		}
		
		NextLL(a) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListLL *L, address1 *P){
	if(FirstLL(*L)!=NULL){
		(*P) = FirstLL(*L);
		FirstLL(*L) = NextLL(FirstLL(*L));
	}
}
/* I.S. ListLL tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* FirstLL element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListLL *L, infotype X){
	if(NbElmtLL(*L)>1){
		if(InfoLL(FirstLL(*L))==X){
			address1 ad = FirstLL(*L);
			FirstLL(*L) = NextLL(FirstLL(*L));
			DealokasiLL(&ad);
		}else if(SearchLL(*L,X)!=NULL){
			address1 ad = FirstLL(*L);
			address1 uy;
			while (ad!=SearchLL(*L,X))
			{
				if(NextLL(ad)==SearchLL(*L,X)){
					uy = ad;
				}
				ad = NextLL(ad);
			}
			NextLL(uy) = NextLL(SearchLL(*L,X));
			DealokasiLL(&ad);
			
		}
		
	}else if(NbElmtLL(*L)==1){
		if(InfoLL(FirstLL(*L))==X){
			address1 ad = FirstLL(*L);
			FirstLL(*L) = NULL;
			DealokasiLL(&ad);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan InfoLL(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan InfoLL berNULLai X */
/* maka yang dihapus hanya elemen pertama dengan InfoLL = X */
/* Jika tidak ada elemen list dengan InfoLL(P)=X, maka list tetap */
/* ListLL mungkin menjadi kosong karena penghapusan */
void DelLast (ListLL *L, address1 *P){
	if(NbElmtLL(*L)>2){
		address1 a = FirstLL(*L);
		address1 b= NextLL(a);
		if(b==NULL){
			(*P) = a;
			FirstLL(*L) = NULL;
		}else{
			a = b;
			b = NextLL(a);
			while (b!=NULL)
			{
				if(NextLL(b)!=NULL){
					a = b;
					b = NextLL(a);
				}	else{
					b = NextLL(b);
				}
			}
			(*P) = NextLL(a);
			NextLL(a)= NULL;
			
		}
		
	}else if(NbElmtLL(*L)==2){
		address1 a;
		a = FirstLL(*L);
		(*P) = NextLL(a);
		NextLL(FirstLL(*L))=NULL;
	}else if(NbElmtLL(*L)==1){
		(*P) = FirstLL(*L);
		FirstLL(*L) = NULL;
	}

}
/* I.S. ListLL tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListLL *L, address1 *Pdel, address1 Prec){
	if(!IsEmptyLL(*L) && SearchLL(*L,InfoLL(Prec))!=NULL){
		address1  a = FirstLL(*L);
		address1 b = NextLL(a);
		boolean flag = false;
		if(b!=NULL){
			if(a==Prec){
				(*Pdel) = NextLL(a);
				NextLL(a) = NextLL(b);
			}else{
				while (b!=NULL && flag==false)
				{
					a=b;
					b = NextLL(b);
					if(a==Prec){
						flag=true;
					}
				}

				if(flag && b!=NULL){
					(*Pdel) = NextLL(a);
					NextLL(a) = NextLL(b);
				}
			}
			
		}
		
		
	}
}
/* I.S. ListLL tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus NextLL(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (ListLL L){
	address1 a = FirstLL(L);
	if(a==NULL){
		printf("[]");
	}else{
		printf("[");
		int c = 0;
		while(a!=NULL){
			c++;
			if(c==NbElmtLL(L)){
				printf("%d",InfoLL(a));
			}else{
				printf("%d,",InfoLL(a));
			}
			a = NextLL(a);
		}
		printf("]");
	}
}
/* I.S. ListLL mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int NbElmtLL (ListLL L){
	address1 a = FirstLL(L);
	if(a==NULL){
		return 0;
	}else{
		int c = 0;
		while(a!=NULL){
			c++;
			a = NextLL(a);
		}
		return c;
	}
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : ListLL tidak kosong ***/
/*** Prekondisi untuk Max: ListLL tidak kosong ***/
infotype Max (ListLL L){
	infotype max = 0;
	if(FirstLL(L)!=NULL){
		address1 a = FirstLL(L);
		max = InfoLL(a);
		a = NextLL(a);
		while (a!=NULL)
		{
			if(InfoLL(a)>=max){
				max = InfoLL(a);
			}
			a = NextLL(a);
		}
		
	}
	return max;
}
/* Mengirimkan NULLai InfoLL(P) yang maksimum */
address1 AdrMax (ListLL L){
    if(NbElmtLL(L)>0){
        infotype x = Max(L);
        return SearchLL(L,x);
    }else{
        return NULL;
    }
}
/* Mengirimkan address1 P, dengan info(P) yang berNULLai maksimum */
/*** Prekondisi untuk Min: ListLL tidak kosong ***/
infotype Min (ListLL L){
	infotype min = 0;	
	if(FirstLL(L)!=NULL){
		address1 a = FirstLL(L);
		min = InfoLL(a);
		a = NextLL(a);
		while(a!=NULL){
			if(InfoLL(a)<=min){
				min = InfoLL(a);
			}
			a = NextLL(a);
		}
	}
	return min;
}
/* Mengirimkan NULLai InfoLL(P) yang minimum */
address1 AdrMin (ListLL L){
    if(NbElmtLL(L)>0){
        infotype x = Min(L);
        return SearchLL(L,x);
    }else{
        return NULL;
    }
}
/* Mengirimkan address1 P, dengan info(P) yang berNULLai minimum */
float Average (ListLL L){
    infotype a = NbElmtLL(L);
    address1 x = FirstLL(L);
    infotype sum = 0;
    if(a>0){
        while (x!=NULL)
        {
            sum = sum + InfoLL(x);
            x = NextLL(x);
        }
        float ret = (float)sum/(float)a;
        return ret;
    }else{
        return 0;
    }
}
/* Mengirimkan NULLai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/
void DelAll (ListLL *L){
    int jmlh = NbElmtLL(*L);
    while (jmlh>0)
    {
        infotype max = Max(*L);
        DelP(L,max);
        jmlh = NbElmtLL(*L);
    }
    
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void InversList (ListLL *L){
    ListLL newlist;
    newlist = (*L);
    newlist = FInversList(newlist);
    FirstLL(*L) = FirstLL(newlist);
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

ListLL FInversList (ListLL L){
    ListLL newlist;
    CreateEmptyLL(&newlist);
    address1 adr = FirstLL(L);
    while (adr!=NULL)
    {
        InsertFirst(&newlist,adr);
        adr = NextLL(adr);
    }
    
    return newlist;
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. AlokasiLL mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CopyList (ListLL *L1, ListLL *L2){
    CreateEmptyLL(L2);
    address1 a = FirstLL(*L1);
    while (a!=NULL)
    {
        InsertLast(L2,a);
        a = NextLL(a);
    }
    
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

ListLL FCopyList (ListLL L){
    ListLL newlist;
    CreateEmptyLL(&newlist);
    address1 adr = FirstLL(L);
    while (adr!=NULL)
    {
        InsVLast(&newlist,InfoLL(adr));
        adr = NextLL(adr);
    }
    
    return newlist;
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CpAlokList (ListLL Lin, ListLL *Lout){
    CreateEmptyLL(Lout);
    address1 a = FirstLL(Lin);
    while (a!=NULL)
    {
        InsVLast(Lout,InfoLL(a));
        a =NextLL(a);
    }

    if(NbElmtLL(Lin)!=NbElmtLL(*Lout)){
        FirstLL(*Lout) = NULL;
    }
    

}
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=NULL dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

void Konkat (ListLL L1, ListLL L2, ListLL * L3){
    CreateEmptyLL(L3);
	address1 a = FirstLL(L1);

	while (a!=NULL)
	{
		InsVLast(L3,InfoLL(a));
		a=NextLL(a);
	}
	
	a = FirstLL(L2);
	while (a!=NULL)
	{
		InsVLast(L3,InfoLL(a));
		a=NextLL(a);
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

void Konkat1 (ListLL *L1, ListLL *L2, ListLL *L3){
	CreateEmptyLL(L3);
	address1 a = FirstLL(*L1);
	// while(a!=NULL){
	// 	InsertLast(L3,a);
	// 	a = NextLL(a);
	// }

	// a = FirstLL(*L2);
	// while(a!=NULL){
	// 	InsertLast(L3,a);
	// 	a = NextLL(a);
	// }

	while (a!=NULL)
	{
		InsVLast(L3,InfoLL(a));
		a=NextLL(a);
	}
	
	a = FirstLL(*L2);
	while (a!=NULL)
	{
		InsVLast(L3,InfoLL(a));
		a=NextLL(a);
	}

	FirstLL(*L1) = NULL;
	FirstLL(*L2) = NULL;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList (ListLL *L1, ListLL *L2, ListLL L){
    address1 a = FirstLL(L);
    int mid = NbElmtLL(L)/2;
    if(NbElmtLL(L)==0){
         CreateEmptyLL(L1);CreateEmptyLL(L2);
    }else{
        CreateEmptyLL(L1);CreateEmptyLL(L2);
        while (NbElmtLL(*L1)<mid)
        {
            InsVLast(L1,InfoLL(a));
            a=NextLL(a);
        }

        while (a!=NULL)
        {
            InsVLast(L2,InfoLL(a));
            a=NextLL(a);
        }
    }
    
    
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmtLL(L) div 2 */
