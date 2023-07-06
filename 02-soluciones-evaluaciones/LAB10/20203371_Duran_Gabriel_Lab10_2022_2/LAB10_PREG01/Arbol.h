/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: alulab14
 *
 * Created on 25 de noviembre de 2022, 08:10 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "medicamento.h"
#include <fstream>
using namespace std;

class Arbol {
public:
    Arbol();
    virtual ~Arbol();
    void insertar(medicamento *&med);
    void imprimir(ofstream &arch);
private:
    void  insertarArbol(class Nodo *&raiz,medicamento *&med);
    void imprimeArbol(class Nodo *&raiz,ofstream &arch);
    void borraArbol(class Nodo *&nodo);
    class Nodo *raiz;
};

#endif /* ARBOL_H */

