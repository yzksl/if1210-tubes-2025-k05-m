#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f17.h"
#include "GlobalVariable.h"


//setelah program dijalankan, pindahin dulu data ke inventory
//setelah itu, hapus data dari stack(perut)
Patient p;
Obat o;
void MinumPenawar(){
    Stack *perut;  //dummy, perut asli sudah dibuat di f16
    if(isStackEmpty(perut)){
        printf("Perut kosong!! Belum ada obat yang dimakan.\n");
    }
    else{
        o = popStack(&perut);  //mungkin syntaxnya masih salah

        printf("Uwekkk!!! %s keluar dan kembali ke inventory\n", o.name);
        int nEff;
        globalCurrentPatient-> inventory[nEff] = o.id;  //bingung syntaxnya bagaimana
        nEff++;
    }
}

// int main() {
//     for (int j = 0; j < globalCurrentPatient->inventory[j])
//     for (int i = 0; i < globalObatDatabase.inventory.nEff; ++i) {
//         int idObat = globalObatDatabase.inventory.contents[j];
//         if (globalObatDatabase.contents->id == idObat) {
//             printf("%d. %s\n", j+1, globalObatDatabase.contents->name);
//         }
//     }
// }