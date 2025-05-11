#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/DynamicList.h"
#include "../header/Boolean.h"
#include "../header/Boolean.h"
#include "../header/ReadCSV.h"

CSVRow parseCSVLine(const char* line) {
    CSVRow row = {0};
    int fieldIdx = 0;
    int charIdx = 0;

    for (int i = 0; line[i] != '\0' && fieldIdx < MAX_FIELDS; i++) {
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

void processUserCSV(const char* filename, ListDin* userDatabase) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR DALAM MEMBUKA FILE\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
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
        
        int emptyInventory[INVENTORY_SIZE];
        memset(emptyInventory, 0, sizeof(emptyInventory));
        GenericData* gd = NULL;
        // extract role based fields
        if (strcmp(role, "pasien") == 0 && row.fieldCount >= NUM_OF_COL_PATIENT) {
            // float kondisiTubuh[KONDISI_TUBUH_SIZE] = {
            //     atof(row.fields[5]),   // suhuTubuh
            //     atof(row.fields[6]),   // tekananDarahSistolik
            //     atof(row.fields[7]),   // tekananDarahDiastolik
            //     atof(row.fields[8]),   // detakJantung
            //     atof(row.fields[9]),   // saturasiOksigen
            //     atof(row.fields[10]),  // kadarGulaDarah
            //     atof(row.fields[11]),  // beratBadan
            //     atof(row.fields[12]),  // tinggiBadan
            //     atof(row.fields[13]),  // kadarKolesterol
            //     atof(row.fields[14]),  // kadarKolesterolLDL
            //     atof(row.fields[15])   // trombosit
            // };

            float kondisiTubuh[KONDISI_TUBUH_SIZE];
            for (int i = 0; i < KONDISI_TUBUH_SIZE; ++i) {
                kondisiTubuh[i] = atof(row.fields[5 + i]);
            }
            
            Patient* p = createPatientWithData(
                id,
                username,
                password,
                row.fields[4],
                emptyInventory,
                kondisiTubuh
            );
            gd = createGD(p, DATA_TYPE_PATIENT);
        }
        else if (strcmp(role, "dokter") == 0) {
            Doctor* d = createDoctorWithData(id, username, password, "", "");
            gd = createGD(d, DATA_TYPE_DOCTOR);
        }
        else if (strcmp(role, "manager") == 0) {
            Manager* m = createManagerWithData(id, username, password);
            gd = createGD(m, DATA_TYPE_MANAGER);
        }
        else {
            printf("ERROR: ROLE TIDAK DIKENALI: %s, ID: %d\n", role, id);
            continue;
        }

        // add to database
        if (gd == NULL)  {
            printf("ERROR ON PROCESSING DATA WITH ID %d\n", id);
        }
        else {
            int temp = userDatabase->nEff;
            insertLastLD(userDatabase, gd);

            // if insertion fail, neff doesn't increment
            if (userDatabase->nEff == temp) {
                dealocateGD(gd);
            }
        }
    }
    fclose(file);
}