#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

void ImprimirLinea(char c, int n){
    cout << setw(n) << setfill(c) << "" << endl;
    cout << setfill(' ');
}

void FormatearNombre(char *nombre){
    for (int i = 0; nombre[i]; i++){
        char c = nombre[i];
        if (c == '/' || c == '-'){
            nombre[i] = ' ';
        }
    }
}


int Strlen(const char*nombre){
    int i;
    for (i=0; nombre[i]; i++){}
    return i;
}
