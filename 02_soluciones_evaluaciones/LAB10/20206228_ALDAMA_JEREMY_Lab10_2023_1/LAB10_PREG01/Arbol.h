/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:10 AM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void llenarArbol(ifstream&arch);
    void insertar(class Boleta&);
    void mostrarArbol(ofstream&arch);
    void imprimirLinea(ofstream&arch, char c, int n);
private:
    class Nodo *raiz;
    class Escala lescala[50];
    void insertarR(class Nodo*&raiz, class Boleta&bol);
    void mostrarArbolR(ofstream&arch, class Nodo*raiz);
};

#endif /* ARBOL_H */

