/* MODUL UNTUK MEMBACA CSV */
/* ASUMSI FILE CSV:
    SETIAP DATA VALID DIAKHIRI DENGAN NEWLINE
    SETIAP DATA MEMILIKI ID UNIK 
    DATA-DATA DALAM OBAT_PENYAKIT, OBAT, PENYAKIT, VALID SEMUA, TIDAK ADA DUPLIKAT, TIDAK ADA URUTAN KOSONG */
/* USER.CSV KEMUNGKINAN ADA DATA YANG KORUP SETELAH READ FILE, DAN MODUL INI MEMPERTIMBANGKAN HAL TERSEBUT */
/* DAPAT DIGUNAKAN UNTUK MEMBACA SELURUH FILE CSV, SETIAP DATABASE AKAN DIBUAT DI FUNGSINYA */

#ifndef READ_CSV_H
#define READ_CSV_H

#include "DynamicList.h"
#include "Boolean.h"

#define MAX_PATH_LENGTH 50
#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 22
#define MAX_FIELD_LENGTH 50
#define NUM_OF_COL_PATIENT 16
#define NUM_OF_COL_GENERIC_USER 4
#define NUM_OF_COL_OBAT 2
#define NUM_OF_COL_PENYAKIT 22
#define NUM_OF_COL_OP 3

typedef struct {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int fieldCount;
} CSVRow;

CSVRow parseCSVLine(const char* line);
/* Fungsi untuk split data dari suatu line dalam csv. Data tersebut dimasukkan ke dalam komponen CSVRow */

void processCSV(const char* filename);
/* Proses: membaca seluruh line dalam filename csv. Menggunakan parseCSVLine untuk split data. Kemudian dibuat data Patient, Doctor, atau Manager dalam heap, dan dimasukkan ke dalam database, atau obat/penyakit/obatpenyakit and stuff. Database user di-expand dan di-shrink sesuai keadaan data akhir secara otomatis */

void processAllCSVInFolder(const char* folderPath);
/* Proses: membaca seluruh csv yang ada dalam folder yang diinput di terminal. Jika terdapat error, maka akan keluar dari program */
/* Contoh: ./build/main file, akan membuka csv-csv yang ada di folder file*/

#endif