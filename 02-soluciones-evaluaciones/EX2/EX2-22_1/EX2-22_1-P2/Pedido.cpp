/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:25
 */

#include <iomanip>

#include "Pedido.h"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
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

void Pedido::leerPedido(ifstream&arch, int cod) {
    codigo = cod;
    cout << "cod ped: " << codigo << endl;
    char c;
    int dd, mm, aa;
    arch >> cantidad >> c >> total >> c >> dni >> c >> dd >> c >> mm >> c >>
            aa;
    fecha = dd + mm*100 + aa*10000;
}

void Pedido::mostrarPedido(ofstream&arch) {
    arch << setprecision(2) << fixed;
    arch << setw(5) << "" << setw(10) << left << fecha << setw(10) << codigo <<
            setw(8) << cantidad << right << setw(8) << total << setw(8) <<
            orden << endl;
}