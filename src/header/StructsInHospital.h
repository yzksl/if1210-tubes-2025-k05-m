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
#define KONDISI_TUBUH_SIZE 12
typedef struct {
    int id;
    char username[50];
    char password[50];
    DataType DATA_TYPE_PATIENT;
    Stack perut;
    int inventory[MAX_SIZE];
    float kondisiTubuh[KONDISI_TUBUH_SIZE];
} Patient;

/* Docter */
typedef struct {
    int id;
    char username[50];
    char password[50];
    DataType DATA_TYPE_DOCTOR;
    char name[50];
    char spesialisasi[50];
} Doctor;

/* Manager */
typedef struct {
    int id;
    char username[50];
    char password[50];
    DataType DATA_TYPE_MANAGER;
} Manager;

/* Obat */
typedef struct {
    int id;         /* id obat */
    char name[50];  /* nama obat */
} Obat;

#endif