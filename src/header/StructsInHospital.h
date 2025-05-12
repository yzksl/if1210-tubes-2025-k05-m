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