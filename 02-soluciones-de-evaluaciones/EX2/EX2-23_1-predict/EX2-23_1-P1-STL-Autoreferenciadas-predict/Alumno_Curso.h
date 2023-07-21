/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno_Curso.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:31
 */

#ifndef ALUMNO_CURSO_H
#define ALUMNO_CURSO_H

#include "Alumno.h"
#include "Curso_Nota.h"
#include "Curso.h"
#include "Escala.h"
#include <vector>

class Alumno_Curso {
public:
    Alumno_Curso();
    ~Alumno_Curso();
    void obtenerNombre(char *cad);
    void leerAlumno(ifstream& arch);
    void imprimirAlumno(ofstream& arch);
    int obtenerCodigoAlumno();
    void leerCursoDelAlumno(ifstream&arch);
    
//    void operator=(const Alumno_Curso &alu_cur);
    void actualizarCostos(const vector<Curso>&cursos,
                            double precio);
    double buscarCreditosCurso(const vector<Curso>&cursos, const char*);
    int obtenerEscalaAlumno();
    
private:
    Alumno alumno;
    vector<Curso_Nota> cursos;
    double totalGastado;
};

#endif /* ALUMNO_CURSO_H */

