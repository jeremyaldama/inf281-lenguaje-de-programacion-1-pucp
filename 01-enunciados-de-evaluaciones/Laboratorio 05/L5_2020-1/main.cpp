/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 20 de octubre de 2020, 04:23 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaAuxiliar.h"
using namespace std;

int main(int argc, char** argv) {
    void *alumnos;
    leerAlumnos(alumnos);
    imprimirAlumnos(alumnos);
    leerCursos(alumnos);
    consolidado(alumnos);
    return (EXIT_SUCCESS);
}

