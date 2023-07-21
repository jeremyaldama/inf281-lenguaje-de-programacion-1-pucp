/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria2.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:16
 */

#include "Categoria2.h"

Categoria2::Categoria2() {
}

Categoria2::Categoria2(const Categoria2& orig) : Producto(orig) {
    *this = orig;
}

void Categoria2::operator=(const class Producto& orig) {
    this->Producto::operator=(orig);
    prioridad = orig.obtenerPrioridad();
    descuento = -2;
}

Categoria2::~Categoria2() {
}

void Categoria2::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria2::GetDescuento() const {
    return descuento;
}

void Categoria2::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria2::GetPrioridad() const {
    return prioridad;
}

void Categoria2::leer(ifstream& arch) {
    arch >> prioridad;
    arch.get();
    arch >> descuento;
    arch.get();
    Producto::leer(arch);
}

void Categoria2::imprime(ofstream& arch) {
    Producto::imprime(arch);
    arch << setw(10) << prioridad << descuento << endl;
}

int Categoria2::obtenerPrioridad() const {
    return prioridad;
}

int Categoria2::obtenerCategoria() const {
    return 2;
}

void Categoria2::setPrioridad(int prio) {
    prioridad = prio;
}

void Categoria2::setDescuento(double desc) {
    descuento = desc;
}

double Categoria2::obtenerDescuento() const {
    return descuento;
}

int Categoria2::obtenerMinimo() const {
    return 0;
}

void Categoria2::setMinimo(int min) {
    return;
}
