/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:26
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    bool compara(const class Nodo&nodo);
    friend class Lista;
private:
    class Pedido *ped;
    class Nodo *sig;
};

#endif /* NODO_H */

