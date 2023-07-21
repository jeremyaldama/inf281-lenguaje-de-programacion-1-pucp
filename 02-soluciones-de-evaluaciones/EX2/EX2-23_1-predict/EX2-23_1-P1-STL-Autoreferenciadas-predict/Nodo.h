/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:36
 */

#ifndef NODO_H
#define NODO_H
#include "Alumno_Curso.h"
#include "Lista.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    
    bool comparar(Nodo& nodo);
    // se tiene que poner class
    friend class Lista;
private:
    Alumno_Curso alumno;
    Nodo* sig;
    Nodo* ant;
};

#endif /* NODO_H */

