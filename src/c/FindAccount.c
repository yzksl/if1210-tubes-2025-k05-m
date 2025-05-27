#include "../header/FindAccount.h"
#include <stdio.h>

char* getAccountName(int id, DataType dataType){
    for (int i=0; i<globalUserDatabase.nEff; i++){
        if (globalUserDatabase.buffer[i]->type==dataType){
            if (dataType==DATA_TYPE_DOCTOR){
                if (((Doctor*)(globalUserDatabase.buffer[i]->data))->id==id) return ((Doctor*)(globalUserDatabase.buffer[i]->data))->username;
            }
            else if (dataType==DATA_TYPE_PATIENT){
                if (((Patient*)(globalUserDatabase.buffer[i]->data))->id==id) return ((Patient*)(globalUserDatabase.buffer[i]->data))->username;
            }
            else if (dataType==DATA_TYPE_MANAGER){
                if (((Manager*)(globalUserDatabase.buffer[i]->data))->id==id) return ((Manager*)(globalUserDatabase.buffer[i]->data))->username;
            }
        }
    }
    return 0;
}

void* getAccountAddress(int id){
    for (int i=0; i<globalUserDatabase.nEff; i++){
        if (globalUserDatabase.buffer[i]->type==DATA_TYPE_DOCTOR){
            if (((Doctor*)(globalUserDatabase.buffer[i]->data))->id==id) ((Doctor*)(globalUserDatabase.buffer[i]->data));
        }
        else if (globalUserDatabase.buffer[i]->type==DATA_TYPE_PATIENT){
            if (((Patient*)(globalUserDatabase.buffer[i]->data))->id==id) return ((Patient*)(globalUserDatabase.buffer[i]->data));
        }
        else if (globalUserDatabase.buffer[i]->type==DATA_TYPE_MANAGER){
            if (((Manager*)(globalUserDatabase.buffer[i]->data))->id==id) return ((Manager*)(globalUserDatabase.buffer[i]->data));
        }
    }
}