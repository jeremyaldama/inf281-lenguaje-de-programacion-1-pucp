/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria2.h
 * Author: cueva
 *
 * Created on 9 de julio de 2022, 09:36 PM
 */
#include <fstream>
#include "Producto.h"

using namespace std;

#ifndef CATEGORIA2_H
#define CATEGORIA2_H

class Categoria2: public Producto {
public:
    Categoria2();
    Categoria2(const Categoria2& orig);
    virtual ~Categoria2();
    void leeprod(ifstream &);
    void setDescuento(double descuento);
    double getDescuento() const;
    void setPrioridad(int prioridad);
    int getPrioridad() const;
    int getMinimo() const{};
    void imprimeprod(ofstream &arch);
    
private:
    int prioridad;
    double descuento;
};

#endif /* CATEGORIA2_H */

