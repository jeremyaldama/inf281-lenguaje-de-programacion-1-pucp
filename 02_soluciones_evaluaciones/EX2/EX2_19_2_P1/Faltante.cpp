/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Faltante.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 16:40
 */

#include "Faltante.h"

Faltante::Faltante() {
}

void Faltante::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Faltante::GetCantidad() const {
    return cantidad;
}

void Faltante::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Faltante::GetCodigo() const {
    return codigo;
}

ofstream& operator <<(ofstream&arch, Faltante&falt) {
    arch << falt.GetCodigo() << "," << falt.GetCantidad();
    return arch;
}