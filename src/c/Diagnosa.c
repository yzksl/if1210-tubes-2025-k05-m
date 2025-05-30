#include <stdio.h>
#include <string.h>
#include "GlobalVariable.h"
#include "Queue.h"
#include "StructsInHospital.h"
#include "DynamicList.h"
#include "Boolean.h"

void diagnosis(Queue* antrianPasien) {

    // 1. Cek apakah antrian kosong
    if (isQueueEmpty(antrianPasien)) {
        printf("\nTidak ada pasien untuk diperiksa!\n");
        return;
    }

    // 2. Ambil pasien terdepan dari antrian
    LinkedListNode* pasienNode = antrianPasien->front;
    Patient* pasien = getPatientFromNode(pasienNode);

    if (pasien == NULL) {
        printf("\nPasien tidak ditemukan\n");
        return;
    }

    // 3. Cek apakah pasien sudah pernah didiagnosis
    if (pasien->sudahDiDiagnosis){
        printf("\n%s Telah Didiagnosa\n", pasien->username);
        return;
    }

    if (strcmp(pasien->riwayatPenyakit, "") != 0) {
        printf("\n%s terdiagnosa penyakit %s!\n", pasien->username, pasien->riwayatPenyakit);
        pasien->sudahDiDiagnosis = true;
        return;
    }
    
    // 4. Lakukan diagnosis dengan mencocokkan kondisi tubuh terhadap threshold penyakit
    boolean cocok;
    for (int i = 0; i < globalPenyakitDatabase.nEff; i++) {
        Penyakit penyakit = globalPenyakitDatabase.contents[i];
        cocok = true;
        printf("\nCHECKING %s\n", penyakit.name);
        // Setiap penyakit memiliki threshold min dan max untuk 11 kondisi tubuh
        for (int j = 0; j < KONDISI_TUBUH_SIZE; j++) {
            float nilai = pasien->kondisiTubuh[j];
            float batasMin = penyakit.threshold[j * 2];
            float batasMax = penyakit.threshold[j * 2 + 1];

            if (nilai < batasMin || nilai > batasMax) {
                cocok = false;
                break;
            }
        }
        if(cocok){
            strcpy(pasien->riwayatPenyakit, penyakit.name);
            printf("\n%s terdiagnosa penyakit %s!\n", pasien->username, pasien->riwayatPenyakit);
            pasien->sudahDiDiagnosis = true;
            return;
        }

    }

    printf("\n%s tidak terdiagnosis penyakit apapun!\n", pasien->username);
    pasien->sudahDiDiagnosis = true;
}
