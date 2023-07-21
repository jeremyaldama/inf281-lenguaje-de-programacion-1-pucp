/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 17 de octubre de 2020, 01:28 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaAuxiliar.h"
using namespace std;

int main(int argc, char** argv) {
    char ***cursos, **profesores;
    int *codProfesores;
    void *sesiones;
    leerDatos(cursos,codProfesores,profesores);
    imprimirDatos(cursos,codProfesores,profesores);
    leerSesiones(sesiones);
    imprimirSesiones(sesiones);
    reporteCargaHorariaDeProf(cursos,codProfesores,profesores,sesiones);
    return (EXIT_SUCCESS);
}

