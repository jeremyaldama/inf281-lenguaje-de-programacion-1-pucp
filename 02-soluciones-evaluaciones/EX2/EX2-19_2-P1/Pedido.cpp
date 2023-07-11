/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 16:36
 */

#include "Pedido.h"

Pedido::Pedido() {
    cantidad = 0;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

ofstream& operator << (ofstream&arch, Pedido&ped) {
    arch << ped.GetCodigo() << "," << ped.GetCantidad();
    return arch;
}