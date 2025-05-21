#include <stdio.h>


void AntrianSaya(){
    if(!Terdaftar){
        printf("\nAnda belum terdaftar dalam antrian check-up!\n");
        printf("Silakan daftar terlebih dahulu dengan command DAFTAR_CHECKUP.\n");
    }
    else{
        printf("\nStatus antrian Anda:\n");
        printf("Dokter: %s\n", nama_dokter);
        printf("Ruangan: %s\n", kode_ruangan);
        printf("Posisi antrian: %d dari %d\n", no_antrian,total_antrian);

    }
}