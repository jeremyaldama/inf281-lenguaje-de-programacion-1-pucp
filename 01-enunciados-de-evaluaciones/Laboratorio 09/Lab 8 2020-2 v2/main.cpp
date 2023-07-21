/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 02:12 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Lista.h"
using namespace std;

int main(int argc, char** argv) {
    class Lista Pacientes;
    Pacientes.crear("AtencionDeCitas.csv");
    Pacientes.imprimir("Reporte.txt");
    return (EXIT_SUCCESS);
}
