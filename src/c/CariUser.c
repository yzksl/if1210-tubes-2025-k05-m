#include <stdio.h>
#include <string.h>

#include "../header/CariUser.h"

void cariUser(ListDin globalUserDatabase) {
/* I.S. userDatabase yang terdefinisi dan tidak kosong */
/* F.S. menampilkan data (meliputi ID, nama, role, dan penyakit) user(pasien & dokter) yang dicari dalam bentuk tabel */
/* apabila data yang dicari tidak ada, maka program akan menampilkan "Tidak ditemukan user dengan nomor ID/nama...!" */
    int tabelEff = 0;

    for(int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* save = globalUserDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            tabelEff++;
            
        }else if(save->type == DATA_TYPE_DOCTOR) {
            tabelEff++;
        }
    }

    tabel printed[tabelEff];

    int idxPrinted = 0;

    for(int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* save = globalUserDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            Patient* p = (Patient*)(save->data);

            printed[idxPrinted].ID = p->id;

            strcpy(printed[idxPrinted].role, "Pasien");
            strcpy(printed[idxPrinted].nama, p->username);
            
            int eff = 0;
            
            while(p->riwayatPenyakit[eff] == '\0' && eff < STR_MAX_SIZE) {
                eff++;
            }
            
            if(eff != STR_MAX_SIZE) {
                strcpy(printed[idxPrinted].penyakit, p->riwayatPenyakit);
            } else {
                strcpy(printed[idxPrinted].penyakit, "(Belum diperiksa dokter)");
            }
            idxPrinted++;

        }else if(save->type == DATA_TYPE_DOCTOR) {
            Doctor* d = (Doctor*)(save->data);

            printed[idxPrinted].ID = d->id;

            strcpy(printed[idxPrinted].nama, d->username);
            strcpy(printed[idxPrinted].penyakit, "-");
            strcpy(printed[idxPrinted].role, "Dokter");

            idxPrinted++;
        }
    }

    int src;

    printf("Cari berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf(">>> Pilihan: ");

    scanf("%d", &src);

    printf("\n");

    if(src == 1) {
        int search;
        
        printf(">>> Masukkan nomor ID user: ");

        scanf("%d", &search);

        printf("\n");

        for(int i = 0; i < (tabelEff - 1); i++) {
            for(int j = 0; j < (tabelEff - i - 1); j++) {
                if(printed[j].ID > printed[j + 1].ID) {
                    tabel temp = printed[j + 1];

                    printed[j + 1] = printed[j];
                    printed[j] = temp;
                }
            }
        }

        int high = tabelEff - 1;
        int idx = -1;
        int low = 0;
        int mid;

        while(low <= high) {
            mid = (low + high)/2;

            if(printed[mid].ID == search) {
                idx = mid;
                break;
            } else if(search < printed[mid].ID) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(idx != -1) {
            printf("Menampilkan pengguna dengan nomor ID %d...\n", search);
            printf("ID   | Nama       | Role     | Penyakit    \n");
            printf("-------------------------------------------\n");

            printf("%-4d | %-10s | %-8s | %-12s \n", printed[idx].ID, printed[idx].nama, printed[idx].role, printed[idx].penyakit);
        } else {        
            printf("Tidak ditemukan pengguna dengan nomor ID %d!\n", search);
        }

        printf("\n");

    } else if(src == 2) {
        int idx;
        int count = 0;
        char search[MAX_TAB];

        printf(">>> Masukkan nama user: ");

        scanf("%s", &search);

        for(int i = 0; i < tabelEff; i++) {
            if(strcmp(printed[i].nama, search) == 0) {
                idx = i;
                count++;
            }
        }

        if(count == 1) {
            printf("Menampilkan pengguna dengan nama %s...\n", search);
            printf("ID   | Nama       | Role     | Penyakit    \n");
            printf("-------------------------------------------\n");

            printf("%-4d | %-10s | %-8s | %-12s \n", printed[idx].ID, printed[idx].nama, printed[idx].role, printed[idx].penyakit);

        } else {
            printf("Tidak ditemukan pengguna dengan nama %s!\n", search);
        }

        printf("\n");
    }
}
 

void cariDokter(ListDin globalUserDatabase) {
/* I.S. userDatabase yang terdefinisi dan tidak kosong */
/* F.S. menampilkan data (meliputi ID dan nama) dokter yang dicari dalam bentuk tabel */
/* apabila data yang dicari tidak ada, maka program akan menampilkan "Tidak ditemukan dokter dengan nomor ID/nama...!" */
    int tabelEff = 0;

    for(int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* save = globalUserDatabase.buffer[i];

        if(save->type == DATA_TYPE_DOCTOR) {
            tabelEff++;
        }
    }

    tabel printed[tabelEff];

    int idxPrinted = 0;

    for(int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* save = globalUserDatabase.buffer[i];
        
        if(save->type == DATA_TYPE_DOCTOR) {
            Doctor* d = (Doctor*)(save->data);

            printed[idxPrinted].ID = d->id;

            strcpy(printed[idxPrinted].nama, d->username);
            strcpy(printed[idxPrinted].penyakit, "-");
            strcpy(printed[idxPrinted].role, "Dokter");

            idxPrinted++;
        }
    }

    int src;

    printf("Cari berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf(">>> Pilihan: ");

    scanf("%d", &src);

    printf("\n");

    if(src == 1) {
        int search;
        
        printf(">>> Masukkan nomor ID dokter: ");

        scanf("%d", &search);

        printf("\n");

        for(int i = 0; i < (tabelEff - 1); i++) {
            for(int j = 0; j < (tabelEff - i - 1); j++) {
                if(printed[j].ID > printed[j + 1].ID) {
                    tabel temp = printed[j + 1];

                    printed[j + 1] = printed[j];
                    printed[j] = temp;
                }
            }
        }

        int high = tabelEff - 1;
        int idx = -1;
        int low = 0;
        int mid;

        while(low <= high) {
            mid = (low + high)/2;

            if(printed[mid].ID == search) {
                idx = mid;
                break;
            } else if(search < printed[mid].ID) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(idx != -1) {
            printf("Menampilkan dokter dengan nomor ID %d...\n", search);
            printf("ID   | Nama       \n");
            printf("------------------\n");

            printf("%-4d | %-10s \n", printed[idx].ID, printed[idx].nama);
        } else {        
            printf("Tidak ditemukan dokter dengan nomor ID %d!\n", search);
        }

        printf("\n");

    } else if(src == 2) {
        int idx;
        int count = 0;
        char search[MAX_TAB];

        printf(">>> Masukkan nama dokter: ");

        scanf("%s", &search);

        for(int i = 0; i < tabelEff; i++) {
            if(strcmp(printed[i].nama, search) == 0) {
                idx = i;
                count++;
            }
        }

        if(count == 1) {
            printf("Menampilkan dokter dengan nama %s...\n", search);
            printf("ID   | Nama       \n");
            printf("------------------\n");

            printf("%-4d | %-10s  \n", printed[idx].ID, printed[idx].nama);

        } else {
            printf("Tidak ditemukan dokter dengan nama %s!\n", search);
        }

        printf("\n");
    }
}

void cariPasien(ListDin globalUserDatabase) {
/* I.S. userDatabase yang terdefinisi dan tidak kosong */
/* F.S. menampilkan data (meliputi ID, nama, dan penyakit) pasien yang dicari dalam bentuk tabel */
/* apabila data yang dicari tidak ada, maka program akan menampilkan "Tidak ditemukan pasien dengan nomor ID/nama/penyakit...!" */
    int tabelEff = 0;

    for(int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* save = globalUserDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            tabelEff++;   
        }
    }

    tabel printed[tabelEff];

    int idxPrinted = 0;

    for(int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* save = globalUserDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            Patient* p = (Patient*)(save->data);

            printed[idxPrinted].ID = p->id;

            strcpy(printed[idxPrinted].role, "Pasien");
            strcpy(printed[idxPrinted].nama, p->username);
            strcpy(printed[idxPrinted].penyakit, p->riwayatPenyakit);   

            idxPrinted++;
        }
    }

    int src;

    printf("Cari berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf("3. Penyakit\n");
    printf(">>> Pilihan: ");

    scanf("%d", &src);

    printf("\n");

    if(src == 1) {
        int search;
        
        printf(">>> Masukkan nomor ID pasien: ");

        scanf("%d", &search);

        printf("\n");

        for(int i = 0; i < (tabelEff - 1); i++) {
            for(int j = 0; j < (tabelEff - i - 1); j++) {
                if(printed[j].ID > printed[j + 1].ID) {
                    tabel temp = printed[j + 1];

                    printed[j + 1] = printed[j];
                    printed[j] = temp;
                }
            }
        }

        int high = tabelEff - 1;
        int idx = -1;
        int low = 0;
        int mid;

        while(low <= high) {
            mid = (low + high)/2;

            if(printed[mid].ID == search) {
                idx = mid;
                break;
            } else if(search < printed[mid].ID) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(idx != -1) {
            printf("Menampilkan pasien dengan nomor ID %d...\n", search);
            printf("ID   | Nama       | Penyakit    \n");
            printf("--------------------------------\n");

            printf("%-4d | %-10s | %-8s | %-12s \n", printed[idx].ID, printed[idx].nama, printed[idx].role, printed[idx].penyakit);
        } else {        
            printf("Tidak ditemukan pasien dengan nomor ID %d!\n", search);
        }

        printf("\n");

    } else if(src == 2) {
        int idx;
        int count = 0;
        char search[MAX_TAB];

        printf(">>> Masukkan nama pasien: ");

        scanf("%s", &search);

        printf("\n");

        for(int i = 0; i < tabelEff; i++) {
            if(strcmp(printed[i].nama, search) == 0) {
                idx = i;
                count++;
            }
        }

        if(count == 1) {
            printf("Menampilkan pasien dengan nama %s...\n", search);
            printf("ID   | Nama       | Penyakit    \n");
            printf("--------------------------------\n");

            printf("%-4d | %-10s | %-12s \n", printed[idx].ID, printed[idx].nama, printed[idx].penyakit);

        } else {
            printf("Tidak ditemukan pasien dengan nama %s!\n", search);
        }

        printf("\n");

    } else if(src == 3) {
        int idx;
        int count = 0;
        char search[MAX_TAB];

        printf(">>> Masukkan nama penyakit: ");

        scanf("%s", &search);

        printf("\n");

        for(int i = 0; i < tabelEff; i++) {
            if(strcmp(printed[i].penyakit, search) == 0) {
                count++;
                idx = i;
            }
        }

        if(count > 1) {
            tabel arr[count];

            for(int i = 0; i < count;) {
                for(int j = 0; j < tabelEff; j++) {
                    if(strcmp(printed[j].penyakit, search) == 0) {
                        arr[i] = printed[j];
                        i++;
                    }
                }
            }

            int urt, srt;

            printf("Urutkan berdasarkan?\n");
            printf("1. ID\n");
            printf("2. Nama\n");
            printf(">>> Pilihan: ");

            scanf("%d", &urt);

            printf("\n");

            if(urt == 1) {
                printf("Urutan sort ID?\n");
                printf("1. ASC (A-Z)\n");
                printf("2. DESC (Z-A)\n");
                printf(">>> Pilihan: ");

                scanf("%d", &srt);

                printf("\n");

                if(srt == 1) {
                    for(int i = 0; i < (count - 1); i++) {
                        for(int j = 0; j < (count - i - 1); j++) {
                            if(arr[j].ID > arr[j + 1].ID) {
                                tabel temp = arr[j + 1];

                                arr[j + 1] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                } else if(srt == 2) {
                    for(int i = 0; i < (count - 1); i++) {
                        for(int j = 0; j < (count - i - 1); j++) {
                            if(arr[j].ID < arr[j + 1].ID) {
                                tabel temp = arr[j + 1];

                                arr[j + 1] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                }
            } else if(urt == 2) {
                printf("Urutan sort nama?\n");
                printf("1. ASC (A-Z)\n");
                printf("2. DESC (Z-A)\n");
                printf(">>> Pilihan: ");

                scanf("%d", &srt);

                printf("\n");

                if(srt == 1) {
                    for(int i = 0; i < (count - 1); i++) {
                        for(int j = 0; j < (count - i - 1); j++) {
                            if(strcmp(arr[j].nama, arr[j + 1].nama) > 0) {
                                tabel temp = arr[j];

                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                } else if(srt == 2) {
                    for(int i = 0; i < (count - 1); i++) {
                        for(int j = 0; j < (count - i - 1); j++) {
                            if(strcmp(arr[j].nama, arr[j + 1].nama) < 0) {
                                tabel temp = arr[j];
                        
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }                       
                        }
                    }
                }
            }

            printf("Menampilkan pasien dengan penyakit %s...", search);
            printf("ID   | Nama       | Penyakit    \n");
            printf("--------------------------------\n");

            for(int i = 0; i < count; i++) {
                printf("%-4d | %-10s | %-12s \n", arr[i].ID, arr[i].nama, arr[i].penyakit);
            }

        } else if(count == 1) {
            printf("Menampilkan pasien dengan penyakit %s...\n", search);
            printf("ID   | Nama       | Penyakit    \n");
            printf("--------------------------------\n");

            printf("%-4d | %-10s | %-12s \n", printed[idx].ID, printed[idx].nama, printed[idx].penyakit);

        } else {
            printf("Tidak ditemukan pasien dengan penyakit %s!\n", search);
        }

        printf("\n");
    }
}