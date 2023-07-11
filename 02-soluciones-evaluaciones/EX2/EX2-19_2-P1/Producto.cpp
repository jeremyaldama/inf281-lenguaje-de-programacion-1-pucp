/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 16:35
 */

#include "Producto.h"

Producto::Producto() {
    codigo = nullptr;
}

Producto::~Producto() {
    if (codigo) delete codigo;
}

void Producto::SetCodigo(const char* c) {
    if (codigo) delete codigo;
    codigo = new char[strlen(c)+1];
    strcpy(codigo, c);
}

void Producto::GetCodigo(char*n) const {
    if (codigo) strcpy(n, codigo);
    else n[0] = 0;
}

void Producto::agregarPallet(const char*id, const char*tipo) {
    lpallets.insertar(id, tipo);
}

void Producto::agregarPedido(int codPed, int cant) {
    class Pedido pedido;
    pedido.SetCodigo(codPed);
    pedido.SetCantidad(cant);
    colaPed.llegada(pedido);
}

void Producto::imprimir(ofstream&arch) {
    arch << "Codigo: " << codigo << endl << endl << "Pallets: " << endl;
    lpallets.imprimirDatos(arch);
    arch << endl << "Pedidos" << endl;
    colaPed.mostrar(arch);
    
    arch << endl << "Faltantes" << endl;
    colaFalt.mostrar(arch);
}

void operator <<(ofstream&arch, Producto&prod) {
    prod.imprimir(arch);
}

void Producto::despacha() {
    class Pedido pedido;
    int cod, cant;
    class Faltante faltante;
    while (!colaPed.estaVacia()) {
        colaPed.atencion(pedido);
        cod = pedido.GetCodigo();
        cant = pedido.GetCantidad();
        lpallets.atenderDespacho(cant);
        
        if (cant != 0) {
            faltante.SetCodigo(cod);
            faltante.SetCantidad(cant);
            colaFalt.llegada(faltante);
        }
    }
}