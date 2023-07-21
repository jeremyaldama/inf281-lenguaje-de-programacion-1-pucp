/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:15
 */

#include "Categoria1.h"

Categoria1::Categoria1() {
}

Categoria1::Categoria1(const Categoria1& orig) : Producto(orig) {
    *this = orig;
}

void Categoria1::operator=(const Producto& orig) {
    cout << "CATEGORIA 1" << endl;
    this->Producto::operator=(orig);
    prioridad = orig.obtenerPrioridad();
    minimo = -1;
}

Categoria1::~Categoria1() {
}

void Categoria1::SetMinimo(int minimo) {
    this->minimo = minimo;
}

int Categoria1::GetMinimo() const {
    return minimo;
}

void Categoria1::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria1::GetPrioridad() const {
    return prioridad;
}

void Categoria1::leer(ifstream& arch) {
    arch >> prioridad;
    arch.get();
    arch >> minimo;
    arch.get();
    Producto::leer(arch);
}

void Categoria1::imprime(ofstream& arch) {
    Producto::imprime(arch);
    arch << setw(10) << prioridad << minimo << endl;
}

int Categoria1::obtenerPrioridad() const {
    return prioridad;
}

int Categoria1::obtenerCategoria() const {
    return 1;
}

void Categoria1::setPrioridad(int prio) {
    prioridad = prio;
}

void Categoria1::setMinimo(int min) {
    minimo = min;
}

int Categoria1::obtenerMinimo() const {
    return minimo;
}

double Categoria1::obtenerDescuento() const {
    return 0.0;
}

void Categoria1::setDescuento(double desc) {
    return;
}
