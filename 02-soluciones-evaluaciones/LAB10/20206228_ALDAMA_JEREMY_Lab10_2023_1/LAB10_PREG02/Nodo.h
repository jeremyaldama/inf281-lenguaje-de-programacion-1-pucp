/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:08 AM
 */

#ifndef NODO_H
#define NODO_H
#include "Boleta.h"
#include "Arbol.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    int compara(class Boleta &bol);
    void actualiza(double);
    int obtenerEscala();
    friend class Arbol;
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

