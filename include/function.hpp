#include <iostream>

void clear (){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleep (){
    #ifdef _WIN32
        _sleep(200);
    #else
        system("sleep 0.2");
    #endif
}