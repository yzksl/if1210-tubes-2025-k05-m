#include "../header/WriteConfig.h"
#include "../header/GlobalVariable.h"

void writeConfig(char path[]){
    // merge folder and filename
    char fullPath[MAX_PATH_LENGTH];
    // folder pasti ada karena ketentuan spesifikasi
    snprintf(fullPath, sizeof(fullPath), "%s/%s", path, "config.txt");
    FILE *configFile = fopen(fullPath, "w"); // Membuka file config
    
    fprintf(configFile,
        "%d %d%c\n"
        "%d %d%c\n"
        , globalDenahRumahSakit.nRow
        , globalDenahRumahSakit.nColumn
        , 13
        , globalDenahRumahSakit.kapasitasRuangan
        , globalDenahRumahSakit.kapasitasAntrian
        , 13
    );

    for (int row=0; row<globalDenahRumahSakit.nRow; row++){
        for (int column=0; column<globalDenahRumahSakit.nColumn; column++){
            DataTypeRuangan ruangan=globalDenahRumahSakit.Ruangan[row][column];
            fprintf(configFile, "%d", ruangan.idDokter);
            if(ruangan.idDokter==0){
                fprintf(configFile, "%c\n", 13);
            }
            else {
                if (ruangan.nEffPasien==0) fprintf(configFile, " %d", 0);
                else for (int i=0; i<ruangan.nEffPasien; i++) fprintf(configFile, " %d", ruangan.idPasien[i]);

                if (ruangan.idAntrian.size>0){
                    int antrianSize=ruangan.idAntrian.size;
                    for (int i=0; i<antrianSize; i++){
                        fprintf(configFile, " %d", ruangan.idAntrian.front->id);
                        deQueue(&ruangan.idAntrian);
                    }
                }
                fprintf(configFile, "%c\n", 13);
            }
        }
    }
    int idPasienObat[globalUserDatabase.nEff];
    int nPasienObat=countBanyakPasienInventory(idPasienObat);
    
    fprintf(configFile, "%d%c\n", nPasienObat, 13);

    for (int i=0; i<nPasienObat; i++){
        Patient* pasien=getAccountAddress(idPasienObat[i]);
        fprintf(configFile, "%d", pasien->id);
        int j=0;
        while (pasien->inventory[j]!=UNDEF_INT_DATA) fprintf(configFile, " %d", pasien->inventory[j++]);
        fprintf(configFile, "%c\n", 13);
    }

    int idPasienPerut[globalUserDatabase.nEff];
    int nPasienPerut=countBanyakPasienPerut(idPasienPerut);

    fprintf(configFile, "%d%c\n", nPasienPerut, 13);

    for (int i=0; i<nPasienPerut; i++){
        Patient* pasien=getAccountAddress(idPasienPerut[i]);
        fprintf(configFile, "%d", pasien->id);
        int perutSize=stackSize(&(pasien->perut));
        for (int j=0; j<perutSize; j++){
            fprintf(configFile, " %d", pasien->perut.obat[j].id);
        }
        fprintf(configFile, "%c\n", 13);
    }
    fclose(configFile);
}