/* MODUL ADT MAP */
/* Berisi definisi dan semua primitif pemrosesan ADT Map */
/* Isi dari sebuah map adalah key dan value yang keduanya bernilai int */
/* Maka, gunakan ID */
/* Tujuannya adalah cara menghubungkan suatu value kepada suatu key */

#ifndef MAP_H
#define MAP_H

#include "Boolean.h"

/*  Definisi elemen dan koleksi objek*/
typedef struct {
    int key;    /* id dari key */
    int value;  /* id dari value */
} Map;

#endif