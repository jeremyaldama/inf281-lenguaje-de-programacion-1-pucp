/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.h
 * Author: cueva
 *
 * Created on 9 de julio de 2022, 09:36 PM
 */
#include <fstream>
#include "Producto.h"

using namespace std;

#ifndef CATEGORIA3_H
#define CATEGORIA3_H

class Categoria3:public Producto {
public:
    Categoria3();
    Categoria3(const Categoria3& orig);
    virtual ~Categoria3();
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

#endif /* CATEGORIA3_H */

