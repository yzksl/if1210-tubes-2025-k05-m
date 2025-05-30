#include <stdio.h>
#include "../header/GlobalVariable.h"
#include "../header/AntrianSaya.h"


//Cek antrian berdasarkan id dan posisi ruangan
Point posisiRuanganAntrianPasien(int userId){
    Point lokasiRuangan={-1, -1, -1};
    for (int row=0; row<globalDenahRumahSakit.nRow; row++){
        for(int column=0; column<globalDenahRumahSakit.nColumn; column++){
            LinkedListNode* transversal = globalDenahRumahSakit.Ruangan[row][column].idAntrian.front;
            for (int i=0; i<globalDenahRumahSakit.Ruangan[row][column].idAntrian.size; i++){
                if (transversal->id==userId && i<globalDenahRumahSakit.kapasitasRuangan){
                    lokasiRuangan.antrian=-2;
                    lokasiRuangan.row=row;
                    lokasiRuangan.column=column;
                    return lokasiRuangan;
                }
                else if (transversal->id==userId && i>=globalDenahRumahSakit.kapasitasRuangan){
                    lokasiRuangan.antrian=i+1-globalDenahRumahSakit.kapasitasRuangan;
                    lokasiRuangan.row=row;
                    lokasiRuangan.column=column;
                    return lokasiRuangan;
                }
                transversal=transversal->next;
            }
        }
    }
    return lokasiRuangan;
}


void antrianSaya(){
    Point lokasiRuangan=posisiRuanganAntrianPasien((*(Patient*)globalCurrentUserGD->data).id);
    if(lokasiRuangan.antrian==-1){
        printf("\nAnda belum terdaftar dalam antrian check-up!\n");
        printf("Silakan daftar terlebih dahulu dengan command DAFTAR_CHECKUP.\n");
    }else if (lokasiRuangan.antrian==-2){
        printf("\nAnda sedang berada di dalam ruangan dokter!\n");
    }
    else {
            printf("\nStatus antrian Anda:\n");
            printf("Dokter: %s\n", getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR));
            printf("Ruangan: %c%d\n", lokasiRuangan.row+'A', lokasiRuangan.column+1);
            printf("Posisi antrian: %d dari %d\n", lokasiRuangan.antrian, globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.size-globalDenahRumahSakit.kapasitasRuangan);
        }
    

    }