/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:18
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include "Producto.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

class NProductos {
public:
    NProductos();
    NProductos(const NProductos& orig);
    virtual ~NProductos();
    void leer(ifstream&arch);
    void operator=(const class NProductos&prod);
    void imprime(ofstream&arch);
    int obtenerPrioridad();
    int obtenerCodigo();
    bool operator<(const class NProductos&prod2);
    int obtenerCategoria() const;
    
    void setear();
private:
    class Producto *prod;
};

#endif /* NPRODUCTOS_H */

