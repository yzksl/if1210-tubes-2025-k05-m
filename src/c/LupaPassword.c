#include "../header/LupaPassword.h"


// Implementasi fungsi Run-Length Encoding (RLE)
void runLengthEncoding(const char* input, char* output) {
    int count = 1;
    char buffer[20];
    int outIndex = 0;
    int len = strlen(input);

    for (int i = 1; i <= len; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            output[outIndex++] = input[i - 1];
            if (count > 1) {
                sprintf(buffer, "%d", count);
                for (int j = 0; buffer[j] != '\0'; j++) {
                    output[outIndex++] = buffer[j];
                }
            }
            count = 1;
        }
    }
    output[outIndex] = '\0';
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
            Patient *userpatient = (Patient*)(user->data)->username;
            char encodedStored[200];
            runLengthEncoding(userpatient, encodedStored);

            if (strcmp(encodedInput, encodedStored) == 0) {
                found = true;
                printf("Masukkan password baru: ");
                scanf("%s", patient.password);

                // Perbarui password di database
                USER_DATABASE.A[i].data.patient = patient;
                printf("Password berhasil diperbarui.\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Username tidak ditemukan.\n");
    }
}