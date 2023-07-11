/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 0:07
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
    char c;
    int dd, mm, aa;
    arch >> cantidad >> c >> codigo >> c >> dd >> c >> mm >> c >> aa;
    fecha = dd + mm*100 + aa*10000;
    return codigo;
}

void Pedido::imprimirDatos(ofstream&arch) {
    arch << setprecision(2) << fixed;
    int dd, mm, aa;
    arch << left << setw(10) << codigo << setw(10) << cantidad << setw(4) <<
            "";
    dd = fecha%100;
    mm = (fecha%10000)/100;
    aa = fecha/10000;
    arch << setfill('0') << right << setw(2) << dd << '/' << setw(2) << mm <<
            '/' << setfill(' ') << left << setw(8) << aa << subTotal << endl;
}

void Pedido::operator=(const class Pedido& ped) {
    codigo = ped.codigo;
    cantidad = ped.cantidad;
    fecha = ped.fecha;
    subTotal = ped.subTotal;
}

bool Pedido::operator<(const Pedido& ped) {
    return subTotal < ped.subTotal;
}
