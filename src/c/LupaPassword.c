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
    char usernameInput[100];
    char encodedInput[200];
    boolean found = false;

    printf("Masukkan username: ");
    scanf("%s", usernameInput);

    runLengthEncoding(usernameInput, encodedInput);

    for (int i = 0; i < globalUserDatabase.nEff; i++) {
        GenericData *user = globalUserDatabase.buffer[i];
        if (user->type == DATA_TYPE_PATIENT) {
            Patient *userpatient = (Patient*)(user->data);
            char encodedStored[200];
            runLengthEncoding(userpatient->username, encodedStored);

            if (strcmp(encodedInput, encodedStored) == 0) {
                found = true;
                printf("Masukkan password baru: ");
                scanf("%s", userpatient->password);
                printf("Password berhasil diperbarui.\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Username tidak ditemukan.\n");
    }
}