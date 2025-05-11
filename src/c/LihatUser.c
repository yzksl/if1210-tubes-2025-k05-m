#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <LihatUser.h>

//masih menggunakan ADT pribadi dan fungsi 'strtok'
//masih menggunakan logaritma pengcopy-an file ke dalam array yang harusnya sudah tidak perlu
//karena sudah ada dynamic list
//kedepannya akan menyesuaikan

void Print_List(Data total[], int n) {
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int max4 = 0; 
    for (int i = 0; i < n; i++) {
        if((total[i].ID/10 + 1) > max1) {
            max1 = (total[i].ID/10 + 2);
        }
        if(strlen(total[i].nama) > max2) {
            max2 = strlen(total[i].nama);
        }
        if(strlen(total[i].role) > max3) {
            max3 = strlen(total[i].role);
        }
        if(strlen(total[i].penyakit) > max4) {
            max4 = strlen(total[i].penyakit);
        }
    
    }

    printf("%-*s | %-*s | %-*s | %-*s\n", max1, "ID", max2, "Nama", max3, "Role", max4, "Penyakit");
    
    int x = max1 + max2 + max3 + max4;
    for (int i = 0; i < (3*x)/2; i++) {
        printf("-");
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%-*d | %-*s | %-*s | %-*s\n", max1, total[i].ID, max2, total[i].nama, max3, total[i].role, max4, total[i].penyakit);
    }
}

void LIHAT_DATA(void) {
    Data total[1000];
    int n = 0;

    FILE *file = fopen("C:/Users/Lenovo/Downloads/Contoh Data RS Alpro.csv", "r");
    if(file == NULL) {
        printf("Gagal membuka file.\n");
    }

    char buffer[150];
    fgets(buffer, sizeof(buffer), file);

    while(fgets(buffer, sizeof(buffer), file) != NULL && n < 1000) {
        char *x = strtok(buffer, ";\n");
        if(x != NULL) total[n].ID = (int)strtol(x, NULL, 10);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].nama, x, 50);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].role, x, 50);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].penyakit, x, 50);

        n++;
    }

    fclose(file);

    int urt, srt;

    printf("Urutkan berdasarkan?\n"); 
    printf("1. ID\n"); 
    printf("2. Nama\n"); 
    printf(">>> Pilihan: ");
    scanf("%d", &urt);

    printf("\n");

    printf("Urutan sort?\n"); 
    printf("1. ASC (A-Z)\n"); 
    printf("2. DESC (Z-A)\n"); 
    printf(">>> Pilihan: ");
    scanf("%d", &srt);

    printf("\n");
    printf("Menampilkan semua pengguna dengan ID terurut ascending...\n"); 

    if(urt == 1) {
        if(srt == 1) {
            for(int i = 0; i < (n - 1); i++) {
                for(int j = 0; j < (n - i - 1); j++) {
                    if(total[j].ID > total[j + 1].ID) {
                        Data temp = total[j + 1];
                        total[j + 1] = total[j];
                        total[j] = temp;
                    }
                }
            }
            Print_List(total, n);
        } else {
            for(int i = 0; i < (n - 1); i++) {
                for(int j = 0; j < (n - i - 1); j++) {
                    if(total[j].ID < total[j + 1].ID) {
                        Data temp = total[j + 1];
                        total[j + 1] = total[j];
                        total[j] = temp;
                    }
                }
            }
            Print_List(total, n);
        }
    } else {
        if(srt == 1) {
            for(int i = 0; i < (n - 1); i++) {
                for(int j = 0; j < (n - i - 1); j++) {
                    if(strcmp(total[j].nama, total[j + 1].nama) > 0) {
                        Data temp = total[j];
                        total[j] = total[j + 1];
                        total[j + 1] = temp;
                    }
                }
            }
            Print_List(total, n);
        } else {
            for(int i = 0; i < (n - 1); i++) {
                for(int j = 0; j < (n - i - 1); j++) {
                    if(strcmp(total[j].nama, total[j + 1].nama) < 0) {
                        Data temp = total[j];
                        total[j] = total[j + 1];
                        total[j + 1] = temp;
                    }                       
                }
            }
            Print_List(total, n);
        }
    }
}

void LIHAT_DOKTER(void) {
    Data total[1000];
    int n = 0;

    FILE *file = fopen("C:/Users/Lenovo/Downloads/Contoh Data RS Alpro.csv", "r");
    if(file == NULL) {
        printf("Gagal membuka file.\n");
    }

    char buffer[150];
    fgets(buffer, sizeof(buffer), file);

    while(fgets(buffer, sizeof(buffer), file) != NULL && n < 1000) {
        char *x = strtok(buffer, ";\n");
        if(x != NULL) total[n].ID = (int)strtol(x, NULL, 10);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].nama, x, 50);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].role, x, 50);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].penyakit, x, 50);

        n++;
    }

    fclose(file);

    int a = 0;
    int b = 0;
    for(int i = 0; i < (n - 1); i++) {
        if(total[i].role[0] == 'D') {
            a++;
        }
    }
    Data arr[a + 1];
    for(int i = 0; i < (n - 1); i++) {
        if(total[i].role[0] == 'D') {
            arr[b] = total[i];
            b++;
        }
    }

    int urt, srt;

    printf("Urutkan berdasarkan?\n"); 
    printf("1. ID\n"); 
    printf("2. Nama\n"); 
    printf(">>> Pilihan: ");
    scanf("%d", &urt);

    printf("\n");

    printf("Urutan sort?\n"); 
    printf("1. ASC (A-Z)\n"); 
    printf("2. DESC (Z-A)\n"); 
    printf(">>> Pilihan: ");
    scanf("%d", &srt);

    printf("\n");
    printf("Menampilkan semua pengguna dengan ID terurut ascending...\n"); 

    if(urt == 1) {
        if(srt == 1) {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(arr[j].ID > arr[j + 1].ID) {
                        Data temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            Print_List(arr, a);
        } else {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(arr[j].ID < arr[j + 1].ID) {
                        Data temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            Print_List(arr, a);
        }
    } else {
        if(srt == 1) {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(strcmp(arr[j].nama, arr[j + 1].nama) > 0) {
                        Data temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            Print_List(arr, a);
        } else {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(strcmp(arr[j].nama, arr[j + 1].nama) < 0) {
                        Data temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }                       
                }
            }
            Print_List(arr, a);
        }
    }
}

void LIHAT_PASIEN(void) {
    Data total[1000];
    int n = 0;

    FILE *file = fopen("C:/Users/Lenovo/Downloads/Contoh Data RS Alpro.csv", "r");
    if(file == NULL) {
        printf("Gagal membuka file.\n");
    }

    char buffer[150];
    fgets(buffer, sizeof(buffer), file);

    while(fgets(buffer, sizeof(buffer), file) != NULL && n < 1000) {
        char *x = strtok(buffer, ";\n");
        if(x != NULL) total[n].ID = (int)strtol(x, NULL, 10);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].nama, x, 50);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].role, x, 50);

        x = strtok(NULL, ";\n");
        if(x != NULL) strncpy(total[n].penyakit, x, 50);

        n++;
    }

    fclose(file);

    int a = 0;
    int b = 0;
    for(int i = 0; i < (n - 1); i++) {
        if(total[i].role[0] == 'P') {
            a++;
        }
    }
    Data arr[a + 1];
    for(int i = 0; i < (n - 1); i++) {
        if(total[i].role[0] == 'P') {
            arr[b] = total[i];
            b++;
        }
    }

    int urt, srt;

    printf("Urutkan berdasarkan?\n"); 
    printf("1. ID\n"); 
    printf("2. Nama\n"); 
    printf(">>> Pilihan: ");
    scanf("%d", &urt);

    printf("\n");

    printf("Urutan sort?\n"); 
    printf("1. ASC (A-Z)\n"); 
    printf("2. DESC (Z-A)\n"); 
    printf(">>> Pilihan: ");
    scanf("%d", &srt);

    printf("\n");
    printf("Menampilkan semua pengguna dengan ID terurut ascending...\n"); 

    if(urt == 1) {
        if(srt == 1) {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(arr[j].ID > arr[j + 1].ID) {
                        Data temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            Print_List(arr, a);
        } else {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(arr[j].ID < arr[j + 1].ID) {
                        Data temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            Print_List(arr, a);
        }
    } else {
        if(srt == 1) {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(strcmp(arr[j].nama, arr[j + 1].nama) > 0) {
                        Data temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            Print_List(arr, a);
        } else {
            for(int i = 0; i < (a - 1); i++) {
                for(int j = 0; j < (a - i - 1); j++) {
                    if(strcmp(arr[j].nama, arr[j + 1].nama) < 0) {
                        Data temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }                       
                }
            }
            Print_List(arr, a);
        }
    }
}