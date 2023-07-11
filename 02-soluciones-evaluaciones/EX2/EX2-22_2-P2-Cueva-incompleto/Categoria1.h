/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.h
 * Author: cueva
 *
 * Created on 9 de julio de 2022, 09:36 PM
 */

#include <fstream>
#include "Producto.h"

using namespace std;

#ifndef CATEGORIA1_H
#define CATEGORIA1_H

class Categoria1:public Producto {
public:
    Categoria1();
    Categoria1(const Categoria1& orig);
    virtual ~Categoria1();
   void leeprod(ifstream &);
    void setMinimo(int minimo);
    int getMinimo() const;
    void setPrioridad(int prioridad);
    int getPrioridad() const;
    void imprimeprod(ofstream &arch);
private:
    int prioridad;
    int minimo;
};

#endif /* CATEGORIA1_H */

