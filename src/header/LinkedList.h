/* MODUL LINKED LIST DINAMIK DENGAN DATA GENERIK*/
/* Berisi definisi dan semua primitif pemrosesan linked list dinamik dengan data generik */
/* Setiap elemen disimpan dalam node yang dialokasikan secara dinamis dan berisi pointer ke dat (void*), dimana data tersebut dapat diganti dengan tipe data yang diinginkan */
/* Banyaknya elemen didefinisikan secara implisit, memori list dinamis */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Boolean.h"
#include "StructsInHospital.h"

/*  Kamus Umum */
/* Linked List Terminology */
/* Linked List Single: Struktur data dinamis yang terdiri dari node, masing-masing berisi data, dan pointer ke node selanjutnya. Berbeda dengan list biasa yang menggunakan index, keberadaan suatu elemen (node) dalam linked list tergantung pada node sebelumnya yang point ke elemen tersebut. */
/* Node: Elemen dalam linked list yang berisi nilai, dan suatu pointer ke node selanjutnya. */
/* Head: Node pertama dalam linked list */
/* Tail: Node terakhir dalam linked list, dimana pointer ke node selanjutnya berisi NULL */
/* Next: Pointer dalam node yang menunjuk ke node berikutnya */
/* Data: Informasi yang disimpan dalam node, dalam kasus ini id dan nama pasien */

/*  Definisi elemen dan koleksi objek*/
typedef struct LinkedListNode {
    int id; // ID dari pasien
    char name[50]; // Nama dari pasien
    struct LinkedListNode* next; // Address node berikutnya
} LinkedListNode;
 
typedef struct LinkedList {
    LinkedListNode *head; // Address node pertama
    int size; // Jumlah elemen (node) dalam linked list
} LinkedList;
/* Jika l adalah LinkedList, cara deklarasi dan akses: */
/* Deklarasi: l : LinkedList*/
/* Maka cara akses: menggunakan fungsi-fungsi dibawah...*/

/* ********** SELEKTOR ********** */
#define LLHEAD(l) (l).head
#define LLSIZE(l) (l).size
#define LLID(node) (node).id
#define LLNAME(node) (node).name
#define LLNEXT(node) (node).next

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
void createLL(LinkedList *l);
/* I.S. l sembarang */
/* F.S. Terbentuk list l kosong dengan size 0, head point to NULL */
/* Konstruktor: create node dengan id dan nama pasien */
LinkedListNode* createLLNode(int id, char name[50]);
/* Mengirimkan pointer ke Node */ 
/* Konstruktor: sambungkan address node yang diterima ke node sebelumnya */
void putNodeInLastLL(LinkedList* l, LinkedListNode* NodeAddress);
/* I.S. l terdefinisi, bisa kosong atau bisa sudah ada isi */
/* F.S. l memiliki node yang di parameter di bagian tail */
/* Konstruktor: sisihkan node ke posisi-pos dalam linked list */
void putNodeInIdxLL(LinkedList* l, LinkedListNode* NodeAddress, int idx);
/* I.S. l terdefinisi, memiliki setidaknya 1 node */
/* F.S. l memiliki node yang di parameter sebagai node di posisi ke-pos. Jika pos invalid (>size), maka akan keluar "POSISI TIDAK VALID". Jika idx = size, panggil function puTNodeInLastLL */

/* ********** SELEKTOR (TAMBAHAN) ********** */
LinkedListNode* getLLNodeById(const LinkedList* l, int id);
/* Mengirimkan data node dengan id tertentu */
LinkedListNode* getLLNodeByIdx(const LinkedList* l, int idx);
/* Mengirimkan data node dengan ekuivalen indeks*/
LinkedListNode* getLLNodeByName(const LinkedList* l, char name[50]);
/* Mengirimkan data node dengan nama tertentu */
Patient* getPatientFromNode(LinkedListNode* node);
/* Mengirimkan pasien dalam globalUserDatabase berdasarkan id yang ada dari node */

/* ********** TEST KOSONG ********** */
boolean isLLEmpty(LinkedList l);
/* Mengirimikan true jika kosong, false jika tidak */
// boolean isLLNodeEmpty(LinkedListNode node);
// /* Mengirimkan true jika kosong, false jika tidak */
/* BELUM DIBUAT KARENA BINGUNG */

/* ********** DEALOKATOR ********** */
/* Dealokator: dealokasi memori dari seluruh linked list */
void freeLL(LinkedList* l);
/* I.S. l terdefinisi, memiliki node-node */
/* F.S. l kosong, header point to NULL, seluruh node didealokasi juga */
void freeNodeLL(LinkedList* l, LinkedListNode* node);
/* I.S. l terdefinisi, memiliki setidaknya satu nilai */
/* F.S. l terdefinisi, mungkin kosong, node sudah didealokasi */

#endif