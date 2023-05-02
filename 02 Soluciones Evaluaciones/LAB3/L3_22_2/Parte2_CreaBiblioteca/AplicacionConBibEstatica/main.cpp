/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 27 de abril de 2023, 23:09
 */

#include <iostream>
#include <iomanip>
#include "Estructuras.h"
#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {
    struct StMedico medicos[100];
    LeerMedicos(medicos);
    
    struct StPaciente pacientes[100];
    LeerPacientes(pacientes);
    
    LeerCitas(medicos, pacientes);
    CalcularGastos(pacientes);
    EmitirReporte(pacientes);
    return 0;
}

