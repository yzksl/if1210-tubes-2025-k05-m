#include <stdio.h>
#include "../header/DaftarCheckup.h"
#include "../header/AntrianSaya.h"

void daftarCheckup(GenericData* globalCurrentUserGD) {
    Point lokasiRuangan = posisiRuanganAntrianPasien((*(Patient*)globalCurrentUserGD->data).id);

    if(lokasiRuangan.antrian == -1) {
        if((*(Patient*)globalCurrentUserGD->data).kondisiTubuh[0]==UNDEF_INT_DATA){
            printf("Silahkan masukkan data checkup Anda:\n");

            printf("Suhu tubuh (celecius): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[0]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[0] < 1) {
                printf("Suhu tubuh harus berupa angka positif!\n");
                printf("Suhu tubuh (celecius): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[0]);
            }     
            printf("Tekanan darah (sistol/diastol, contoh 120 80): ");
            scanf("%f %f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1], &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1] < 1 || ((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2] < 1) {
                printf("Tekanan darah harus berupa angka positif!\n");
                printf("Tekanan darah (sistol/diastol, contoh 120 80): ");
                scanf("%f %f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1], &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2]);
            }
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2] > ((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1]) {
                printf("Tekanan sistolik harus lebih besar dibanding diastolik!\n");
                printf("Tekanan darah (sistol/diastol, contoh 120 80): ");
                scanf("%f %f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[1], &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[2]);
            }
            printf("Detak jantung (bpm): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3] < 1) {
                printf("Detak jantung harus berupa angka positif!\n");
                printf("Detak jantung (bpm): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3]);
            }
            printf("Saturasi oksigen: ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[4]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[4] < 1 || ((Patient*)globalCurrentUserGD->data)->kondisiTubuh[3] > 100) {
                printf("Saturasi oksigen harus dalam rentang 1 - 100!\n");
                printf("Saturasi oksigen: ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[4]);
            }
            printf("Kadar gula darah (mg/dL): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[5]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[5] < 1) {
                printf("Kadar gula darah harus berupa angka positif!\n");
                printf("Kadar gula darah (mg/dL): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[5]);
            }
            printf("Berat badan (kg): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[6]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[6] < 1) {
                printf("Berat badan harus berupa angka positif!\n");
                printf("Berat badan (kg): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[6]);
            }
            printf("Tinggi badan (cm): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[7]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[7] < 1) {
                printf("Tinggi badan harus berupa angka positif!\n");
                printf("Tinggi badan (cm): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[7]);
            }
            printf("Kadar kolestrol (mg/dL): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[8]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[8] < 1) {
                printf("Kadar kolestrol harus berupa angka positif!\n");
                printf("Kadar kolestrol (mg/dL): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[8]);
            }
            printf("Trombosit (ribu/μL): ");
            scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[9]);
            while(((Patient*)globalCurrentUserGD->data)->kondisiTubuh[9] < 1) {
                printf("Trombosit harus berupa angka positif!\n");
                printf("Trombosit (ribu/μL): ");
                scanf("%f", &((Patient*)globalCurrentUserGD->data)->kondisiTubuh[9]);
            }
        }

        int count = 0;

        for(int row = 0; row < globalDenahRumahSakit.nRow; row++) {
            for(int col = 0; col < globalDenahRumahSakit.nColumn; col++) {
                if(globalDenahRumahSakit.Ruangan[row][col].idAntrian.size < globalDenahRumahSakit.Ruangan[row][col].idAntrian.capacity && globalDenahRumahSakit.Ruangan[row][col].idDokter != 0) {
                    count++;
                }
            }
        }
        printf("\n");

        if(count >= 1) {
            printf("Berikut adalah daftar dokter yang tersedia:\n");

            int idxtemp = 0;
            int rowtemp[100];
            int coltemp[100];
            char name[100][100];
            char spes[100][100];

            for(int row = 0; row < globalDenahRumahSakit.nRow; row++) {
                for(int col = 0; col < globalDenahRumahSakit.nColumn; col++) {
                    if(globalDenahRumahSakit.Ruangan[row][col].idAntrian.size < globalDenahRumahSakit.Ruangan[row][col].idAntrian.capacity && globalDenahRumahSakit.Ruangan[row][col].idDokter != 0) {
                        int idokter = globalDenahRumahSakit.Ruangan[row][col].idDokter;
                        rowtemp[idxtemp] = row;
                        coltemp[idxtemp] = col;

                        for(int i = 0; i < globalUserDatabase.nEff; i++) {
                            if(globalUserDatabase.buffer[i]->type == DATA_TYPE_DOCTOR){
                                if(((Doctor*)(globalUserDatabase.buffer[i])->data)->id == idokter) {
                                    for(int j = 0; j < MAX_CAPACITY; j++) {
                                        name[idxtemp][j] = ((Doctor*)(globalUserDatabase.buffer[i])->data)->username[j];
                                        spes[idxtemp][j] = ((Doctor*)(globalUserDatabase.buffer[i])->data)->spesialisasi[j];
                                    }
                                }
                            }
                        }
                        char baris = (char)(row + 65);
                        printf("%d. Dr. %s - Spesialisasi %s - Ruangan %c%d ", idxtemp + 1, name[idxtemp], spes[idxtemp], baris, col + 1);
                        
                        if(globalDenahRumahSakit.Ruangan[row][col].idAntrian.size < globalDenahRumahSakit.kapasitasRuangan) {
                            printf("(Ruangan belum penuh)\n");
                        } else {
                            printf("(Antrian: %d orang)\n", globalDenahRumahSakit.Ruangan[row][col].idAntrian.size-globalDenahRumahSakit.kapasitasRuangan);
                        }

                        idxtemp++;
                    }
                }
            }
            printf("\n");

            if(idxtemp == 1) {
                printf("Pilih dokter (1): ");
            } else if(idxtemp > 1) {
                printf("Pilih dokter (1 - %d): ", idxtemp);
            }

            int idx;
            scanf("%d", &idx);

            printf("\n");

            LinkedListNode* pasien = createLLNode(((Patient*)globalCurrentUserGD->data)->id, ((Patient*)globalCurrentUserGD->data)->username);

            enQueue(&globalDenahRumahSakit.Ruangan[rowtemp[idx - 1]][coltemp[idx - 1]].idAntrian, pasien);

            if(globalDenahRumahSakit.Ruangan[rowtemp[idx - 1]][coltemp[idx - 1]].idAntrian.size <= globalDenahRumahSakit.kapasitasRuangan) {
                printf("Pendaftaran check-up berhasil!\n");
                printf("Anda terdaftar pada antrian Dr. %s di ruangan %c%d.\n", name[idx - 1], (char)(rowtemp[idx - 1] + 65), (coltemp[idx - 1] + 1));
                printf("Anda dapat langsung masuk ke dalam ruangan.\n");
            } else {
                printf("Pendaftaran check-up berhasil!\n");
                printf("Anda terdaftar pada antrian Dr. %s di ruangan %c%d.\n", name[idx - 1], (char)(rowtemp[idx - 1] + 65), (coltemp[idx - 1] + 1));
                printf("Posisi antrian anda: %d.\n", globalDenahRumahSakit.Ruangan[rowtemp[idx - 1]][coltemp[idx - 1]].idAntrian.size-globalDenahRumahSakit.kapasitasRuangan);
            }
            printf("\n");

        } else {
            printf("Maaf, tidak ada dokter yang tersedia!\n\n");
        }

    } else {
        printf("Anda sudah terdaftar dalam antrian check-up!\n"); 
        printf("Silakan selesaikan check-up yang sudah terdaftar terlebih dahulu.\n\n");
    }
}