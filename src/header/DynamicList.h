/* MODUL DYNAMIC LIST UNTUK DATABASE LOGIK USER */
/* Digunakan untuk database logik dari seluruh anggota hospital (pasien, dokter, manager) */
/* Berisi definisi dan semua primitif pemrosesan ADT List Dinamik */
/* MODUL DYNAMIC LIST UNTUK DATABASE LOGIK USER */
/* Digunakan untuk database logik dari seluruh anggota hospital (pasien, dokter, manager) */
/* Berisi definisi dan semua primitif pemrosesan ADT List Dinamik */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen efektif didefinisikan dengan nEff (eksplisit) */
/* Banyaknya elemen efektif didefinisikan dengan nEff (eksplisit) */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "Boolean.h"
#include "DatatypeEnums.h"
#include "StructsInHospital.h"

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
// #define GETELMT(l, i) (*(((l).buffer[i])->data))
// #define GETTYPE(l, i) (((l).buffer[i])->type)

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void createLD(ListDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
/* Konstruktor : create GenericData */
GenericData* createGD(void* data, DataType type);
/* Membuat suatu GenericData dengan pointer generik ke data dan type dari data tersebut */
/* dan mengembalikan address dari GenericData tersebut */

/* ********** DEALOKATOR ********** */
void dealocateLD(ListDin *l);
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Semua elemen difree dan pointer ke NULL CAPACITY(l)=0; NEFF(l)=0 */
void dealocateGD(GenericData* gd);
/* I.S. gd terdefinisi */
/* F.S. Data dalam gd di-free, type menjadi unknown, data point to NULL */

/* ********** SELEKTOR (TAMBAHAN) ********** */
int lengthLD(const ListDin* l);
/* Mengembalikan banyaknya elemen efektif list */
DataType getDataTypeGD(const GenericData* gd);
/* Mengembalikan type dari gd */
GenericData* getGDbyIdx(const ListDin* l, int idx);
/* Mengembalikan address dari GenericData pada index idx. Jika tidak efektif, maka dikeluarkan "INVALID IDX" dan mengembalikan NULL */
Patient* getPatientInGD(const GenericData* gd);
/* Jika type memang Patient, nilai dalam data dengan casting patient alias mengembalikan address dari patient di gd */
/* Jika type bukan Patient, maka dikeluarkan "BUKAN PASIEN" */
Doctor* getDoctorInGD(const GenericData* gd);
/* Jika type memang Doctor, nilai dalam data dengan casting patient alias mengembalikan address dari patient di gd */
/* Jika type bukan Doctor, maka dikeluarkan "BUKAN PASIEN" */
Manager* getManagerInGD(const GenericData* gd);
/* Jika type memang Manager, nilai dalam data dengan casting patient alias mengembalikan address dari patient di gd */
/* Jika type bukan Manager, maka dikeluarkan "BUKAN PASIEN" */

/* *** Selektor INDEKS *** */
int getLDFirstIdx(const ListDin* l);
/* Mengembalikan index pertama */
int getLDLastIdx(const ListDin* l);
/* Mengembalikan index elemen efektif terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isLDIdxValid(const ListDin* l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isLDIdxEff(const ListDin* l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isLDEmpty(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isLDFull(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLD(ListDin *l, ElType val);
/* I.S. l terdefinisi, mungkin penuh */
/* F.S. Jika tidak penuh, val adalah elemen terakhir l yang baru. Jika penuh, maka dikeluarkan "LIST PENUH" */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastLD(ListDin *l);
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Jika tidak kosong, maka elemen terakhir di-free dan pointernya ke null */
/*      Banyaknya elemen list berkurang satu, l mungkin menjadi kosong */
/*      Jika kosong, maka dikeluarkan "LIST KOSONG" */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandLD(ListDin *l, int num);
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */

void shrinkLD(ListDin *l, int num);
/* I.S. l terdefinisi, mungkin kapasitas < num atau nEff > capacity - num */
/* F.S. Jika tidak, ukuran list berkurang sebanyak num. Jika iya, dikeluarkan "INVALID NUM" */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */

void compressLD(ListDin *l);
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Jika tidak, ukuran nEff = capcity. Jika iya, dikeluarkan "LIST KOSONG" */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */

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