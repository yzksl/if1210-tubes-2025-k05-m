// Header ReadConfig memuat prosedur membaca file config
#ifndef READCONFIG_h
#define READCONFIG_h

#define MAX_PATH_LENGTH 256

#include <stdio.h>
#include "DataTypeRuangan.h"
#include "CTypePalsu.h"
#include "FindAccount.h"
#include "StructsInHospital.h"

int scanNumber(FILE* file); // Fungsi untuk mengscan nomor dalam suatu file

void readConfig(const char* path); // Prosedur untuk membaca file config

#endif