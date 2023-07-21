/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 5 de octubre de 2020, 09:07 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesActividad04.h"
using namespace std;

int main(int argc, char** argv) {
    char **nombres, ***cursos;
    int *codigos;
    leerAlumnos(codigos,nombres,cursos);
    imprimirAlumnos(codigos,nombres);
    leerCursos(codigos,cursos);
    imprimirReporte(codigos,nombres,cursos);
    return (EXIT_SUCCESS);
}

