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
    globalCurrentPatient = (Patient*)(globalCurrentUserGD->data);
    printf("Halo %s\nSilahkan masukan fungsi yang anda ingin jalankan\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid\n\n", (*(Patient*)globalCurrentUserGD->data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpPasien();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "PULANGDOK")==0) pulangDok(getQueueFromPatientId(globalCurrentPatient->id));
        else if (strcmp(input, "ANTRIAN")==0) antrianSaya();
        else if (strcmp(input, "DAFTAR_CHECKUP")==0) daftarCheckup(globalCurrentUserGD);
        else if (strcmp(input, "MINUM_OBAT")==0) minumObat();
        else if (strcmp(input, "PENAWAR")==0) minumPenawar();
        else if (strcmp(input, "LUPA_PASSWORD")==0) lupaPassword();
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
    globalCurrentDoctor = (Doctor*)(globalCurrentUserGD->data);
    printf("Halo Dokter %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n\n", (*(Doctor*)globalCurrentUserGD->data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpDokter();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "DIAGNOSIS")==0) diagnosis(getQueueFromDoctorId(globalCurrentDoctor->id));
        else if (strcmp(input, "NGOBATIN")==0) ngobatin(getQueueFromDoctorId(globalCurrentDoctor->id));
        else if (strcmp(input, "LUPA_PASSWORD")==0) lupaPassword();
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
    globalCurrentManager = (Manager*)(globalCurrentUserGD->data);
    printf("Halo Manager %s. Silahkan masukan fungsi yang anda ingin jalankan.\nMasukan HELP untuk memunculkan list fungsi-fungsi yang valid.\n\n", (*(Manager*)globalCurrentUserGD->data).username/*Nama*/);
    while(1){
        printf(">>> ");
        scanf("%s", input);
        if (strcmp(input, "HELP")==0) helpManager();
        else if (strcmp(input, "LIHAT_DENAH")==0) lihatDenah();
        else if (strcmp(input, "LIHAT_USER")==0) lihatUser(globalUserDatabase);
        else if (strcmp(input, "LIHAT_DOKTER")==0) lihatDokter(globalUserDatabase);
        else if (strcmp(input, "LIHAT_PASIEN")==0) lihatPasien(globalUserDatabase);
        else if (strcmp(input, "LIHAT_RUANGAN")==0) lihatRuangan(-1, -1);
        else if (strcmp(input, "LIHAT_USER")==0) lihatUser(globalUserDatabase);
        else if (strcmp(input, "LIHAT_PASIEN")==0) lihatPasien(globalUserDatabase);
        else if (strcmp(input, "LIHAT_DOKTER")==0) lihatDokter(globalUserDatabase);
        else if (strcmp(input, "CARI_USER")==0) cariUser(globalUserDatabase);
        else if (strcmp(input, "CARI_PASIEN")==0) cariPasien(globalUserDatabase);
        else if (strcmp(input, "CARI_DOKTER")==0) cariDokter(globalUserDatabase);
        else if (strcmp(input, "LIHAT_SEMUA_ANTRIAN")==0) lihatSemuaAntrian();
        else if (strcmp(input, "TAMBAH_DOKTER")==0) tambahDokter(); 
        else if (strcmp(input, "ASSIGN_DOKTER")==0) assignDokter();
        else if (strcmp(input, "PINDAH_DOKTER")==0) pindahDokter();
        else if (strcmp(input, "UBAH_DENAH")==0) ubahDenah();
        else if (strcmp(input, "LUPA_PASSWORD")==0) lupaPassword();
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
        else if (strcmp(input, "LOGIN")==0){
            login();
            if (globalCurrentUserGD->type!=DATA_TYPE_UNKNOWN) break;
        }
        else if (strcmp(input, "LOGOUT")==0) logout();
        else if (strcmp(input, "REGISTER")==0) registerPasien();
        else if (strcmp(input, "EXIT")==0) exitFromHospital();
        // Fungsi lanjutan yang belum ditulis
        else printf("\nInput tidak valid. Masukan kembali input yang valid.❌\n\n");
    }
}