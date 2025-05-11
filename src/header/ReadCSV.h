#ifndef READ_CSV_H
#define READ_CSV_H

#include "DynamicList.h"
#include "Boolean.h"
#include "StructsInHospital.h"

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 22
#define MAX_FIELD_LENGTH 50
#define NUM_OF_COL_PATIENT 16
#define NUM_OF_COL_GENERIC_USER 4

typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int fieldCount;
} CSVRow;

CSVRow parseCSVLine(const char* line);
/* Fungsi untuk split data dari suatu line dalam csv. Data tersebut dimasukkan ke dalam komponen CSVRow */

void processUserCSV(const char* filename, ListDin* userDatabase);
/* Proses: membaca seluruh line dalam user.csv. Menggunakan parseCSVLine untuk split data. Kemudian dibuat data Patient, Doctor, atau Manager dalam heap, dan dimasukkan ke dalam database. Database di-expand dan di-shrink sesuai keadaan data akhir secara otomatis */
/* I.S. userDatabase kosong */
/* F.S. userDatabase diisi oleh data-data dalam csv. Jika tidak ada, seharusnya tidak akan dilakukan apa-apa */

#endif