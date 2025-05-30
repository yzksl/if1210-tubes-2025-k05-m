#include <stdio.h>
#include <string.h>
#include "GlobalVariable.h"
#include "Queue.h"
#include "StructsInHospital.h"
#include "DynamicList.h"
#include "Boolean.h"

void F11_DIAGNOSIS(Queue* antrianPasien) {

    // 1. Cek apakah antrian kosong
    if (isQueueEmpty(antrianPasien)) {
        printf("Tidak ada pasien untuk diperiksa!\n");
        return;
    }

    // 2. Ambil pasien terdepan dari antrian
    LinkedListNode* pasienNode = antrianPasien->front;
    Patient* pasien = getPatientFromNode(pasienNode);

    if (pasien == NULL) {
        return;
    }

    // 3. Cek apakah pasien sudah pernah didiagnosis
    if (strcmp(pasien->riwayatPenyakit, "") != 0) {
        return;
    }

    // 4. Lakukan diagnosis dengan mencocokkan kondisi tubuh terhadap threshold penyakit
    for (int i = 0; i < globalPenyakitDatabase.nEff; i++) {
        Penyakit penyakit = globalPenyakitDatabase.contents[i];
        boolean cocok = true;

        // Setiap penyakit memiliki threshold min dan max untuk 11 kondisi tubuh
        for (int j = 0; j < THRESHOLD_SIZE; j++) {
            int nilai = pasien->kondisiTubuh[j];
            int batasMin = penyakit.threshold[j * 2];
            int batasMax = penyakit.threshold[j * 2 + 1];

            if (!(nilai >= batasMin && nilai <= batasMax)) {
                cocok = false;
                break;
            }
        }

        // Jika cocok, diagnosa selesai
        if (cocok) {
            strcpy(pasien->riwayatPenyakit, penyakit.name);
            printf("%s terdiagnosa penyakit %s!\n", pasien->username, penyakit.name);
            return;
        }
    }

    // 5. Jika tidak cocok dengan penyakit apa pun
    printf("%s tidak terdiagnosis penyakit apapun!\n", pasien->username);
}
