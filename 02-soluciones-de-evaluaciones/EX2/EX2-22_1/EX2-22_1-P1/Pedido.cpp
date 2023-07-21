/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 25 de junio de 2023, 22:50
 */

#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
    *this = orig;
}

Pedido::~Pedido() {
}

void Pedido::SetSubTotal(double subTotal) {
    this->subTotal = subTotal;
}

double Pedido::GetSubTotal() const {
    return subTotal;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(double cantidad) {
    this->cantidad = cantidad;
}

double Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

int Pedido::leerDatos(ifstream&arch) {
    double cantidad;
    int dni, dd, mm, aa, fecha;
    char c;
    arch >> cantidad >> c >> dni >> c >> dd >> c >> mm >> c >> aa;
    cout << cantidad << " " ;
    fecha = dd + mm*100 + aa*10000;
    cout << fecha << endl;
    SetCantidad(cantidad);
    SetCodigo(dni);
    SetFecha(fecha);
    return dni;
}

void Pedido::imprimirDatos(ofstream&arch) {
    arch << setprecision(2) << fixed;
    int dd, mm, aa;
    dd = fecha % 100;
    mm = (fecha % 10000) / 100;
    aa = fecha/10000;
    arch << right << setw(2) << setfill('0') << dd << '/' << setw(2) << mm <<
            '/' << setfill(' ') << left << setw(10) << aa << setw(10) << 
            codigo << setw(10) << cantidad << subTotal << endl;
}

bool Pedido::operator<(const class Pedido&ped) {
    return fecha < ped.fecha;
}

void Pedido::operator=(const class Pedido &ped) {
    cantidad = ped.cantidad;
    codigo = ped.codigo;
    fecha = ped.fecha;
    subTotal = ped.subTotal;
}
