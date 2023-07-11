/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:26
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
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    virtual void leer(ifstream&arch);
    void operator =(const class Producto&);
    virtual void imprime(ofstream&arch);
    virtual int obtenerPrioridad() = 0;
private:
    int codprod;
    char *nombre;
    int stock;
};

#endif /* PRODUCTO_H */

