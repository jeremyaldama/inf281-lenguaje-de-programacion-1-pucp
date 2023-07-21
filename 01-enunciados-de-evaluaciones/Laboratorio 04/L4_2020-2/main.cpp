/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de octubre de 2020, 08:01 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Laboratorio04_Funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char **codigoMed, **medicos;
    double *tarifas;
    cargarMedicos(codigoMed,medicos,tarifas);
    reporteMedicos(codigoMed,medicos,tarifas);
    reporteDeIngresos(codigoMed,medicos,tarifas);
    return (EXIT_SUCCESS);
}

