/* Definisi type boolean */

#ifndef _BOOLEAN_h
#define _BOOLEAN_h

#define boolean unsigned char
#define true 1
#define false 0

#endif

#ifndef STRUCTS_IN_HOSPITAL_H
#define STRUCTS_IN_HOSPITAL_H

#include "Stack.h"
#include "Queue.h"

/* MODUL ADT SEDERHANA */
/* Berisi beberapa definisi dan primitif pemrosesan dari beberapa tipe data bentukan */
/* Terdapat tipe data Pasien, Dokter, Manager, Obat, Penyakit, dll */

/*  Kamus Umum */
#define MAX_SIZE 100

/* Definisi elemen dan koleksi objek */
/* DATATYPE ENUMS */
typedef enum {
    DATA_TYPE_UNKNOWN,  /* indikator tidak diketahui */
    DATA_TYPE_PATIENT,  /* indikator data patient */
    DATA_TYPE_DOCTOR,   /* indikator data doctor*/
    DATA_TYPE_MANAGER   /* indikator data manager */
} DataType;

/* Patient */
#define KONDISI_TUBUH_SIZE 11
#define INVENTORY_SIZE 10
typedef struct {
    int id;
    char username[50];
    char password[50];
    DataType type;
    char riwayatPenyakit[50];
    Stack perut;
    int inventory[INVENTORY_SIZE];
    float kondisiTubuh[KONDISI_TUBUH_SIZE];
} Patient;

/* Docter */
typedef struct {
    int id;
    char username[50];
    char password[50];
    DataType type;
    char name[50];
    char spesialisasi[50];
} Doctor;

/* Manager */
typedef struct {
    int id;
    char username[50];
    char password[50];
    DataType type;
} Manager;

/* Obat */
typedef struct {
    int id;         /* id obat */
    char name[50];  /* nama obat */
} Obat;

/* Penyakit */
#define THRESHOLD_SIZE 18
typedef struct {
    int id;
    char name[50];
    float threshold[THRESHOLD_SIZE];    /* treshold sakit/tidak disimpan disini (lihat contoh file user.csv) */
} Penyakit;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor Patient */
Patient* createPatient();
/* Membuat sebuah Patient di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
Patient* createPatientWithData(const int id, const char username[50], const char password[50], const char riwayatPenyakit[50], const int inventory[INVENTORY_SIZE], float kondisiTubuh[KONDISI_TUBUH_SIZE]);
/* Membuat sebuah Patient di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */

/* Konstruktor Doctor */
Doctor* createDoctor();
/* Membuat sebuah Doctor di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
Doctor* createDoctorWithData(const int id, const char username[50], const char password[50], const char name[50], const char spesialisasi[50]);
/* Membuat sebuah Doctor di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */

/* Konstruktor Manager */
Manager* createManager();
/* Membuat sebuah Manager di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
Manager* createManagerWithData(const int id, const char username[50], const char password[50]);
/* Membuat sebuah Manager di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */

/* ********** DEALOKATOR ********** */
/* Untuk Patient, Doctor, Manager, dealokasi diatur oleh GenericData */

#endif

/* MODUL ADT STACK */
/* Berisi definisi dan semua primitif pemrosesan ADT Queue */
/* Stack berdasarkan list statik eksplisit rata kiri */
/* Banyaknya elemen didefinisikan dengan index top (index elemen efektif terakhir) + 1 */
/* Stack menggunakan konsep LIFO (Last In First Out) */
/* Setiap proses penambahan (push) elemen ke stack, index top bertambah satu dan elemen tersebut ditambahkan di index tersebut. Setiap pengurangan elemen, index top berkurang satu */
/* Isi stack adalah sebuah list of obat dan index top */

#ifndef STACK_H
#define STACK_H

#include "Boolean.h"
#include "StructsInHospital.h"

/*  Kamus Umum */
#define MAX_SIZE 100
#define IDX_UNDEF -1

/* Definisi elemen dan koleksi objek */
typedef struct {
    Obat obat[MAX_SIZE]; /* statik list rata kiri dengan kapasitas 100, berisi type Obat */
    int top;            /* index elemen paling atas dari stack (elemen efektif terakhir dalam list) */
} Stack;
/* Jika s adalah : Stack, cara deklarasi dan akses: */
/* Deklarasi : s : Stack */
/* Maka cara akses: 
    index top: s.top
    elemen top: s.obat[s.top] atau dengan fungsi/macro selektor */
/* Definisi:
    stack kosong: top = IDX_UNDEF = -1
    stack penuh: top = MAX_SIZE - 1 = 99 
    stack dengan satu elemen: top = 0, s.obat[s.top] terdefinisi */

/* ********** SELEKTOR ********** */
#define TOPIDX(s) (s).top
#define TOPELMT(s) ((s).obat[(s).top])

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: membentuk sebuah stack */
void createStack(Stack* s);
/* I.S. s sembarang (baru di deklarasi Stack s) */
/* F.S. top = IDX_UNDEF = -1 */
/* Konstruktor: menambahkan elemen ke stack */
void pushStack(Stack* s, Obat o);
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. Jika s tidak penuh, top += 1, elemen di index top adalah o. Jika s penuh, dikeluarkan "STACK PENUH" */

/* ********** DEALOKATOR/SELEKTOR ********** */
/* Dealokator & Selektor */
Obat popStack(Stack* s);
/* Jika s tidak kosong, Mengembalikan obat di top dan menghapus obat tersebut dari stack (top -= 1). Walaupun mengembalikan datanya, tidak harus meng-assign data tersebut ke suatu variabel jika tidak diperlukan (cukup di panggil fungsi ini saja tanpa assignment ke suatu variabel ). Jika s kosong, dikeluarkan "STACK KOSONG" */
void deleteStack(Stack *s);
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. s kosong */

/* ********** SELEKTOR TAMBAHAN ********** */
int getTopIdx(const Stack* s);
/* Mengembalikan nilai top index */
Obat getTopElmt(const Stack* s);
/* Jika s tidak kosong, mengembalikan obat top. Jika s kosong, dikeluarkan "STACK KOSONG" dan mengembalikan obat sentinel */
Obat getElmtByIdxStack(const Stack* s, int idx);
/* Jika s tidak kosong dan 0 <= idx <= top, mengembalikan obat di index idx. Jika s kosong atau idx di luar daerah asal, dikeluarkan "STACK KOSONG" atau "IDX DI LUAR RANGE" dan mengembalikan obat sentinel */
int stackSize(const Stack* s);
/* Mengembalikan size dari stack (top + 1) (bukan kapasitas maksimum) */

/* ********** TEST KOSONG/PENUH ********** */
boolean isStackEmpty(const Stack* q);
/* Mengembalikan true jika stack kosong, false jika tidak kosong */
boolean isStackFull(const Stack* q);
/* Mengembalikan true jika stack penuh, false jika tidak penuh */

#endif