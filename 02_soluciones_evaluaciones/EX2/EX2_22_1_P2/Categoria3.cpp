/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Categoria3.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:31
 */

#include "Categoria3.h"

Categoria3::Categoria3() {
}

Categoria3::Categoria3(const Categoria3& orig) {
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

void Categoria3::leer(ifstream&arch) {
    char c;
    arch >> prioridad >> c >> descuento >> c;
    Producto::leer(arch);
}

void Categoria3::imprime(ofstream&arch) {
    Producto::imprime(arch);
    arch << setw(8) << prioridad << descuento << endl;
    cout << "descuento: " << descuento << endl;
}


int Categoria3::obtenerPrioridad() {
    return prioridad;
}