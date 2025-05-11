#include <MainMenu.h>

// Realisasi Header Main Menu

void mainMenu(){
    if (globalCurrentUser.type==DATA_TYPE_PATIENT) menuPasien();
    else if (globalCurrentUser.type==DATA_TYPE_DOCTOR) menuDokter();
    else if (globalCurrentUser.type==DATA_TYPE_MANAGER) menuManager();
    else if (globalCurrentUser.type==DATA_TYPE_UNKNOWN) menuBelumLogin();
}

void menuPasien(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo %s\nSilahkan masukan fungsi yang anda ingin jalankan\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid\n", (*(Patient*)globalCurrentUser.data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpPasien();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan();
        else if (strcmp(input, "LOGOUT")==0) break/*Logout*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else printf("Input tidak valid. Masukan kembali input yang valid.\n");
    }
    
}

void menuDokter(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo Dokter %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", (*(Doctor*)globalCurrentUser.data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpDokter();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan();
        else if (strcmp(input, "LOGOUT")==0) break/*Logout*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else printf("Input tidak valid. Masukan kembali input yang valid.\n");
    }
}

void menuManager(){
    char input[20]; // variable yang menyimpan input user
    printf("Halo Manager %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n", (*(Manager*)globalCurrentUser.data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpManager();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan();
        else if (strcmp(input, "LOGOUT")==0) break/*Logout*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else printf("Input tidak valid. Masukan kembali input yang valid.\n");
    }
}

void menuBelumLogin(){
    char input[20]; // variable yang menyimpan input user
    printf("Anda belum masuk ke suatu akun.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n");
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpBelumLogin();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan();
        else if (strcmp(input, "LOGIN")==0) break/*Login*/;
        else if (strcmp(input, "REGISTER")==0) break/*Register*/;
        else if (strcmp(input, "EXIT")==0) /*Exit*/;
        // Fungsi lanjutan yang belum ditulis
        else printf("Input tidak valid. Masukan kembali input yang valid.\n");
    }
}