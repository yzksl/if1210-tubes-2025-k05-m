#include <stdio.h>
#include "../header/DynamicList.h"
#include "../header/Boolean.h"

void CreateListDin(ListDin *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType* )malloc(l->nEff * sizeof(ElType));
    int list[10]; // int *list 
    int *lstdin;

    lstdin = (int *) malloc(10 * sizeof(int)); //void * //0209332x
}

void dealocateList(ListDin *l) {
/* I.S. l terdefinisi, buffer ada beberapa nilai (pointer ke patient/doctor/etc); */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */   
    for (int i = 0 ;i < l->nEff; ++i) {
        free(l->buffer[i]);
    }
    free(l->buffer);
    l->buffer = NULL;
    l->capacity = 0;
    l->nEff = 0;
}

int listLength(ListDin l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return (IdxType)0;
}

IdxType getLastIdx(ListDin l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (IdxType)(l.capacity - 1);
}

boolean isIdxValid(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= IDX_MIN && i < l.capacity);
}

boolean isIdxEff(ListDin l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return(i >= IDX_MIN && i < l.nEff);
}

boolean isEmpty(ListDin l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return(l.nEff == 0);    
}

boolean isFull(ListDin l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return(l.nEff == l.capacity);
}

ElType* searchWithID(ListDin l, int id) {
/* Search apakah ada elemen List l yang memiliki id */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    if (isEmpty(l)) {
        return IDX_UNDEF;
    }
    for (int i = 0; i < l.nEff; ++i) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void insertLast(ListDin *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (isFull(*l)) {
        return;
    } else {
        l->buffer[l->nEff] = val;
        NEFF(*l) += 1;
    }
}

void deleteLast(ListDin *l, ElType *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    ELMT(*l, getLastIdx(*l)) = *val;
    NEFF(*l) -= 1;
}