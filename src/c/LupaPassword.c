#include "../header/LupaPassword.h"


// Implementasi fungsi Run-Length Encoding (RLE)
void runLengthEncoding(const char* input, char* output) {
    int i = 0;
    int count = 1;
    char buffer[100];
    output[0] = '\0';

    while (input[i]){
        while (input[i] == input[i+1]){
            count++;
            i++;
        }
        if (count>1){
            sprintf(buffer, "%d%c", count, input[i]);
        } else {
            sprintf(buffer,"%c", input[i]);
        }
        strcat(output,buffer);
        count=1;
        i++;
    }

  
}

// Implementasi fungsi lupaPassword
void lupaPassword() {
    char usernameInput[STR_MAX_SIZE];
    char kodeUnik[STR_MAX_SIZE];
    boolean found = false, correct = false;

    printf("\nMasukkan username: ");
    scanf("%s", usernameInput);

    printf("Masukkan kode unik: ");
    scanf("%s", kodeUnik);

    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData *user = globalUserDatabase.buffer[i];
        if (user->type == DATA_TYPE_PATIENT) {
            Patient *userPatient = (Patient*)(user->data);
            char encodedStored[STR_MAX_SIZE];
            if (strcmp(usernameInput, userPatient->username) == 0){ 
                runLengthEncoding(userPatient->username, encodedStored);
                found = true;
                 if (strcmp(kodeUnik, encodedStored) == 0) {
                    correct = true;
                    printf("\nHalo %s, silakan daftarkan ulang password anda!\n", userPatient->username);
                    printf("Masukkan password baru: ");
                    scanf("%s", userPatient->password);
                    printf("Password berhasil diperbarui.\n\n");
                    break;
                }
            }
        }
        else if (user->type == DATA_TYPE_DOCTOR) {
            Doctor *userDoctor = (Doctor*)(user->data);
            char encodedStored[STR_MAX_SIZE];
            if (strcmp(usernameInput, userDoctor->username) == 0){ 
                runLengthEncoding(userDoctor->username, encodedStored);
                found = true;
                if (strcmp(kodeUnik, encodedStored) == 0) {
                    correct = true;
                    printf("\nHalo Dokter %s, silakan daftarkan ulang password anda!\n", userDoctor->username);
                    printf("Masukkan password baru: ");
                    scanf("%s", userDoctor->password);
                    printf("Password berhasil diperbarui.\n\n");
                    break;
                }
            } 
        }
        else if (user->type == DATA_TYPE_MANAGER) {
            Manager *userManager = (Manager*)(user->data);
            char encodedStored[STR_MAX_SIZE];
            if (strcmp(usernameInput, userManager->username) == 0){ 
                runLengthEncoding(userManager->username, encodedStored);
                found = true;
                if (strcmp(kodeUnik, encodedStored) == 0) {
                    correct = true;
                    printf("\nHalo Manager %s, silakan daftarkan ulang password anda!\n", userManager->username);
                    printf("Masukkan password baru: ");
                    scanf("%s", userManager->password);
                    printf("Password berhasil diperbarui.\n\n");
                    break;
                }
            } 
        } 
    }

    if (!found) {
        printf("Username tidak ditemukan.\n\n");
    } else if (!correct){
        printf("Kode unik salah!\n\n");
    }
}