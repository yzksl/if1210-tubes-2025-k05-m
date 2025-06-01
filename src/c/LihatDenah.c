#include "../header/LihatDenah.h"
#include "../header/GlobalVariable.h"

void kodeRuanganKonverter(char kodeRuangan[], int *rowRuangan, int *columnRuangan){
    if (strlen(kodeRuangan)>3 || kodeRuangan[0]<'A' || kodeRuangan[0]>'Z'|| !isDigit(kodeRuangan[1]) || (!isDigit(kodeRuangan[2]) && strlen(kodeRuangan)==3)){
        *rowRuangan=-1;
        *columnRuangan=-1;
        return;
    }
    *rowRuangan = kodeRuangan[0] - 'A'; // mendapatakan row ruangan
    *columnRuangan = kodeRuangan[1] - '0'; // mendapatkan digit pertama column ruangan
    if (isDigit(kodeRuangan[2])) *columnRuangan = (*columnRuangan)*10 + (kodeRuangan[2]-'0'); // jika column ruangan memiliki dua digit, ini akan mendapatkan digit kedua
    (*columnRuangan)--;
}

void lihatDenah(){
    printf("\n "); //spasi di awal
    for (int column=0; column<globalDenahRumahSakit.nColumn; column++){ // Menulis Angka-Angka Kolom
        if (column<10) printf("     %d", column+1);
        else printf("    %d", column+1);
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
        printf("+\n\n"); // + diakhir dan newline
    }
}

void lihatRuangan(int row, int column){

    char kodeRuangan[256]; // inisialisasi variable untuk membaca kode ruangan
    int rowRuangan, columnRuangan; // inisialisasi variable row ruangan dan column ruangan

    if (row==-1||column==-1){
        scanf(" %s", kodeRuangan);
        if (strcmp(kodeRuangan, "UHUY!!!!!🥴")==0) printEasterEgg1();
        if (strcmp(kodeRuangan, "jjww😘")==0) printEasterEgg2();
        kodeRuanganKonverter(kodeRuangan, &rowRuangan, &columnRuangan);
        
        if(rowRuangan<0 || columnRuangan<0 || rowRuangan>=globalDenahRumahSakit.nRow || columnRuangan>=globalDenahRumahSakit.nColumn){
            printf("\nTidak ada ruangan dengan kode ruangan %s\n\n", kodeRuangan);
            return;
        }
        printf("\n--- Detail Ruangan %s ---\n", kodeRuangan);
    } else {
        rowRuangan = row;
        columnRuangan = column;

        snprintf(kodeRuangan, sizeof(kodeRuangan), "%c%d", rowRuangan+'A', columnRuangan+1);

        printf("============ %s ============\n", kodeRuangan);
    }


    printf("Kapasitas  : %d\n", globalDenahRumahSakit.kapasitasRuangan);
    int idDokter = globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idDokter;

    if (idDokter==0) printf("Dokter     : -\n");
    else printf("Dokter     : %s\n", getAccountName(idDokter, DATA_TYPE_DOCTOR)/*Variable Sementara*/);

    printf("Pasien di dalam ruangan :\n");
    if (isQueueEmpty(&globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idAntrian)) printf("  Tidak ada pasien di dalam ruangan saat ini.\n");
    else{
        LinkedListNode* forTraverse = globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idAntrian.front;
        for (int i=0; i<((globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idAntrian.size<globalDenahRumahSakit.kapasitasRuangan) ? globalDenahRumahSakit.Ruangan[rowRuangan][columnRuangan].idAntrian.size : globalDenahRumahSakit.kapasitasRuangan); i++){
            printf("  %d. %s\n", i+1, getAccountName(forTraverse->id, DATA_TYPE_PATIENT));
            forTraverse = forTraverse->next;
        }
    }

    if (row==-1||column==-1) printf("------------------------------\n\n");
}

void lihatSemuaAntrian(){
    lihatDenah();
    printf("\n");
    for (int row=0; row<globalDenahRumahSakit.nRow; row++){
        for (int column=0; column<globalDenahRumahSakit.nColumn; column++){
            if (globalDenahRumahSakit.Ruangan[row][column].idDokter==0) continue;

            lihatRuangan(row, column);

            printf("Pasien di antrian:\n");

            if (globalDenahRumahSakit.Ruangan[row][column].idAntrian.size<=globalDenahRumahSakit.kapasitasRuangan) printf("  Tidak ada pasien di antrian saat ini.\n");
            else {
                LinkedListNode* forTraverse = globalDenahRumahSakit.Ruangan[row][column].idAntrian.front;
                for (int i=0; i<globalDenahRumahSakit.Ruangan[row][column].idAntrian.size; i++){
                    if (i<globalDenahRumahSakit.kapasitasRuangan){
                        forTraverse = forTraverse->next;
                        continue;
                    }
                    printf("  %d. %s\n", i+1-globalDenahRumahSakit.kapasitasRuangan, getAccountName(forTraverse->id, DATA_TYPE_PATIENT));
                    forTraverse = forTraverse->next;
                }
            }
            printf("\n");

        }
    }
    
}