/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:10 AM
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::llenarArbol(ifstream& arch) {
    class Boleta dato;
    while (1) {
        dato.leerAlumno(arch);
        if (arch.eof()) break;
        insertar(dato);
    }
}

void Arbol::insertar(Boleta&bol) {
    insertarR(raiz, bol);
}

void Arbol::insertarR(Nodo*& raiz, Boleta& bol) {
    if (raiz == nullptr) {
        raiz = new class Nodo;
        raiz->dboleta = bol;
        raiz->der = raiz->izq = nullptr;
    } else {
        if (raiz->dboleta.obtenerCodigo() > bol.obtenerCodigo())
            insertarR(raiz->izq, bol);
        else insertarR(raiz->der, bol);
    }
}

void Arbol::mostrarArbol(ofstream& arch) {
    arch << left << setw(15) << "Codigo" << left << setw(60) << "Nombre" <<
            setw(10) << "Escala" << setw(10) << "Cred." << setw(15) <<
            "Licencia" << "Total" << endl;
    imprimirLinea(arch, '=', 115);
    mostrarArbolR(arch, raiz);
}

void Arbol::mostrarArbolR(ofstream& arch, class Nodo*raiz) {
    if (raiz) {
        mostrarArbolR(arch, raiz->izq);
        raiz->dboleta.imprime(arch);
        mostrarArbolR(arch, raiz->der);
    }
}

void Arbol::imprimirLinea(ofstream& arch, char c, int n) {
    for (int i=0; i<n; i++) arch << c;
    arch << endl;
}

void Arbol::cargarEscalas(ifstream& arch) {
    int i = 0;
    
    while (1) {
        lescala[i++].leerEscala(arch);
        if (arch.eof()) break;
    }
}

void Arbol::actualizaTotal() {
    actualizaTotalR(raiz);
}

void Arbol::actualizaTotalR(Nodo* raiz) {
    if (raiz) {
        actualizaTotalR(raiz->izq);
        int esc = raiz->obtenerEscala();
        cout << esc << endl;
        double precio = buscarPrecio(esc);
        raiz->actualiza(precio);
        actualizaTotalR(raiz->der);
    }
}

double Arbol::buscarPrecio(int esc) {
    for (int i=0; lescala[i].GetCodigo(); i++) {
        if (lescala[i].GetCodigo() == esc) return lescala[i].GetPrecio();
    }
}
