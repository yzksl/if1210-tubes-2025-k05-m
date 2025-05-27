#include "../header/Login.h"


void login() {
    // Cek apakah sudah ada user yang login
    // if (!isSetEmpty(currentUser)) {
    //     printf("ANDA SUDAH LOGIN. MOHON LOGOUT TERLEBIH DAHULU UNTUK MELAKUKAN LOGIN KEMBALI.\n");
    //     return;
    // }

    char username[STR_MAX_SIZE];
    char password[STR_MAX_SIZE];

    printf("Masukkan username: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);

    boolean found = false;

    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData* gd=globalUserDatabase.buffer[i];

        if (gd->type == DATA_TYPE_PATIENT) {
            if ((strcmp(((Patient*)(gd->data))->username, username) == 0) && (strcmp(((Patient*)(gd->data))->password, password) == 0)) {
                globalCurrentUserGD=getGDbyIdx(&globalUserDatabase, i);
                printf("SELAMAT DATANG PASIEN %s!\n", ((Patient*)(gd->data))->username);
                found = true;
                break;
            }
        } else if (gd->type == DATA_TYPE_DOCTOR) {
            if (strcmp(((Doctor*)(gd->data))->username, username) == 0 && strcmp(((Doctor*)(gd->data))->password, password) == 0) {
                globalCurrentUserGD=getGDbyIdx(&globalUserDatabase, i);
                printf("SELAMAT DATANG DOKTER %s!\n", ((Doctor*)(gd->data))->username);
                found = true;
                break;
            }
        } else if (gd->type == DATA_TYPE_MANAGER) {
            if (strcmp(((Manager*)(gd->data))->username, username) == 0 && strcmp(((Manager*)(gd->data))->password, password) == 0) {
                globalCurrentUserGD=getGDbyIdx(&globalUserDatabase, i);
                printf("SELAMAT DATANG MANAGER %s!\n", ((Manager*)(gd->data))->username);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        printf("USERNAME ATAU PASSWORD SALAH. SILAKAN COBA LAGI.\n");
    }
}
