/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NProductos.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:32
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include "Producto.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

class NProductos {
public:
    NProductos() { prod = nullptr; };
    NProductos(const NProductos& orig);
    virtual ~NProductos();
    void leerProducto(ifstream&);
    void AsignarProducto(class Producto*&prod, int cat);
    void operator =(const class NProductos&);
    void imprime(ofstream&);
    int obtenerCodigo();
    int obtenerPrioridad();
private:
    class Producto *prod;
};

#endif /* NPRODUCTOS_H */

