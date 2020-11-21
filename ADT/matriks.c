/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(BrsMin<=i && i<=BrsMax && KolMin<=j && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(KolMin);
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(NBrsEff(M)-1+GetFirstIdxBrs(M));
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(NKolEff(M)-1+GetFirstIdxKol(M));
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(GetFirstIdxBrs(M)<=i && i<=GetLastIdxBrs(M) && GetFirstIdxKol(M)<=j && j<=GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    /*Kamus Lokal*/
    indeks i,j;
    /*Algoritma*/
    for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++)
    {
        for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++)
        {
            Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
        }
    }
    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    /*Kamus Lokal*/
    indeks i,j;
    /*Algoritma*/
    if (IsIdxValid(NB,NK))
    {
        MakeMATRIKS(NB,NK,M);
        for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
        {
            for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
            {
                scanf("%d",&Elmt(*M,i,j));
            }
        }
    }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /*Kamus Lokal*/
    indeks i,j;
    /*Algoritma*/
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            printf("%d",Elmt(M,i,j));
            if (j<GetLastIdxKol(M))
            {
                printf(" ");
            }
        }
        if (i<GetLastIdxBrs(M))
        {
            printf("\n");
        }
    }    
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    /*Kamus Lokal*/
    indeks i,j;
    MATRIKS Mout;
    /*Algoritma*/
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&Mout);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            Elmt(Mout,i,j)= Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }

    return(Mout);
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    /*Kamus Lokal*/
    indeks i,j;
    MATRIKS Mout;
    /*Algoritma*/
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&Mout);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            Elmt(Mout,i,j)= Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }
    return(Mout);
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    /*Kamus Lokal*/
    indeks i,j,k;
    MATRIKS Mout;
    ElType temp;
    /*Algoritma*/
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&Mout);
    for (i = GetFirstIdxBrs(Mout); i <= GetLastIdxBrs(Mout); i++)
    {
        for (j = GetFirstIdxKol(Mout); j <= GetLastIdxKol(Mout); j++)
        {
            temp=0;
            for (k = GetFirstIdxKol(M1); k <= GetLastIdxBrs(M2); k++)
            {
                temp += (Elmt(M1,i,k)*Elmt(M2,k,j));
            }
            Elmt(Mout,i,j)=temp;
        }
    }
    return(Mout);    
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    /*Kamus Lokal*/
    indeks i,j;
    MATRIKS Mout;
    /*Algoritma*/
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mout);
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            Elmt(Mout,i,j)= Elmt(M,i,j) * X;
        }
    }
    return(Mout);
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    /*Kamus Lokal*/
    indeks i,j;
    /*Algoritma*/
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
    {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
        {
            Elmt(*M,i,j)= Elmt(*M,i,j) * K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQMatriks (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	/*Kamus Lokal*/
	boolean result;
	indeks i, j;
	/*Algoritma*/
	result = true;
	if ((GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetLastIdxKol(M1) != GetLastIdxKol(M2)) || (NBElmt(M1) != NBElmt(M2)))
	{
		result = false;
	}
	else
	{
		i = GetFirstIdxBrs(M1);
		while (result && i<=GetLastIdxBrs(M1))
		{
            j = GetFirstIdxKol(M1);
			while (result && j<=GetLastIdxKol(M1))
			{
				if (Elmt(M1, i,j) != Elmt(M2, i, j))
				{
					result = false;
				}
				else
				{
					j++;
				}
			}
			if(result)
			{
				i++;
			}
		}
	}
	return result;
}

boolean NEQMatriks (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return(!EQMatriks(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    /*Kamus Lokal*/
    /*Algoritma*/
    return (NBrsEff(M)==NKolEff(M));    
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
    /*Kamus Lokal*/
    /*Algoritma*/
{
    /*Kamus Lokal*/
    indeks i,j;
    boolean result=true;
    /*Algoritma*/
    if (IsBujurSangkar(M))
    {
        i = GetFirstIdxBrs(M);
        while (result && (i<=GetLastIdxBrs(M)))
        {
            j = GetFirstIdxKol(M);
            while (result && (j<=GetLastIdxKol(M)))
            {
                if (Elmt(M,i,j) != Elmt(M,j,i))
                {
                    result=false;
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        result=false;
    }

    return result;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    /*Kamus Lokal*/
    indeks i,j;
    boolean result=true;
    /*Algoritma*/

    if (IsBujurSangkar(M))
    {
        i = GetFirstIdxBrs(M);
        while (result && (i<=GetLastIdxBrs(M)))
        {   
            if (Elmt(M,i,i)!=1)
            {
                result = false;
            }

            j = GetFirstIdxKol(M);
            while (result && (j<=GetLastIdxKol(M)))
            {
                if ((Elmt(M,i,j)!=0)&&(i!=j))
                {
                    result=false;
                }
                j++;
            }
            i++;
        }
    }
    else
    {
        result=false;
    }

    return result;
}   

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    /*Kamus Lokal*/
    indeks i,j;
    int jumlah=0;
    /*Algoritma*/
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            if (Elmt(M,i,j)!=0)
            {
                jumlah++;
            }
        }
    }
    return(jumlah*20 <= NBElmt(M));    
} 

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    //KaliKons(M,-1);
    /*Kamus Lokal*/
    indeks i,j;
    MATRIKS Mout;
    /*Algoritma*/
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mout);
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            Elmt(Mout,i,j)= Elmt(M,i,j) * -1;
        }
    }
    return(Mout);
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    /*Kamus Lokal*/
    indeks i,j,k;
    indeks a,b;
    float result;
    int sign;
    MATRIKS Mout;
    /*Algoritma*/
    if (NBElmt(M)==4)
    {
        result = (Elmt(M,1,1)*Elmt(M,0,0)-Elmt(M,0,1)*Elmt(M,1,0));
    }
    else if (NBElmt(M)==1)
    {
        result = Elmt(M,0,0);
    }
    else if (NBElmt(M)==0)
    {
        result = 0;
    }
    else
    {
        sign=1;
        result=0;
        for (k = GetFirstIdxBrs(M); k <= GetLastIdxBrs(M); k++)
        {
            MakeMATRIKS((NBrsEff(M)-1),NKolEff(M)-1,&Mout);
            for (i = GetFirstIdxBrs(M)+1; i <=GetLastIdxBrs(M); i++)
            {
                a=GetFirstIdxKol(Mout);
                b=i-1;
                for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
                {
                    if (!(j==k))
                    {
                        Elmt(Mout,b,a) = Elmt(M,i,j);
                        a++;
                    }
                }
            }

            result += sign * Elmt(M,GetFirstIdxBrs(M),k)*Determinan(Mout);
            sign *= -1;
        }
    }
    return result;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    //PKaliKons(M,-1);
    /*Kamus Lokal*/
    indeks i,j;
    /*Algoritma*/
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
    {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
        {
            Elmt(*M,i,j)= Elmt(*M,i,j) * -1;
        }
    }
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    /*Kamus Lokal*/
    indeks i,j;
    ElType temp;
    /*Algoritma*/
    for (i = GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++)
    {
        for (j = GetFirstIdxKol(*M); j<i; j++)
        {
            temp = Elmt(*M,i,j);
            Elmt(*M,i,j)= Elmt(*M,j,i);
            Elmt(*M,j,i)= temp;
        }
    }   
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    /*Kamus Lokal*/
    indeks j;
    float jmlh=0;
    float n,hasil;
    /*Algoritma*/
    for (j = 0; j<= GetLastIdxKol(M); j++)
    {
        jmlh += (float)Elmt(M,i,j);
    }
    n = NKolEff(M);
    hasil = jmlh/n;
    return hasil;
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    /*Kamus Lokal*/
    indeks i;
    float jmlh=0;
    float n,hasil;
    /*Algoritma*/
    for (i = 0; i<= GetLastIdxBrs(M); i++)
    {
        jmlh += (float)Elmt(M,i,j);
    }
    n = NBrsEff(M);
    hasil = jmlh/n;
    return hasil;
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    /*Kamus Lokal*/
    indeks j;
    /*Algoritma*/
    *max=Elmt(M,i,0);
    *min=Elmt(M,i,0);

    for (j = 0; j<= GetLastIdxKol(M); j++)
    {
        if (Elmt(M,i,j)>*max)
        {
            *max=Elmt(M,i,j);
        }
        if (Elmt(M,i,j)<*min)
        {
            *min=Elmt(M,i,j);
        }
    }
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    /*Kamus Lokal*/
    indeks i;
    /*Algoritma*/
    *max=Elmt(M,0,j);
    *min=Elmt(M,0,j);

    for (i = 0; i<= GetLastIdxBrs(M); i++)
    {
        if (Elmt(M,i,j)>*max)
        {
            *max=Elmt(M,i,j);
        }
        if (Elmt(M,i,j)<*min)
        {
            *min=Elmt(M,i,j);
        }
    }
}           

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    /*Kamus Lokal*/
    indeks j;
    int count=0;
    /*Algoritma*/
    for (j = 0; j<= GetLastIdxKol(M); j++)
    {
        if (Elmt(M,i,j)==X)
        {
            count++;
        }
    }
    return count;
} 

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    /*Kamus Lokal*/
    indeks i;
    int count=0;
    /*Algoritma*/
    for (i = 0; i<= GetLastIdxBrs(M); i++)
    {
        if (Elmt(M,i,j)==X)
        {
            count++;
        }
    }
    return count;
} 
