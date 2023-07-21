/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de noviembre de 2020, 09:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Medico.h"
#include "FuncionesAuxiliares.h"
using namespace std;

int main(int argc, char** argv) {
    class Medico medico[100];
    ifstream archMed = abrirArchL("Medicos.txt");
    ifstream archPac = abrirArchL("AtencionPacientes.txt");
    ifstream archOp = abrirArchL("Acciones.txt");
    ofstream archRep1 = abrirArchE("Reporte1.txt");
    ofstream archRep2 = abrirArchE("Reporte2.txt");
    archRep1.precision(2); archRep1 << fixed;
    archRep2.precision(2); archRep2 << fixed;
    int cant = 0;
    llenarMedicos(medico,archMed,cant);
    leerPacientes(medico,archPac,cant);
    imprimirMedicos(medico,archRep1,cant);
    leerOperaciones(medico,archOp,cant);
    imprimirMedicos(medico,archRep2,cant);
    return (EXIT_SUCCESS);
}
