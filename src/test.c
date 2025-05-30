#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/DynamicList.h"
#include "header/Boolean.h"
#include "header/ReadCSV.h"
#include "header/StructsInHospital.h"
#include "header/GlobalVariable.h"
#include "header/MainMenu.h"
#include "header/ReadConfig.h"
#include "header/ReadCSV.h"
#include "header/PrintArt.h"
/* di run dengan makefile */ 
/* ./test file */

int main(int argc, char** argv){
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
    globalCurrentUserGD = getGDbyIdx(&globalUserDatabase, 8);
    // DataType currentUserType = getDataTypeGD(globalCurrentUserGD);
    globalCurrentPatient = getPatientInGD(globalCurrentUserGD);
    if (globalCurrentPatient->sudahDiDiagnosis) {
        printf("sudah\n");
    } else {
        printf("belum\n");
    }

    globalCurrentPatient->sudahDiDiagnosis = true;
    if (globalCurrentPatient->sudahDiDiagnosis) {
        printf("sudah2");
    }
    readConfig(argv[1]);
    return 0;
}