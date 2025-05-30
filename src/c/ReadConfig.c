#include "../header/ReadConfig.h"
#include "../header/GlobalVariable.h"
// Realisasi header ReadConfig

int scanNumber(FILE* file){
    int character, number=0, isNumber=0;
    while((character=fgetc(file))!=EOF){
        if (isDigit(character)){
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

    int nRow, nColumn, maxPasien, maxAntrian, nPasienObat, nPasienPerut; // Inisialisasi variable

    nRow = scanNumber(configFile); // Membaca nilai baris
    nColumn = scanNumber(configFile); // Membaca nilai kolom

    globalDenahRumahSakit.nRow=nRow; // Memasuki banyak baris

    globalDenahRumahSakit.nColumn=nColumn; // Memasuki banyak kolom
    
    fgetc(configFile); // skip \n

    maxPasien = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    maxAntrian = scanNumber(configFile); // Membaca nilai maximal banyak pasien

    globalDenahRumahSakit.kapasitasRuangan = maxPasien; // Memasukan jumlah maksimal pasien

    globalDenahRumahSakit.kapasitasAntrian = maxAntrian; // Memasukan jumlah maksimal antrian

    fgetc(configFile); // skip \n

    for (int row=0; row<nRow; row++){ // Mengiterasi barisan
        for (int column=0; column<nColumn; column++){

            createQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian, maxAntrian+maxPasien);

            globalDenahRumahSakit.Ruangan[row][column].idDokter = scanNumber(configFile); // Scan id dokter di ruang ngan tersebut

            if (globalDenahRumahSakit.Ruangan[row][column].idDokter==0){ // Jika Tidak ada dokter
                globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = 0; // Menulis banyak pasien sebagai nol
                fgetc(configFile); // Skip \n
                continue;
            }

            int count=0; // Inisialisasi perhitungan jumlah pasien

            for (int id=0; id<maxPasien+maxAntrian; id++){

                int temp=scanNumber(configFile); // Scan id-id pasien

                if (temp==0){ // Jika pasian tidak ada di ruangan
                    globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = 0; // Menulis banyak pasien sebagai nol
                    fgetc(configFile); // Skip \n
                    break; // memutus loop karena pasien kosong
                }
                
                else if (temp==-1){ // Jika jumlah pasien kurang dari kapasitas ruangan
                    globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = count; // Menuliskan banyak pasien
                    break; // memutus loop jika sudah list semua pasien
                }
                else{
                    LinkedListNode* node = createLLNode(temp, "");
                    enQueue(&globalDenahRumahSakit.Ruangan[row][column].idAntrian, node); // Memasukan id pasien pada queue
                    count++; // Menghitung jumlah pasien
                    if (id==(maxPasien+maxAntrian-1)){ // Kondisi jika ini merupakan itirasi terakhir
                        globalDenahRumahSakit.Ruangan[row][column].idAntrian.size = count;    // Menuliskan banyak pasien
                        fgetc(configFile); // Skip \n
                    }
                }
            }
        }
    }

    nPasienObat=scanNumber(configFile); // Membaca banyak pasien yang memiliki obat
    fgetc(configFile); // Skip \n

    for(int i=0; i<nPasienObat; i++){
        int id=scanNumber(configFile); // Membaca id pasien

        Patient* pasienObat=getAccountAddress(id); // Mendapatkan pointer akun pasien

        pasienObat->sudahDiObatin=true;
        pasienObat->sudahDiDiagnosis=true;

        int temp=scanNumber(configFile); // Membaca id Obat

        while(temp!=-1){
            int j=0; // inisialisasi index

            while(pasienObat->inventory[j]!=UNDEF_INT_DATA) j++; // Memcari index yang kosong

            if (j==INVENTORY_SIZE) printf("INVENTORY %s FULL\n", pasienObat->username); // Jika inventory pasien kosong

            else pasienObat->inventory[j]=temp; // Memasukan id obat ke inventory pasien

            temp=scanNumber(configFile); // Membaca id Obat
        }
    }

    nPasienPerut=scanNumber(configFile); // Membaca banyak pasien yang telah meminum obat
    fgetc(configFile); // Skip \n

    for(int i=0; i<nPasienPerut; i++){
        int id=scanNumber(configFile); // Membaca id pasien

        Patient* pasienPerut=getAccountAddress(id); // Mendapatkan pointer akun pasien

        pasienPerut->sudahDiObatin=true;
        pasienPerut->sudahDiDiagnosis=true;

        int temp=scanNumber(configFile); // Membaca id Obat

        Stack tempStack;
        createStack(&tempStack);
        while(temp!=-1){
            Obat* obat = getObatById(temp); // Inisialisasi obat

            pushStack(&tempStack, *obat); // Push obat ke perut pasien

            temp=scanNumber(configFile); // Membaca id obat
        }
        int sizeStack=stackSize(&tempStack);

        while (sizeStack--){
            Obat obat=popStack(&tempStack);
            pushStack(&(pasienPerut->perut), obat);
        }
    }

    fclose(configFile); // Menutup File
}