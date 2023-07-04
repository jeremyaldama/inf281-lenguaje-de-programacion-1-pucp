/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaProducto.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 17:10
 */

#include "ListaProducto.h"

ListaProducto::ListaProducto() {
    lista = nullptr;
}

ListaProducto::~ListaProducto() {
    class NodoProducto *p = lista, *sale;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaProducto::cargarCodigos(const char*nombArch) {
    ifstream arch(nombArch, ios::in); 
    if (!arch) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << nombArch << endl;
        exit(1);
    }
    
    char codigo[10];
    while (1) {
        arch.getline(codigo, 10);
        if (arch.eof()) break;
        insertarNodo(codigo);
    }
}

void ListaProducto::insertarNodo(const char*codigo) {
    class NodoProducto *p = lista, *ant = nullptr, *nuevo;
    char codP[10];
    nuevo = new NodoProducto;
    nuevo->producto.SetCodigo(codigo);
    while (p) {
        p->producto.GetCodigo(codP);
        if (strcmp(codP, codigo)>0) break;
        ant = p;
        p = p->sig;
    }
    
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaProducto::imprimirContenido(const char*nombArch) {
    ofstream arch(nombArch, ios::out);
    if (!arch) {
        cout << "ERROR no se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    class NodoProducto *p = lista;
    while (p) {
        p->producto.imprimir(arch);
        imprimirLinea('=', 20, arch);
        arch << endl;
        p = p->sig;
    }
}

void ListaProducto::imprimirLinea(char c, int n, ofstream&arch) {
    for (int i=0; i<n; i++) arch.put(c);
    arch << endl;
}

void ListaProducto::cargarStock(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "ERROR: NO SE PUDO ABRIR " << nombArch << endl;
        exit(1);
    }
    
    char codigo[10], id[10], tipo[10];
    class NodoProducto *p;
    while (1) {
        arch.getline(codigo, 10, ',');
        if (arch.eof()) break;
        arch.getline(id, 10, ',');
        arch.getline(tipo, 10);
        p = buscarProducto(codigo);
        if (p) p->producto.agregarPallet(id, tipo);
    }
}

NodoProducto* ListaProducto::buscarProducto(const char*codigo) {
    class NodoProducto *p = lista;
    char codP[10];
    while (p) {
        p->producto.GetCodigo(codP);
        if (strcmp(codP, codigo) == 0) return p;
        p = p->sig;
    }
    return nullptr;
}

void ListaProducto::cargarPedidos(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "ERROR: NO SE PUDO ABRIR " << nombArch;
        exit(1);
    }
    int codPed, cant;
    char codProd[10];
    class NodoProducto *p;
    
    while (1) {
        arch >> codPed;
        if (arch.eof()) break;
        arch.get();
        arch.getline(codProd, 10, ',');
        arch >> cant;
        p = buscarProducto(codProd);
        if (p) p->producto.agregarPedido(codPed, cant);
    }
}

void ListaProducto::despachar() {
    class NodoProducto *p = lista;
    while (p) {
        p->producto.despacha();
        p = p->sig;
    }
}