#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Penawar.h"
#include "GlobalVariable.h"


//setelah program dijalankan, pindahin dulu data ke inventory
//setelah itu, hapus data dari stack(perut)

void minumPenawar(){
    if(isStackEmpty(&globalCurrentPatient->perut)){
        printf("\nPerut kosong, belum ada obat yang diminum.\n\n"); //kalau ternyata tidak perlu tidak apa
        return;
    }
    
    //obat yang akan dikembalikan ke inventory disimpan dalam variabel
    //Obat backToInventory = getTopElmt(&globalCurrentPatient->perut);
    //popStack(&globalCurrentPatient->perut);
    Obat backToInventory = popStack(&globalCurrentPatient->perut);
    

    //ini program agar obat kembali ke inventory
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (globalCurrentPatient->inventory[i] == UNDEF_INT_DATA) {
            globalCurrentPatient->inventory[i] = backToInventory.id;
            break;
        }
    }
    printf("\nUwekkk!!! %s keluar dan kembali ke inventory.\n\n", backToInventory.name);
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
