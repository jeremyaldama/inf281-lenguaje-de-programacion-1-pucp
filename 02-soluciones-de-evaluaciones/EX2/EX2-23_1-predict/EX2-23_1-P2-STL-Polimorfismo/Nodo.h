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

class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    int compara(class Boleta &bol);
    int obtenerEscala();
    void leer(ifstream&arch);
    void imprimir(ofstream&arch);
    void actualiza(double);
private:
    class Boleta dboleta;
};

#endif /* NODO_H */

