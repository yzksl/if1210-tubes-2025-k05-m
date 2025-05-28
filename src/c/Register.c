#include "../header/Register.h"
#include "Set.h"

static struct Alphabet {
    char lower[26];
    char higher[26];
} Alphabet;

void lowercaseStr(char* cek, const char* userpass){
    int i = 0;
    while (userpass[i]){
        cek[i] = tolower(userpass[i]);
        i++;
    }
}
void registerPasien(){

    char username[STR_MAX_SIZE];
    char password[STR_MAX_SIZE];

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    char usernameLower[STR_MAX_SIZE];
    lowercaseStr(usernameLower, username);

       if (idxIsValInSet(&globalUsernames, usernameLower) != -1) {
        printf("\nRegistrasi gagal! Pasien dengan nama %s sudah terdaftar.\n", username);
        return;
    } 

    // Cari ID terbesar dan tambah 1
    int maxId = 0;
    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* gd = globalUserDatabase.buffer[i];
        Patient* p = getPatientInGD(gd);
        if (p->id > maxId) {
            maxId = p->id;
        }
    }
    int newId = maxId + 1;

    // Buat data pasien baru
      Patient* newPatient = createPatient();
    if (newPatient == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return;
    }

    newPatient->id = newId;
    strcpy(newPatient->username, username);
    strcpy(newPatient->password, password);
    newPatient->type = DATA_TYPE_PATIENT;
    strcpy(newPatient->riwayatPenyakit, "");
    newPatient->perut.top = -1;

    GenericData* newGD = createGD((void*)newPatient, DATA_TYPE_PATIENT);
    if (newGD == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        free(newPatient);
        return;
    }

    insertLastLD(&globalUserDatabase, newGD);

    // Tambah username ke dalam Set (dalam bentuk lowercase)
    if (isSetFull(&globalUsernames)) {
        expandSet(&globalUsernames, 1);
    }
    addToSet(&globalUsernames, usernameLower);

    printf("\nPasien %s berhasil ditambahkan!\n", username);
}
  
