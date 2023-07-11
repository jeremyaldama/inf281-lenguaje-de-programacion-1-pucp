/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 08:10 PM
 */
#include "Pedido.h"


#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Lista;
private:
    Pedido ped;
    Nodo *sig;
};

#endif /* NODO_H */

