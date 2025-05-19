// Include any necessary headers
#include <stdio.h>
#include <MainMenu.h>
#include <ReadConfig.h>
#include <ReadCSV.h>

int main() {
    // Your code goes here
    createLD(&globalUserDataBase, 22);
    readConfig();
    char filename[]="file/user.csv";
    processUserCSV(filename, &globalUserDataBase);
    mainMenu();
    dealocateLD(&globalUserDataBase);
    return 0;
}