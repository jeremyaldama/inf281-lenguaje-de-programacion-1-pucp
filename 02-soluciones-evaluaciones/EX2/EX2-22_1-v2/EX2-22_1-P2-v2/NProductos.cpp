/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:18
 */

#include "NProductos.h"

NProductos::NProductos() {
    prod = nullptr;
}

NProductos::NProductos(const NProductos& orig) {
    // se puede hacer esto porque solo estamos haciendo asignacion de
    // memoria por punteros, si hubieran cadenas hacemos sobrecarga del =
    static int i = 0;
    cout << "constructor copia " << ++i << endl;
    *this = orig;
}

// no es necesario en este caso porque solo asigna la direccion de memoria
void NProductos::operator=(const class NProductos& nodo) {
    static int i = 0;
    cout << "copia p: " << ++i << endl;
//    prod = nodo.prod;
    int cat = nodo.obtenerCategoria();
    if (cat == 1) prod = new class Categoria1;
    else if (cat == 2) prod = new class Categoria2;
    else prod = new class Categoria3;
    *prod = *nodo.prod;
    prod->setPrioridad(nodo.prod->obtenerPrioridad());
    if (cat == 1) prod->setMinimo(nodo.prod->obtenerMinimo());
    else prod->setDescuento(nodo.prod->obtenerDescuento());
}

int NProductos::obtenerCategoria() const {
    return prod->obtenerCategoria();
}


NProductos::~NProductos() {
    // No se hace destructor, porque el vector al hacer push_back hace un copia
    // y estaría destruyendo esa copia que luego ira en el vector
    
//     Aparte cuando el vector crece y se multiplica x2, por ejemplo tiene 2
//     y se multiplica a 4, esos 2 se eliminan pero primero se pasan una copia
//     al nuevo vector con capacidad 4
    static int i = 0;
    cout << "eliminado " << ++i << endl;
    if (prod) delete prod;
}

void NProductos::leer(ifstream& arch) {
    int cat;
    arch >> cat;
    if (arch.eof()) return;
    arch.get();
    if (cat == 1) prod = new class Categoria1;
    else if (cat == 2) prod = new class Categoria2;
    else prod = new class Categoria3;
    prod->leer(arch);
}

void NProductos::imprime(ofstream& arch) {
    prod->imprime(arch);
}

int NProductos::obtenerPrioridad() {
    return prod->obtenerPrioridad();
}

int NProductos::obtenerCodigo() {
    return prod->GetCodprod();
}

bool NProductos::operator<(const class NProductos& prod2) {
    char nom1[100], nom2[200];
    prod->GetNombre(nom1);
    prod2.prod->GetNombre(nom2);
    return strcmp(nom1, nom2)<0;
}

void NProductos::setear() {
    prod = new class Categoria1;
    prod->SetNombre("JEREMYYYYYYY");
    prod->SetCodprod(9999999);
}
