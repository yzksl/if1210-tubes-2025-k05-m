#include "../header/MaininAntrian.h"
#include "../header/GlobalVariable.h"

void skipAntrian(){
    Point lokasiRuangan = posisiRuanganAntrianPasien(globalCurrentPatient->id);
    if (lokasiRuangan.antrian==-1) printf("\nSkip antrian gagal! Anda tidak sedang terdaftar dalam antrian manapun!\n\n");
    else if (lokasiRuangan.antrian==-2) printf("\nAnda sudah berada di dalam ruangan %c%d bersama Dr. %s! Tidak bisa skip antrian lagi.\n\n", lokasiRuangan.row+'A', lokasiRuangan.column+1, getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR));
    else if (lokasiRuangan.antrian==1) printf("\nAnda sudah berada di posisi paling depan antrian Dr. %s di ruangan %c%d! Tidak bisa skip lagi.\n\n", getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR), lokasiRuangan.row+'A', lokasiRuangan.column+1);
    else {
        int sizeQueue=globalDenahRumahSakit.kapasitasRuangan+lokasiRuangan.antrian;
        LinkedListNode* pasienYangSkip = globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.front, *pasienSebelumYangSkip, *pasienTerakhirDalamRuangan;
        for (int i=1; i<sizeQueue && pasienYangSkip->id != globalCurrentPatient->id; i++){
            pasienSebelumYangSkip = pasienYangSkip;
            if(i==globalDenahRumahSakit.kapasitasRuangan) pasienTerakhirDalamRuangan = pasienYangSkip;
            pasienYangSkip = pasienYangSkip->next;
        }
        LinkedListNode* temp=pasienYangSkip->next;
        pasienYangSkip->next=pasienTerakhirDalamRuangan->next;
        pasienTerakhirDalamRuangan->next=pasienSebelumYangSkip->next;
        pasienSebelumYangSkip->next=temp;

        if (lokasiRuangan.antrian==globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.size-globalDenahRumahSakit.kapasitasRuangan) globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.rear = pasienSebelumYangSkip;

        printf("\nAnda berhasil maju ke depan antrian Dr. %s di ruangan %c%d!\nPosisi antrian Anda sebelumnya: %d\nPosisi antrian Anda sekarang: 1\n\n", getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR), lokasiRuangan.row+'A', lokasiRuangan.column+1, lokasiRuangan.antrian);
    }
}

void cancelAntrian(){
    Point lokasiRuangan = posisiRuanganAntrianPasien(globalCurrentPatient->id);
    if (lokasiRuangan.antrian==-1) printf("\nCancel antrian gagal! Anda tidak sedang terdaftar dalam antrian manapun!\n\n");
    else if (lokasiRuangan.antrian==-2) printf("\nAnda sudah berada di dalam ruangan %c%d bersama Dr. %s! Tidak bisa cancel antrian.\n\n", lokasiRuangan.row+'A', lokasiRuangan.column+1, getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR));
    else {
        int sizeQueue=globalDenahRumahSakit.kapasitasRuangan+lokasiRuangan.antrian;
        LinkedListNode* pasienYangCancel = globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.front, *pasienSebelumYangCancel;
        for (int i=1; i<sizeQueue && pasienYangCancel->id != globalCurrentPatient->id; i++){
            pasienSebelumYangCancel = pasienYangCancel;
            pasienYangCancel = pasienYangCancel->next;
        }
        pasienSebelumYangCancel->next=pasienYangCancel->next;
        free(pasienYangCancel);
        globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.size-=1;

        printf("\nAnda berhasil keluar dari antrian Dr. %s di ruangan %c%d!\n\n", getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR), lokasiRuangan.row+'A', lokasiRuangan.column+1);
    }
}