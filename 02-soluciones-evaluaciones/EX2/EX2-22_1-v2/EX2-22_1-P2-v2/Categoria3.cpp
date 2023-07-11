/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:17
 */

#include "Categoria3.h"

Categoria3::Categoria3() {
}

Categoria3::Categoria3(const Categoria3& orig) : Producto(orig) {
    *this = orig;
}

void Categoria3::operator=(const class Producto& orig) {
    this->Producto::operator=(orig);
    prioridad = orig.obtenerPrioridad();
    descuento = -2;
}


Categoria3::~Categoria3() {
}

void Categoria3::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria3::GetDescuento() const {
    return descuento;
}

void Categoria3::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria3::GetPrioridad() const {
    return prioridad;
}

void Categoria3::leer(ifstream& arch) {
    arch >> prioridad;
    arch.get();
    arch >> descuento;
    arch.get();
    Producto::leer(arch);
}

void Categoria3::imprime(ofstream& arch) {
    Producto::imprime(arch);
    arch << setw(10) << prioridad << descuento << endl;
}

int Categoria3::obtenerPrioridad() const {
    return prioridad;
}

int Categoria3::obtenerCategoria() const {
    return 3;
}

void Categoria3::setPrioridad(int prio) {
    prioridad = prio;
}

void Categoria3::setDescuento(double desc) {
    descuento = desc;
}

double Categoria3::obtenerDescuento() const {
    return descuento;
}

int Categoria3::obtenerMinimo() const {
    return 0;
}

void Categoria3::setMinimo(int min) {
    return;
}
