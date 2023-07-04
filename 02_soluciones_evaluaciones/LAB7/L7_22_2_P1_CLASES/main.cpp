/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 9 de junio de 2023, 0:21
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "medico.h"
#include "cita.h"
#include "paciente.h"

int main(int argc, char** argv) {
    ifstream arch_med("medicos.csv", ios::in);
    medico med1;
    arch_med >> med1;
    
    ifstream arch_pac("pacientes.csv", ios::in);
    paciente pac1;
    
    return 0;
}

