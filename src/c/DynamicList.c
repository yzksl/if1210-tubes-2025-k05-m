<<<<<<< HEAD
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
=======
#include <stdlib.h>
#include "../header/DynamicList.h"
#include "../header/Boolean.h"

void createLD(ListDin *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
    if (capacity < 1) {
        printf("KAPASITAS INVALID\n");
        return;
    } else {
        l->capacity = capacity;
        l->nEff = 0;
        BUFFER(*l) = (ElType* )malloc(l->capacity * sizeof(ElType));
    }
}

void dealocateLD(ListDin *l) {
/* I.S. l terdefinisi */
/* F.S. semua elemen difree dan pointer ke NULL CAPACITY(l)=0; NEFF(l)=0 */   
    for (int i = 0; i < l->nEff; ++i) {
        free(l->buffer[i]);
        /* l-> buffer [i] = NULL; is not needed, will be dealocated anyway. Slows down program */
>>>>>>> b883cdcc4a265f7e517813a290d872aba2660891
    }
    free(l->buffer);
    l->buffer = NULL;
    l->capacity = 0;
    l->nEff = 0;
}

<<<<<<< HEAD
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
=======
int lengthLD(const ListDin* l) {
/* Mengembalikan banyaknya elemen efektif list. 0 jika kosong */
    return l->nEff;
}

int getLDFirstIdx(const ListDin* l) {
/* Mengembalikan index pertama */
    return 0;
}

int getLDLastIdx(const ListDin* l) {
/* Mengembalikan index elemen efektif terakhir */
    return (l->nEff - 1);
}

boolean isLDIdxValid(const ListDin* l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < l->capacity);
}

boolean isLDIdxEff(const ListDin* l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return(i >= 0 && i < l->nEff);
}

boolean isLDEmpty(ListDin l) {
>>>>>>> b883cdcc4a265f7e517813a290d872aba2660891
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return(l.nEff == 0);    
}

<<<<<<< HEAD
boolean isFull(ListDin l) {
=======
boolean isLDFull(ListDin l) {
>>>>>>> b883cdcc4a265f7e517813a290d872aba2660891
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return(l.nEff == l.capacity);
}

<<<<<<< HEAD
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
=======
void insertLastLD(ListDin *l, ElType val) {
/* I.S. l terdefinisi, mungkin penuh */
/* F.S. Jika tidak penuh, val adalah elemen terakhir l yang baru. Jika penuh, maka dikeluarkan "LIST PENUH" */
    if (isFull(*l)) {
        printf("LIST PENUH\n");
        return;
    } else {
        l->buffer[l->nEff] = val;
        l->nEff += 1; 
    }
}

void deleteLastLD(ListDin *l) {
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Jika tidak kosong, maka elemen terakhir di-free dan pointernya ke null */
/*      Banyaknya elemen list berkurang satu, l mungkin menjadi kosong */
/*      Jika kosong, maka dikeluarkan "LIST KOSONG" */
    if (l->nEff == 0) {
        printf("LIST KOSONG\n");
        return;
    }
    free(l->buffer[l->nEff-1]);
    l->buffer[l->nEff-1] = NULL;
    l->nEff -= 1;
}

void expandLD(ListDin *l, int num) {
/* I.S. l terdefinisi, mungkin num <= 0 */
/* F.S. Jika tidak, ukuran list bertambah sebanyak num. Jika iya, dikeluarkan INVALID NUM */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
    if (num <= 0) {
        printf("INVALID NUM\n");
        return;
    }

    ElType* newBuffer = realloc(l->buffer, (l->capacity + num)*sizeof(ElType));
    if (newBuffer == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        return;
    }

    l->buffer = newBuffer;
    l->capacity += num;
}

void shrinkLD(ListDin *l, int num) {
/* I.S. l terdefinisi, mungkin kapasitas < num atau nEff > capacity - num atau n <= 0 */
/* F.S. Jika tidak, ukuran list berkurang sebanyak num. Jika iya, dikeluarkan "INVALID NUM" */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
    if (num <= 0 || l->capacity < num || l->nEff > l->capacity - num) {
        printf("NUM INVALID\n");
        return;
    }
    
    ElType* newBuffer = realloc(l->buffer, (l->capacity - num)*sizeof(ElType));
    if (newBuffer == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        return;
    }
    
    l->buffer = newBuffer;
    l->capacity -= num;
}

void compressLD(ListDin* l) {
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Jika tidak, ukuran nEff = capcity. Jika iya, dikeluarkan "LIST KOSONG" */
/* PERHATIAN: mungkin memori akan kekurangan untuk alokasi, sehingga prosedur tidak dapat berjalan sesuai fungsi. Jika hal tersebut terjadi, maka akan dikeluarkan "GAGAL REALOKASI MEMORI" */
    if (l->nEff == 0) {
        printf("LIST KOSONG\n");
        return;
    }

    ElType* newBuffer = realloc(l->buffer, (l->nEff)*sizeof(ElType));
    if (newBuffer == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        return;
    }

    l->buffer = newBuffer;
    l->capacity = l->nEff;
>>>>>>> b883cdcc4a265f7e517813a290d872aba2660891
}