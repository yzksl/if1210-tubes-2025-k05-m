/* MODUL UNTUK KELUAR DARI PROGRAM */
/* Menanyakan jika ingin save. Jika iya, maka di-save, dan keluar dari program. Jika tidak, maka hanya keluar saja tanpa save. */
/* Dealokasi dilakukan disini */

#ifndef F18_EXIT_H
#define F18_EXIT_H

/*  KAMUS UMUM */
/* - */

/* Definisi elemen dan koleksi objek */
/* - */

/* F18 Exit: Fungsi yang akan dipanggil di main/menu*/
/* Menjalankan proses keluar dari program. Bisa save atau tidak save. Dealokasi seluruh memori dalam heap */
/* I.S. Dalam keadaan tidak error pada program */
/* F.S. Menulis ke file-file jika pengguna meminta untuk save. Seluruh memori dinamis di-dealokasi. Keluar dari program*/
void exitFromHospital();

#endif