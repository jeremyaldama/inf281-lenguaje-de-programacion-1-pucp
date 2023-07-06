/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NProductos.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:32
 */

#include "NProductos.h"

NProductos::NProductos(const NProductos& orig) {
    *this = orig;
}

NProductos::~NProductos() {
}

void NProductos::leerProducto(ifstream&arch) {
    int cat;
    arch >> cat;
    if (arch.eof()) return;
    char c;
    arch >> c;
    if (cat == 1) prod = new Categoria1;
    else if (cat == 2) prod = new Categoria2;
    else if (cat == 3) prod = new Categoria3;
    prod->leer(arch);
}

void NProductos::AsignarProducto(class Producto*&prod, int cat) {
    if (cat == 1) prod = new Categoria1;
    else if (cat == 2) prod = new Categoria2;
    else prod = new Categoria3;
}

void NProductos::operator=(const class NProductos&nodo) {
    prod = nodo.prod;
}

void NProductos::imprime(ofstream&arch) {
    prod->imprime(arch);
}

int NProductos::obtenerCodigo() {
    return prod->GetCodprod();
}

int NProductos::obtenerPrioridad() {
    return prod->obtenerPrioridad();
}