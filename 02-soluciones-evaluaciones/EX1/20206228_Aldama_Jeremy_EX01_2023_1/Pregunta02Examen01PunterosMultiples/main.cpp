/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 09:15 AM
 */
// Jeremy Aldama Giraldo 20206228
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "Preg2_Funciones_de_historia_de_notas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    char ***cursos, ***alumnos_nom_mod;
    double *cursos_cred, escalas[5];
    int *alumnos_cod, **alumnos;
    cargarCursosYEscalas(cursos, cursos_cred, escalas, "Cursos.csv",
            "Escalas.csv");
    pruebaDeCargaDeCursos(cursos, cursos_cred, "PruebaCursos.txt");
    
    cargarAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, "Alumnos.csv");
    pruebaDeCargaDeAlumnos(alumnos_cod, alumnos, alumnos_nom_mod, 
            "PruebaAlumnos.txt");
    
    int***cursos_nota_sem_veces;
    double **costos;
    char ***cursos_cod;
    
    cargarNotas(cursos_cod, cursos_nota_sem_veces, costos, alumnos, 
            alumnos_nom_mod, escalas, cursos, cursos_cred, "HistoriaDeNotas.csv");
//    pruebaDeCargaDeNotas(cursos_cod, cursos_nota_sem_veces, costos, alumnos, 
//            alumnos_nom_mod, "PruebaDeNotas.txt");
    
    return 0;
}

