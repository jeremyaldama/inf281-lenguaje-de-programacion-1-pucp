/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 10 de octubre de 2020, 01:08 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Bib_Func_Medicos.h"
#include "Bib_Func_Pacientes.h"
using namespace std;

int main(int argc, char** argv) {
    char **especialidad, ****medicos, ***pacientes;
    double **gastos;
    leerMedicos(especialidad,medicos);
    imprimirMedicos(especialidad,medicos);
    leerPacientes(pacientes,gastos,especialidad,medicos);
    imprimirPacientes(pacientes,gastos,especialidad);
    return (EXIT_SUCCESS);
}