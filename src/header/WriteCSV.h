/* MODUL UNTUK MENULIS KE CSV (KHUSUNYA USER.CSV) */
/* ASUMSI FILE CSV:
    SETIAP DATA VALID DIAKHIRI DENGAN NEWLINE
    SETIAP DATA MEMILIKI ID UNIK */

#ifndef WRITE_CSV_H
#define WRITE_CSV_H

#include "Boolean.h"

/*  KAMUS UMUM */
#define MAX_CMD_LENGTH 512

/*  Definisi elemen dan koleksi objek*/
/* - */

/* DO4 Save: Fungsi yang akan dipanggil di main/menu */
/* Menulis seluruh data dalam setiap database dalam file csv masing-masing dalam folder yang ditentukan oleh masukan user */
/* I.S. Seluruh database terdefinisi, terdapat data. Folder dan file-file yang ingin ditulis mungkin tidak ada*/
/* F.S. Jika folder dan file-file tidak ada, maka dibuat. Jika ada, maka di overwrite. Setiap file diisi dengan data masing-masing dari database */
void saveCSV();

/* *** FUNGSI-FUNGSI DASAR *** */
/* Mengecek jika folder ada */
boolean doesFolderExist(const char* path);

/* Proses: membuat folder sesuai dengan path */
void createDir(char* path);

/* Proses: Menulis data-data dalam database yang berkaitan dengan filename ke filename */
/* I.S. file user.csv berisi data lama, globalDatabaseUser setidaknya ada satu data valid */
/* F.S. file user.csv berisi data dari globalDatabaseUser */
void writeToCSV(const char* folder, const char* filename);


#endif