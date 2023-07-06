/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 08:06 AM
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

#include <fstream>
using namespace std;
void cargarCursosYEscalas(char***&cursos, double*&cursos_cred, double*escalas,
        const char*nom_cur, const char*nom_esc) ;
void IncrementarCursos(char***&cursos, double*&cursos_cred, int&num, 
        int&cap);
void LeerEscalas(ifstream&arch, double*escalas);
void pruebaDeCargaDeCursos(char***cursos, double*cursos_cred, const char*nom);
void IncrementarAlumnos(int*&alumnos_cod,
                    int&num, int&cap);
void cargarAlumnos(int*&alumnos_cod, const char*nom) ;
void AgregarAlumnos(int*alumnos_cod,
        int cod, int i);
void pruebaDeCargaDeAlumnos(int*alumnos_cod, int**alumnos,
        char***alumnos_nom_mod, const char*nom);
#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */

