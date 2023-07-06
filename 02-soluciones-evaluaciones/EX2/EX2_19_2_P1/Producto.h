/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 16:35
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "PlCola.h"
#include "ListaPallet.h"
#include "Pedido.h"
#include "Faltante.h"

class Producto {
private:
    char *codigo;
    class ListaPallet lpallets;
    class PlCola<Pedido> colaPed;
    class PlCola<Faltante> colaFalt;
public:
    Producto();
    virtual ~Producto();
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    void agregarPallet(const char*, const char*);
    void agregarPedido(int, int);
    void imprimir(ofstream&);
    void despacha();
};

#endif /* PRODUCTO_H */

