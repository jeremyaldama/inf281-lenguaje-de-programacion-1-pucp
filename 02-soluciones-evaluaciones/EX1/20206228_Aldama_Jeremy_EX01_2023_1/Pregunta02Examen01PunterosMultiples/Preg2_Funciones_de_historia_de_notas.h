/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Preg2_Funciones_de_historia_de_notas.h
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 09:19 AM
 */

#ifndef PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H
#define PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H
#include <fstream>
using namespace std;

void cargarNotas(char***&cursos_cod, int***&cursos_nota_sem_veces, 
        double**&costos, int**alumnos, char***alumnos_nom_mod, double*escalas, 
        char***cursos, double*cursos_cred, const char*nom);
int BuscarCursoAlumno(char**cur_cod, char*cod_cur);
int BuscarAlumno(int**alumnos, int cod_al);
void AgregarCursos(char***&cursos_cod, int***&cursos_nota_sem_veces, 
        double**&costos, char***cur_cod_aux, int***cur_no_se_v_aux, 
        double**costo_aux, int*n_cur_al, int n);
int ObtenerNumCursos(char**cur_cod);
#endif /* PREG2_FUNCIONES_DE_HISTORIA_DE_NOTAS_H */

