/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:17
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H
#include "Producto.h"

class Categoria3 : public Producto {
public:
    Categoria3();
    Categoria3(const Categoria3& orig);
    void operator=(const class Producto&);
    virtual ~Categoria3();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream&arch);
    void imprime(ofstream&arch);
    int obtenerPrioridad() const;
    int obtenerCategoria() const;
    void setPrioridad(int prio);
    void setDescuento(double desc);
    void setMinimo(int min);
    double obtenerDescuento() const;
    int obtenerMinimo() const;
private:
    int prioridad;
    double descuento;
};

#endif /* CATEGORIA3_H */

