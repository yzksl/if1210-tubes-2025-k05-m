#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Minum_Obat.h"


void PrintObat(){
    if(!diobatin){
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
        char nama_obat[10] = inventory[pilihan];
        printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", nama_obat);
        createStack(Stack* perut){

        }
        pushStack(Stack* perut, Obat o);
    }
    
    for(int i = pilihan; i<nEff; i++){
        inventory[i] = inventory[i+1];
    }
    nEff--;
}
