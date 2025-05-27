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
// di run dengan gcc -o main .\main.c .\c\GlobalVariable.c .\c\StructsInHospital.c .\c\DynamicList.c .\c\ReadCSV.c
// .\main.exe
// belum dicoba di wsl dan makefile jujur

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
    globalCurrentUserGD = getGDbyIdx(&globalUserDatabase, 17);
    globalCurrentUserGD->type=DATA_TYPE_UNKNOWN;
    globalCurrentUserGD->data=NULL;
    DataType currentUserType = getDataTypeGD(globalCurrentUserGD);
    readConfig(argv[1]);
    printStart();
    mainMenu();
    printf("====================\n\n====================\n");
    printf("CLEANING UP...\n");
    dealocateLD(&globalUserDatabase);
    printf("GOODBYE!\n");
    return 0;
}