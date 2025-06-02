#include <stdio.h>
#include <string.h>
#include "GlobalVariable.h"
#include "Queue.h"
#include "StructsInHospital.h"
#include "Stack.h"
#include "DynamicList.h"
#include "Boolean.h"
#include "Ngobatin.h"
 
void resetPatientData() {
    strcpy(globalCurrentPatient->riwayatPenyakit, "");
    deleteStack(&(globalCurrentPatient->perut));
    for (int i = 0; i < KONDISI_TUBUH_SIZE; i++) {
        globalCurrentPatient->kondisiTubuh[i] = UNDEF_INT_DATA;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        globalCurrentPatient->inventory[i] = UNDEF_INT_DATA;
    }
}
 
void pulangDok(Queue* antrianPasien) {
    if (globalCurrentPatient == NULL) {
            printf("\nPasien tidak ditemukan dalam database!\n\n");
            return;
    }
 
    if(globalCurrentPatient->sudahDiDiagnosis == false){
        printf("\nKamu belum menerima diagnosis apapun dari dokter, jangan buru-buru pulang!\n\n");
        return;
    }
 
    if(globalCurrentPatient->sudahDiObatin == false){
        printf("\nKamu belum menerima obat dari dokter, jangan buru buru pulang!\n\n");
        return;
    }
   
    printf("\nDokter sedang memeriksa keadaanmu...\n");
    // Temukan id penyakit
    int idPenyakit = -1;
    for (int i = 0; i < globalPenyakitDatabase.nEff; i++) {
        if (strcmp(globalPenyakitDatabase.contents[i].name, globalCurrentPatient->riwayatPenyakit) == 0) {
            idPenyakit = globalPenyakitDatabase.contents[i].id;
            break;
        }
    }
 
    if (idPenyakit == -1) {
        printf("Penyakit tidak ditemukan dalam database!\n\n");
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
        printf("Data obat tidak ditemukan untuk penyakit ini!\n\n");
        return;
    }
 
    if (stackSize(&globalCurrentPatient->perut) < op->nEff) {
        printf("\nMasih ada obat yang belum kamu habiskan, minum semuanya dulu yukk!\n\n");
        return;
    }
 
    // Cek urutan konsumsi obat (dibandingkan terbalik karena stack)
    boolean urutanBenar = true;
    for (int i = 0; i < op->nEff; i++) {
        if (globalCurrentPatient->perut.obat[i].id != op->idObat[i]) {
            urutanBenar = false;
        }
    }
 
    if (urutanBenar) {
        printf("\nSelamat! Kamu sudah dinyatakan sembuh oleh dokter. Silahkan pulang dan semoga sehat selalu!\n\n");
        resetPatientData();
        deQueue(antrianPasien);
        return;
    }
 
    // urutan salah
    printf("\nMaaf, tapi kamu masih belum bisa pulang!\n");
    printf("Urutan peminuman obat yang diharapkan:\n");
    for (int i = 0; i < op->nEff; i++) {
        Obat* o = getObatById(op->idObat[i]);
        printf("%s", o->name);
        if (i < op->nEff - 1) printf(" -> ");
    }
    printf("\n");
 
    printf("\nUrutan obat yang kamu minum:\n");
    for (int i = 0; i < op->nEff; i++) {
        if (globalCurrentPatient->perut.obat[i].id != op->idObat[i]) {
            urutanBenar = false;
        }
 
        Obat o = globalCurrentPatient->perut.obat[i];
        printf("%s", o.name);
        if (i < stackSize(&globalCurrentPatient->perut) - 1) printf(" -> ");
    }
    printf("\n");
 
   
    printf("\nSilahkan kunjungi dokter untuk meminta penawar yang sesuai!\n\n");
    return;
}
 
 