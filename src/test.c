#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/DynamicList.h"
#include "header/Boolean.h"
#include "header/ReadCSV.h"
#include "header/StructsInHospital.h"
#include "header/GlobalVariable.h"
#include "WriteCSV.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Set.h"
#include "Exit.h"
#include "Diagnosa.h"
#include "header/MainMenu.h"
#include "header/ReadConfig.h"
#include "header/ReadCSV.h"
#include "header/PrintArt.h"
/* di run dengan makefile */ 
/* ./test file */

int main(int argc, char** argv){
    /* di globalvariable.c ada deklarasi variable2 global, cek ya */
    /* intinya, global variable itu agar setiap fungsi dapat mengubah nilai dari variable tsb tanpa harus memanggil fungsi dengan parameter yang menerima addressnya */
    // selalu cek struktur data dari setiap tipe data ya
    
    loadCSV(argc, argv);
    // jika seluruh file dibaca dengan baik, maka akan lanjut programnya. jika tidak, maka akan keluar dari program
    // anggap login ke orang di index ke-2 (misal aja), dan kita tahu lebih dahulu bahwa dia pasien maka yang akan dijalankan adalah menu pasien (misal)
    globalCurrentUserGD = getGDbyIdx(&globalUserDatabase, 19);
    DataType currentUserType = getDataTypeGD(globalCurrentUserGD);
    globalCurrentPatient = getPatientInGD(globalCurrentUserGD);

    printf("ID: %d, Nama: %s\n", globalCurrentPatient->id, globalCurrentPatient->username);
    // // ambil langsung pointer ke data pasiennya aja, gausah genericdatanya untuk simplisitas. ini yang dijadikan global
    // if (currentUserType == DATA_TYPE_PATIENT) {
    //     Patient* globalCurrentPatient = getPatientInGD(globalCurrentUserGD);
    //     if (globalCurrentPatient) {
    //         printf("GOT CURRENT PATIENT!\n");
    //     }
    //     // run other functions for patient here
    //     // menuPatient()
    //     // misal kita mau tau username, password, etc
    //     // lihat struct Patient di StructsInHospital.h
    //     int currentUserID = globalCurrentPatient->id;
    //     char currentUserUsername[STR_MAX_SIZE];
    //     strcpy(currentUserUsername, globalCurrentPatient->username);
    //     char currentUserPassword[STR_MAX_SIZE];
    //     strcpy(currentUserPassword, globalCurrentPatient->password);
    //     char currentUserRP[STR_MAX_SIZE];
    //     strcpy(currentUserRP, globalCurrentPatient->riwayatPenyakit);
    //     float currentUserTK0 = globalCurrentPatient->kondisiTubuh[0]; // kondisi tubuh index 0, yaitu suhu tubuh in this case (cek line 1 user.csv)
    //     printf("ID: %d\nUsername: %s\nPassword: %s\nRiwayat Penyakit: %s\nSuhu Tubuh: %f\n", currentUserID, currentUserUsername, currentUserPassword, currentUserRP, currentUserTK0);
    //     printf("Other kondisi tubuh:\n");
    //     for (int z = 0; z < KONDISI_TUBUH_SIZE; ++z){
    //         printf("%.1f ", globalCurrentPatient->kondisiTubuh[z]);
    //     }
    //     printf("\n");
    // } else if (currentUserType == DATA_TYPE_DOCTOR) {
    //     globalCurrentDoctor = getDoctorInGD(globalCurrentUserGD);
    //     if (globalCurrentDoctor) {
    //         printf("GOT CURRENT DOCTOR!\n");
    //     }
    //     // run other functions for doctor here
    //     // menuDoctor()

    // } else if (currentUserType == DATA_TYPE_MANAGER) {
    //     globalCurrentManager = getManagerInGD(globalCurrentUserGD);
    //     if (globalCurrentManager) {
    //         printf("GOT CURRENT MANAGER!\n");
    //     }
    // }

    // // anggap kita mau ketahui neff-neff dan obat, penyakit, obat-penyakit di indeks tertentu gitu, kita bisa gini
    // // selalu cek struktur data dari setiap tipe data ya
    // printf("nEff Database obat: %d\n", globalObatDatabase.nEff);
    // for (int i = 0; i < globalObatDatabase.nEff; ++i) {
    //     printf("ID: %d. Nama: %s\n", globalObatDatabase.contents[i].id, globalObatDatabase.contents[i].name);
    // }
    // printf("nEff Database Penyakit: %d\n", globalPenyakitDatabase.nEff);
    // for (int i = 0; i < globalPenyakitDatabase.nEff; ++i) {
    //     printf("ID: %d. Nama: %s\n", globalPenyakitDatabase.contents[i].id, globalPenyakitDatabase.contents[i].name);
    // }
    // printf("nEeff Database Obat-Penyakit %d\n", globalOPDatabase.nEff);
    // for (int i = 0; i < globalOPDatabase.nEff; ++i) {
    //     printf("Penyakit: %d, obat:", globalOPDatabase.contents[i].idPenyakit);
    //     for (int j = 0; j < globalOPDatabase.contents[i].nEff; ++j) {
    //         printf(" %d", globalOPDatabase.contents[i].idObat[j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < globalUserDatabase.nEff; ++i) {
    //     GenericData* gd = getGDbyIdx(&globalUserDatabase, i);
    //     if (gd->type == DATA_TYPE_PATIENT) {
    //         Patient* orang = getPatientInGD(gd);
    //         printf("ID: %d, NAMA PASIEN: %s\n", orang->id, orang->username);
    //     } else if (gd->type == DATA_TYPE_DOCTOR) {
    //         Doctor* orang = getDoctorInGD(gd);
    //         printf("ID: %d, NAMA DOKTER: %s\n", orang->id, orang->username);
    //     } else if (gd->type == DATA_TYPE_MANAGER) {
    //         Manager* orang = getManagerInGD(gd);
    //         printf("ID: %d, NAMA MANAGER: %s\n", orang->id, orang->username);
    //     } else {
    //         printf("USER ERROR\n");
    //     }
    // }

    Queue antrian;
    createQueue(&antrian, 4);

    // cek kasus antrian kosong
    diagnosis(&antrian);


    // antrian sedang ditambah
    GenericData* gd = getGDbyIdx(&globalUserDatabase, 20);
    Patient* patientDalamAntrian = getPatientInGD(gd);
    LinkedListNode* orang = createLLNode(patientDalamAntrian->id, patientDalamAntrian->username);
    enQueue(&antrian, orang);

    gd = getGDbyIdx(&globalUserDatabase, 10);
    patientDalamAntrian = getPatientInGD(gd);
    orang = createLLNode(patientDalamAntrian->id, patientDalamAntrian->username);
    enQueue(&antrian, orang);

    gd = getGDbyIdx(&globalUserDatabase, 7);
    patientDalamAntrian = getPatientInGD(gd);
    orang = createLLNode(patientDalamAntrian->id, patientDalamAntrian->username);
    enQueue(&antrian, orang);

    gd = getGDbyIdx(&globalUserDatabase, 8);
    patientDalamAntrian = getPatientInGD(gd);
    orang = createLLNode(patientDalamAntrian->id, patientDalamAntrian->username);
    enQueue(&antrian, orang);

    // print orang2 dalam antrian
    LinkedListNode* forTraverse = antrian.front;
    printf("Orang dalam antrian:\n");
    while (forTraverse != NULL) {
        printf("ID %d, nama %s\n", forTraverse->id, forTraverse->name);
        forTraverse = forTraverse->next;
    }

    // cek pasien antrien terdepan
    diagnosis(&antrian);
    diagnosis(&antrian);
    diagnosis(&antrian);
    diagnosis(&antrian);
    diagnosis(&antrian);

    // // masukkan 4 orang awal ke dalam queue
    // for (int i = 6; i < 10; ++i) {
    //     GenericData* gd = getGDbyIdx(&globalUserDatabase, i);
    //     Patient* patientDalamAntrian = getPatientInGD(gd);
    //     LinkedListNode* orang = createLLNode(patientDalamAntrian->id, patientDalamAntrian->username);
    //     enQueue(&antrian, orang);
    // }
    // // print orang2 dalam antrian
    // LinkedListNode* forTraverse = antrian.front;
    // printf("Orang dalam antrian:\n");
    // while (forTraverse != NULL) {
    //     printf("ID %d, nama %s\n", forTraverse->id, forTraverse->name);
    //     forTraverse = forTraverse->next;
    // }
    // // contoh dequeue
    // printf("Orang ini akan masuk ruangan: %s\n", antrian.front->name);
    // deQueue(&antrian);
    // //conoh enqueue
    // printf("Dan orang ini akan masuk antrian: ");
    // GenericData *gd = getGDbyIdx(&globalUserDatabase, 8); // misal, pasti pasien
    // Patient* pAkanMasukAntrian = getPatientInGD(gd);
    // LinkedListNode* orang = createLLNode(pAkanMasukAntrian->id, pAkanMasukAntrian->username);
    // enQueue(&antrian, orang);
    // printf("%s\n", pAkanMasukAntrian->username);
    // printf("Sekarang, orang dalam antrian:\n");
    // forTraverse = antrian.front;
    // while (forTraverse != NULL) {
    //     printf("ID %d, nama %s\n", forTraverse->id, forTraverse->name);
    //     forTraverse = forTraverse->next;
    // }

    // printf("NOW FOR SETTTTTTTTTTTTTTTTTT\n");
    // // print set
    // printf("%s", globalUsernames.buffer[0]);
    // for (int i = 1; i < globalUsernames.nEff; ++i) {
    //     printf(", %s", globalUsernames.buffer[i]);
    // }
    // printf("\n");
    // // check if can add duplicate value
    // printf("NOW CHECK IF I CAN ADD DUPLICATE VALUE (stewart)\n");
    // GenericData* gd2 = getGDbyIdx(&globalUserDatabase, 6);
    // // stewart itu patient
    // Patient* p = getPatientInGD(gd2);
    // expandSet(&globalUsernames, 1);
    // addToSet(&globalUsernames, p->username); // duplikat, maka tidak akan ditambah
    // printf("THAT'S ALL FOR SET!\n");

    printf("CLEANING UP...\n");
    saveCSV();
    dealocateLD(&globalUserDatabase);
    freeSet(&globalUsernames);
    printf("GOODBYE!\n");
    return 0;
}