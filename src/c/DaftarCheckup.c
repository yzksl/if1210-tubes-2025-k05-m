#include <stdio.h>
#include "../header/DaftarCheckup.h"
#include "../header/AntrianSaya.h"

void daftarCheckup(GenericData* globalCurrentUserGD) {
    Point lokasiRuangan = posisiRuanganAntrianPasien((*(Patient*)globalCurrentUserGD->data).id);

    if(lokasiRuangan.antrian == -1) {
        printf("Silahkan masukkan data checkup Anda:\n");

        printf("Suhu tubuh (celecius):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[0]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[0] < 0) {
            printf("Suhu tubuh harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[0]);
        }     
        printf("Tekanan darah (sistol/diastol, contoh 120 80):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1] < 0) {
            printf("Tekanan darah harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1]);
        }
        printf("Detak jantung (bpm):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2] < 0) {
            printf("Detak jantung harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2]);
        }
        printf("Saturasi oksigen:");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3] < 1 || ((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3] > 100) {
            printf("Saturasi oksigen harus dalam rentang 1 -100!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3]);
        }
        printf("Kadar gula darah (mg/dL):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[4]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[4] < 0) {
            printf("Kadar gula darah harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[4]);
        }
        printf("Berat badan (kg):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[5]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[5] < 0) {
            printf("Berat badan harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[5]);
        }
        printf("Tinggi badan (cm):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[6]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[6] < 0) {
            printf("Tinggi badan harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[6]);
        }
        printf("Kadar kolestrol (mg/dL):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[7]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[7] < 0) {
            printf("Kadar kolestrol harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[7]);
        }
        printf("Kadar kolestrol LDL (mg/dL):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[8]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[8] < 0) {
            printf("Kadar kolestrol LDL harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[8]);
        }
        printf("Trombosit (ribu/μL):");
        scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[9]);
        while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[9] < 0) {
            printf("Trombosit harus berupa angka positif!\n");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[9]);
        }
        printf("Berikut adalah daftar dokter yang tersedia:\n");

        int idxtemp = 0;
        int a[100], b[100];
        char name[100][100];
        char spes[100][100];
        for(int row = 0; row < globalDenahRumahSakit.nRow; row++) {
            for(int col = 0; col < globalDenahRumahSakit.nColumn; col++) {
                if(globalDenahRumahSakit.Ruangan[row][col].idAntrian.size < globalDenahRumahSakit.Ruangan[row][col].idAntrian.capacity && globalDenahRumahSakit.Ruangan[row][col].idDokter!=0) {
                    int idokter = globalDenahRumahSakit.Ruangan[row][col].idDokter;
                    a[idxtemp] = row;
                    b[idxtemp] = col;

                    for(int i = 0; i < globalUserDatabase.nEff; i++) {
                        if(globalUserDatabase.buffer[i]->type==DATA_TYPE_DOCTOR){
                            if(((Doctor*)(globalUserDatabase.buffer[i])->data)->id == idokter) {
                                for(int j = 0; j < 100; j++) {
                                    name[idxtemp][j] = ((Doctor*)(globalUserDatabase.buffer[i])->data)->username[j];
                                    spes[idxtemp][j] = ((Doctor*)globalUserDatabase.buffer[i]->data)->spesialisasi[j];
                                }
                            }
                        }
                    }
                    char baris = (char)(row + 65);
                    printf("%d. Dr. %s - Spesialisasi %s - Ruangan %c%d ", idxtemp + 1, name[idxtemp], spes[idxtemp], baris, col + 1);
                    if(globalDenahRumahSakit.Ruangan[row][col].nEffPasien < globalDenahRumahSakit.kapasitasRuangan) {
                        printf("(Ruangan belum penuh)\n");
                    } else {
                        printf("(Antrian: %d orang)\n", globalDenahRumahSakit.Ruangan[row][col].idAntrian.size);
                    }
                    idxtemp++;
                }
            }
        }

        printf("\n");
        if(idxtemp < 1) {
            printf("Maaf, tidak ada dokter yang tersedia!\n");
        } else if(idxtemp == 1) {
            printf("Pilih dokter (1):");
        } else {
            printf("Pilih dokter (1 - %d):", idxtemp);
        }


        int apalah;
        scanf("%d", &apalah);

        printf("\n");

        if(globalDenahRumahSakit.Ruangan[a[apalah - 1]][b[apalah - 1]].nEffPasien < globalDenahRumahSakit.kapasitasRuangan) {
            globalDenahRumahSakit.Ruangan[a[apalah - 1]][b[apalah - 1]].idPasien[globalDenahRumahSakit.Ruangan[a[apalah - 1]][b[apalah - 1]].nEffPasien] = ((Patient*)globalCurrentUserGD->data)->id;
            globalDenahRumahSakit.Ruangan[a[apalah - 1]][b[apalah - 1]].nEffPasien++;
            
            printf("Pendaftaran check-up berhasil!\n");
            printf("Anda terdaftar pada antrian Dr. %s di ruangan %c%d.\n", name[apalah - 1], (char)(a[apalah - 1] + 65), (b[apalah - 1] + 1));
            printf("Anda dapat langsung masuk ke dalam ruangan\n");
        } else {
            LinkedListNode* pasien = createLLNode(((Patient*)globalCurrentUserGD->data)->id, ((Patient*)globalCurrentUserGD->data)->username);

            enQueue(&globalDenahRumahSakit.Ruangan[a[apalah - 1]][b[apalah - 1]].idAntrian, pasien);

            printf("Pendaftaran check-up berhasil!\n");
            printf("Anda terdaftar pada antrian Dr. %s di ruangan %c%d.\n", name[apalah - 1], (char)(a[apalah - 1] + 65), (b[apalah - 1] + 1));
            printf("Posisi antrian anda: %d\n", globalDenahRumahSakit.Ruangan[a[apalah - 1]][b[apalah - 1]].idAntrian.size);
        }

    } else {
        printf("Anda sudah terdaftar dalam antrian check-up!\n"); 
        printf("Silakan selesaikan check-up yang sudah terdaftar terlebih dahulu.\n");
    }
}