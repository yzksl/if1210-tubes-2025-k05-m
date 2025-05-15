#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void PrintObat(){
    if(!diobatin){
        printf("Belum ada obat tersedia\n");
    }
    else{
        printf("\n============ DAFTAR OBAT ============");
        int i;
        while(i = 1, i< nEff, i++){
            printf("%d. %s", i, inventory[i]);

        }}
}

int MinumObat(){
    scanf("Pilih Obat untuk diminum: %d", &pilihan);
    if(pilihan<=0 || pilihan >nEff){
        printf("Pilihan nomor tidak tersedia!");
    }
    else{
        printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", inventory[pilihan]);
        createStack(Stack* perut);
        pushStack(Stack* perut, Obat o);
    }
    
    for(int i = pilihan; i<nEff; i++){
        inventory[i] = inventory[i+1];
    }
    nEff--;
}
