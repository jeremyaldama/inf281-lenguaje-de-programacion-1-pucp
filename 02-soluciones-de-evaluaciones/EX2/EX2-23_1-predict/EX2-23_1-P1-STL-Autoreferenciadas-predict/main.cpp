/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 22:06
 */

#include <cstdlib>

using namespace std;
#include "Universidad.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Universidad uni;
    uni.leerCursos("Cursos.csv");
    uni.leerEscalas("Escalas.csv");
    uni.leerAlumnos("Alumnos.csv");
    uni.mostrarAlumnos("ReporteAlumnos.txt");
    uni.cargarNotas("HistoriaDeNotas.csv");
    uni.mostrarAlumnos("ReporteAlumnosCursos.txt");
    uni.actualizarCostoCurso();
    uni.mostrarAlumnos("ReporteAlumnosCursosTotal.txt");
    return 0;
}

