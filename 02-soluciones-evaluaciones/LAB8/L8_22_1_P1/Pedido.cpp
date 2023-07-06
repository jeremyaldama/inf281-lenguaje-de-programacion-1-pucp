/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 23:06
 */

#include "Pedido.h"

Pedido::Pedido() {
    cantidad = codigo = dni = fecha = total = 0;
    obs = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if (obs != nullptr) delete obs;
}

void Pedido::SetObs(const char* obs) {
    if (this->obs != nullptr) delete this->obs;
    this->obs = new char[strlen(obs)+1];
    strcpy(this->obs, obs);
}

void Pedido::GetObs(char*n) const {
    if (obs == nullptr) n[0] = 0;
    else strcpy(n, obs);
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

void Pedido::AsignarProducto(int codigo_buscar) {
    ifstream arch("productos3.csv", ios::in);
    
    int codigo, stock;
    double precio;
    char nombre[100], c;
    
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        arch >> precio >> c >> stock;
        
        if (codigo == codigo_buscar) {
            SetNombre(nombre);
            SetPrecio(precio);
            SetStock(stock);
            SetCodprod(codigo);
            SetTotal(GetCantidad()*precio);
            break;
        }
    }
}

void Pedido::Copia(const class Pedido&pedido) {
    SetCantidad(pedido.GetCantidad());
    SetCodigo(pedido.GetCodigo());
    SetCodprod(pedido.GetCodprod());
    SetDni(pedido.GetDni());
    SetFecha(pedido.GetFecha());
    SetPrecio(pedido.GetPrecio());
    SetStock(pedido.GetStock());
    SetTotal(pedido.GetTotal());
    
    char n[100];
    pedido.GetNombre(n);
    SetNombre(n);
    pedido.GetObs(n);
    SetObs(n);
}