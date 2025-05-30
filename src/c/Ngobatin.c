#include <stdio.h>
#include <string.h>
#include "GlobalVariable.h"
#include "Queue.h"
#include "StructsInHospital.h"
#include "Stack.h"
#include "DynamicList.h"
#include "Boolean.h"

/* Sequential search untuk mendapatkan data obat dari ID */
Obat* getObatById(int idObat) {
    for (int i = 0; i < globalObatDatabase.nEff; i++) {
        if (globalObatDatabase.contents[i].id == idObat) {
            return &globalObatDatabase.contents[i];
        }
    }
    return NULL;
}

void F12_NGOBATIN(Queue* antrianPasien) {
    printf(">>> NGOBATIN\n");

    // Pastikan antrian tidak kosong
    if (isQueueEmpty(antrianPasien)) {
        return;
    }

    // Ambil pasien terdepan
    LinkedListNode* pasienNode = antrianPasien->front;
    Patient* pasien = getPatientFromNode(pasienNode);

    if (pasien == NULL) {
        return;
    }

    // Pastikan pasien sudah didiagnosis
    if (strcmp(pasien->riwayatPenyakit, "") == 0) {
        printf("Pasien belum menerima diagnosis!\n");
        return;
    }

    // Cari ID penyakit dari database penyakit
    int idPenyakit = -1;
    for (int i = 0; i < globalPenyakitDatabase.nEff; i++) {
        if (strcmp(globalPenyakitDatabase.contents[i].name, pasien->riwayatPenyakit) == 0) {
            idPenyakit = globalPenyakitDatabase.contents[i].id;
            break;
        }
    }

    if (idPenyakit == -1) {
        printf("Penyakit tidak ditemukan dalam database!\n");
        return;
    }

    // Cari daftar obat berdasarkan penyakit
    boolean found = false;
    for (int i = 0; i < globalOPDatabase.nEff && !found; i++) {
        if (globalOPDatabase.contents[i].idPenyakit == idPenyakit) {
            found = true;

            printf("Dokter sedang mengobati pasien %s\n", pasien->username);
            printf("Pasien memiliki penyakit %s\n", pasien->riwayatPenyakit);
            printf("Obat yang harus diberikan:\n");

            for (int j = 0; j < globalOPDatabase.contents[i].nEff; j++) {
                int idObat = globalOPDatabase.contents[i].idObat[j];
                Obat* obat = getObatById(idObat);

                if (obat != NULL) {
                    // Masukkan obat ke inventory pasien
                    insertLastList(&(pasien->inventory), *obat);
                    printf("%d. %s\n", j + 1, obat->name);
                } else {
                    printf("%d. Obat dengan ID %d tidak ditemukan!\n", j + 1, idObat);
                }
            }
        }
    }

    if (!found) {
        printf("Tidak ada daftar obat untuk penyakit ini.\n");
    }
}
