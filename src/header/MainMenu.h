// Module Main Menu yang memuat prosedur Main Menu
#ifndef MAINMENU_h
#define MAINMENU_h

#include <stdio.h>
#include <string.h>
#include <Boolean.h>
#include <GlobalVariable.h>

void MainMenu(); // Prosedur untuk membuka Main Menu dengan ketentuan role user

void MenuPasien(); // Prosedur untuk menerima input pilihan fungsi dari pasien

void MenuDokter(); // Prosedur untuk menerima input pilihan fungsi dari dokter

void MenuManager(); // Prosedur untuk menerima input pilihan fungsi dari manager

void MenuBelumLogin(); // Prosedur untuk menerima input pilihan fungsi dari user yang belum login


#endif