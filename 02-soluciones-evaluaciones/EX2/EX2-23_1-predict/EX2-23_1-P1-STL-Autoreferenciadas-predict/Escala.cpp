/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:12
 */

#include "Escala.h"

Escala::Escala() {
} 

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

void Escala::leer(ifstream& arch) {
//    if (arch.get() == '\n') return;
    arch.get();
    if (arch.eof()) return;
    arch >> codigo;
    arch.get();
    arch >> precio;
    arch.get();
}
