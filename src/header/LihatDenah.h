#ifndef LIHATDENAH_H
#define LIHATDENAH_H

#include <stdio.h>
#include "GlobalVariable.h"
#include "FindAccount.h"
#include "CTypePalsu.h"
#include "PrintArt.h"

void kodeRuanganKonverter(char arr[], int *rowRuangan, int *columnRuangan); // Mengkonvert kode ruangan menjadi titik baris dan kolom

void lihatDenah(); // Menampilkan Denah Rumah Sakit

void lihatRuangan(int row, int column); // Menampilkan Kondisi Ruangan

void lihatSemuaAntrian(); // Menampilkan Rincian di Seluruh Ruangan yang tidak kosong

#endif