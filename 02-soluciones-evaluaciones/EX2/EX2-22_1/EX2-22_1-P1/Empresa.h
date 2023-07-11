/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Empresa.h
 * Author: Danie
 *
 * Created on 25 de junio de 2023, 22:57
 */

#ifndef EMPRESA_H
#define EMPRESA_H
#include "Producto.h"
#include "RegCliente.h"

class Empresa {
public:
    void abrirArchivoLectura(ifstream&arch, const char*);
    void abrirArchivoEscritura(ofstream&arch, const char*);
    void leerClientes(const char*);
    void asignarDescuento(class Cliente&cli);
    void imprimirClientes(const char*);
    void leerPedidos(const char*);
    int BuscarProducto(int cod);
    void ordenarPedidos();
    void imprimirProductos(const char*);
private:
    list<class Producto> lstProductos;
    list<class RegCliente> lstClientes;
};

#endif /* EMPRESA_H */

