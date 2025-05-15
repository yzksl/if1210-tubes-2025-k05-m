#ifndef STRUCTS_IN_HOSPITAL_H
#define STRUCTS_IN_HOSPITAL_H

// Forward declarations (no #include needed)
typedef struct Stack Stack;
typedef struct Queue Queue;


/* MODUL ADT SEDERHANA */
/* Berisi beberapa definisi dan primitif pemrosesan dari beberapa tipe data bentukan */
/* Terdapat tipe data Pasien, Dokter, Manager, Obat, Penyakit, dll */

/*  Kamus Umum */
#define STR_MAX_SIZE 100

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

/* Obat */
typedef struct {
    int id;         /* id obat */
    char name[STR_MAX_SIZE];  /* nama obat */
} Obat;

/* Penyakit */
#define THRESHOLD_SIZE 18
typedef struct {
    int id;
    char name[STR_MAX_SIZE];
    float threshold[THRESHOLD_SIZE];    /* treshold sakit/tidak disimpan disini (lihat contoh file user.csv) */
} Penyakit;

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
                                float kondisiTubuh[KONDISI_TUBUH_SIZE]);
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