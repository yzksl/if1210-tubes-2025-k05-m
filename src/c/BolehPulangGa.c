#include <stdio.h>
#include <string.h>
#include "GlobalVariable.h"
#include "Queue.h"
#include "StructsInHospital.h"
#include "Stack.h"
#include "DynamicList.h"
#include "Boolean.h"

/* REVISI: */
/* resetPatientData bagian perut bener (kayaknya), tapi yang pasti harus ganti kondisi tubuhnya si */
    // // Temukan obat yang seharusnya diminum
    // ObatPenyakit* op = NULL;
    // for (int i = 0; i < globalOPDatabase.nEff; i++) {
    //     if (globalOPDatabase.contents[i].idPenyakit == idPenyakit) {
    //         op = &globalOPDatabase.contents[i];
    //         break;
    //     }
    // }
/* di bagian ini, pastikan jangan ubah-ubah op nya ya, apapun itu, soalnya itu data dalam database. kalau harus ganti, mending copy elemen dalam array opnya ke array lokal baru di fungsi kamu */
/* jadi, bikin var obat baru aja yang copy elemen dari obat tersebut */
/* popStack harusnya nge-delet juga si bukan ambil elemen atas doang, coba pastikan dengan jose saragi */
/* warnain obat-obat yang salah urutan */

Patient* getPatientFromNode(LinkedListNode* node) {
    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        if (globalUserDatabase.buffer[i]->type == DATA_TYPE_PATIENT) {
            Patient* p = (Patient*)(globalUserDatabase.buffer[i]->data);
            if (p->id == node->id) {
                return p;
            }
        }
    }
    return NULL;
}

void resetPatientData(Patient* pasien) {
    strcpy(pasien->riwayatPenyakit, "");
    deleteStack(&(pasien->perut));
    for (int i = 0; i < KONDISI_TUBUH_SIZE; i++) {
        pasien->kondisiTubuh[i] = 0.0;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        pasien->inventory[i] = 0;
    }
}

void F13_PULANGDOK(Queue* antrianPasien) {
    printf(">>> PULANGDOK\n");

    if (isQueueEmpty(antrianPasien)) {
        printf("Tidak ada pasien dalam ruangan!\n");
        return;
    }

    LinkedListNode* pasienNode = antrianPasien->front;
    Patient* pasien = getPatientFromNode(pasienNode);

    if (pasien == NULL) {
        printf("Pasien tidak ditemukan dalam database!\n");
        return;
    }

    if (strcmp(pasien->riwayatPenyakit, "") == 0) {
        printf("Kamu belum menerima diagnosis apapun dari dokter, jangan buru-buru pulang!\n");
        return;
    }

    // Temukan id penyakit
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

    // Temukan obat yang seharusnya diminum
    ObatPenyakit* op = NULL;
    for (int i = 0; i < globalOPDatabase.nEff; i++) {
        if (globalOPDatabase.contents[i].idPenyakit == idPenyakit) {
            op = &globalOPDatabase.contents[i];
            break;
        }
    }

    if (op == NULL) {
        printf("Data obat tidak ditemukan untuk penyakit ini!\n");
        return;
    }

    if (stackSize(&pasien->perut) < op->nEff) {
        printf("Masih ada obat yang belum kamu habiskan, minum semuanya dulu yukk!\n");
        return;
    }

    // Cek urutan konsumsi obat (dibandingkan terbalik karena stack)
    boolean urutanBenar = true;

    printf("Urutan peminuman obat yang diharapkan:\n");
    for (int i = 0; i < op->nEff; i++) {
        printf("%s", globalObatDatabase.contents[op->idObat[i]].name);
        if (i < op->nEff - 1) printf(" -> ");
    }
    printf("\n");

    printf("Urutan obat yang kamu minum:\n");
    for (int i = op->nEff - 1; i >= 0; i--) {
        Obat o = popStack(&pasien->perut);
        printf("%s", o.name);
        if (i > 0) printf(" -> ");
        if (strcmp(o.name, globalObatDatabase.contents[op->idObat[i]].name) != 0) {
            urutanBenar = false;
        }
    }
    printf("\n");

    if (!urutanBenar) {
        printf("Silahkan kunjungi dokter untuk meminta penawar yang sesuai!\n");
        return;
    }

    // Pasien sembuh dan boleh pulang
    printf("Selamat! Kamu sudah dinyatakan sembuh oleh dokter. Silahkan pulang dan semoga sehat selalu!\n");

    // Reset data pasien
    resetPatientData(pasien);

    // Keluarkan dari antrian
    deQueue(antrianPasien);
}
