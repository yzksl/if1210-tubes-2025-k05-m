#include "../header/Register.h"
#include "../header/CTypePalsu.h"
#include "Set.h"
#include "Stack.h"
#include "GlobalVariable.h"

void registerPasien(){

    char username[STR_MAX_SIZE];
    char password[STR_MAX_SIZE];

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    char usernameLower[STR_MAX_SIZE];
    toLowerString(username, usernameLower);

       if (idxIsValInSet(&globalUsernames, usernameLower) != -1) {
        printf("\nRegistrasi gagal! Pasien dengan nama %s sudah terdaftar.\n", usernameLower);
        return;
    } 

    // Cari ID terbesar dan tambah 1
    int maxId = 0;
    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* gd = getGDbyIdx(&globalUserDatabase,i);
        if (gd->type== DATA_TYPE_DOCTOR){
            Doctor* d = getDoctorInGD(gd);
            if (d->id > maxId) {
                maxId = d->id;
            }
        } else if (gd->type == DATA_TYPE_PATIENT){
            Patient* p = getPatientInGD(gd);
            if (p->id > maxId) {
                maxId = p->id;
            }
        } else if (gd->type == DATA_TYPE_MANAGER){
            Manager* m = getManagerInGD(gd);
            if (m->id > maxId) {
                maxId = m->id;
            }
        }
    }
    int newId = maxId + 1;

    // Buat data pasien baru
    int emptyInventory[INVENTORY_SIZE]; // Inisialisasi inventory kosong
    memset(emptyInventory, 0, sizeof(emptyInventory));
    float emptyKondisiTubuh[KONDISI_TUBUH_SIZE]; // Inisialisasi kondisi tubuh kosong
    memset(emptyKondisiTubuh, 0, sizeof(emptyKondisiTubuh));
    Patient* newPatient = createPatientWithData(newId, username, password, "", emptyInventory, emptyKondisiTubuh);
    createStack(&newPatient->perut); // Inisialisasi stack perut
    newPatient->sudahDiDiagnosis = false;
    newPatient->sudahDiObatin = false;
    if (newPatient == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        newPatient->inventory[i] = UNDEF_INT_DATA;
    }
    for (int i = 0; i < KONDISI_TUBUH_SIZE; i++) {
        newPatient->kondisiTubuh[i] = UNDEF_INT_DATA;
    }
    GenericData* newGD = createGD((void*)newPatient, DATA_TYPE_PATIENT);
    if (newGD == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        free(newPatient);
        return;
    }

    if (isLDFull(&globalUserDatabase)){
        expandLD(&globalUserDatabase, 1);
    }
    insertLastLD(&globalUserDatabase, newGD);

    // Tambah username ke dalam Set (dalam bentuk lowercase)
    if (isSetFull(&globalUsernames)) {
        expandSet(&globalUsernames, 1);
    }
    addToSet(&globalUsernames, usernameLower);

    printf("\nPasien %s berhasil ditambahkan!\n", username);
}
  
