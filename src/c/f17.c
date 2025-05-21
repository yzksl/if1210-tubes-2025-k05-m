#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f17.h"


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
        p.inventory[nEff] = o.id;  //bingung syntaxnya bagaimana
        nEff++;
    }
}