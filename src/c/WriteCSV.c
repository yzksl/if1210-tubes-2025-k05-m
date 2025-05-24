#include "WriteCSV.h"
#include <stdio.h>
#include "Boolean.h"
#include "StructsInHospital.h"
#include "GlobalVariable.h"
#include <string.h>
#include <stdlib.h>

// csv files that will be written to:
static const char* filenamePathList[] = {
    "file/user.csv",
    NULL
};

void writeToCSV(const char* filename) {
    // find filename
    boolean isFilenameFound = false;
    for (int i = 0; filenamePathList[i] != NULL; ++i) {
        if (strcmp(filename, filenamePathList[i]) ==0) {
            isFilenameFound = true;
            break;
        }
    }
    if (!isFilenameFound) {
        printf("ERROR! TIDAK DITEMUKAN FILE %s\n", filename);
        return;
    }
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("ERROR DALAM MEMBUKA FILE %s\n", filename);
        return;
    }

    /* WRITE USER.CSV */
    if (strcmp(filename, "file/user.csv") == 0) {
        int numOfUsersDeleted = 0;

        // attribute row
        fprintf(file, "id;username;password;role;riwayat_penyakit;suhu_tubuh;tekanan_darah_sistolik;tekanan_darah_diastolik;detak_jantung;saturasi_oksigen;kadar_gula_darah;berat_badan;tinggi_badan;kadar_kolesterol;kadar_kolesterol_ldl;trombosit\n");
    
        // write data
        for (int i = 0; i < globalUserDatabase.nEff; ++i) {
            GenericData* gd = getGDbyIdx(&globalUserDatabase, i);
            DataType gdDataType = getDataTypeGD(gd);

            /* FOR PATIENT */
            if (gdDataType == DATA_TYPE_PATIENT) {
                Patient* p = getPatientInGD(gd);

                fprintf(file, "%d;%s;%s;pasien;%s", p->id, p->username, p->password, p->riwayatPenyakit);
                for (int j = 0; j < KONDISI_TUBUH_SIZE; ++j) {
                    fprintf(file, ";%.1f", p->kondisiTubuh[j]);
                }
                fprintf(file, "\n");
            }

            /* FOR DOCTOR */
            else if (gdDataType == DATA_TYPE_DOCTOR) {
                Doctor* d = getDoctorInGD(gd);
                
                fprintf(file, "%d;%s;%s;dokter;;;;;;;;;;;;;\n",
                    d->id, d->username, d->password);
            }

            /* FOR MANAGER */
            else if (gdDataType == DATA_TYPE_MANAGER) {
                Manager* m = getManagerInGD(gd);

                fprintf(file, "%d;%s;%s;manager;;;;;;;;;;;;;\n",
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
    
    fclose(file);
}