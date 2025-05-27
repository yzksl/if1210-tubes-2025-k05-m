#include <stdio.h>
#include <string.h>

#include "DynamicList.h"
#include "LihatUser.h"


void lihatUser(ListDin userDatabase) {
/*  I.S. userDatabase terdefinisi dan terisi */
/*  F.S. menampilkan data dokter dan pasien yang meliputi ID, nama, role, dan penyakit dalam tabel */
    int urt, srt;

    printf("Urutkan berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf(">>> Pilihan: ");
    scanf("%d", &urt);

    printf("Urutan sort?\n");
    printf("1. ASC (A-Z)\n");
    printf("2. DESC (Z-A)\n");
    printf(">>> Pilihan: ");
    scanf("%d", &srt);

    int tabelEff = 0;

    for(int i = 0; i < userDatabase.nEff; i++) {
        GenericData* save = userDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            tabelEff++;
            
        }else if(save->type == DATA_TYPE_DOCTOR) {
            tabelEff++;
        }
    }

    tabel printed[tabelEff];

    for(int i = 0; i < userDatabase.nEff; i++) {
        GenericData* save = userDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            Patient* p = (Patient*)(save->data);

            printed[i].ID = p->id;

            strcpy(printed[i].role, "Pasien");
            strcpy(printed[i].nama, p->username);
            strcpy(printed[i].penyakit, p->riwayatPenyakit);

            
        }else if(save->type == DATA_TYPE_DOCTOR) {
            Doctor* d = (Doctor*)(save->data);

            printed[i].ID = d->id;

            strcpy(printed[i].nama, d->name);
            strcpy(printed[i].penyakit, "-");
            strcpy(printed[i].role, "Dokter");
        }
    }

    if(urt == 1) {
        if(srt == 1) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(printed[j].ID > printed[j + 1].ID) {
                        tabel temp = printed[j + 1];

                        printed[j + 1] = printed[j];
                        printed[j] = temp;
                    }
                }
            }
        } else if(srt == 2) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(printed[j].ID < printed[j + 1].ID) {
                        tabel temp = printed[j + 1];

                        printed[j + 1] = printed[j];
                        printed[j] = temp;
                    }
                }
            }
        }
    } else if(urt == 2){
        if(srt == 1) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(strcmp(printed[j].nama, printed[j + 1].nama) > 0) {
                        tabel temp = printed[j];

                        printed[j] = printed[j + 1];
                        printed[j + 1] = temp;
                    }
                }
            }
        } else if(srt == 2){
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(strcmp(printed[j].nama, printed[j + 1].nama) < 0) {
                        tabel temp = printed[j];
                        
                        printed[j] = printed[j + 1];
                        printed[j + 1] = temp;
                    }                       
                }
            }
        }
    }

    printf("ID | Nama     | Role     | Penyakit  \n");
    printf("-------------------------------------\n");

    for(int i = 0; i < tabelEff; i++) {
        printf("%-2d | %-8s | %-8s | %-10s \n", printed[i].ID, printed[i].nama, printed[i].role, printed[i].penyakit);
    }
}
 

void lihatDokter(ListDin userDatabase) {
/*  I.S. userDatabase terdefinisi dan terisi */
/*  F.S. menampilkan data seluruh dokter pada database yang meliputi ID dan nama dalam tabel  */
    int urt, srt;

    printf("Urutkan berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf(">>> Pilihan: ");
    scanf("%d", &urt);

    printf("Urutan sort?\n");
    printf("1. ASC (A-Z)\n");
    printf("2. DESC (Z-A)\n");
    printf(">>> Pilihan: ");
    scanf("%d", &srt);

    int tabelEff = 0;

    for(int i = 0; i < userDatabase.nEff; i++) {
        GenericData* save = userDatabase.buffer[i];

        if(save->type == DATA_TYPE_DOCTOR) {
            tabelEff++;
        }
    }

    tabel printed[tabelEff];

    for(int i = 0; i < userDatabase.nEff; i++) {
        GenericData* save = userDatabase.buffer[i];
        
        if(save->type == DATA_TYPE_DOCTOR) {
            Doctor* d = (Doctor*)(save->data);

            printed[i].ID = d->id;

            strcpy(printed[i].nama, d->name);
            strcpy(printed[i].penyakit, "-");
            strcpy(printed[i].role, "Dokter");
        }
    }

    if(urt == 1) {
        if(srt == 1) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(printed[j].ID > printed[j + 1].ID) {
                        tabel temp = printed[j + 1];

                        printed[j + 1] = printed[j];
                        printed[j] = temp;
                    }
                }
            }
        } else if(srt == 2) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(printed[j].ID < printed[j + 1].ID) {
                        tabel temp = printed[j + 1];

                        printed[j + 1] = printed[j];
                        printed[j] = temp;
                    }
                }
            }
        }
    } else if(urt == 2){
        if(srt == 1) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(strcmp(printed[j].nama, printed[j + 1].nama) > 0) {
                        tabel temp = printed[j];

                        printed[j] = printed[j + 1];
                        printed[j + 1] = temp;
                    }
                }
            }
        } else if(srt == 2){
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(strcmp(printed[j].nama, printed[j + 1].nama) < 0) {
                        tabel temp = printed[j];
                        
                        printed[j] = printed[j + 1];
                        printed[j + 1] = temp;
                    }                       
                }
            }
        }
    }

    printf("ID | Nama     \n");
    printf("--------------\n");

    for(int i = 0; i < tabelEff; i++) {
        printf("%-2d | %-8s \n", printed[i].ID, printed[i].nama);
    }
}

void lihatPasien(ListDin userDatabase) {
/*  I.S. userDatabase terdefinisi dan terisi */
/*  F.S. menampilkan data seluruh pasien pada database yang meliputi ID, nama dan penyakit dalam tabel */
    int urt, srt;

    printf("Urutkan berdasarkan?\n");
    printf("1. ID\n");
    printf("2. Nama\n");
    printf(">>> Pilihan: ");
    scanf("%d", &urt);

    printf("Urutan sort?\n");
    printf("1. ASC (A-Z)\n");
    printf("2. DESC (Z-A)\n");
    printf(">>> Pilihan: ");
    scanf("%d", &srt);

    int tabelEff = 0;

    for(int i = 0; i < userDatabase.nEff; i++) {
        GenericData* save = userDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            tabelEff++;   
        }
    }

    tabel printed[tabelEff];

    for(int i = 0; i < userDatabase.nEff; i++) {
        GenericData* save = userDatabase.buffer[i];

        if(save->type == DATA_TYPE_PATIENT) {
            Patient* p = (Patient*)(save->data);

            printed[i].ID = p->id;

            strcpy(printed[i].role, "Pasien");
            strcpy(printed[i].nama, p->username);
            strcpy(printed[i].penyakit, p->riwayatPenyakit);   
        }
    }

    if(urt == 1) {
        if(srt == 1) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(printed[j].ID > printed[j + 1].ID) {
                        tabel temp = printed[j + 1];

                        printed[j + 1] = printed[j];
                        printed[j] = temp;
                    }
                }
            }
        } else if(srt == 2) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(printed[j].ID < printed[j + 1].ID) {
                        tabel temp = printed[j + 1];

                        printed[j + 1] = printed[j];
                        printed[j] = temp;
                    }
                }
            }
        }
    } else if(urt == 2){
        if(srt == 1) {
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(strcmp(printed[j].nama, printed[j + 1].nama) > 0) {
                        tabel temp = printed[j];

                        printed[j] = printed[j + 1];
                        printed[j + 1] = temp;
                    }
                }
            }
        } else if(srt == 2){
            for(int i = 0; i < (tabelEff - 1); i++) {
                for(int j = 0; j < (tabelEff - i - 1); j++) {
                    if(strcmp(printed[j].nama, printed[j + 1].nama) < 0) {
                        tabel temp = printed[j];
                        
                        printed[j] = printed[j + 1];
                        printed[j + 1] = temp;
                    }                       
                }
            }
        }
    }

    printf("ID | Nama     | Penyakit  \n");
    printf("--------------------------\n");

    for(int i = 0; i < tabelEff; i++) {
        printf("%-2d | %-8s | %-10s \n", printed[i].ID, printed[i].nama, printed[i].penyakit);
    }
}