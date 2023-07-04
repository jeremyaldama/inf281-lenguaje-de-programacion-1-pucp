/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoProducto.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 17:09
 */

#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H
#include "Producto.h"
#include "ListaProducto.h"

class NodoProducto {
private:
    class Producto producto;
    class NodoProducto *sig;
public:
    NodoProducto() { sig = nullptr; }
    friend class ListaProducto;
};

#endif /* NODOPRODUCTO_H */

