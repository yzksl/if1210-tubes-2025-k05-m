#include <stdlib.h>
#include <string.h>
#include <Boolean.h>
#include <StructsInHospital.h>
#include <Stack.h>

Patient* createPatient() {
/* Membuat sebuah Patient di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
    Patient* p = (Patient*)malloc(sizeof(Patient));
    if (p == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return NULL;
    }
    memset(p, 0, sizeof(Patient));
    p->type = DATA_TYPE_PATIENT;
    return p;
}

Patient* createPatientWithData(const int id, const char username[50], const char password[50], const char riwayatPenyakit[50], const int inventory[INVENTORY_SIZE], float kondisiTubuh[KONDISI_TUBUH_SIZE]){
/* Membuat sebuah Patient di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
    Patient* p = (Patient*)malloc(sizeof(Patient));
    if (p == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return NULL;
    }
    p->id = id;
    strcpy(p->username, username);
    strcpy(p->password, password);
    strcpy(p->riwayatPenyakit, riwayatPenyakit);
    memcpy(p->kondisiTubuh, kondisiTubuh, KONDISI_TUBUH_SIZE*sizeof(float));
    memcpy(p->inventory, inventory, sizeof(int));
    p->type = DATA_TYPE_PATIENT;

    return p;
}

Doctor* createDoctor() {
/* Membuat sebuah Doctor di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
    Doctor* d = (Doctor*)malloc(sizeof(Doctor));
    if (d == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return NULL;
    }
    memset(d, 0, sizeof(Doctor));
    d->type = DATA_TYPE_DOCTOR;
    return d;
}

Doctor* createDoctorWithData(const int id, const char username[50], const char password[50], const char name[50], const char spesialisasi[50]) {
/* Membuat sebuah Doctor di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
    Doctor* d = (Doctor*)malloc(sizeof(Doctor));
    if (d == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return NULL;
    }
    d->id = id;
    strcpy(d->username, username);
    strcpy(d->password, password);
    strcpy(d->name, name);
    strcpy(d->spesialisasi, spesialisasi);
    d->type = DATA_TYPE_DOCTOR;

    return d;
}

Manager* createManager() {
/* Membuat sebuah Manager di heap, komponen-komponen zero-filled. Mengembalikan address dari data tersebut dalam heap */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
    Manager* m = (Manager*)malloc(sizeof(Manager));
    if (m == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return NULL;
    }
    memset(m, 0, sizeof(Manager));
    m->type = DATA_TYPE_MANAGER;
    return m;
}

Manager* createManagerWithData(const int id, const char username[50], const char password[50]) {
/* Membuat sebuah Manager di heap dengan komponen-komponen dalam parameter */
/* PERHATIAN: mungkin alokasi memori dapat gagal. Jika iya, dikeluarkan ALOKASI MEMORI GAGAL */
    Manager* m = (Manager*)malloc(sizeof(Manager));
    if (m == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return NULL;
    }
    m->id = id;
    strcpy(m->username, username);
    strcpy(m->password, password);
    m->type = DATA_TYPE_MANAGER;

    return m;
}