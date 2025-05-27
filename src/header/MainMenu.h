// Module Main Menu yang memuat prosedur Main Menu
#ifndef MAINMENU_h
#define MAINMENU_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Boolean.h"
#include "GlobalVariable.h"
#include "Help.h"
#include "LihatDenah.h"
#include "GlobalVariable.h"
#include "Exit.h"
#include "PrintArt.h"
#include "AntrianSaya.h"
#include "Login.h"
#include "Logout.h"
#include "MinumObat.h"
#include "Penawar.h"

void mainMenu(); // Prosedur untuk membuka Main Menu dengan ketentuan role user

void menuPasien(); // Prosedur untuk menerima input pilihan fungsi dari pasien

void menuDokter(); // Prosedur untuk menerima input pilihan fungsi dari dokter

void menuManager(); // Prosedur untuk menerima input pilihan fungsi dari manager

void menuBelumLogin(); // Prosedur untuk menerima input pilihan fungsi dari user yang belum login


#endif