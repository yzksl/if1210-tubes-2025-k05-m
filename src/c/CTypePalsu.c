#include "../header/CTypePalsu.h"

char toLower(char character){
    if (character>='A' && character<='Z') return character+32;
    else return character;
}

void toLowerString(char string[],char lowerString[]){
    int i=0;
    while(string[i]!='\0'){
        lowerString[i]=toLower(string[i]);
        i++;
    }
    lowerString[i]='\0';
}

int isDigit(char character){
    if (character>='0' && character<='9') return 1;
    else return 0;
}