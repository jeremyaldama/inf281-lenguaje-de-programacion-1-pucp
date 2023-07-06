/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 10:28 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "FuncionesAuxiliares.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int *alumnos_cod;
    void *alumnoveces;
    cargarAlumnos(alumnos_cod, "Alumnos.csv");
    CargaCursos(alumnos_cod, alumnoveces, "HistoriaDeNotas.csv");
    
    return 0;
}

