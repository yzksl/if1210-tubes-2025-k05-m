#include <MainMenu.h>

// Realisasi prosedur Main Menu

void MainMenu(){
    if (strcmp(Role, "Pasien")==0) MenuPasien();
    else if (strcmp(Role, "Dokter")==0) MenuDokter();
    else if (strcmp(Role, "Manager")==0) MenuManager();
    else if (strcmp(Role, "BelumLogin")==0) MenuBelumLogin();
}

void MenuPasien(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) /*HelpPasien*/;
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

void MenuDokter(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo Dokter %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) /*HelpDokter*/;
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

void MenuManager(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo Manager %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) /*HelpManager*/;
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

void MenuBelumLogin(){
    char input[20]; // variable yang menyimpan input user
    printf("Anda belum masuk ke suatu akun.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", Role/*Nama*/);
    while(1){
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) /*HelpBelumLogin*/;
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