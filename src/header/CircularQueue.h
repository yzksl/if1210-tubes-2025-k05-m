/* MODUL ADT QUEUE */
/* Berisi definisi dan semua primitif pemrosesan ADT Queue */
/* Queue berdasarkan linked list (bukan list) */
/* Banyaknya elemen didefinisikan dengan posisi "indeks" front dan rear, memori dinamis namun tidak melewati kapasitas queue */
/* Queue menggunakan konsep FIFO (First In First Out) */
/* Setiap proses penambahan (enqueue) elemen (node) ke queue, node tersebut di malloc dan ditambahkan di indeks terakhir, dan pointer rear menunjukkan address node tersebut. Setiap pengurangan node, node di index pertama di free, dan pointer front menunjukkan address node selanjutnya. */

#ifndef QUEUE_H
#define QUEUE_H

#include "Boolean.h"
#include "LinkedList.h"

/*  Kamus Umum */
/* - */

/* Definisi elemen dan koleksi objek */
typedef struct {
    LinkedListNode* front;  /* pointer ke node paling depan */
    LinkedListNode* rear;   /* pointer ke node paling belakang (elemen yang "ditunjuk" oleh pointer ini tidak termasuk sebuah nilai )*/
    int size;               /* besar queue */
    int capacity;           /* kapasitas queue yang dapat dibuat */
} Queue;
/* Jika q adalah : Queue, cara deklarasi dan akses: */
/* Deklarasi : q : Queue */
/* Maka cara akses: 
    gunakan fungsi-fungsi selektor */
/* Definisi:
    list kosong: front = rear = NULL, size = 0
    list penuh: rear.next = front, size = capacity
    list dengan satu elemen: front = rear = address suatu node
    elemen pertama jika tidak kosong: nilai dalam pointer front
    elemen terakhir jika tidak kosong: nilai sebelum rear */

/* ********** SELEKTOR ********** */
#define FRONT(q) (q).front
#define FRONTELMT(q) (*((q).front))
#define REAR(q) (q).rear
#define REARELMT(q) (*((q).rear))
#define SIZE(q) (q).size
#define CAPACITY(q) (q).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: menambahkan node ke queue */
void enQueue(Queue* q, LinkedListNode* node);
/* I.S. q terdefinisi, mungkin kosong */
/* F.S. Jika size < capacity, elemen terakhir q adalah node, size bertambah satu. Rear diupdate untuk memiliki nilai address node tersebut. Jika sama, maka dikeluaran "ANTRIAN PENUH" */

/* ********** DEALOKATOR ********** */
void deQueue(Queue* q);
/* I.S. q terdefinisi */
/* F.S. Jika tidak kosong, elemen front di free. Front diupdate untuk memiliki nilai address node selanjutnya. Jika kosong, dikeluarkan "ANTRIAN KOSONG" */
void freeQueue(Queue* q);
/* I.S. q terdefinisi, mungkin memiliki beberapa node */
/* F.S. semua node di free, tidak ada node dalam queue, all pointers point to NULL */

/* ********** SELEKTOR TAMBAHAN ********** */
LinkedListNode* getFrontAddr(const Queue* q);
/* Mengembalikan address node pertama dalam queue */
LinkedListNode* getLastAddr(const Queue* q);
/* Mengembalikan address node terakhir dalam queue */
int getFrontID(const Queue* q);
/* Mengembalikan ID dari node pertama */
char* getFrontName(const Queue* q);
/* Mengembalikan nama dari node pertama */
int getLastID(const Queue* q);
/* Mengemblikan ID dari node terakhir */
char* getFrontName(const Queue *q);
/* Mengembalikan nama dari node terakhir */
LinkedListNode* getNodeAddrByIdx(const Queue* q, int idx);
/* Mengembalikan address dari node di index ke-idx dalam queue */
/* Front: index 0, rear: index size - 1 */
LinkedListNode* getNodeAddrByID(const Queue* q, int id);
/* Mengembalikan address dari node dengan id tertentu */
int getIDByIdx(const Queue* q, int idx);
/* Mengembalikan id dari node di index ke-idx */
char* getNameByIdx(const Queue* q, int idx);
/* Mengembalikan nama dari node di index ke-idx */

/* ********** TEST KOSONG/PENUH ********** */
boolean isQueueEmpty(const Queue* q);
/* Mengembalikan true jika queue kosong, false jika tidak kosong */
boolean isQueueFull(const Queue* q);
/* Mengembalikan true jika queue penuh, faalse jika tidak penuh*/

#endif