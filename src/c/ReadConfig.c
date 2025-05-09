#include <ReadConfig.h>
// Realisasi header ReadConfig

int scanNumber(FILE* file){
    int character, number=0;

    while((character=fgetc(file))!=EOF){
        if (isdigit(character)){
            number = number * 10 + (character - '0');
        } else break;
    }

    return number;
}

void readConfig(){
    FILE *configFile = fopen("file/config.txt", "r"); // Membuka file config

    int nRow, nColumn, maxPasien; // Inisialisasi variable

    nRow = scanNumber(configFile); // Membaca nilai baris
    nColumn = scanNumber(configFile); // Membaca nilai kolom

    // ADT Matrix constructor (Ditambah saat udah dibuat selanjutnya)
    
    fgetc(configFile); // skip \n

    maxPasien = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    fgetc(configFile); // skip \n

    int matriksSementara[nRow][nColumn][maxPasien+1]; // Matriks sementara untuk testing

    for (int row=0; row<nRow; row++){ // Mengiterasi barisan
        for (int column=0; column<nColumn; column++){
            
            matriksSementara[nRow][nColumn][0] = scanNumber(configFile); // Scan id dokter di ruang ngan tersebut

            for (int id=1; id<=maxPasien; id++){

                int temp=scanNumber(configFile); // Scan id-id pasien

                if (temp=0){
                    fgetc(configFile); // Skip \n
                    break; // memutus loop jika pasien kosong
                }
                
                else if (temp='\n'){
                    matriksSementara[nRow][nColumn][id] = 0;
                    break; // memutus loop jika sudah list semua pasien
                }

                else matriksSementara[nRow][nColumn][id] = temp; // Meletakan id pasien di list pasien
            }
        }
    }


    // Fungsi Scan Baca Inventori belum dibuat
    // printf("%d %d %d %d\n", nrow, ncolumn, maxpasien, iddoc);


    fclose(configFile);
}