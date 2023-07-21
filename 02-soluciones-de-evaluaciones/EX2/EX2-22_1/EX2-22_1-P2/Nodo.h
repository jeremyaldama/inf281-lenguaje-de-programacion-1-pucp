/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:34
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <fstream>
#include "Pedido.h"
#include "Lista.h"
using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Lista;
    void operator=(const class Nodo&);
    int obtenerCodigo();
private:
    class Pedido *ped;
    class Nodo *sig;
};

#endif /* NODO_H */

