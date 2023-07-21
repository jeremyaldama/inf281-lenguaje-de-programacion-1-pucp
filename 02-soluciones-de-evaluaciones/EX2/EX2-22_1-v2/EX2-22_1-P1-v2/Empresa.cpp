/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 0:09
 */

#include "Empresa.h"

void Empresa::abrirArchivoEscritura(ofstream& arch, const char*cad) {
    arch.open(cad, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void Empresa::abrirArchivoLectura(ifstream& arch, const char* cad) {
    arch.open(cad, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void Empresa::leerClientes(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);

    class RegCliente reg;

    while (1) {
        reg.leerCliente(arch);
        if (arch.eof()) break;
        lstClientes.push_back(reg);
    }
}

void Empresa::imprimirClientes(const char*cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);

    for (list<RegCliente>::iterator it = lstClientes.begin();
            it != lstClientes.end(); it++) {
        it->imprimirCliente(arch);
        arch << endl;
    }
}

void Empresa::leerPedidos(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);

    int dni;
    class Producto prod;
    class Pedido ped;
    list<class RegCliente>::iterator itReg;
    while (1) {
        prod.leerDatos(arch);
        cout << prod.GetCodigo() << endl;
        if (arch.eof()) break;
        if (!productoAgregado(prod)) lstProductos.push_back(prod);

        dni = ped.leerDatos(arch);
        itReg = buscarCliente(dni);

        if (itReg != lstClientes.end()) {
            ped.SetCodigo(prod.GetCodigo());
            ped.SetSubTotal(prod.GetPrecioUnitario() * ped.GetCantidad()*
                    (1 - prod.GetDescuento() / 100) *
                    (1 - itReg->obtenerDescuento() / 100));
            itReg->agregarPedido(ped);
        }

    }
}

bool Empresa::productoAgregado(const class Producto& prod) {
    for (list<Producto>::iterator it = lstProductos.begin();
            it != lstProductos.end(); it++) {
        if (it->GetCodigo() == prod.GetCodigo()) return true;
    }
    // CUIDADO CON LO QUE SE RETORNA, NO PUEDE SER -1, PORQUE LO EVALUO CON !
    // Y LA UNICA FORMA DE QUE SEA FALSO EN UN IF ES QUE SEA 0 LUEGO
    // TODOS LOS NUMEROS INCLUYENDO NEGATIVOS LO CONSIDERA COMO TRUE
    return false;
}

list<RegCliente>::iterator Empresa::buscarCliente(int cod) {
    for (list<RegCliente>::iterator it = lstClientes.begin();
            it != lstClientes.end(); it++) {
        if (it->obtenerDNI() == cod) return it;
    }
    return lstClientes.end();
}

void Empresa::imprimirProductos(const char*cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);

    for (list<Producto>::iterator it = lstProductos.begin();
            it != lstProductos.end(); it++) {
        it->imprimirDatos(arch);
    }
}

void Empresa::imprimirclientes(const char*cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);

    for (list<RegCliente>::iterator it = lstClientes.begin();
            it != lstClientes.end(); it++) {
        it->imprimirCliente(arch);
    }
}

void Empresa::ordenarPedidos() {
    for (list<class RegCliente>::iterator it = lstClientes.begin();
            it != lstClientes.end(); it++) {
        it->ordenar();
    }
}
