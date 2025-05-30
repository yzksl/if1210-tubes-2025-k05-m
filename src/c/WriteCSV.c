#include "WriteCSV.h"
#include <stdio.h>
#include "StructsInHospital.h"
#include "GlobalVariable.h"
#include <string.h>
#include <stdlib.h>
#include "ReadCSV.h"

// csv files that will be written to:
static const char* filenameList[] = {
    "user.csv",
    "obat.csv",
    "penyakit.csv",
    "obat_penyakit.csv",
    NULL
};

void saveCSV() {
    char path[MAX_PATH_LENGTH];
    while (true) {
        printf("Masukkan nama folder (contoh: data/hari_ini): ");
        scanf("%s", path);

        if (strstr(path, "\\")) {
            printf("Gunakan forward slashes (/), bukan backslashes (\\)\n");
        }
        // prevent path traversal attacks
        else if (strstr(path, "..") || strstr(path, "~")) {
            printf("Path tidak boleh mengandung '..' atau '~'\n");
        }
        else {
            break; // sudah valid
        }
    }
   
    // create folder if dne
    if (!doesFolderExist(path)) {
        printf("Membuat folder %s ...\n", path);
        createDir(path);
    }

    writeConfig(path);
    // write to all csv
    for (int i = 0; filenameList[i] != NULL; ++i) {
        writeToCSV(path, filenameList[i]);
    }

    printf("Data berhasil disimpan di folder %s!\n", path);
}

boolean doesFolderExist(const char* path) {
    char cmd[MAX_CMD_LENGTH];
    #ifdef _WIN32
        // convert to windows format (/ to \)
        char winPath[MAX_PATH_LENGTH];
        strcpy(winPath, path);
        char temp = winPath[0];
        for (int i = 0; i < MAX_PATH_LENGTH && winPath[i] != '\0'; ++i) {
            if (winPath[i] == '/') {
                winPath[i] = '\\';
            }
        }
        snprintf(cmd, sizeof(cmd), "if exist \"%s\\\" exit 0", path);
    #else
        snprintf(cmd, sizeof(cmd), "test -d \"%s\" && exit 0", path);
    #endif
    return (system(cmd) == 0);
}

void createDir(char* path) {
    char cmd[MAX_CMD_LENGTH];
    // if else but for macro
    #ifdef _WIN32
        // convert to windows format (/ to \)
        char winPath[MAX_PATH_LENGTH];
        strcpy(winPath, path);
        char temp = winPath[0];
        for (int i = 0; i < MAX_PATH_LENGTH && winPath[i] != '\0'; ++i) {
            if (winPath[i] == '/') {
                winPath[i] = '\\';
            }
        }
        snprintf(cmd, sizeof(cmd), "mkdir \"%s\" >nul 2>&1", winPath); // >nul 2&>1 is omit any messages sent by terminal
    #else
        snprintf(cmd, sizeof(cmd), "mkdir -p \"%s\" >/dev/null 2>&1", path);
    #endif
    system(cmd);
}

void writeToCSV(const char* folder, const char* filename) {
    // merge folder and filename
    char fullPath[MAX_PATH_LENGTH];
    snprintf(fullPath, sizeof(fullPath), "%s/%s", folder, filename);
    // overwrite or make file in mode write
    FILE* file = fopen(fullPath, "wb"); // wb is write in binary to prevent line ending conversion from lf to crlf
    if (file == NULL) {
        printf("ERROR: GAGAL MEMBUKA FILE %s\n", fullPath);
        return;
    }

    /* WRITE USER.CSV */
    if (strcmp(filename, "user.csv") == 0) {
        int numOfUsersDeleted = 0;

        // attribute row
        fprintf(file, "id;username;password;role;riwayat_penyakit;suhu_tubuh;tekanan_darah_sistolik;tekanan_darah_diastolik;detak_jantung;saturasi_oksigen;kadar_gula_darah;berat_badan;tinggi_badan;kadar_kolesterol;trombosit\n");
    
        // write data
        for (int i = 0; i < globalUserDatabase.nEff; ++i) {
            GenericData* gd = getGDbyIdx(&globalUserDatabase, i);
            DataType gdDataType = getDataTypeGD(gd);

            /* FOR PATIENT */
            if (gdDataType == DATA_TYPE_PATIENT) {
                Patient* p = getPatientInGD(gd);

                fprintf(file, "%d;%s;%s;pasien;%s", p->id, p->username, p->password, p->riwayatPenyakit);
                for (int j = 0; j < KONDISI_TUBUH_SIZE; ++j) {
                    if (p->kondisiTubuh[j] - UNDEF_INT_DATA < 0.001) {
                        // don't put number if undef, just put empty field
                        fprintf(file, ";");
                    }
                    else if (p->kondisiTubuh[j] == (int)p->kondisiTubuh[j]) {
                        fprintf(file, ";%.0f", p->kondisiTubuh[j]);
                    }
                    else {
                        fprintf(file, ";%.1f", p->kondisiTubuh[j]);
                    }
                }
                fprintf(file, "\n");
            }

            /* FOR DOCTOR */
            else if (gdDataType == DATA_TYPE_DOCTOR) {
                Doctor* d = getDoctorInGD(gd);
                
                fprintf(file, "%d;%s;%s;dokter;;;;;;;;;;;\n",
                    d->id, d->username, d->password);
            }

            /* FOR MANAGER */
            else if (gdDataType == DATA_TYPE_MANAGER) {
                Manager* m = getManagerInGD(gd);

                fprintf(file, "%d;%s;%s;manager;;;;;;;;;;;\n",
                    m->id, m->username, m->password);              
            }

            /* IF USER DELETED (DIED IF PATIENT, DELETED IF DOCTOR?), THEN DATATYPE BECOMES UNKNOWN */
            else {
                numOfUsersDeleted += 1;
                continue;
            }
        }

        // print jumlah pengguna yang dihapus jika ada
        if (numOfUsersDeleted > 0) {
            printf("Jumlah pengguna yang dihapus dari hospital Niemons: %d\n", numOfUsersDeleted);
        }
        printf("SAVED USER DATABASE!\n");
    }

    /* WRITE OBAT.CSV */
    else if (strcmp(filename, "obat.csv") == 0) {
        // attribute row
        fprintf(file, "obat_id;nama_obat\n");

        // write data
        for (int i = 0; i < globalObatDatabase.nEff; ++i) {
            fprintf(file, "%d;%s\n", globalObatDatabase.contents[i].id, globalObatDatabase.contents[i].name);
        }
        printf("SAVED OBAT DATABASE!\n");
    }

    /* WRITE PENYAKIT.CSV */
    else if (strcmp(filename, "penyakit.csv") == 0) {
        // attribute row
        fprintf(file, "id;nama_penyakit;suhu_tubuh_min;suhu_tubuh_max;tekanan_darah_sistolik_min;tekanan_darah_sistolik_max;tekanan_darah_diastolik_min;tekanan_darah_diastolik_max;detak_jantung_min;detak_jantung_max;saturasi_oksigen_min;saturasi_oksigen_max;kadar_gula_darah_min;kadar_gula_darah_max;berat_badan_min;berat_badan_max;tinggi_badan_min;tinggi_badan_max;kadar_kolesterol_min;kadar_kolesterol_max;trombosit_min;trombosit_max\n");

        // write data
        for (int i = 0; i < globalPenyakitDatabase.nEff; ++i) {
            fprintf(file, "%d;%s", globalPenyakitDatabase.contents[i].id, globalPenyakitDatabase.contents[i].name);
            for (int j = 0; j < THRESHOLD_SIZE; ++j) {
                if (globalPenyakitDatabase.contents[i].threshold[j] == (int)globalPenyakitDatabase.contents[i].threshold[j]) {
                    fprintf(file, ";%.0f", globalPenyakitDatabase.contents[i].threshold[j]);
                }
                else {
                    fprintf(file, ";%.1f", globalPenyakitDatabase.contents[i].threshold[j]);
                }
            }
            fprintf(file, "\n");
        }
        printf("SAVED PENYAKIT DATABASE!\n");
    }

    /* WRITE OBAT_PENYAKIT.CSV */
    else if (strcmp(filename, "obat_penyakit.csv") == 0) {
        // attribute row
        fprintf(file, "obat_id;penyakit_id;urutan_minum\n");

        // write data
        for (int i = 0; i < globalOPDatabase.nEff; ++i) {
            for (int j = 0; j < globalOPDatabase.contents[i].nEff; ++j) {
                fprintf(file, "%d;%d;%d\n", globalOPDatabase.contents[i].idObat[j], globalOPDatabase.contents[i].idPenyakit, (j+1));
            }
        }
        printf("SAVED OBAT PENYAKIT DATABASE!\n");
    }
    
    fclose(file);
}