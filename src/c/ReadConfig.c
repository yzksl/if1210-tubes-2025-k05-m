#include <ReadConfig.h>
// Realisasi header ReadConfig

int ScanNumber(FILE* file){
    int character, number=0;

    while((character=fgetc(file))!=EOF){
        if (isdigit(character)){
            number = number * 10 + (character - '0');
        } else break;
    }

    return number;
}

void ReadConfig(){
    FILE *configfile = fopen("file/config.txt", "r"); // Membuka file config

    int nrow, ncolumn, maxpasien; // Inisialisasi variable

    nrow = ScanNumber(configfile); // Membaca nilai baris
    ncolumn = ScanNumber(configfile); // Membaca nilai kolom

    // ADT Matrix constructor (Ditambah saat udah dibuat selanjutnya)
    
    fgetc(configfile); // skip \n

    maxpasien = ScanNumber(configfile); // Membaca nilai maximal banyak pasien

    fgetc(configfile); // skip \n

    int MatriksSementara[nrow][ncolumn][maxpasien+1]; // Matriks sementara untuk testing

    for (int row=0; row<nrow; row++){ // Mengiterasi barisan
        for (int column=0; column<ncolumn; column++){
            
            MatriksSementara[nrow][ncolumn][0] = ScanNumber(configfile); // Scan id dokter di ruang ngan tersebut

            for (int id=1; id<=maxpasien; id++){

                int temp=ScanNumber(configfile); // Scan id-id pasien

                if (temp=0){
                    fgetc(configfile); // Skip \n
                    break; // memutus loop jika pasien kosong
                }
                
                else if (temp='\n'){
                    MatriksSementara[nrow][ncolumn][id] = 0;
                    break; // memutus loop jika sudah list semua pasien
                }

                else MatriksSementara[nrow][ncolumn][id] = temp; // Meletakan id pasien di list pasien
            }
        }
    }


    // Fungsi Scan Baca Inventori belum dibuat
    // printf("%d %d %d %d\n", nrow, ncolumn, maxpasien, iddoc);


    fclose(configfile);
}