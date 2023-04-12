#include <iostream>
#include <fstream>

using namespace std;
#include "regalo.h"

void CargaAlumnos(tregalu *alumnos, const char* arch){
    ifstream entrada(arch, ios::in);
    int i = 0;
    while(!entrada.eof()){
        entrada >> alumnos[i].codigo;
        entrada >> alumnos[i].nombre;
        i++;
    }
    alumnos[i].codigo = -1;
}