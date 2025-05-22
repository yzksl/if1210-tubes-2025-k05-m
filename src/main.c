#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/DynamicList.h"
#include "header/Boolean.h"
#include "header/ReadCSV.h"
#include "header/StructsInHospital.h"
#include "header/GlobalVariable.h"
#include "WriteCSV.h"
/* di run dengan makefile */ 
/* ./build/main file */

int main(int argc, char** argv){
    /* di globalvariable.c ada deklarasi variable2 global, cek ya */
    /* intinya, global variable itu agar setiap fungsi dapat mengubah nilai dari variable tsb tanpa harus memanggil fungsi dengan parameter yang menerima addressnya */
    // selalu cek struktur data dari setiap tipe data ya
    
    // create database dengan list dynamic
    createLD(&globalUserDatabase, 20);
    // baca csv-csv yang ada dalam folder yang ditentukan dalam input terminal
    if (argc < 2) {
        printf("ERROR: TIDAK ADA NAMA FOLDER YANG DIBERIKAN!\n");
        exit(1);
    } else {
        processAllCSVInFolder(argv[1]);
    }
    // jika seluruh file dibaca dengan baik, maka akan lanjut programnya. jika tidak, maka akan keluar dari program
    // anggap login ke orang di index ke-2 (misal aja), dan kita tahu lebih dahulu bahwa dia pasien maka yang akan dijalankan adalah menu pasien (misal)
    globalCurrentUserGD = getGDbyIdx(&globalUserDatabase, 0);
    DataType currentUserType = getDataTypeGD(globalCurrentUserGD);
    // ambil langsung pointer ke data pasiennya aja, gausah genericdatanya untuk simplisitas. ini yang dijadikan global
    if (currentUserType == DATA_TYPE_PATIENT) {
        Patient* globalCurrentPatient = getPatientInGD(globalCurrentUserGD);
        if (globalCurrentPatient) {
            printf("GOT CURRENT PATIENT!\n");
        }
        // run other functions for patient here
        // menuPatient()
        // misal kita mau tau username, password, etc
        // lihat struct Patient di StructsInHospital.h
        int currentUserID = globalCurrentPatient->id;
        char currentUserUsername[STR_MAX_SIZE];
        strcpy(currentUserUsername, globalCurrentPatient->username);
        char currentUserPassword[STR_MAX_SIZE];
        strcpy(currentUserPassword, globalCurrentPatient->password);
        char currentUserRP[STR_MAX_SIZE];
        strcpy(currentUserRP, globalCurrentPatient->riwayatPenyakit);
        float currentUserTK0 = globalCurrentPatient->kondisiTubuh[0]; // kondisi tubuh index 0, yaitu suhu tubuh in this case (cek line 1 user.csv)
        printf("ID: %d\nUsername: %s\nPassword: %s\nRiwayat Penyakit: %s\nSuhu Tubuh: %f\n", currentUserID, currentUserUsername, currentUserPassword, currentUserRP, currentUserTK0);
    } else if (currentUserType == DATA_TYPE_DOCTOR) {
        globalCurrentDoctor = getDoctorInGD(globalCurrentUserGD);
        if (globalCurrentDoctor) {
            printf("GOT CURRENT DOCTOR!\n");
        }
        // run other functions for doctor here
        // menuDoctor()

    } else if (currentUserType == DATA_TYPE_MANAGER) {
        globalCurrentManager = getManagerInGD(globalCurrentUserGD);
        if (globalCurrentManager) {
            printf("GOT CURRENT MANAGER!\n");
        }
    }

    // anggap kita mau ketahui neff-neff dan obat, penyakit, obat-penyakit di indeks tertentu gitu, kita bisa gini
    // selalu cek struktur data dari setiap tipe data ya
    printf("nEff Database obat: %d\n", globalObatDatabase.nEff);
    for (int i = 0; i < globalObatDatabase.nEff; ++i) {
        printf("ID: %d. Nama: %s\n", globalObatDatabase.contents[i].id, globalObatDatabase.contents[i].name);
    }
    printf("nEff Database Penyakit: %d\n", globalPenyakitDatabase.nEff);
    for (int i = 0; i < globalPenyakitDatabase.nEff; ++i) {
        printf("ID: %d. Nama: %s\n", globalPenyakitDatabase.contents[i].id, globalPenyakitDatabase.contents[i].name);
    }
    printf("nEeff Database Obat-Penyakit %d\n", globalOPDatabase.nEff);
    for (int i = 0; i < globalOPDatabase.nEff; ++i) {
        printf("Penyakit: %d, obat:", globalOPDatabase.contents[i].idPenyakit);
        for (int j = 0; j < globalOPDatabase.contents[i].nEff; ++j) {
            printf(" %d", globalOPDatabase.contents[i].idObat[j]);
        }
        printf("\n");
    }
    writeToCSV("file/user.csv");
    printf("CLEANING UP...\n");
    dealocateLD(&globalUserDatabase);
    printf("GOODBYE!\n");
    return 0;
}