/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de octubre de 2020, 11:49 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
using namespace std;

int main(int argc, char** argv) {
    char **especialidad, ***listaMedicos, ***medicos, ***pacientes;
    double ***montos;
    cargarMedicosEspecialidad(especialidad,listaMedicos,medicos);
    reporteMedicos(especialidad,listaMedicos,medicos);
    cargarPacientes(medicos,pacientes,montos);
    reportePacientesPorMedico(especialidad,listaMedicos,medicos,pacientes,montos);
    return (EXIT_SUCCESS);
}

