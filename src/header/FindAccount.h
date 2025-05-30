#ifndef FINDACCOUNT_h
#define FINDACCOUNT_h

#include "DynamicList.h"
#include "GlobalVariable.h"

char* getAccountName(int id, DataType dataType);

void* getAccountAddress(int id);

int countBanyakPasienInventory(int arr[]);

int countBanyakPasienPerut(int arr[]);

Queue* getQueueFromDoctorId(int id);

Queue* getQueueFromPatientId(int id);

#endif