# Rumah Sakit Niemons!
![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Language](https://img.shields.io/badge/language-C-lightgrey)
![Project Status](https://img.shields.io/badge/status-maintenance-lightgrey)
[![Release](https://img.shields.io/badge/release-1.2.1-blue)](https://github.com/yzksl/if1210-tubes-2025-k05-m/releases/tag/1.2.1)

Hasil tugas besar oleh Kelompok 05-M untuk mata kuliah IF1210, yaitu membangun sebuah sistem hospital canggih untuk para Niemons tercinta!

## ⁉️ Latar Belakang
Dr. Neroifa, ilmuwan Gro, merasa jenuh dengan rutinitas dan melihat para Nimon sering mengalami insiden medis kecil yang ditangani seadanya. Ia pun berinisiatif membangun Rumah Sakit Nimon yang canggih. Namun, masalah muncul saat Dr. Neroifa sadar ia tidak mampu membuat sistem manajemen untuk rumah sakit tersebut. Ia meminta bantuan dari kami, K05-M, untuk membuat sistem tersebut!

## 🏥 Fungsi dan Fitur
Fungsi dan fitur ditentukan dengan penuh sayang dan cermat oleh Dr. Neroifa dan asisten-asisten tercinta! Hal tersebut dapat dilihat di pranala situs web berikut: 

[Spesifikasi Tugas Besar
IF1210 Algoritma & Pemrograman 1 2025](https://docs.google.com/document/d/1rBkHIlNWIrlvH-hodqMFcGcVvMPRYlddjCkFWQuAfuw/edit?usp=sharing)

## 📃 Laporan
Agar Dr. Neroifa dapat memahami program kami, kami membuat sebuah laporan yang menjelaskan segala hal mengenai program, seperti rencana dan implementasi ADT, flowchart program, dan bahkan notasi algoritmik dari setiap fungsi 😱 Laporan dapat dilihat dalam file berikut:

[IF1210_LaporanTB_K05-M](doc/IF1210_LaporanTB_K05-M.pdf) 

TLDR: Program menggunakan data dari file-file csv user, penyakit, obat, obat penyakit, dan txt config. Kemudian pengguna dapat memilih untuk login, register pasien, logout, lupa password, memunculkan menu dan help, denah rumah sakit, lihat user, cari user, lihat antrian rumah sakit, tambah dokter, diagnosis, ngobatin, pasien boleh pulang?, daftar check-up, cek antrian pasien, minum obat, minum penawar, mainin antrian, mengubah denah rumah sakit, dan exit.

## Instalasi dan Penggunaan
Disarankan melakukan instalasi melalui halaman repositori GitHub. Jalankan program dengan WSL. Berikut petunjuk instalasi:
1. **Instalasi WSL**
Panduan dari Microsoft:  
[https://learn.microsoft.com/en-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install)
2. **Instalasi Dependensi**
    Asumsi menggunakan Ubuntu.
    - Update sistem terlebih dahulu sesuai dengan distro yang digunakan
    ```
    sudo apt-get upgrade
    sudo apt-get update
    sudo apt upgrade
    sudo apt update
    ```
    - Instal gcc, make, dan git
    ```
    sudo apt install gcc make git
    ```
3. **Clone Repository**
    ```
    git clone https://github.com/Labpro-22/if1210-tubes-2025-k05-m
    ```
4. **Masuk ke Direktori Src**
    ```
    cd if1210-tubes-2025-k05-m/src/
    ```
5. **Compile program dengan Make**
    ```
    make main
    ```
6. **Jalankan program**
    ```
    ./main <folder_data>
    ```
    Contoh:
    ```
    ./main data/25-05-2025
    ```

## 🪪 Identitas Kelompok
Kelompok kami terdiri dari 6 mahasigma dari Kelas 05 IF1210 Algoritma Dan Pemrograman!
- Jose Luis Fernando Saragi (13224013)
- Muhammad Zaki Azzamy Syauqi (13224045)
- Luis Matthew Sembiring (13224053)
- Muhammad Aqeel Ghani (13224071)
- Nahidl Denhaq Syaha (13224089)
- Gabrielle Garcia Hardanta P (18324015)

## Kontak Kelompok
- NIM: 13224045
- Nama: Muhammad Zaki Azzamy Syauqi
- Email: mzakiasyauqi@proton.me
