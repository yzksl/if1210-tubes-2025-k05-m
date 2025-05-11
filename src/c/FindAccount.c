#include <FindAccount.h>

char* getAccountName(int id, DataType dataType){
    for (int i=0; i<globalUserDataBase.nEff; i++){
        if (globalUserDataBase.buffer[i]->type==dataType){
            if (dataType==DATA_TYPE_DOCTOR){
                if (((Doctor*)(globalUserDataBase.buffer[i]->data))->id==id) return ((Doctor*)(globalUserDataBase.buffer[i]->data))->username;
            }
            else if (dataType==DATA_TYPE_PATIENT){
                if (((Patient*)(globalUserDataBase.buffer[i]->data))->id==id) return ((Patient*)(globalUserDataBase.buffer[i]->data))->username;
            }
            else if (dataType==DATA_TYPE_MANAGER){
                if (((Manager*)(globalUserDataBase.buffer[i]->data))->id==id) return ((Manager*)(globalUserDataBase.buffer[i]->data))->username;
            }
        }
    }
}