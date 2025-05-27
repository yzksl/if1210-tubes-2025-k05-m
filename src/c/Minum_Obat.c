#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Minum_Obat.h"

//procedure ini agar inventory rata kiri
void goToLeft(Patient* p) {
    int temp[INVENTORY_SIZE];
    int idx = 0;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (p->inventory[i] != -1) {
            temp[idx++] = p->inventory[i];
        }
    }

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (i < idx) {
            p->inventory[i] = temp[i];
        } else {
            p->inventory[i] = -1;
        }
    }
}

void minumObat(){
    printf("\n============ DAFTAR OBAT ============\n");
    int jlhObat = 0;
    for(int i = 0; i<INVENTORY_SIZE;++i){
        if(globalCurrentPatient->inventory[i] != IDX_UNDEF){
            Obat o = globalObatDatabase.contents[globalCurrentPatient->inventory[i]];
            printf("%d. %s\n", jlhObat+1, o.name);
            jlhObat++;
        }
        else{
            break;
        }
    }
    if(jlhObat = 0){
        printf("Belum ada obat dalam inventory Anda. Tolong minta obat dengan command NGOBATIN!!!\n");
        return;
    }
    int pilihan;
    scanf("\nPilih Obat untuk diminum: %d", &pilihan);

    if(pilihan<1 || pilihan >jlhObat){
        printf("\nPilihan nomor tidak tersedia!\n");
        return;
    }

    int idx = pilihan-1; //indexnya mulai dari 0
    int idObat = globalCurrentPatient->inventory[idx];
    Obat iniObat = globalObatDatabase.contents[idObat]; //disini masih dengan anggapan idObat == idx idObat

    pushStack(&(globalCurrentPatient->perut), iniObat);
    globalCurrentPatient->inventory[idx] = IDX_UNDEF; //dihapus dari list inventory

    goToLeft(globalCurrentPatient);

    printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", iniObat.name);
}

