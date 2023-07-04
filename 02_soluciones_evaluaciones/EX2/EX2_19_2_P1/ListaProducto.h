/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaProducto.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 17:10
 */

#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H
#include "NodoProducto.h"

class ListaProducto {
private:
    class NodoProducto*lista;
    class NodoProducto*buscarProducto(const char*);
public:
    ListaProducto();
    virtual ~ListaProducto();
    void cargarCodigos(const char*);
    void insertarNodo(const char*);
    void imprimirContenido(const char*);
    void imprimirLinea(char, int, ofstream&);
    void cargarStock(const char*);
    void cargarPedidos(const char*);
    void despachar(void);
};

#endif /* LISTAPRODUCTO_H */

