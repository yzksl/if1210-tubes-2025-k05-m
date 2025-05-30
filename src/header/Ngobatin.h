#ifndef F12_NGOBATIN_H
#define F12_NGOBATIN_H

#include "Queue.h"
#include "StructsInHospital.h"
#include "GlobalVariable.h"
#include "Boolean.h"

// Fungsi untuk memberikan obat kepada pasien yang sudah terdiagnosis
void ngobatin(Queue* antrianPasien);

// Fungsi Mencari dan mengembalikan data Obat dari globalObatDatabase
Obat* getObatById(int idObat);
#endif
