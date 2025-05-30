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

//ini dia fungsi utamanya
void minumObat(){
    globalCurrentPatient->sudahDiDiagnosis = true;
    globalCurrentPatient->sudahDiObatin = false;
    if(globalCurrentPatient->sudahDiDiagnosis){ //jika sudah diagnosis
        //cek dulu sudah diobatin atau tidak
        if(globalCurrentPatient->sudahDiObatin){ //jika sudah diobatin
            //ini untuk cek apakah ada obat di inventory
            int jlhObat = 0;
            for(int i = 0; i<INVENTORY_SIZE && globalCurrentPatient->inventory[i] != UNDEF_INT_DATA;++i){
                Obat o;
                for (int j = 0; j < globalObatDatabase.nEff; ++j) {
                    if (globalObatDatabase.contents[j].id == globalCurrentPatient->inventory[i]) {
                        o = globalObatDatabase.contents[j];
                        break;
                    }
                }
                jlhObat++;
            }
            if(jlhObat == 0){ //kalau tidak ada obat
                printf("Inventorynya udah kosong. Minum penawar dengan command PENAWAR jika perlu mengulang minum obat.\n");
                return;
            }
            else{ //kalau ada obat
                //daftar obat di-print ke layar
                printf("\n============ DAFTAR OBAT ============\n");
                for(int i = 0; i<INVENTORY_SIZE && globalCurrentPatient->inventory[i] != UNDEF_INT_DATA;++i){
                    Obat o;
                for (int j = 0; j < globalObatDatabase.nEff; ++j) {
                    if (globalObatDatabase.contents[j].id == globalCurrentPatient->inventory[i]) {
                        o = globalObatDatabase.contents[j];
                        break;
                        }
                    }
                    printf("%d. %s\n", i+1, o.name);
                }
                //pasien pilih obat untuk diminum
                int pilihan = UNDEF_INT_DATA;
                while(pilihan<1 || pilihan > jlhObat){
                    printf("\nPilih Obat untuk diminum: ");
                    scanf("%d", &pilihan);
        
                    if(pilihan<1 || pilihan >jlhObat){ //jika nomor yang diketik tidak ada pada urutan daftar obat
                        printf("\nPilihan nomor tidak tersedia!\n");
                    }

                }
                // buat variabel bertipe Obat untuk dipush ke perut
                Obat iniObat;
                for (int i = 0; i < globalObatDatabase.nEff; ++i) {
                    if (globalObatDatabase.contents[i].id == globalCurrentPatient->inventory[pilihan - 1]){
                        iniObat = globalObatDatabase.contents[i];
                    }
                }
                //Push obat ke perut (obatnya sekarang di top)
                pushStack(&(globalCurrentPatient->perut), iniObat);
                globalCurrentPatient->inventory[pilihan - 1] = UNDEF_INT_DATA; //dihapus dari list inventory
                goToLeft(); // meratakirikan printer daftar obat
                printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", iniObat.name); //nama obat berada di variabel iniObat
            }
        

        }
        else{ //sudah diagnosis tapi belum diobatin dokter
            printf("Anda belum meminta obat dari dokter. Minta obat dengan command NGOBATIN.\n");
        }
    }
    else{ //kalau belum diagnosis
            printf("Anda belum melakukan diagnosis. Lakukan diagnosis dengan command DIAGNOSIS.\n");

    }

}


// printf("\n============ DAFTAR OBAT ============\n");
// int jlhObat = 0;
// for(int i = 0; i<INVENTORY_SIZE && globalCurrentPatient->inventory[i] != UNDEF_INT_DATA;++i){
//     Obat o;
//     for (int j = 0; j < globalObatDatabase.nEff; ++j) {
//         if (globalObatDatabase.contents[j].id == globalCurrentPatient->inventory[i]) {
//             o = globalObatDatabase.contents[j];
//             break;
//         }
//     }
//     printf("%d. %s\n", jlhObat+1, o.name);
//     jlhObat++;
// }

// if(jlhObat == 0){
//     printf("Belum ada obat dalam inventory Anda. Tolong minta obat dengan command NGOBATIN!!!\n");
//     return;
// }
/*  // printf("\nPilih Obat untuk diminum: ");
    // scanf("%d", &pilihan);*/
// int pilihan;
// while(pilihan<1 || pilihan > jlhObat){
//     printf("\nPilih Obat untuk diminum: ");
//     scanf("%d", &pilihan);
    
//     if(pilihan<1 || pilihan >jlhObat){
//         printf("\nPilihan nomor tidak tersedia!\n");
//     }

// }


// Obat iniObat;
// for (int i = 0; i < globalObatDatabase.nEff; ++i) {
//     if (globalObatDatabase.contents[i].id == globalCurrentPatient->inventory[pilihan - 1]) {
//         iniObat = globalObatDatabase.contents[i];
//     }
// }

// pushStack(&(globalCurrentPatient->perut), iniObat);
// globalCurrentPatient->inventory[pilihan - 1] = UNDEF_INT_DATA; //dihapus dari list inventory

// goToLeft(); // meratakirikan printer list obat
// printf("\nGLEKGLEKGLEK... %s berhasil diminum!!!\n", iniObat.name);