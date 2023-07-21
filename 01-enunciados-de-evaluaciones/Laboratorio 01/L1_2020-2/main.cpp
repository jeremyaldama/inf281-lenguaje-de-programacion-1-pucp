/* 
 * Archivo:   main.cpp
 * Autor: Oscar DueÃ±as Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 29 de octubre de 2020, 11:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
using namespace std;

int main(int argc, char** argv) {
    cout << setw(80) << "INFORMACION ACADEMICA DE LOS ESTUDIANTES" << endl;
    cout.precision(2); cout << fixed;
    int codAl = -1, anioIngreso, cant = 0;
    while (1) { 
        if (cin.eof()) break;
        leerAlumno(codAl,anioIngreso); // leemos e imprimimos el alumno      
        procesarCursos(codAl,anioIngreso); // procesamos sus notas
        cant++;
    }
    imprimeLinea('=',140);
    cout << "TOTAL DE ALUMNOS REGISTRADOS: " << setfill('0') << setw(2) << cant << setfill(' ') << endl;
    return (EXIT_SUCCESS);
}

