#include "../header/LihatDenah.h"
#include "../header/GlobalVariable.h"

void lihatDenah(){
    printf("\n "); //spasi di awal
    for (int column=0; column<globalDenahRumahSakit.nColumn; column++){ // Menulis Angka-Angka Kolom
        printf("     %d", column+1);
    }
    printf("\n"); // newline

    for (int i=0; i<3; i++) printf(" "); // Spasi di awal pembatas

    for (int column=0; column<globalDenahRumahSakit.nColumn; column++) { //Menulis batasan antara angka-angka kolom
        printf("+-----");
    }
    printf("+\n"); // + diakhir dan newline

    for (int row=0; row<globalDenahRumahSakit.nRow; row++){ // Menulis setiap row
        printf(" %c ", row+65); // Menulis huruf row

        for (int column=0; column<globalDenahRumahSakit.nColumn; column++){ // menulis setiap ruangan
            printf("| %c%d ", row+65, column+1); // menulis ruangan
            if (column<9) printf(" "); // jika berada di kolom kurang dari 10 (atau 9 jika dihitung dari 0) menambahkan spasi
        }
        printf("|\n   "); // | diakhir dan newline

        for (int column=0; column<globalDenahRumahSakit.nColumn; column++) { //Menulis batasan antara angka-angka kolom
            printf("+-----");
        }
        printf("+\n"); // + diakhir dan newline
    }
}

void lihatRuangan(int ruangan){
    char nomorRuangan[256]; // inisialisasi variable untuk membaca nomor ruangan
    int rowRuangan, columnRuangan; // inisialisasi variable row ruangan dan column ruangan

    if (ruangan==-1){
        scanf(" %s", nomorRuangan);

        rowRuangan = nomorRuangan[0] - 'A'; // mendapatakan row ruangan

        columnRuangan = nomorRuangan[1] - '0'; // mendapatkan digit pertama column ruangan
        if (isdigit(nomorRuangan[2])) columnRuangan = columnRuangan*10 + (nomorRuangan[2]-'0'); // jika column ruangan memiliki dua digit, ini akan mendapatkan digit kedua
        columnRuangan--;
        if(rowRuangan<0 || columnRuangan<0 || rowRuangan>=globalDenahRumahSakit.nRow || columnRuangan>=globalDenahRumahSakit.nColumn){
            printf("\nTidak ruangan dengan nomor ruangan %s\n\n", nomorRuangan);
            return;
        }
        printf("\n--- Detail Ruangan %s ---\n", nomorRuangan);
    } else {
        rowRuangan = ruangan/globalDenahRumahSakit.nColumn;
        columnRuangan = ruangan-rowRuangan*globalDenahRumahSakit.nColumn;

        snprintf(nomorRuangan, sizeof(nomorRuangan), "%c%d", rowRuangan+'A', columnRuangan+1);

        printf("============ %s ============\n", nomorRuangan);
    }

    

    printf("Kapasitas  : %d\n", globalDenahRumahSakit.kapasitasRuangan);

    int idDokter = globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idDokter;

    if (idDokter==0) printf("Dokter     : -\n");
    else printf("Dokter     : %s\n", getAccountName(idDokter, DATA_TYPE_DOCTOR)/*Variable Sementara*/);

    printf("Pasien di dalam ruangan :\n");

    int jumlahPasien=globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].nEffPasien;


    if (jumlahPasien==0) printf("  Tidak ada pasien di dalam ruangan saat ini.\n");
    else for (int i=0; i<jumlahPasien; i++) printf("  %d. %s\n", i+1, getAccountName(globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idPasien[i], DATA_TYPE_PATIENT));

    if (ruangan==-1) printf("------------------------------\n");
}

void lihatSemuaAntrian(){
    lihatDenah();
    printf("\n");
    for (int row=0; row<globalDenahRumahSakit.nRow; row++){
        for (int column=0; column<globalDenahRumahSakit.nColumn; column++){
            if (globalDenahRumahSakit.Ruangan[row][column].idDokter==0) continue;

            lihatRuangan(row*globalDenahRumahSakit.nColumn+column);

            printf("Pasien di antrian:\n");

            if (isQueueEmpty(&globalDenahRumahSakit.Ruangan[row][column].idAntrian)) printf("  Tidak ada pasien di antrian saat ini.\n");
            else {
                LinkedListNode* forTraverse = globalDenahRumahSakit.Ruangan[row][column].idAntrian.front;
                for (int i=0; i<globalDenahRumahSakit.Ruangan[row][column].idAntrian.size; i++){
                    printf("  %d. %s\n", i+1, getAccountName(forTraverse->id, DATA_TYPE_PATIENT));
                    forTraverse = forTraverse->next;
                }
            }
            printf("\n");

        }
    }
    
}