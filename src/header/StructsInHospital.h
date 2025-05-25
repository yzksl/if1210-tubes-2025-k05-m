#ifndef STRUCTS_IN_HOSPITAL_H
#define STRUCTS_IN_HOSPITAL_H

/* MODUL ADT SEDERHANA */
/* Berisi beberapa definisi dan primitif pemrosesan dari beberapa tipe data bentukan */
/* Terdapat tipe data Pasien, Dokter, Manager, Obat, Penyakit, dll */
/* Database user menggunakan DynamicList, sedangkan database lainnya menggunakan list statik */
/* Pertimbangannya adalah user dapat ditambah sejalan program sedangkan yang lainnya tidak, contohnya obat dan penyakit */

/*  Kamus Umum */
#define OBAT_MAX_SIZE 100
#define IDX_UNDEF -1
#define STR_MAX_SIZE 50
#define PENYAKIT_MAX_SIZE 100
#define OBAT_PENYAKIT_MAX_SIZE 10
#define UNDEF_INT_DATA -99;

/* Definisi elemen dan koleksi objek */
/* Obat */
typedef struct {
    int id;         /* id obat */
    char name[STR_MAX_SIZE];  /* nama obat */
} Obat;

// declaration for stack
typedef struct {
    Obat obat[OBAT_MAX_SIZE]; /* statik list rata kiri dengan kapasitas 100, berisi type Obat */
    int top;            /* index elemen paling atas dari stack (elemen efektif terakhir dalam list) */
} Stack;

/* DATATYPE ENUMS */
typedef enum {
    DATA_TYPE_UNKNOWN,  /* indikator tidak diketahui */
    DATA_TYPE_PATIENT,  /* indikator data patient */
    DATA_TYPE_DOCTOR,   /* indikator data doctor*/
    DATA_TYPE_MANAGER   /* indikator data manager */
} DataType;

/* Patient */
#define KONDISI_TUBUH_SIZE 10
#define INVENTORY_SIZE 10
typedef struct {
    int id;
    char username[STR_MAX_SIZE];
    char password[STR_MAX_SIZE];
    DataType type;
    char riwayatPenyakit[STR_MAX_SIZE];
    Stack perut;
    int inventory[INVENTORY_SIZE];
    float kondisiTubuh[KONDISI_TUBUH_SIZE];
} Patient;

/* Docter */
typedef struct {
    int id;
    char username[STR_MAX_SIZE];
    char password[STR_MAX_SIZE];
    DataType type;
    char name[STR_MAX_SIZE];
    char spesialisasi[STR_MAX_SIZE];
} Doctor;

/* Manager */
typedef struct {
    int id;
    char username[STR_MAX_SIZE];
    char password[STR_MAX_SIZE];
    DataType type;
} Manager;

/* Penyakit */
#define THRESHOLD_SIZE 20
typedef struct {
    int id;
    char name[STR_MAX_SIZE];
    float threshold[THRESHOLD_SIZE];    /* treshold sakit/tidak disimpan disini (lihat contoh file user.csv) */
} Penyakit;

/* Database Obat */
typedef struct {
    Obat contents[OBAT_MAX_SIZE];
    int nEff;
} ObatDatabase;

/* Database Penyakit */
typedef struct {
    Penyakit contents[PENYAKIT_MAX_SIZE];
    int nEff;
} PenyakitDatabase;

/* Obat Penyakit */
typedef struct {
    int idPenyakit;
    int idObat[OBAT_PENYAKIT_MAX_SIZE];
    int nEff;
} ObatPenyakit;

/* Database Obat Penyakit */
typedef struct {
    ObatPenyakit contents[PENYAKIT_MAX_SIZE];
    int nEff;
} ObatPenyakitDatabase;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor Patient */
Patient* createPatient();
/* Membuat sebuah Patient di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
Patient* createPatientWithData( const int id,
                                const char username[STR_MAX_SIZE],
                                const char password[STR_MAX_SIZE],
                                const char riwayatPenyakit[STR_MAX_SIZE],
                                // Stack perut,
                                const int inventory[INVENTORY_SIZE],
                                const float kondisiTubuh[KONDISI_TUBUH_SIZE]);
/* Membuat sebuah Patient di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */

/* Konstruktor Doctor */
Doctor* createDoctor();
/* Membuat sebuah Doctor di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
Doctor* createDoctorWithData(const int id, const char username[STR_MAX_SIZE], const char password[STR_MAX_SIZE], const char name[STR_MAX_SIZE], const char spesialisasi[STR_MAX_SIZE]);
/* Membuat sebuah Doctor di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */

/* Konstruktor Manager */
Manager* createManager();
/* Membuat sebuah Manager di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
Manager* createManagerWithData(const int id, const char username[STR_MAX_SIZE], const char password[STR_MAX_SIZE]);
/* Membuat sebuah Manager di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */

/* ********** DEALOKATOR ********** */
/* Untuk Patient, Doctor, Manager, dealokasi diatur oleh GenericData */

#endif