#include <MainMenu.h>
#include <Help.h>
#include <stdlib.h>

// Realisasi Header Main Menu

void mainMenu(){
    printf("==============================\n\n==============================\n");
    if (strcmp(Role, "Pasien")==0) menuPasien();
    else if (strcmp(Role, "Dokter")==0) menuDokter();
    else if (strcmp(Role, "Manager")==0) menuManager();
    else if (strcmp(Role, "BelumLogin")==0) menuBelumLogin();
    else exit(0); // Untuk Testing Bukan Permanen
}

void menuPasien(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo %s\nSilahkan masukan fungsi yang anda ingin jalankan\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid\n", Role/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpPasien();
        else if (strcmp(input, "LOGOUT")==0) /*Logout*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else{
            printf("Input tidak valid. Masukan kembali input yang valid.\n");
            continue; // memutus iterasi ini supaya tidak lanjut ke break
        }
        break; // memutuskan loop saat input valid sehingga fungsi bisa selesai
    }
    
}

void menuDokter(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo Dokter %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpDokter();
        else if (strcmp(input, "LOGOUT")==0) /*Logout*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else{
            printf("Input tidak valid. Masukan kembali input yang valid.\n");
            continue; // memutus iterasi ini supaya tidak lanjut ke break
        }
        break; // memutuskan loop saat input valid sehingga fungsi bisa selesai
    }
}

void menuManager(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo Manager %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpManager();
        else if (strcmp(input, "LOGOUT")==0) /*Logout*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else{
            printf("Input tidak valid. Masukan kembali input yang valid.\n");
            continue; // memutus iterasi ini supaya tidak lanjut ke break
        }
        break; // memutuskan loop saat input valid sehingga fungsi bisa selesai
    }
}

void menuBelumLogin(){
    char input[20]; // variable yang menyimpan input user
    printf("Anda belum masuk ke suatu akun.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpBelumLogin();
        else if (strcmp(input, "LOGIN")==0) /*Login*/;
        else if (strcmp(input, "REGISTER")==0) /*Register*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else{
            printf("Input tidak valid. Masukan kembali input yang valid.\n");
            continue; // memutus iterasi ini supaya tidak lanjut ke break
        }
        break; // memutuskan loop saat input valid sehingga fungsi bisa selesai
    }
}