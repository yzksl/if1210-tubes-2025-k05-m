#include "DynamicList.h"

#ifndef LIHATUSER_H
#define LIHATUSER_H

#define MAX_TAB 50
/*Jumlah maksimal untuk array of char dalam ADT*/

typedef struct {
    int ID;
    char nama[MAX_TAB];
    char role[MAX_TAB];
    char penyakit[MAX_TAB];
}tabel;
/* tabel merupakan ADT sederhana yang berfungsi untuk menyimpan elemen data baik dari pasien maupun dokter */
/* elemen yang disimpan dalam tabel hanyalah elemen yang akan digunakan dalam fungsi f07 dan f08 */
/* elemen tersebut meliputi ID, nama, role(dokter/pasien), dan penyakit*/  
/* tabel berfungsi untuk mempermudah proses pencarian dan penampilan data user */

#endif

void lihatUser(ListDin userDatabase);
/*  I.S. userDatabase terdefinisi dan terisi */
/*  F.S. menampilkan data dokter dan pasien yang meliputi ID, nama, role, dan penyakit dalam tabel sesuai urutan yang diinginkan */
/*  dilakukan dengan mengonversi tipe data void* ke Patient* untuk pasien, dan Doctor* untuk dokter */
/*  dilanjutkan dengan menyalin elemen data yang dibutuhkan ke dalam array of tabel */
/*  array of tabel ini yang akan diproses dan ditampilkan sebagai output prosedur */

void lihatDokter(ListDin userDatabase);
/*  I.S. userDatabase terdefinisi dan terisi */
/*  F.S. menampilkan data seluruh dokter pada database yang meliputi ID dan nama dalam tabel sesuai urutan yang diinginkan */
/*  dilakukan dengan menggunakan cara yang sama yang digunakan pada prosedur lihatUser*/

void lihatPasien(ListDin userDatabase);
/*  I.S. userDatabase terdefinisi dan terisi */
/*  F.S. menampilkan data seluruh pasien pada database yang meliputi ID, nama dan penyakit dalam tabel sesuai urutan yang diinginkan */
/*  dilakukan dengan menggunakan cara yang sama yang digunakan pada prosedur lihatUser*/