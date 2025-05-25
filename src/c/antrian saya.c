#include <stdio.h>
#include "GlobalVariable.h"
#include "antrian saya.h"



//Cek antrian berdasarkan id
boolean cekAntrian(Queue* q, int userId){
    LinkedListNode* current = q->front;
    while (current != NULL) {
        if (current->id == userId) {
            return true;
        }
        current = current->next;
    }
    return false;
}

//Cari posisi pasien di antriannya
int cariPosisiPasien(Queue* q, int userId){
    LinkedListNode* current = q->front;
    int position = 1;  // Posisi dimulai dari 1
    while (current != NULL) {
        if (current->id == userId) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Tidak ditemukan
}


void AntrianSaya(Queue* q, int userId/*ini variabel untuk id pasien yang sedang login, belum tau bagaimana cara ceknya id yang sedang login*/, const char* nama_dokter/*tipe data masih belum fix*/, const char* kode_ruangan/*tipe data masih belum fix*/){
    if(!cekAntrian(q, userId) && !cekListRuangan){
        printf("\nAnda belum terdaftar dalam antrian check-up!\n");
        printf("Silakan daftar terlebih dahulu dengan command DAFTAR_CHECKUP.\n");
    }
    else if(!cekListRuangan, cekAntrian(q, userId)){
        int posisi = cariPosisiPasien(q, userId);
        if(posisi != -1){
            printf("\nStatus antrian Anda:\n");
            printf("Dokter: %s\n", nama_dokter);
            printf("Ruangan: %s\n", kode_ruangan);
            printf("Posisi antrian: %d dari %d\n", posisi, q->size);
        }
    else if (!cekAntrian(q, userId), cekListRuangan){
        printf("\nAnda sedang berada di dalam ruangan dokter!\n");
    }

    }
}