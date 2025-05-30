#include "../header/LihatUser.h"
#include "../header/GlobalVariable.h"
/* menggunakan ADT yang sama dengan yang digunakan di f07, yakni ADT tabel */

#define CARIUSER_H

void cariUser(ListDin globalUserDatabase);
/*  I.S. userDatabase yang terdefinisi dan tidak kosong */
/*  F.S. menampilkan data (meliputi ID, nama, role, dan penyakit) user(pasien & dokter) yang dicari dalam bentuk tabel */
/*  apabila data yang dicari tidak ada, maka program akan menampilkan "Tidak ditemukan user dengan nomor ID/nama...!" */
/*  dilakukan dengan mengonversi tipe data void* ke Patient* untuk pasien, dan Doctor* untuk dokter */
/*  dilanjutkan dengan menyalin elemen data yang dibutuhkan ke dalam array of tabel */
/*  pencarian (baik yang berdasarkan nama ataupun ID) akan dilakukan di array of tabel */

void cariDokter(ListDin globalUserDatabase);
/*  I.S. userDatabase yang terdefinisi dan tidak kosong */
/*  F.S. menampilkan data (meliputi ID dan nama) dokter yang dicari dalam bentuk tabel */
/*  apabila data yang dicari tidak ada, maka program akan menampilkan "Tidak ditemukan dokter dengan nomor ID/nama...!" */
/*  pencarian (baik yang berdasarkan nama ataupun ID) akan dilakukan di array of tabel */


void cariPasien(ListDin globalUserDatabase);
/*  I.S. userDatabase yang terdefinisi dan tidak kosong */
/*  F.S. menampilkan data (meliputi ID, nama, dan penyakit) pasien yang dicari dalam bentuk tabel */
/*  apabila data yang dicari tidak ada, maka program akan menampilkan "Tidak ditemukan pasien dengan nomor ID/nama/penyakit...!" */
/*  pencarian (baik yang berdasarkan nama, ID, ataupun penyakit) akan dilakukan di array of tabel */
/*  pencarian berdasarkan penyakit memungkinkan tercetak lebih dari 1 data pasien */