/**
 * NIM       : 13519112
 * Nama      : Pratama Andiko
 * file      : matriks.c
 */

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
   NBrsEff(*M) = NB;
   NKolEff(*M) = NK;
   for (int i = 0; i < NB; i++)
   {
      for (int j = 0; j < NK; j++)
      {
         Elmt(*M, i, j) = 0;
      }
   }
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
   return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
   return BrsMin;
}
indeks GetFirstIdxKol(MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
   return KolMin;
}
indeks GetLastIdxBrs(MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
   return (NBrsEff(M) - 1);
}
indeks GetLastIdxKol(MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
   return (NKolEff(M) - 1);
}
boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
   return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal(MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
   return Elmt(M, i, i);
}
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
/* Melakukan assignment MHsl  MIn */
{
   MATRIKS M;
   MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), &M);
   for (int i = 0; i <= GetLastIdxBrs(MIn); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(MIn); j++)
      {
         Elmt(M, i, j) = Elmt(MIn, i, j);
      }
   }
   *MHsl = M;
}
/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
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
   MakeMATRIKS(NB, NK, M);

   int i, j;
   for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
   {
      for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
      {
         scanf("%d", &(M->Mem[i][j]));
      }
   }
}
void TulisMATRIKS(MATRIKS M)
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
   int i, j;
   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
   {
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
      {
         printf((
                    (j != GetLastIdxKol(M)) ? "%d " : ((i != GetLastIdxBrs(M)) ? "%d\n" : "%d")),
                M.Mem[i][j]);
      }
   }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS(MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
   MATRIKS newM;
   MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &newM);
   for (int i = 0; i <= GetLastIdxBrs(M1); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(M1); j++)
      {
         Elmt(newM, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
      }
   }
   return newM;
}
MATRIKS KurangMATRIKS(MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
   MATRIKS newM;
   MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &newM);
   for (int i = 0; i <= GetLastIdxBrs(M1); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(M1); j++)
      {
         Elmt(newM, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
      }
   }
   return newM;
}
MATRIKS KaliMATRIKS(MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
   MATRIKS M;
   MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
   for (int i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
   {
      for (int j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++)
      {
         for (int k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++)
         {
            Elmt(M, i, j) += (Elmt(M1, i, k) * Elmt(M2, k, j));
         }
      }
   }
   return M;
}
MATRIKS KaliKons(MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
   MATRIKS newM;
   MakeMATRIKS(NBrsEff(M), NKolEff(M), &newM);
   for (int i = GetFirstIdxBrs(newM); i <= GetLastIdxBrs(newM); i++)
   {
      for (int j = GetFirstIdxKol(newM); j <= GetLastIdxKol(newM); j++)
      {
         Elmt(newM, i, j) = Elmt(M, i, j) * X;
      }
   }
   return newM;
}
void PKaliKons(MATRIKS *M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
   MATRIKS newM = KaliKons(*M, K);
   *M = newM;
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ(MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
   boolean equal = true;
   for (int i = 0; i <= GetLastIdxBrs(M1); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(M1); j++)
      {
         if (Elmt(M1, i, j) != Elmt(M2, i, j))
         {
            equal = false;
         }
      }
   }
   return (NBElmt(M1) == NBElmt(M2) && equal);
}
boolean NEQ(MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
   return !EQ(M1, M2);
}
boolean EQSize(MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
   return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}
/* ********** Operasi lain ********** */
int NBElmt(MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
   return (NKolEff(M) * NBrsEff(M));
}
/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar(MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
   return (NKolEff(M) == NBrsEff(M));
}
boolean IsSimetri(MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
   boolean simetri = true;
   for (int i = 0; i <= GetLastIdxBrs(M); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(M); j++)
      {
         if (Elmt(M, i, j) != Elmt(M, j, i))
         {
            simetri = false;
         }
      }
   }
   return (IsBujurSangkar(M) && simetri);
}
boolean IsSatuan(MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
   boolean satuan = true;
   for (int i = 0; i <= GetLastIdxBrs(M); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(M); j++)
      {
         if (GetElmtDiagonal(M, i) != 1 || Elmt(M, i, j) != 0)
         {
            satuan = false;
         }
      }
   }
   return (IsBujurSangkar(M) && satuan);
}
boolean IsSparse(MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
   int count;
   for (int i = 0; i <= GetLastIdxBrs(M); i++)
   {
      for (int j = 0; j <= GetLastIdxKol(M); j++)
      {
         if (Elmt(M, i, j) != 0)
         {
            count++;
         }
      }
   }
   return (count <= (NBElmt(M) / 20));
}
MATRIKS Inverse1(MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
   return KaliKons(M, -1);
}
float Determinan(MATRIKS M)
{
   int size = NBrsEff(M);
   float m[size][size];
   int i, j;

   for (i = 0; i < size; i++)
   {
      for (j = 0; j < size; j++)
      {
         m[i][j] = Elmt(M, i, j);
      }
   }

   float result = 1;
   int swapped = 0;

   while (size > 0)
   {
      boolean swap = false;
      i = 0;
      if (m[size - 1][size - 1] == 0)
      {
         while (i < (size - 1) && (!swap))
         {
            if (m[i][size - 1] == 0)
            {
               i++;
            }
            else
            {
               swap = true;
            }
         }
      }
      if (i == (size - 1) && (size > 1))
      {
         return 0;
      }
      else if (swap)
      {
         for (j = 0; j < size; j++)
         {
            float temp = m[size - 1][j];
            m[size - 1][j] = m[i][j];
            m[i][j] = temp;
         }
      }
      for (i = 0; i < (size - 1); i++)
      {
         for (j = 0; j < size; j++)
         {
            m[i][j] -= m[size - 1][j] * (m[i][size - 1] / m[size - 1][size - 1]);
         }
      }
      result *= m[size - 1][size - 1];
      swapped = (swapped + (swap ? 1 : 0)) % 2;
      size--;
   }
   float finalresult = (result * (swapped == 0 ? 1.0f : -1.0f));
   return ((finalresult < 0.5f && finalresult > -0.5f) ? 0.0f : finalresult);
}
void PInverse1(MATRIKS *M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
   MATRIKS newM;
   MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &newM);
   newM = *M;
   Inverse1(newM);
   *M = newM;
}
void Transpose(MATRIKS *M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
   MATRIKS MNew;
   MakeMATRIKS(M->NBrsEff, M->NKolEff, &MNew);

   int i, j;
   for (i = GetFirstIdxBrs(MNew); i <= GetLastIdxBrs(MNew); i++)
   {
      for (j = GetFirstIdxKol(MNew); j <= GetLastIdxKol(MNew); j++)
      {
         MNew.Mem[i][j] = M->Mem[j][i];
      }
   }

   *M = MNew;
}
/* Operasi berbasis baris dan per kolom */

float RataBrs(MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
   float total = 0;
   int counter = 0;
   for (int row = GetFirstIdxBrs(M); row <= GetLastIdxBrs(M); row++)
   {
      for (int col = GetFirstIdxKol(M); col <= GetLastIdxKol(M); col++)
      {
         if (row == i)
         {
            total += Elmt(M, i, col);
            counter++;
         }
      }
   }
   return total / counter;
}
float RataKol(MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
   float total = 0;
   int counter = 0;
   for (int row = GetFirstIdxBrs(M); row <= GetLastIdxBrs(M); row++)
   {
      for (int col = GetFirstIdxKol(M); col <= GetLastIdxKol(M); col++)
      {
         if (col == j)
         {
            total += Elmt(M, row, j);
         }
      }
   }
   return total / NBrsEff(M);
}
void MaxMinBrs(MATRIKS M, indeks i, ElType *max, ElType *min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
   ElType elMin = Elmt(M, i, GetFirstIdxKol(M));
   ElType elMax = Elmt(M, i, GetFirstIdxKol(M));
   for (int row = GetFirstIdxBrs(M); row <= GetLastIdxBrs(M); row++)
   {
      for (int col = GetFirstIdxKol(M); col <= GetLastIdxKol(M); col++)
      {
         if (row == i)
         {
            if (Elmt(M, i, col) > elMax)
            {
               elMax = Elmt(M, i, col);
            }

            if (Elmt(M, i, col) < elMin)
            {
               elMin = Elmt(M, i, col);
            }
         }
      }
   }
   *max = elMax;
   *min = elMin;
}
void MaxMinKol(MATRIKS M, indeks j, ElType *max, ElType *min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
   ElType elMin = Elmt(M, GetFirstIdxBrs(M), j);
   ElType elMax = Elmt(M, GetFirstIdxBrs(M), j);
   for (int row = GetFirstIdxBrs(M); row <= GetLastIdxBrs(M); row++)
   {
      for (int col = GetFirstIdxKol(M); col <= GetLastIdxKol(M); col++)
      {
         if (col == j)
         {
            if (Elmt(M, row, j) > elMax)
            {
               elMax = Elmt(M, row, j);
            }

            if (Elmt(M, row, j) < elMin)
            {
               elMin = Elmt(M, row, j);
            }
         }
      }
   }
   *max = elMax;
   *min = elMin;
}
int CountXBrs(MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
   int counter = 0;
   for (int row = GetFirstIdxBrs(M); row <= GetLastIdxBrs(M); row++)
   {
      for (int col = GetFirstIdxKol(M); col <= GetLastIdxKol(M); col++)
      {
         if (row == i)
         {
            if (Elmt(M, i, col) == X)
            {
               counter += 1;
            }
         }
      }
   }
   return counter;
}
int CountXKol(MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
   int counter = 0;
   for (int row = GetFirstIdxBrs(M); row <= GetLastIdxBrs(M); row++)
   {
      for (int col = GetFirstIdxKol(M); col <= GetLastIdxKol(M); col++)
      {
         if (col == j)
         {
            if (Elmt(M, row, j) == X)
            {
               counter += 1;
            }
         }
      }
   }
   return counter;
}