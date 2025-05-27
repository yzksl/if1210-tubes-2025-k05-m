#include "../header/MainMenu.h"
#include "../header/GlobalVariable.h"

// Realisasi Header Main Menu

void mainMenu(){
    while(1){
        if (globalCurrentUserGD->type==DATA_TYPE_PATIENT) menuPasien();
        else if (globalCurrentUserGD->type==DATA_TYPE_DOCTOR) menuDokter();
        else if (globalCurrentUserGD->type==DATA_TYPE_MANAGER) menuManager();
        else if (globalCurrentUserGD->type==DATA_TYPE_UNKNOWN) menuBelumLogin();
    }
    
}

void menuPasien(){
    char input[20]; // variable yang menyimpan input user
    printMenuPasien();
    printf("Halo %s\nSilahkan masukan fungsi yang anda ingin jalankan\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid\n\n", (*(Patient*)globalCurrentUserGD->data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpPasien();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "ANTRIAN")==0) antrianSaya();
        else if (strcmp(input, "LOGIN")==0) login();
        else if (strcmp(input, "LOGOUT")==0){
            logout();
            if (globalCurrentUserGD->type!=DATA_TYPE_PATIENT) break;
        }
        else if (strcmp(input, "EXIT")==0) exitFromHospital();
        // Fungsi lanjutan yang belum ditulis
        else printf("\nInput tidak valid. Masukan kembali input yang valid.❌\n\n");
    }
    
}

void menuDokter(){
    char input[20]; // variable yang menyimpan input user
    printMenuDokter();
    printf("Halo Dokter %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n\n", (*(Doctor*)globalCurrentUserGD->data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpDokter();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "LOGIN")==0) login();
        else if (strcmp(input, "LOGOUT")==0){
            logout();
            if (globalCurrentUserGD->type!=DATA_TYPE_DOCTOR) break;
        }
        else if (strcmp(input, "EXIT")==0) exitFromHospital();
        // Fungsi lanjutan yang belum ditulis
        else printf("\nInput tidak valid. Masukan kembali input yang valid.❌\n\n");
    }
}

void menuManager(){
    char input[20]; // variable yang menyimpan input user
    printMenuManager();
    printf("Halo Manager %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n\n", (*(Manager*)globalCurrentUserGD->data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpManager();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "LIHAT_SEMUA_ANTRIAN")==0) lihatSemuaAntrian();
        else if (strcmp(input, "LOGIN")==0) login();
        else if (strcmp(input, "LOGOUT")==0){
            logout();
            if (globalCurrentUserGD->type!=DATA_TYPE_MANAGER) break;
        }
        else if (strcmp(input, "EXIT")==0) exitFromHospital();
        // Fungsi lanjutan yang belum ditulis
        else printf("\nInput tidak valid. Masukan kembali input yang valid.❌\n\n");
    }
}

void menuBelumLogin(){
    char input[20]; // variable yang menyimpan input user
    printf("Anda belum masuk ke suatu akun.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n\n");
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpBelumLogin();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "LOGIN")==0){
            login();
            if (globalCurrentUserGD->type!=DATA_TYPE_UNKNOWN) break;
        }
        else if (strcmp(input, "LOGOUT")==0) logout();
        else if (strcmp(input, "REGISTER")==0) break/*Register*/;
        else if (strcmp(input, "EXIT")==0) exitFromHospital();
        // Fungsi lanjutan yang belum ditulis
        else printf("\nInput tidak valid. Masukan kembali input yang valid.❌\n\n");
    }
}