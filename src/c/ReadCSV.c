#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/DynamicList.h"
#include "../header/Boolean.h"
#include "../header/ReadCSV.h"
#include "../header/StructsInHospital.h"
#include "../header/GlobalVariable.h"
#include "Set.h"
#include "Stack.h"

void loadCSV(int argc, char** argv) {
    // create database dengan list dynamic
    createLD(&globalUserDatabase, 20);
    createSet(&globalUsernames, 20);
    // baca csv-csv yang ada dalam folder yang ditentukan dalam input terminal
    if (argc < 2) {
        printf("ERROR: TIDAK ADA NAMA FOLDER YANG DIBERIKAN!\n");
        exit(1);
    } else {
        if (!isFileInPath(argv[1])) {
            printf("ERROR: FILE ATAU FOLDER TIDAK DITEMUKAN\n");
            exit(1);
        }
        processAllCSVInFolder(argv[1]);
    }
}

// csv files that will be read:
static const char *filenameList[] = {
    "user.csv",
    "obat.csv",
    "penyakit.csv",
    "obat_penyakit.csv",
    NULL
};

// static const char* filenamePathList[] = {
//     "file/user.csv",
//     "file/obat.csv",
//     "file/penyakit.csv",
//     "file/obat_penyakit.csv",
//     NULL
// };

static boolean isAllReadSuccessfully;

boolean isFileInPath(const char* path) {
    for (int i = 0; filenameList[i] != NULL; ++i) {
        // merge folder and filename
        char fullPath[MAX_PATH_LENGTH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, filenameList[i]);

        // try opening file in path
        FILE* file = fopen(fullPath, "r");
        if (file == NULL) {
            isAllReadSuccessfully = false;
            return false;
        }
        // close file if successfully read to check next one
        fclose(file);
    }
    return true;
}

CSVRow parseCSVLine(const char* line) {
    CSVRow row = {0};
    int fieldIdx = 0;
    int charIdx = 0;

    for (int i = 0; line[i] != '\0' && fieldIdx < MAX_FIELDS; i++) {
        if (line[i] == '\r') {
            /* skip clrf \r */
            continue;
        }
        if (line[i] == ';' || line[i] == '\n') {
            // end of field
            row.fields[fieldIdx][charIdx] = '\0';
            fieldIdx += 1;
            charIdx = 0;
        } else {
            // add chr to current field
            if (charIdx < MAX_FIELD_LENGTH - 1) {
                row.fields[fieldIdx][charIdx] = line[i];
                charIdx += 1;
            }
        }
    }
    row.fieldCount = fieldIdx;
    return row;
}

void processCSV(const char* folder, const char* filename) {
    // merge folder and filename
    char fullPath[MAX_PATH_LENGTH];
    // folder pasti ada karena ketentuan spesifikasi
    snprintf(fullPath, sizeof(fullPath), "%s/%s", folder, filename);

    FILE* file = fopen(fullPath, "r");
    if (file == NULL) {
        printf("ERROR DALAM MEMBUKA FILE %s\n", fullPath);
        isAllReadSuccessfully = false;
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // unprocess first row (column indicators)

    /* PROCESS USER.CSV*/
    if (strcmp(filename, "user.csv") == 0) {
        while (fgets(line, sizeof(line), file)) {
            // check and expand if full
            if (isLDFull(&globalUserDatabase)) {
                expandLD(&globalUserDatabase, 10); // expand by 10 slots
            }

            // split line into fields 
            CSVRow row = parseCSVLine(line);
            
            // skip empty/incomplete lines
            if (row.fieldCount < NUM_OF_COL_GENERIC_USER) {
                continue;
            }

            // extract generic fields 
            int id = atoi(row.fields[0]);
            char* username = row.fields[1];
            char* password = row.fields[2];
            char* role = row.fields[3];

            // add username into set
            if (isSetFull(&globalUsernames)) {
                expandSet(&globalUsernames, 10);
            }
            addToSet(&globalUsernames, username);

            // declare emptyInventory here because somehow not allowed to declare in the if in patient
            int emptyInventory[INVENTORY_SIZE];
            memset(emptyInventory, 0, sizeof(emptyInventory));
            GenericData* gd = NULL;
            // extract role based fields
            /* FOR PATIENT */
            if (strcmp(role, "pasien") == 0 && row.fieldCount >= NUM_OF_COL_PATIENT) {
                float kondisiTubuh[KONDISI_TUBUH_SIZE];
                for (int i = 0; i < KONDISI_TUBUH_SIZE; ++i) {
                    if (row.fields[5 + i][0] != '\0') {
                        // field is not empty => has valid value
                        kondisiTubuh[i] = atof(row.fields[5 + i]);
                    } else {
                        // field is empty, only has null terminate character
                        kondisiTubuh[i] = UNDEF_INT_DATA;
                    }
                } 
                Patient* p = createPatientWithData(
                    id,
                    username,
                    password,
                    row.fields[4],
                    emptyInventory,
                    kondisiTubuh
                );
                createStack(&p->perut);
                gd = createGD(p, DATA_TYPE_PATIENT);
            }
            /* FOR DOCTOR */
            else if (strcmp(role, "dokter") == 0) {
                // this part will change later, for now just use empty string
                // to fill the name and spesialisasi
                char name[50];
                memset(name, 0, sizeof(name));
                char spesialisasi[50];
                memset(spesialisasi, 0, sizeof(spesialisasi));

                Doctor* d = createDoctorWithData(id, username, password, name, spesialisasi);
                gd = createGD(d, DATA_TYPE_DOCTOR);
            }
            /* FOR MANAGER */
            else if (strcmp(role, "manager") == 0) {
                Manager* m = createManagerWithData(id, username, password);
                gd = createGD(m, DATA_TYPE_MANAGER);
            }
            /* UNKONWN */
            else {
                printf("ERROR: ROLE TIDAK DIKENALI: %s, ID: %d\n", role, id);
                isAllReadSuccessfully = false;
                continue;
            }

            // add to database
            if (gd == NULL)  {
                printf("ERROR ON PROCESSING DATA WITH ID %d\n", id);
                isAllReadSuccessfully = false;
            }
            else {
                int temp = globalUserDatabase.nEff;
                insertLastLD(&globalUserDatabase, gd);

                // if insertion fail, neff doesn't increment
                if (globalUserDatabase.nEff == temp) {
                    dealocateGD(gd);
                }
            }
        }
        // compress list dynamic after finishing
        compressLD(&globalUserDatabase);
        compressSet(&globalUsernames);
        printf("LOADED USER DATABASE!\n");
    }
    
    /* PROCESS OBAT.CSV */
    else if (strcmp(filename, "obat.csv") == 0) {
        globalObatDatabase.nEff = 0;
        int i = 0;
        while (fgets(line, sizeof(line), file)) {
            // split line into fields 
            CSVRow row = parseCSVLine(line);
            
            // skip empty/incomplete lines
            if (row.fieldCount < NUM_OF_COL_OBAT) {
                continue;
            }

            // make obat
            Obat obat;

            // extract  fields into obat
            obat.id = atoi(row.fields[0]);
            strcpy(obat.name, row.fields[1]);
            
            // add obat to database
            globalObatDatabase.contents[i] = obat;
            i += 1;
            globalObatDatabase.nEff += 1;
        }
        printf("LOADED OBAT DATABASE!\n");
    }
    
    /* PROCESS PENYAKIT.CSV */
    else if (strcmp(filename, "penyakit.csv") == 0) {
        globalPenyakitDatabase.nEff = 0;
        int i = 0;
        while (fgets(line, sizeof(line), file)) {
            // split line into fields 
            CSVRow row = parseCSVLine(line);
            
            // skip empty/incomplete lines
            if (row.fieldCount < NUM_OF_COL_PENYAKIT) {
                continue;
            }

            // make penyakit
            Penyakit penyakit;

            // extract  fields into penyakit
            penyakit.id = atoi(row.fields[0]);
            strcpy(penyakit.name, row.fields[1]);
            for (int j = 0; j < THRESHOLD_SIZE; ++j) {
                penyakit.threshold[j] = atof(row.fields[2 + j]);
            }

            // add obat to database
            globalPenyakitDatabase.contents[i] = penyakit;
            i += 1;
            globalPenyakitDatabase.nEff += 1;
        }
        printf("LOADED PENYAKIT DATABASE!\n");
    }
    
    /* PROCESS OBAT_PENYAKIT.CSV */
    else if (strcmp(filename, "obat_penyakit.csv") == 0) {
        globalOPDatabase.nEff = 0;
        int i = 0;
        while (fgets(line, sizeof(line), file)) {
            // split line into fields 
            CSVRow row = parseCSVLine(line);
            
            // skip empty/incomplete lines
            if (row.fieldCount < NUM_OF_COL_OP) {
                continue;
            }

            // extract fields
            int idObat = atoi(row.fields[0]);
            int idPenyakit = atoi(row.fields[1]);
            int obatUrutan = atoi(row.fields[2]);

            // check if penyakit id is already in the database
            int foundPenyakitID = false;
            int foundAtIdx = -1;
            for (int j = 0; j < globalOPDatabase.nEff; ++j) {
                if (globalOPDatabase.contents[j].idPenyakit == idPenyakit) {
                    foundPenyakitID = true;
                    foundAtIdx = j;
                    break;
                }
            }
            
            if (!foundPenyakitID) {
                // make obat penyakit
                ObatPenyakit op;
                op.idPenyakit = idPenyakit;
                op.idObat[obatUrutan - 1] = idObat;
                op.nEff = 1;
                // add new op to database at index i
                globalOPDatabase.contents[i] = op;
                globalOPDatabase.nEff += 1;
                i += 1;
            } else if (foundPenyakitID) {
                globalOPDatabase.contents[foundAtIdx].idObat[obatUrutan - 1] = idObat;
                globalOPDatabase.contents[foundAtIdx].nEff += 1;
            }            
        }
        printf("LOADED OBAT PENYAKIT DATABASE!\n");
    }
    else {
        printf("ERROR: FILE %s NOT FOUND\n", filename);
        isAllReadSuccessfully = false;
    }
    fclose(file);
}

void processAllCSVInFolder(const char* folderPath) {
    printf("Loading...\n");
    isAllReadSuccessfully = true;
    // call processCSV with param folderPath/each filename in filenameList array
    for (int i = 0; filenameList[i] != NULL; ++i) {
        processCSV(folderPath, filenameList[i]);
    }
    if (isAllReadSuccessfully) {
        printf("Finished Loading!\n");
        printf("Selamat datang di rumah sakit Niemons!\n");
    } else {
        printf("ERROR: TERDAPAT DATA YANG TIDAK DIBACA\n");
        exit(1);
    }
}
