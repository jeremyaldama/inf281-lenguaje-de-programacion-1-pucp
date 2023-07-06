/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Categoria1.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:30
 */

#include "Categoria1.h"

Categoria1::Categoria1() {
}

Categoria1::Categoria1(const Categoria1& orig) {
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

void Categoria1::leer(ifstream&arch) {
    char c;
    arch >> prioridad >> c >> minimo >> c;
    Producto::leer(arch);
}

void Categoria1::imprime(ofstream&arch) {
    Producto::imprime(arch);
    arch << setw(8) << prioridad << minimo << endl;
    cout << "minimo: " << minimo << endl;
}

int Categoria1::obtenerPrioridad() {
    return prioridad;
}