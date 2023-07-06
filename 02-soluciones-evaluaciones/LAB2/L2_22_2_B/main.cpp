/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 20 de abril de 2023, 20:29
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"
using namespace std;

int main(int argc, char** argv) {
    CompletarGastoXPaciente();
    VerificarCreacion("Pacientes.bin", "Pacientes.txt");
    return 0;
}

