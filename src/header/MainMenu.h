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
#include "Register.h"
#include "LupaPassword.h"
#include "MinumObat.h"
#include "LihatUser.h"
#include "Penawar.h"
#include "TambahDokter.h"
#include "LihatUser.h"
#include "DenahDinamis.h"
#include "Ngobatin.h"
#include "BolehPulangGa.h"
#include "MaininAntrian.h"

void mainMenu(); // Prosedur untuk membuka Main Menu dengan ketentuan role user

void menuPasien(); // Prosedur untuk menerima input pilihan fungsi dari pasien

void menuDokter(); // Prosedur untuk menerima input pilihan fungsi dari dokter

void menuManager(); // Prosedur untuk menerima input pilihan fungsi dari manager

void menuBelumLogin(); // Prosedur untuk menerima input pilihan fungsi dari user yang belum login


#endif