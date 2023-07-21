/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:37
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Curso.h"
#include "Escala.h"

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    
    void cargarAlumnos(ifstream& arch);
    void insertar(const Alumno_Curso &alu);
    void mostrarLista(ofstream&arch);
    
    void cargarNotas(ifstream&arch);
    void actualizarCostos(const vector<Curso>&cursos, 
        const vector<Escala>&escalas);
    double buscarPrecio(int escala, const vector<Escala>&escalas);
    
private:
    class Nodo* ini;
    class Nodo* fin;
    Nodo* buscarAlumno(int codigo);
};

#endif /* LISTA_H */

