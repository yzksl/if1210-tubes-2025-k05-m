/* MODUL ADT SET */
/* Berisi definisi dan semua primitif pemrosesan ADT Set */
/* Set adalah suatu array dimana dalamnya tidak diperbolehkan ada nilai yang duplikat */
/* Set digunakan untuk menyimpan username-username dari seluruh pengguna */
/* Ketika sebuah user ditambahkan, username tidak boleh sama dengan username user lainnya. Maka, Set digunakan untuk mengatasi hal tersebut */
/* Set menggunakan list dinamis kontigu rata kiri, eksplisit */


#ifndef ADT_SET_H
#define ADT_SET_H

#include "Boolean.h"
#include "StructsInHospital.h"

/* Definisi elemen dan koleksi objek */
typedef struct {
    char** buffer;  /* memori tempat penyimpanan string-string dengan max karakter 50 */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* banyaknya elemen yang dapat ditampung */
} Set;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika s adalah : Set, cara deklarasi dan akses: */
/* Deklarasi : s : Set */
/* Maka cara akses: 
    memakai fungsi selektor, atau...
    s.nEff      untuk mengetahui banyaknya elemen
    s.buffer    untuk mengakses seluruh nilai elemen list
    s.buffer[i] untuk mengakses elemen (sebuah string) */
/* Definisi :
    set kosong: l.nEff = 0
    Definisi elemen pertama : s.buffer[0]
    Definisi elemen terakhir yang terdefinisi : s.buffer[s.nEff - 1] */ 

/* ********** SELEKTOR ********** */
#define SETNEFF(s) (s).nEff
#define SETBUFFER(s) (s).nEff
#define SETCAPACITY(s) (s).capacity
#define SETGETELMT(s, i) ((s).buffer[i])

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create set kosong  */
/* I.S. s sembarang, capacity > 0 */
/* F.S. Terbentuk set s dengan kapasitas capacity */
void createSet(Set* s, const int capacity);

/* ********** DEALOKATOR ********** */
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. Semua elemen difree dan pointer ke NULL, capacity dan nEff = 0 */
void freeSet(Set* s);

/* ********** FUNGSIONAL ********** */
/* *** Menambahkan elemen *** */
/* I.S. s dan val terdefinisi, mungkin penuh */
/* F.S. Jika tidak penuh dan val tidak ada dalam set, val adalah elemen yang ditempatkan di paling kanan, nEff bertambah satu. Jika penuh, maka dikeluarkan "SET PENUH", jiak ada, maka dikeluarkan sebuah error message */
void addToSet(Set* s, const char* val);
/* *** Menghapuskan elemen *** */
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. Jika s tidak kosong, maka dihapuskan elemen dengan val dari set, di-rata kiri kan, dan nEff berkurang satu. */
void removeFromSet(Set* s, const char* val);
/* *** Mencari jika val ada dalam set *** */
/* Mengirimkan indeks >= 0 dimana terdapat val, -1 jika tidak ada */
int idxIsValInSet(const Set* s, const char* val);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test set kosong *** */
/* Mengirimkan true jika set l kosong, mengirimkan false jika tidak */
boolean isSetEmpty(const Set* s);
/* *** Test list penuh *** */
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isSetFull(const Set* s);

/* ********* MENGUBAH UKURAN SET ********* */
/* I.S. s sudah terdefinisi */
/* F.S. Ukuran set bertambah sebanyak num */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
void expandSet(Set* s, const int num);
/* I.S. s terdefinisi, mungkin kapasitas < num atau nEff > capacity - num */
/* F.S. Jika tidak, ukuran list berkurang sebanyak num. Jika iya, dikeluarkan "INVALID NUM" */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
void shrinkSet(Set* s, const int num);
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. Jika tidak, ukuran nEff = capcity. Jika iya, dikeluarkan "LIST KOSONG" */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
void compressSet(Set* s);

/* ********* DELETED FUNCTIONS ********* */
// /* ********** SELEKTOR (TAMBAHAN) ********** */
// /* Mengembalikan banyaknya elemen efektif dalam set */
// int lengthSet(const Set* s);
// /* Mengembalikan kapasitas dalam set */
// int capacitySet(const Set* s);
// /* Mendapatkan elemen dalam set di indeks ke-i */
// char* getElmtAtIdxSet(const Set* s, int i);

#endif