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
    }

    ElType* newBuffer = (ElType* )malloc(l->capacity * sizeof(ElType));
    if (newBuffer == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        return;
    }

    l->buffer = newBuffer;
    l->capacity = capacity;
    l->nEff = 0;
}

void dealocateLD(ListDin *l) {
/* I.S. l terdefinisi */
/* F.S. semua elemen difree dan pointer ke NULL CAPACITY(l)=0; NEFF(l)=0 */   
    for (int i = 0; i < l->nEff; ++i) {
        free(l->buffer[i]);
        /* l-> buffer [i] = NULL; is not needed, will be dealocated anyway. Slows down program */
    }
    free(l->buffer);
    l->buffer = NULL;
    l->capacity = 0;
    l->nEff = 0;
}

void dealocateGD(GenericData* gd) {
/* I.S. gd terdefinisi */
/* F.S. Data dalam gd di-free, type menjadi unknown, data point to NULL */
    free(gd->data);
    // gd->data = NULL;
    // gd->type = DATA_TYPE_UNKNOWN;
    free(gd);
}

int lengthLD(const ListDin* l) {
/* Mengembalikan banyaknya elemen efektif list. 0 jika kosong */
    return l->nEff;
}

DataType getDataTypeGD(const GenericData* gd) {
/* Mengembalikan type dari gd */
    return gd->type;
}

GenericData* getGDbyIdx(const ListDin* l, int idx){
/* Mengembalikan address dari GenericData pada index idx. Jika tidak efektif, maka dikeluarkan "INVALID IDX" dan mengembalikan NULL */
    if (idx >= l->nEff || idx < 0) {
        printf("INVALID IDX\n");
        return NULL;
    }
    return l->buffer[idx];
}

Patient* getPatientInGD(const GenericData* gd){
/* Jika type memang Patient, nilai dalam data dengan casting patient alias mengembalikan address dari patient di gd */
/* Jika type bukan Patient, maka dikeluarkan "BUKAN PASIEN" */
    if (gd->type != DATA_TYPE_PATIENT) {
        printf("BUKAN PASIEN\n");
        return NULL;
    }
    return (Patient*)gd->data;
}

Doctor* getDoctorInGD(const GenericData* gd) {
/* Jika type memang Doctor, nilai dalam data dengan casting patient alias mengembalikan address dari patient di gd */
/* Jika type bukan Doctor, maka dikeluarkan "BUKAN DOKTER" */
    if (gd->type != DATA_TYPE_DOCTOR) {
        printf("BUKAN DOKTER\n");
        return NULL;
    }
    return (Doctor*)gd->data;
}

Manager* getManagerInGD(const GenericData* gd) {
/* Jika type memang Manager, nilai dalam data dengan casting patient alias mengembalikan address dari patient di gd */
/* Jika type bukan Manager, maka dikeluarkan "BUKAN MANAGER" */
    if (gd->type != DATA_TYPE_MANAGER) {
        printf("BUKAN MANAGER\n");
        return NULL;
    }
    return (Manager*)gd->data;
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
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return(l.nEff == 0);    
}

boolean isLDFull(ListDin l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return(l.nEff == l.capacity);
}

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
}