#include <stdio.h>
#include <MainMenu.h>
#include <ReadConfig.h>
#include <ReadCSV.h>

int main() {
    // Your code goes here
    createLD(&globalUserDatabase, 22);
    createLD(&globalUserDatabase, 20);
    // baca setiap csv
    processCSV("file/user.csv");
    processCSV("file/obat.csv");
    processCSV("file/penyakit.csv");
    processCSV("file/obat_penyakit.csv");

    printf("Finished processing.\n");

    // anggap login ke orang di index ke-2 (misal aja), dan kita tahu lebih dahulu bahwa dia pasien maka yang akan dijalankan adalah menu pasien (misal)
    globalCurrentUserGD = getGDbyIdx(&globalUserDatabase, 0);
    DataType currentUserType = getDataTypeGD(globalCurrentUserGD);
    readConfig();
    printf("====================\n\n====================\n");
    mainMenu();
    printf("====================\n\n====================\n");
    printf("CLEANING UP...\n");
    dealocateLD(&globalUserDatabase);
    printf("GOODBYE!\n");
    return 0;
}