#include "../header/Help.h"

// Realisasi Header Help

void helpPasien(){
    printf("==============================\n\n==============================\n");
    printf(
        "Terimakasih telah memanggil fungsi Help\n"
        "Berikut merupakan fungsi-fungsi yang dapat anda gunakan\n"
        "1) HELP : Memunculkan list fungsi-fungsi yang dapat digunakan beserta penjelasannya\n"
        "2) LIHAT_DENAH : Memunculkan denah rumah sakit\n"
        "3) LIHAT_RUANGAN XX : Memunculkan detail ruangan XX (XX: kode ruangan)\n"
        "4) PULANGDOK : Bertanya ke dokter apakah kamu sudah boleh pulang\n"
        "5) DAFTAR_CHECKUP : Mendaftarkan check-up dengan dokter\n"
        "6) ANTRIAN : Menunjukan status antrian pasien\n"
        "7) SKIP_ANTRIAN : Pasien akan maju ke urutan pertama antrian di luar ruangan\n"
        "8) CANCEL_ANTRIAN : Pasien akan keluar dari antrian\n"
        "9) MINUM_OBAT : Meminum obat yang berada di inventory\n"
        "10) PENAWAR : Meminum penawar untuk memuntahkan obat yang berada di perut\n"
        "11) LOGOUT : Keluar dari akun yang sedang digunakan\n"
        "12) EXIT : Keluar dari program\n\n"
        "Footnote:\n"
        "1) Untuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar\n"
        "2) Jangan lupa untuk memasukkan input yang valid\n"
    );
}

void helpDokter(){
    printf("==============================\n\n==============================\n");
    printf(
        "Terimakasih telah memanggil fungsi Help\n"
        "Berikut merupakan fungsi-fungsi yang dapat anda gunakan\n"
        "1) HELP : Memunculkan list fungsi-fungsi yang dapat digunakan beserta penjelasannya\n"
        "2) LIHAT_DENAH : Memunculkan denah rumah sakit\n"
        "3) LIHAT_RUANGAN XX : Memunculkan detail ruangan XX (XX: kode ruangan)\n"
        "4) DIAGNOSIS : Mendiagnosis pasien yang berada di depan antrian\n"
        "5) NGOBATIN : Mengobati pasien yang berada di depan antrian\n"
        "6) LOGOUT : Keluar dari akun yang sedang digunakan\n"
        "7) EXIT : Keluar dari program\n\n"
        "Footnote:\n"
        "1) Untuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar\n"
        "2) Jangan lupa untuk memasukkan input yang valid\n"
    );
}

void helpManager(){
    printf("==============================\n\n==============================\n");
    printf(
        "Terimakasih telah memanggil fungsi Help\n"
        "Berikut merupakan fungsi-fungsi yang dapat anda gunakan\n"
        "1) HELP : Memunculkan list fungsi-fungsi yang dapat digunakan beserta penjelasannya\n"
        "2) LIHAT_DENAH : Memunculkan denah rumah sakit\n"
        "3) LIHAT_RUANGAN XX : Memunculkan detail ruangan XX (XX: kode ruangan)\n"
        "4) LIHAT_USER : Melihat data seluruh pengguna\n"
        "5) LIHAT_PASIEN : Melihat data seluruh pasien\n"
        "6) LIHAT_DOKTER : Melihat data seluruh dokter\n"
        "7) CARI_USER : Mencari data pengguna secara spesifik berdasarkan ID atau Nama\n"
        "8) CARI_PASIEN : Mencari data pengguna secara spesifik berdasarkan ID, Nama, atau Penyakit\n"
        "9) CARI_DOKTER : Mencari data pengguna secara spesifik berdasarkan ID, atau Nama\n"
        "10) LIHAT_SEMUA_ANTRIAN : Melihat rincian di seluruh ruangan saat ini\n"
        "11) TAMBAH_DOKTER : Menambahkan dokter baru\n"
        "12) ASSIGN_DOKTER : Melakukan assign ruangan ke dokter tertentu yang belum memiliki ruangan\n"
        "13) PINDAH_DOKTER XX YY: Melakukan pemindahan dokter dari ruangan XX ke YY (XX, YY: kode ruangan)\n"
        "14) UBAH_DENAH X Y : Mengubah ukuran denah menjadi Y X (Y: Jumlah barisan, X : Jumlah kolom)\n"
        "15) LOGOUT : Keluar dari akun yang sedang digunakan\n"
        "16) EXIT : Keluar dari program\n\n"
        "Footnote:\n"
        "1) Untuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar\n"
        "2) Jangan lupa untuk memasukkan input yang valid\n"
    );
}

void helpBelumLogin(){
    printf("==============================\n\n==============================\n");
    printf(
        "Terimakasih telah memanggil fungsi Help\n"
        "Berikut merupakan fungsi-fungsi yang dapat anda gunakan\n"
        "1) HELP : Memunculkan list fungsi-fungsi yang dapat digunakan beserta penjelasannya\n"
        "2) LOGIN : Masuki suatu akun\n"
        "3) LUPA_PASSWORD : Mengganti atau memperbarui password akun\n"
        "4) REGISTER : Membuat akun baru\n"
        "5) EXIT : Keluar dari program\n\n"
        "Footnote:\n"
        "1) Untuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar\n"
        "2) Jangan lupa untuk memasukkan input yang valid\n"
    );
}