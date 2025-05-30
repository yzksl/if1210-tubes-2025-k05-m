#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MinumObat.h"

//procedure ini agar inventory rata kiri
void goToLeft() {
    int temp[INVENTORY_SIZE];
    int idx = 0;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (globalCurrentPatient->inventory[i] != UNDEF_INT_DATA) {
            temp[idx++] = globalCurrentPatient->inventory[i];
        }
    }

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (i < idx) {
            globalCurrentPatient->inventory[i] = temp[i];
        } else {
            globalCurrentPatient->inventory[i] = UNDEF_INT_DATA;
        }
    }
}

void minumObat(){
    printf("\n============ DAFTAR OBAT ============\n");
    int jlhObat = 0;
    for(int i = 0; i<INVENTORY_SIZE && globalCurrentPatient->inventory[i] != UNDEF_INT_DATA;++i){
        Obat o;
        for (int j = 0; j < globalObatDatabase.nEff; ++j) {
            if (globalObatDatabase.contents[j].id == globalCurrentPatient->inventory[i]) {
                o = globalObatDatabase.contents[j];
                break;
            }
        }
        printf("%d. %s\n", jlhObat+1, o.name);
        jlhObat++;
    }
    
    if(jlhObat == 0){
        printf("Belum ada obat dalam inventory Anda. Tolong minta obat dengan command NGOBATIN!!!\n");
        return;
    }
    int pilihan;
    while(pilihan<1 || pilihan > jlhObat){
        printf("\nPilih Obat untuk diminum: ");
        scanf("%d", &pilihan);
        
        if(pilihan<1 || pilihan >jlhObat){
            printf("\nPilihan nomor tidak tersedia!\n");
        }

    }
    
    
    Obat iniObat;
    for (int i = 0; i < globalObatDatabase.nEff; ++i) {
        if (globalObatDatabase.contents[i].id == globalCurrentPatient->inventory[pilihan - 1]) {
            iniObat = globalObatDatabase.contents[i];
        }
    }

    pushStack(&(globalCurrentPatient->perut), iniObat);
    globalCurrentPatient->inventory[pilihan - 1] = UNDEF_INT_DATA; //dihapus dari list inventory
    
    goToLeft(); // meratakirikan printer list obat
    printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", iniObat.name);
}

