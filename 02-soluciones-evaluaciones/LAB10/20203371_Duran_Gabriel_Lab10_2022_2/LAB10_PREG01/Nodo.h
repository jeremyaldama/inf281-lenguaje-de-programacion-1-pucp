/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 25 de noviembre de 2022, 08:09 AM
 */

#ifndef NODO_H
#define NODO_H
#include "Arbol.h"
#include "medicamento.h"


class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    friend class Arbol;
private:
    medicamento *med;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

