/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Categoria2.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:31
 */

#include "Categoria2.h"

Categoria2::Categoria2() {
}

Categoria2::Categoria2(const Categoria2& orig) {
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

void Categoria2::leer(ifstream&arch) {
    char c;
    arch >> prioridad >> c >> descuento >> c;
    Producto::leer(arch);
}

void Categoria2::imprime(ofstream&arch) {
    Producto::imprime(arch);
    arch << setw(8) << prioridad << descuento << endl;
}

int Categoria2::obtenerPrioridad() {
    return prioridad;
}