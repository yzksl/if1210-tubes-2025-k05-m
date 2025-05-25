#include "GlobalVariable.h"
#include "Boolean.h"
#include "Queue.h"
#include "LinkedList.h"

boolean cekAntrian(Queue* q, int userId);
/*Fungsi untuk mengecek apakah pasien ada dalam antrian*/
int cariPosisiPasien(Queue* q, int userId);
/*Fungsi untuk mencari posisi pasien dalam antrian*/
void antrianSaya();
/*Prosedur utama untuk mengecek urutan antrian*/