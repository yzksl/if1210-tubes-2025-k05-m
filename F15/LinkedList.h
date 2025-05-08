/* MODUL LINKED LIST DINAMIK DENGAN DATA GENERIK*/
/* Berisi definisi dan semua primitif pemrosesan linked list dinamik dengan data generik */
/* Setiap elemen disimpan dalam node yang dialokasikan secara dinamis dan berisi pointer ke dat (void*), dimana data tersebut dapat diganti dengan tipe data yang diinginkan */
/* Banyaknya elemen didefinisikan secara implisit, memori list dinamis */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Boolean.h"

/*  Kamus Umum */
/* Linked List Terminology */
/* Linked List Single: Struktur data dinamis yang terdiri dari node, masing-masing berisi sebuah pointer ke data, dan pointer ke node selanjutnya. Berbeda dengan list biasa yang menggunakan index, keberadaan suatu elemen (node) dalam linked list tergantung pada node sebelumnya yang point ke elemen tersebut. */
/* Node: Elemen dalam linked list yang berisi nilai, dan suatu pointer ke node selanjutnya. */
/* Head: Node pertama dalam linked list */
/* Tail: Node terakhir dalam linked list, dimana pointer ke node selanjutnya berisi NULL */
/* Next: Pointer dalam node yang menunjuk ke node berikutnya */
/* Data: Informasi yang disimpan dalam node, sebuah pointer */

/*  Definisi elemen dan koleksi objek*/
typedef struct LinkedListNode {
    int id; // ID dari data (jika ada)
    char name[50]; // Nama dari data (jika ada)
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
    int size;
} LinkedList;
/* Jika l adalah LinkedList, cara deklarasi dan akses: */
/* Deklarasi: l : LinkedList*/
/* Maka cara akses: menggunakan fungsi-fungsi dibawah...*/

/* ********** SELEKTOR ********** */
#define HEAD(l) (l).head
#define SIZE(l) (l).size
#define DATA(node) (node).data
#define ID(node) (node).id
#define NAME(node) (node).name

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
void CreateLL(LinkedList *l);
/* I.S. l sembarang */
/* F.S. Terbentuk list l kosong dengan size 0, head point to NULL */
LinkedListNode* CreateLLNode(void *data);
/* Mengirimkan pointer ke Node */

/* ********** SELEKTOR (TAMBAHAN) ********** */
LinkedListNode getLLNodeById(LinkedList l, int id);
/* Mengirimkan data node dengan id tertentu */
LinkedListNode getLLNodeByIdx(LinkedList l, int pos);
/* Mengirimkan data node dengan ekuivalen indeks*/
LinkedListNode getLLNodeByName(LinkedList l, char name[50]);
/* Mengirimkan data node dengan nama tertentu */

/* ********** TEST KOSONG ********** */
boolean isLLEmpty(LinkedList l);
/* Mengirimikan true jika kosong, false jika tidak */
boolean isLLNodeEmpty(LinkedListNode node);
/* Mengirimkan true jika kosong, false jika tidak */

#endif