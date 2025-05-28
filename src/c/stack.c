#include "Stack.h"
#include "StructsInHospital.h"
#include <stdio.h>
#include <string.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor: membentuk sebuah stack */
void createStack(Stack* s){
    s->top = IDX_UNDEF;
}
/* I.S. s sembarang (baru di deklarasi Stack s) */
/* F.S. top = IDX_UNDEF = -1 */
/* Konstruktor: menambahkan elemen ke stack */
void pushStack(Stack* s, Obat o){
    if (isStackEmpty(s)) {
        s->top = 0;
        s->obat[s->top] = o;
    }
    
    else if(!isStackFull(s)){
        s->top++;
        s->obat[s->top] = o;
    }
    else{
        printf("STACK PENUH\n");
    }
}
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. Jika s tidak penuh, top += 1, elemen di index top adalah o. Jika s penuh, dikeluarkan "STACK PENUH" */

/* ********** DEALOKATOR/SELEKTOR ********** */
/* Dealokator & Selektor */
Obat popStack(Stack* s){
    if(!isStackEmpty(s)){
        Obat o = s->obat[s->top];
        s->top--;
        return o;
    }
    else{
        printf("STACK KOSONG\n");
        Obat temp;
        temp.id = UNDEF_INT_DATA;
        strcpy(temp.name, "");
        return temp; //keluaran kalau stack kosong
    }
}
/* Jika s tidak kosong, Mengembalikan obat di top dan menghapus obat tersebut dari stack (top -= 1). Walaupun mengembalikan datanya, tidak harus meng-assign data tersebut ke suatu variabel jika tidak diperlukan (cukup di panggil fungsi ini saja tanpa assignment ke suatu variabel ). Jika s kosong, dikeluarkan "STACK KOSONG" */
void deleteStack(Stack *s){
    s->top = IDX_UNDEF;
}
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. s kosong */

/* ********** SELEKTOR TAMBAHAN ********** */
int getTopIdx(const Stack* s){
    return s->top;
}
/* Mengembalikan nilai top index */
Obat getTopElmt(const Stack* s){
    if(isStackEmpty(s)){
        printf("STACK KOSONG\n");
        Obat temp;
        temp.id = IDX_UNDEF;
        strcpy(temp.name, "");
        return temp;
    }
    else{
        return s->obat[s->top];
    }
}
/* Jika s tidak kosong, mengembalikan obat top. Jika s kosong, dikeluarkan "STACK KOSONG" dan mengembalikan obat sentinel */
Obat getElmtByIdxStack(const Stack* s, int idx){
    Obat temp;
    temp.id = UNDEF_INT_DATA;
    strcpy(temp.name, "");

    if(isStackEmpty(s)){
        printf("STACK KOSONG\n");
        return temp; // mengembalikan obat sentinel
    }
    else if(idx<0 || idx>s->top){
        printf("IDX DI LUAR RANGE\n");
        return temp; // mengembalikan obat sentinel}
    }
    else{
        return s->obat[idx];
    }
}

/* Jika s tidak kosong dan 0 <= idx <= top, mengembalikan obat di index idx. Jika s kosong atau idx di luar daerah asal, dikeluarkan "STACK KOSONG" atau "IDX DI LUAR RANGE" dan mengembalikan obat sentinel */
int stackSize(const Stack* s){
    return s->top+1;
}
/* Mengembalikan size dari stack (top + 1) (bukan kapasitas maksimum) */

/* ********** TEST KOSONG/PENUH ********** */
boolean isStackEmpty(const Stack* q){
    return q->top == IDX_UNDEF;
}
/* Mengembalikan true jika stack kosong, false jika tidak kosong */
boolean isStackFull(const Stack* q){
    return q->top == OBAT_MAX_SIZE-1;
}
/* Mengembalikan true jika stack penuh, false jika tidak penuh */
