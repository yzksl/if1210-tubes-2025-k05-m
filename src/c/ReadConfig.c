#include <ReadConfig.h>
#include <GlobalVariable.h>
// Realisasi header ReadConfig

int scanNumber(FILE* file){
    int character, number=0, isNumber=0;

    while((character=fgetc(file))!=EOF){
        if (isdigit(character)){
            number = number * 10 + (character - '0');
            isNumber=1; // Penanda bahwa sebuah nomor
        } else break;
    }
    if (isNumber) return number; // Mengembalikan nomor
    else return -1; // Mengembalikan -1 karena bukan nomor
    
}

void readConfig(){
    FILE *configFile = fopen("file/config.txt", "r"); // Membuka file config

    int nRow, nColumn, maxPasien; // Inisialisasi variable

    nRow = scanNumber(configFile); // Membaca nilai baris
    nColumn = scanNumber(configFile); // Membaca nilai kolom

    globalDenahRumahSakit.nRow=nRow; // Memasuki banyak baris

    globalDenahRumahSakit.nColumn=nColumn; // Memasuki banyak kolom
    
    fgetc(configFile); // skip \n

    maxPasien = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    globalDenahRumahSakit.kapasitasRuangan = maxPasien; // Memasukan jumlah maksimal pasien

    fgetc(configFile); // skip \n

    for (int row=0; row<nRow; row++){ // Mengiterasi barisan
        for (int column=0; column<nColumn; column++){

            globalDenahRumahSakit.Ruangan[row][column].idDokter = scanNumber(configFile); // Scan id dokter di ruang ngan tersebut

            if (globalDenahRumahSakit.Ruangan[row][column].idDokter==0){ // Jika Tidak ada dokter
                globalDenahRumahSakit.Ruangan[row][column].nEffPasien = 0; // Menulis banyak pasien sebagai nol
                fgetc(configFile); // Skip \n
                continue;
            }

            int count=0; // Inisialisasi perhitungan jumlah pasien

            for (int id=0; id<maxPasien; id++){

                int temp=scanNumber(configFile); // Scan id-id pasien

                if (temp==0){
                    globalDenahRumahSakit.Ruangan[row][column].nEffPasien = 0; // Menulis banyak pasien sebagai nol
                    fgetc(configFile); // Skip \n
                    break; // memutus loop karena pasien kosong
                }
                
                else if (temp==-1){
                    globalDenahRumahSakit.Ruangan[row][column].nEffPasien = count; // Menuliskan banyak pasien
                    break; // memutus loop jika sudah list semua pasien
                }
                else{
                    globalDenahRumahSakit.Ruangan[row][column].idPasien[id] = temp; // Meletakan id pasien di list pasien
                    count++; // Menghitung jumlah pasien
                    if (id==(maxPasien-1)){ // Kondisi jika ini merupakan itirasi terakhir
                        globalDenahRumahSakit.Ruangan[row][column].nEffPasien = count;    // Menuliskan banyak pasien
                        fgetc(configFile); // Skip \n
                    }
                }
            }
        }
    }


    // Fungsi Scan Baca Inventori belum dibuat
    // printf("%d %d %d %d\n", nrow, ncolumn, maxpasien, iddoc);


    fclose(configFile);
}