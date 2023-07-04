/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 19 de abril de 2023, 23:11
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"
using namespace std;

int main(int argc, char** argv) {
    LeerArchivos();
    VerificarCreacion("Pacientes.bin", "PacientesPrueba.txt");
    VerificarCreacion("Medicinas.bin", "MedicinasPrueba.txt");
    return 0;
}

