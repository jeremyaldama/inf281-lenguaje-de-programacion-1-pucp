/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 23:03
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(char* nombre);
    void GetNombre(char *n) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
private:
    int codprod;
    char *nombre;
    double precio;
    int stock;
};

#endif /* PRODUCTO_H */

