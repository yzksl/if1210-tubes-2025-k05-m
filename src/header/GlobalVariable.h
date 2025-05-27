#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

// Global variable antar file
#include <stdlib.h>
#include "DynamicList.h"
#include "StructsInHospital.h"
#include "Set.h"

// databases
extern ListDin globalUserDatabase;
extern ObatDatabase globalObatDatabase;
extern PenyakitDatabase globalPenyakitDatabase;
extern ObatPenyakitDatabase globalOPDatabase;
extern Set globalUsernames;

// current user
extern GenericData* globalCurrentUserGD; 
extern Patient* globalCurrentPatient;
extern Doctor* globalCurrentDoctor;
extern Manager* globalCurrentManager;

// extern DataTypeDenah globalDenahRumahSakit; 

#endif