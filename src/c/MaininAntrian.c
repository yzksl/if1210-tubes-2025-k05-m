#include "../header/MaininAntrian.h"
#include "../header/GlobalVariable.h"

void skipAntrian(){
    Point lokasiRuangan = posisiRuanganAntrianPasien(globalCurrentPatient->id);
    if (lokasiRuangan.antrian==-1) printf("Skip antrian gagal! Anda tidak sedang terdaftar dalam antrian manapun!\n");
    else if (lokasiRuangan.antrian==-2) printf("Anda sudah berada di dalam ruangan %c%d bersama Dr. %s! Tidak bisa skip antrian lagi.\n", lokasiRuangan.row+'A', lokasiRuangan.column+1, getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR));
    else if (lokasiRuangan.antrian==1) printf("Anda sudah berada di posisi paling depan antrian Dr. %s di ruangan %c%d! Tidak bisa skip lagi.\n", getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR), lokasiRuangan.row+'A', lokasiRuangan.column+1);
    else {
        int sizeQueue=globalDenahRumahSakit.kapasitasRuangan+lokasiRuangan.antrian;
        LinkedListNode* pasienYangSkip = globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idAntrian.front, *pasienSebelumYangSkip, *pasienTerakhirDalamRuangan;
        for (int i=1; i<sizeQueue; i++){
            pasienSebelumYangSkip = pasienYangSkip;
            if(i==globalDenahRumahSakit.kapasitasRuangan) pasienTerakhirDalamRuangan = pasienYangSkip;
            pasienYangSkip = pasienYangSkip->next;
        }
        pasienYangSkip->next=pasienTerakhirDalamRuangan->next;
        pasienTerakhirDalamRuangan->next=pasienSebelumYangSkip->next;
        pasienSebelumYangSkip->next=NULL;

        printf("Anda berhasil maju ke depan antrian Dr. %s di ruangan %c%d!\nPosisi antrian Anda sebelumnya: %d\nPosisi antrian Anda sekarang: 1\n", getAccountName(globalDenahRumahSakit.Ruangan[lokasiRuangan.row][lokasiRuangan.column].idDokter, DATA_TYPE_DOCTOR), lokasiRuangan.row+'A', lokasiRuangan.column+1, lokasiRuangan.antrian);
    }
}