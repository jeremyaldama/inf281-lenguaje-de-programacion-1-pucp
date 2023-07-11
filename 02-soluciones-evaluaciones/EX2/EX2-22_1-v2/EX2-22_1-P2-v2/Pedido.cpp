/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:09
 */

#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    cout << "se elimina pedido" << endl;
}

void Pedido::SetOrden(int orden) {
    this->orden = orden;
}

int Pedido::GetOrden() const {
    return orden;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
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

void Pedido::leer(ifstream& arch) {
    char c;
    arch >> cantidad >> c >> total >> c >> dni >> c;
    int dd, mm, aa;
    arch >> dd >> c >> mm >> c >> aa;
    fecha = dd+mm*100+aa*10000;
}

void Pedido::mostrarPedido(ofstream& arch) {
    int dd, mm, aa;
    dd = fecha%100;
    mm = (fecha%10000)/100;
    aa = fecha/10000;
    arch << right << setfill('0') << setw(2) << dd << '/' << setw(2) << mm << 
            '/' << left << setfill(' ') << setw(10) << aa << setw(10) << 
            codigo << right << setw(3) << cantidad << setw(10) << total << 
            setw(8) << "";
    if (orden) arch << "Si" << endl;
    else arch << "No" << endl;
    
//    arch << right << setw(5) << "" << left << setw(10) << codigo << setw(10) << cantidad <<
//            setw(10) << dni << setw(10) << fecha << setw(10) << total << 
//            orden << endl;
}
