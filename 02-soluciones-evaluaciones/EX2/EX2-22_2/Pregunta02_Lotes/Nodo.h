/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:14
 */

#ifndef NODO_H
#define NODO_H
#include "medicamento.h"
#include "Arbol.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    bool compararMedicamento(const class medicamento &med);
    
    friend class Arbol;
private:
    class medicamento *med;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

