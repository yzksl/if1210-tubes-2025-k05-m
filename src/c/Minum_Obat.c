#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Minum_Obat.h"


int inventory[10]; //hanya untuk dummy, aslinya dibuat oleh f12
int nEff;//dummy, nEff dari inventory
void PrintObat(){
    if( p.inventory == NULL){
        printf("Belum ada obat tersedia\n");
    }
    else{
        printf("\n============ DAFTAR OBAT ============\n");
        int i;
        while(i = 1, i< nEff, i++){
            printf("%d. %s\n", i, inventory[i-1]);

        }}
}

void MinumObat(){
    int pilihan;
    scanf("Pilih Obat untuk diminum: %d", &pilihan);
    if(pilihan<=0 || pilihan >nEff){
        printf("Pilihan nomor tidak tersedia!\n");
    }
    else{
        Obat nama_obat[10] = inventory[pilihan];
        printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", nama_obat);
        Stack perut;
        createStack(&perut);
        Obat o = *nama_obat;//Obat o adalah nama obat di inventory yang dipilih
        pushStack(&perut, o);
    }
    
    for(int i = pilihan; i<nEff; i++){
        inventory[i] = inventory[i+1];
    }
    nEff--;
}
