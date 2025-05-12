#ifndef LIHATUSER_H
#define LIHATUSER_H

typedef struct {
    int ID;
    char nama[50];
    char role[50];
    char penyakit[50];
} Data; // ADT pribadi, selanjutnya akan menyesuaikan dengan dynamic list

void Print_List(Data total[], int n);
    //Menginput array of ADT dan nEff array
    //Menampilkan data dalam format 'kolom 1 | kolom 2 | kolom 3 | kolom 4'

void LIHAT_DATA(void);
    //Membaca file database dan mencopy isinya ke dalam sebuah array of ADT
    //Menampilkan 4 kolom (ID, nama, role, penyakit) untuk seluruh data yang ada

void LIHAT_DOKTER(void);
    //Membaca file database dan mencopy isinya ke dalam sebuah array of ADT
    //Menyortir array yang memiliki role DOKTER dan mencopy isinya ke dalam array baru
    //Menampilkan 4 kolom (ID, nama, role, penyakit) untuk seluruh data yang ada

void LIHAT_PASIEN(void);
    //Membaca file database dan mencopy isinya ke dalam sebuah array of ADT
    //Menyortir array yang memiliki role PASIEN dan mencopy isinya ke dalam array baru
    //Menampilkan 4 kolom (ID, nama, role, penyakit) untuk seluruh data yang ada
#endif