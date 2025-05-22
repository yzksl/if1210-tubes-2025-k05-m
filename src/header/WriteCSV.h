/* MODUL UNTUK MENULIS KE CSV (KHUSUNYA USER.CSV) */
/* ASUMSI FILE CSV:
    SETIAP DATA VALID DIAKHIRI DENGAN NEWLINE
    SETIAP DATA MEMILIKI ID UNIK */

#ifndef WRITE_CSV_H
#define WRITE_CSV_H

void writeToCSV(const char* filename);
/* Proses: Menulis data-data dalam database yang berkaitan dengan filename ke filename */
/* I.S. file user.csv berisi data lama, globalDatabaseUser setidaknya ada satu data valid */
/* F.S. file user.csv berisi data dari globalDatabaseUser */


#endif