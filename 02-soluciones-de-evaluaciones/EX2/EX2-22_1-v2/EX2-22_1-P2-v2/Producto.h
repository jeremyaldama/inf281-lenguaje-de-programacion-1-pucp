/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:10
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void operator=(const class Producto&prod);
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    virtual void leer(ifstream&arch);
    virtual void imprime(ofstream&arch);
    virtual int obtenerCategoria() const = 0;
    
    virtual void setPrioridad(int) = 0;
    virtual void setDescuento(double) = 0;
    virtual void setMinimo(int) = 0;
    
    virtual int obtenerPrioridad() const = 0;
    virtual int obtenerMinimo() const = 0;
    virtual double obtenerDescuento() const = 0;
private:
    int codprod;
    char *nombre;
    int stock;
};

#endif /* PRODUCTO_H */

