// Global variable antar file
#include <stdlib.h>
#include "../header/DynamicList.h"
#include "../header/StructsInHospital.h"
#include <string.h>
#include "../header/GlobalVariable.h"

// ... = {0} artinya mengisi seluruh komponen data dalam variabel tsb dengan nilai kosong

// databases
ListDin globalUserDatabase = {0};
ObatDatabase globalObatDatabase = {0};
PenyakitDatabase globalPenyakitDatabase = {0};
ObatPenyakitDatabase globalOPDatabase = {0};

// current user
GenericData* globalCurrentUserGD = {0};
Patient* globalCurrentPatient = {0};
Doctor* globalCurrentDoctor = {0};
Manager* globalCurrentManager = {0};

DataTypeDenah globalDenahRumahSakit; 