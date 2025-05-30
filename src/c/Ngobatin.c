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
 
void ngobatin(Queue* antrianPasien) {
   
    // Pastikan antrian tidak kosong
    if (isQueueEmpty(antrianPasien)) {
        printf("\nTidak ada pasien untuk diobatin!\n");
        return;
    }
   
    // Ambil pasien terdepan
    LinkedListNode* pasienNode = antrianPasien->front;
    Patient* pasien = getPatientFromNode(pasienNode);
 
    if (pasien == NULL) {
        return;
    }
 
    // Pastikan pasien sudah didiagnosis
    if (pasien->sudahDiDiagnosis == false) {
        printf("\nPasien belum menerima diagnosis!\n");
        return;
    }
 
    // Pastikan pasien tidak berulang-ulang diobatin
    if (pasien->sudahDiObatin == true) {
        printf("\nPasien sudah diobatin!\n");
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
        printf("\nPenyakit tidak ditemukan dalam database!\n");
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
                    // traverse through inventory untuk cari index inefektif
                    int l = 0;
                    while (l < INVENTORY_SIZE && pasien->inventory[l] != UNDEF_INT_DATA) {
                        l += 1;
                    }
                    // tambahin obat di index pertama inefektif
                    pasien->inventory[l] = idObat;
                    // keluarannya
                    printf("%d. %s\n", j + 1, obat->name);
                } else {
                    printf("\n%d. Obat dengan ID %d tidak ditemukan!\n", j + 1, idObat);
                }
            }
        }
    }
 
    if (!found) {
        printf("\nTidak ada daftar obat untuk penyakit ini.\n");
    }
    pasien->sudahDiObatin = true;
}
 
 