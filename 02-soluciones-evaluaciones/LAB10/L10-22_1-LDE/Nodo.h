/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 23:20
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"

class Nodo {
public:
    Nodo();
    ~Nodo();
    friend class Lista;
private:
    class Pedido *ped;
    class Nodo *sig;
    class Nodo *ant;
};

#endif /* NODO_H */

