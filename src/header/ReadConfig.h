// Header ReadConfig memuat prosedur membaca file config
#ifndef READCONFIG_h
#define READCONFIG_h

#include <stdio.h>
#include <DataTypeRuangan.h>

int scanNumber(FILE* file); // Fungsi untuk mengscan nomor dalam suatu file

void readConfig(); // Prosedur untuk membaca file config

#endif