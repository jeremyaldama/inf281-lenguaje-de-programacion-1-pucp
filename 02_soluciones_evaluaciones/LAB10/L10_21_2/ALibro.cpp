/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ALibro.cpp
 * Author: Danie
 * 
 * Created on 23 de junio de 2023, 23:33
 */

#include "ALibro.h"

ALibro::ALibro() {
    Raiz = nullptr;
}

ALibro::~ALibro() {
    elimina(Raiz);
}

void ALibro::elimina(class NLibro *arbol) {
    if (arbol) {
        elimina(arbol->izq);
        elimina(arbol->der);
        delete arbol;
    }
}

void ALibro::insertar(class Libro &lib) {
    insertarR(Raiz, lib);
}

void ALibro::insertarR(class NLibro*&arbol, const class Libro&lib) {
    if (arbol == nullptr) {
        // el constructor pone a la izquierda y derecha con nullptr
        arbol = new class NLibro;
        arbol->dlibro = lib;
        cout << "inserta" << endl;
        return;
    }
    if (arbol->dlibro > lib) insertarR(arbol->izq, lib);
    else insertarR(arbol->der, lib);
}

void ALibro::mostrarEnOrden(ofstream&arch) {
    mostrarEnOrdenR(arch, Raiz);
}

void ALibro::mostrarEnOrdenR(ofstream&arch, class NLibro *arbol) {
    if (arbol) {
        mostrarEnOrdenR(arch, arbol->izq);
        arch << arbol->dlibro;
        arch << "----------------------------------------" << endl;
        mostrarEnOrdenR(arch, arbol->der);
    }
}

void ALibro::crear(ifstream&arch) {
    class Libro lib;
    while (true) {
        arch >> lib;
        if (arch.eof()) break;
        insertarR(Raiz, lib);
    }
}

void ALibro::actualiza(const char*cod) {
    actualiza(Raiz, cod);
}

// se sobrecarga con la función en público
void ALibro::actualiza(class NLibro *arbol, const char*cod) {
    if (arbol) {
        char cad[100];
        arbol->dlibro.GetCodigo(cad);
        int cmp = strcmp(cad, cod);
        if (cmp == 0 ) {
            arbol->dlibro.actualiza();
            return;
        } else if (cmp > 0) actualiza(arbol->izq, cod);
        else actualiza(arbol->der, cod);
    }
}