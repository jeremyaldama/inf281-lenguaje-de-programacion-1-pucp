/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:15
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H
#include "Producto.h"

class Categoria1 : public Producto {
public:
    Categoria1();
    Categoria1(const Categoria1& orig);
    virtual ~Categoria1();
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream&arch);
    void imprime(ofstream&arch);
    int obtenerPrioridad() const;
    int obtenerCategoria() const;
    void operator=(const class Producto&);
    
    void setPrioridad(int prio);
    void setDescuento(double);
    void setMinimo(int min);
    double obtenerDescuento() const;;
    int obtenerMinimo() const;
private:
    int prioridad;
    int minimo;
};

#endif /* CATEGORIA1_H */

