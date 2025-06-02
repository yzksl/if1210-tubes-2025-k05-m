#include "../header/TambahDokter.h"
#include "StructsInHospital.h"
#include "GlobalVariable.h"
#include "DynamicList.h"
#include "CTypePalsu.h"
#include "LihatDenah.h"

void tambahDokter(){

    char usernameNew[STR_MAX_SIZE];
    char passwordNew[STR_MAX_SIZE];

    printf("Username: ");
    scanf("%s", usernameNew);
    printf("Password: ");
    scanf("%s", passwordNew);

    char usernameLower[STR_MAX_SIZE];
    toLowerString(usernameNew, usernameLower);

       if (idxIsValInSet(&globalUsernames, usernameLower) != -1) {
        printf("\nSudah ada dokter bernama %s!\n\n", usernameLower);
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

    // Buat data dokter baru
    Doctor* newDoctor = createDoctorWithData(newId, usernameNew, passwordNew, usernameNew, "");
    if (newDoctor == NULL) {
        printf("ALOKASI MEMORI GAGAL\n");
        return;
    }

    GenericData* newGD = createGD((void*)newDoctor, DATA_TYPE_DOCTOR);
    if (newGD == NULL) {
        printf("GAGAL REALOKASI MEMORI\n");
        free(newDoctor);
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

    printf("\nDokter %s berhasil ditambahkan!\n\n", usernameNew);
}
  


void assignDokter(){
    char username[50];
    char ruangan[256];
    printf("Username: ");
    scanf("%s", username);
    printf("\n");

    // Cari idDokter di globalUserDatabase berdasarkan username
    int idDokter = -1;
    Doctor* dokterPtr = NULL;
    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData *gd = getGDbyIdx(&globalUserDatabase, i);
        if (gd->type == DATA_TYPE_DOCTOR) {
            Doctor* d = (Doctor*) gd->data;
            if (strcmp(d->username, username) == 0) {
                idDokter = d->id;
                dokterPtr = d;
                break;
            }
        }
    }

    if (idDokter == -1) {
        printf("Dokter dengan username %s tidak ditemukan.\n\n", username);
        return;
    }

    printf("Ruangan: ");
    scanf("%s", ruangan);
    printf("\n");

    // Konversi ruangan string (misal A2) ke index baris dan kolom
    int row, col;
    kodeRuanganKonverter(ruangan, &row, &col);

    if (row < 0 || row >= globalDenahRumahSakit.nRow || col < 0 || col >= globalDenahRumahSakit.nColumn) {
        printf("Ruangan %s tidak valid.\n\n", ruangan);
        return;
    }

    // Cek apakah dokter sudah menempati ruangan
    boolean dokterSudahDiassign = false;
    int rowAssigned = -1, colAssigned = -1;
    for (int i = 0; i < globalDenahRumahSakit.nRow; i++) {
        for (int j = 0; j < globalDenahRumahSakit.nColumn; j++) {
            if (globalDenahRumahSakit.Ruangan[i][j].idDokter == idDokter) {
                dokterSudahDiassign = true;
                rowAssigned = i;
                colAssigned = j;
                break;
            }
        }
        if (dokterSudahDiassign) break;
    }

    // Cek apakah ruangan target kosong
    int idDokterDiTarget = globalDenahRumahSakit.Ruangan[row][col].idDokter;

    if (!dokterSudahDiassign && idDokterDiTarget == 0) {
        // Kasus 1
        globalDenahRumahSakit.Ruangan[row][col].idDokter = idDokter;
        printf("Dokter %s berhasil diassign ke ruangan %s!\n\n", dokterPtr->username, ruangan);
    } 
    /* Kasus 2 ini sebenarnya PINDAH_DOKTER ya */
    // else if (dokterSudahDiassign && idDokterDiTarget == -1) {
    //     // Kasus 2
    //     printf("Dokter %s sudah diassign ke ruangan %c%d!\n",
    //            dokterPtr->username,
    //            'A' + rowAssigned, colAssigned + 1); }
    else if (!dokterSudahDiassign && idDokterDiTarget != 0) {
        // Kasus 3
        // Cari username dokter yang sudah menempati ruangan
        char namaDokterDiRuangan[50] = "DokterLain";
        for (int i = 0; i < globalUserDatabase.nEff; i++) {
            GenericData *gd = getGDbyIdx(&globalUserDatabase, i);
            if (gd->type == DATA_TYPE_DOCTOR) {
                Doctor* d = (Doctor*) gd->data;
                if (gd->type == idDokterDiTarget) {
                    strcpy(namaDokterDiRuangan, d->username);
                    break;
                }
            }
        }
        printf("Dokter %s sudah menempati ruangan %s!\n", namaDokterDiRuangan, ruangan);
        printf("Silakan cari ruangan lain untuk dokter %s.\n\n", dokterPtr->username);
    } else {
        // Kasus 4
        // Cari username dokter yang sudah menempati ruangan
        char namaDokterDiRuangan[50] = "DokterLain";
        for (int i = 0; i < globalUserDatabase.nEff; i++) {
            GenericData *gd = getGDbyIdx(&globalUserDatabase, i);
            if (gd->type == DATA_TYPE_DOCTOR) {
                Doctor* d = (Doctor*) gd->data;
                if ((gd->type) == idDokterDiTarget) {
                    strcpy(namaDokterDiRuangan, d->username);
                    break;
                }
            }
        }
        printf("Dokter %s sudah menempati ruangan %c%d!\n\n", dokterPtr->username, 'A' + rowAssigned, colAssigned + 1);
        // printf("Ruangan %s juga sudah ditempati dokter %s!\n", ruangan, namaDokterDiRuangan);
    }
}



