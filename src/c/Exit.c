#include "GlobalVariable.h"
#include "Exit.h"
#include "WriteCSV.h"
#include "DynamicList.h"
#include "Set.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exitFromHospital() {
    // tanya jika ingin save. input diulang hingga valid
    char input = 'a';
    while (input != 'y' && input != 'n') {
        printf("Apakah Anda mau melakukan penyimpanan file yang sudah diubah? (y/n): ");
        scanf("%c", &input);
    }
    
    if (input == 'y' || input == 'Y') {
        saveCSV();
        // saveConfig; // txt save here
    }

    printf("Sampai jumpa, Niemons!\n");
    // free semua disini
    // JANGAN LUPA YANG QUEUE
    dealocateLD(&globalUserDatabase);
    freeSet(&globalUsernames);

    exit(0);
}