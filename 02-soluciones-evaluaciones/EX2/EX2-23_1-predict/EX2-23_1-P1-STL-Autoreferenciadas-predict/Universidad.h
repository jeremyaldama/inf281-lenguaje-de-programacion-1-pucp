/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Universidad.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:43
 */

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "Curso.h"
#include "Escala.h"
#include "Lista.h"

class Universidad {
public:
    Universidad();
    Universidad(const Universidad& orig);
    virtual ~Universidad();
    void abrirArchivoLectura(ifstream& arch, const char* cad);
    void abrirArchivoEscritura(ofstream& arch, const char* cad);
    
    void leerCursos(const char* cad);
    void leerEscalas(const char* cad);
    void leerAlumnos(const char* cad);
    void mostrarAlumnos(const char* cad);
    void cargarNotas(const char* cad);
    void actualizarCostoCurso();
    
private:
    vector<Curso> cursos;
    vector<Escala> escalas;
    // Lista de Alumno_Curso
    Lista alumnos;
};

#endif /* UNIVERSIDAD_H */

