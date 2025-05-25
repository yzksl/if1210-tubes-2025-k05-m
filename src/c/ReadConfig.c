#include "../header/ReadConfig.h"
#include "../header/GlobalVariable.h"
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

void readConfig(const char* path){
    // merge folder and filename
    char fullPath[MAX_PATH_LENGTH];
    // folder pasti ada karena ketentuan spesifikasi
    snprintf(fullPath, sizeof(fullPath), "%s/%s", path, "config.txt");
    FILE *configFile = fopen(fullPath, "r"); // Membuka file config

    int nRow, nColumn, maxPasien, maxAntrian; // Inisialisasi variable

    nRow = scanNumber(configFile); // Membaca nilai baris
    nColumn = scanNumber(configFile); // Membaca nilai kolom

    globalDenahRumahSakit.nRow=nRow; // Memasuki banyak baris

    globalDenahRumahSakit.nColumn=nColumn; // Memasuki banyak kolom
    
    fgetc(configFile); // skip \n

    maxPasien = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    maxAntrian = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    globalDenahRumahSakit.kapasitasRuangan = maxPasien; // Memasukan jumlah maksimal pasien

    fgetc(configFile); // skip \n

    for (int row=0; row<nRow; row++){ // Mengiterasi barisan
        for (int column=0; column<nColumn; column++){

            createQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian, maxAntrian);

            globalDenahRumahSakit.Ruangan[row][column].idDokter = scanNumber(configFile); // Scan id dokter di ruang ngan tersebut

            if (globalDenahRumahSakit.Ruangan[row][column].idDokter==0){ // Jika Tidak ada dokter
                globalDenahRumahSakit.Ruangan[row][column].nEffPasien = 0; // Menulis banyak pasien sebagai nol
                fgetc(configFile); // Skip \n
                continue;
            }

            int count=0; // Inisialisasi perhitungan jumlah pasien

            for (int id=0; id<maxPasien+maxAntrian; id++){

                int temp=scanNumber(configFile); // Scan id-id pasien

                if (temp==0){ // Jika pasian tidak ada di ruangan
                    globalDenahRumahSakit.Ruangan[row][column].nEffPasien = 0; // Menulis banyak pasien sebagai nol
                    fgetc(configFile); // Skip \n
                    break; // memutus loop karena pasien kosong
                }
                
                else if (temp==-1){ // Jika jumlah pasien kurang dari kapasitas ruangan
                    if (id<=maxPasien){
                        globalDenahRumahSakit.Ruangan[row][column].nEffPasien = count; // Menuliskan banyak pasien
                        globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = 0; // Menulis banyak antrian
                    }
                    else if (id>maxPasien){
                        globalDenahRumahSakit.Ruangan[row][column].nEffPasien = maxPasien; // Menuliskan banyak pasien
                        globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = count-maxPasien; // Menulis banyak antrian
                    }
                    break; // memutus loop jika sudah list semua pasien
                }
                else{
                    if (id<maxPasien) globalDenahRumahSakit.Ruangan[row][column].idPasien[id] = temp; // Meletakan id pasien di list pasien
                    else{
                        LinkedListNode* node = createLLNode(temp, "");
                        enQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian, node);
                    }
                    count++; // Menghitung jumlah pasien
                    if (id==(maxPasien+maxAntrian-1)){ // Kondisi jika ini merupakan itirasi terakhir
                        globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = count-maxPasien;    // Menuliskan banyak pasien
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