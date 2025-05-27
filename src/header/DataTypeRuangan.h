#ifndef DATATYPERUANGAN_H
#define DATATYPERUANGAN_H

#define MAX_CAPACITY 100

#include "Queue.h"

typedef struct {
    int idDokter; // id dokter
    int idPasien[MAX_CAPACITY]; // Array berisi id pasien
    int nEffPasien; // Jumlah pasien
    Queue idAntrian; // Antrian Pasien
} DataTypeRuangan; // Tipe data untuk ruangan

typedef struct {
    int nRow; // Jumlah barisan
    int nColumn; // Jumlah Colom
    int kapasitasRuangan; // Kapasitas Maksimal Pasien dalam ruangan
    DataTypeRuangan Ruangan[MAX_CAPACITY][MAX_CAPACITY]; // Matriks denah
} DataTypeDenah; // Tipe data untuk denah

typedef struct{
    int row;
    int column;
    int antrian;
} Point;

#endif