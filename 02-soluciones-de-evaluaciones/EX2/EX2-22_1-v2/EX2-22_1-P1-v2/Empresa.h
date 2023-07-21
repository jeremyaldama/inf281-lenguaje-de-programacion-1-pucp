/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 0:09
 */

#ifndef EMPRESA_H
#define EMPRESA_H
#include "Producto.h"
#include "RegCliente.h"
#include <list>

class Empresa {
public:
    // EN LA SUPERCLASE SE PUEDE BORRAR LOS 3 METODOS POR DEFAULT
    // PREGUNTAR SI NOS VAN A DAR FUNCIONES PARA LA APERTURA DE ARCHIVOS
    void abrirArchivoLectura(ifstream&arch, const char*cad);
    void abrirArchivoEscritura(ofstream&arch, const char*cad);
    void leerClientes(const char*cad);
    void imprimirClientes(const char*);
    void leerPedidos(const char*cad);
    bool productoAgregado(const class Producto &prod);
    void imprimirProductos(const char*);
    void imprimirclientes(const char*);
    void ordenarPedidos();
    list<class RegCliente>::iterator buscarCliente(int cod);
private:
    list <class Producto> lstProductos;
    list <class RegCliente> lstClientes;
};

#endif /* EMPRESA_H */

