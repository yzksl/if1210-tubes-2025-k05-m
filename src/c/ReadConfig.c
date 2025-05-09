#include <ReadConfig.h>
#include <GlobalVariable.h>
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

    denahRumahSakit.nRow=nRow; // Memasuki banyak baris

    denahRumahSakit.nColumn=nColumn; // Memasuki banyak kolom
    
    fgetc(configFile); // skip \n

    maxPasien = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    denahRumahSakit.kapasitasRuangan = maxPasien; // Memasukan jumlah maksimal pasien

    fgetc(configFile); // skip \n

    for (int row=0; row<nRow; row++){ // Mengiterasi barisan
        for (int column=0; column<nColumn; column++){

            denahRumahSakit.Ruangan[row][column].idDokter = scanNumber(configFile); // Scan id dokter di ruang ngan tersebut

            for (int id=0; id<maxPasien; id++){

                int count=0; // Inisialisasi perhitungan jumlah pasien

                int temp=scanNumber(configFile); // Scan id-id pasien

                if (temp=0){
                    denahRumahSakit.Ruangan[row][column].nEffPasien = 0; // Menulis banyak pasien sebagai nol
                    fgetc(configFile); // Skip \n
                    break; // memutus loop karena pasien kosong
                }
                
                else if (temp='\n'){
                    denahRumahSakit.Ruangan[row][column].nEffPasien = count; // Menuliskan banyak pasien
                    break; // memutus loop jika sudah list semua pasien
                }

                else{
                    denahRumahSakit.Ruangan[row][column].idPasien[id] = temp; // Meletakan id pasien di list pasien
                    count++; // Menghitung jumlah pasien
                }
            }
        }
    }


    // Fungsi Scan Baca Inventori belum dibuat
    // printf("%d %d %d %d\n", nrow, ncolumn, maxpasien, iddoc);


    fclose(configFile);
}