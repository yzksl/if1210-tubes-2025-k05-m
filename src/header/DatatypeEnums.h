/* MODUL UNTUK DEKLARASI DATATYPE YANG ADA DALAM ENUM */
/* Berisi datatype-datatype yang digunakan dalam program  */
/* Digunakan untuk membuat pengecekan datatype lebih mudah, seperti pengecekan datatype dalam void* data pada linked list */
/* Digunakan enum untuk memberi nama logik untuk datatype yang dapat digunakan untuk pengecekan */

#ifndef DATATYPE_H
#define DATATYPE_H

typedef enum {
    DATA_TYPE_UNKNOWN,
    DATA_TYPE_PATIENT,
    DATA_TYPE_DOCTOR,
    DATA_TYPE_MANAGER
} DataType;

#endif