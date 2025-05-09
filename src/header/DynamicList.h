/* MODUL DYNAMIC LIST UNTUK DATABASE LOGIK USER */
/* Digunakan untuk database logik dari seluruh anggota hospital (pasien, dokter, manager) */
/* Berisi definisi dan semua primitif pemrosesan ADT List Dinamik */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen efektif didefinisikan dengan nEff (eksplisit) */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "Boolean.h"
#include "DatatypeEnums.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
    void* data;
    DataType type;
} GenericData;
/* GenericData adalah tipe bentukan yang dapat memuat data dengan type apapun (Patient, Doctor, etc) karena menggunakan sebuah pointer void */
/* DataType menunjukkan type yang ada dalam pointer data */
/* Misal: variabel GD bertipe GenericData menampung data dari sebuah pasien dengan type Patient, maka: */
/* GD.data adalah pointer ke data Patient, GD.type harus bernilai DATA_TYPE_PATIENT (lihat file DatatypeEnums) */
typedef GenericData* ElType; /* type elemen yang digunakan dalam list */
typedef int IdxType; /* type index yang digunakan dalam list */
typedef struct {
    ElType* buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
    memakai fungsi selektor, atau...
    l.nEff      untuk mengetahui banyaknya elemen
    l.buffer    untuk mengakses seluruh nilai elemen list
    l.buffer[i] untuk mengakses elemen (pointer ke sebuah GenericData) ke-i */
/* Definisi :
    list kosong: l.nEff = 0
    Definisi elemen pertama : l.buffer[i] dengan i=0
    Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define CAPACITY(l) (l).capacity
#define GETPOINTER(l, i) ((l).buffer[i])
#define GETELMT(l, i) (*(((l).buffer[i])->data))
#define GETTYPE(l, i) (((l).buffer[i])->type)

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* ********** DEALOKATOR ********** */
void dealocateListDin(ListDin *l);
/* I.S. l terdefinisi, buffer ada beberapa nilai (pointer ke patient/doctor/etc); */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
int listDinLength(ListDin l);
/* Mengirimkan banyaknya elemen efektif list */

/* *** Selektor INDEKS *** */
int getFirstIdx(ListDin l);
/* Jika list tidak kosong, mengembalikan index pertama. Jika list kosong, dikeluarkan "LIST KOSONG" dan mengembalikan IDX_UNDEF */
int getLastIdx(ListDin l);
/* Jika list tidak kosong, mengembalikan indeks elemen l terakhir. Jika list kosong, dikeluarkan "LIST KOSONG" dan mengembalikan IDX_UNDEF */

/* ********** Test Indeks yang valid ********** */
boolean isListDinIdxValid(ListDin l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isListDinIdxEff(ListDin l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinEmpty(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isListDinFull(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDin(ListDin *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDin(ListDin *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDin(ListDin *l);
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

/* ********* DELETED FUNCTIONS ********* */
/* PERTIMBANGAN: sorting dan searching dilakukan oleh f07 dan selanjutnya dalam file masing-masing */

// /* ********** SEARCHING ********** */
// /* ***  Perhatian : list boleh kosong!! *** */
// ElType* searchWithID(ListDin l, int val);
// /* Search apakah ada elemen List l yang memiliki id */
// /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
// /* Jika tidak ada, mengirimkan IDX_UNDEF */
// /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
// /* Skema Searching yang digunakan bebas */

//    /* ********** NILAI EKSTREM ********** */
//    void extremeValues(ListDin l, ElType *max, ElType *min);
//    /* I.S. List l tidak kosong */
//    /* F.S. max berisi nilai maksimum l;
//            min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
//    void copyList(ListDin lIn, ListDin *lOut);
//    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
//    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
//    /* Proses : Menyalin isi lIn ke lOut */ 
//    ElType sumList(ListDin l);
//    /* Menghasilkan hasil penjumlahan semua elemen l */
//    /* Jika l kosong menghasilkan 0 */
//    int countVal(ListDin l, ElType val);
//    /* Menghasilkan berapa banyak kemunculan val di l */
//    /* Jika l kosong menghasilkan 0 */

//    /* ********** SORTING ********** */
//    void sort(ListDin *l, boolean asc);
//    /* I.S. l boleh kosong */
//    /* F.S. Jika asc = true, l terurut membesar */
//    /*      Jika asc = false, l terurut mengecil */
//    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//       algoritma bebas */

//    /* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
//    /* *** Mendefinisikan isi list dari pembacaan *** */
//    void readList(ListDin *l);
//    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
//    /* F.S. List l terdefinisi */
//    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
//    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
//    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
//    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
//    /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
//          0 satu per satu diakhiri enter */
//    /*    Jika N = 0; hanya terbentuk l kosong */
//    void printList(ListDin l);
//    /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
//       antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
//       di tengah, atau di belakang, termasuk spasi dan enter */
//    /* I.S. l boleh kosong */
//    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
//    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
//    /* Jika list kosong : menulis [] */

//    /* ********** OPERATOR ARITMATIKA ********** */
//    /* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
//    ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus);
//    /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
//    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
//    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

//    /* ********** OPERATOR RELASIONAL ********** */
//    /* *** Operasi pembandingan list : < =, > *** */
//    boolean isListEqual(ListDin l1, ListDin l2);
//    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

#endif