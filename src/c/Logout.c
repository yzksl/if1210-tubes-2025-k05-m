#include "../header/Logout.h"

void logout() {
    if (globalCurrentUserGD->type!=DATA_TYPE_UNKNOWN) {
       printf("Sampai jumpa\n==========\n\n");
    globalCurrentUserGD=&globalNotLogin;

    } else {
        printf("Logout gagal!\n");
        printf("Anda belum login, silahkan login terlebih dahulu sebelum melakukan logout\n\n");
    }
}