/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 23:03
 */

#include "Producto.h"

Producto::Producto() {
    codprod = precio = stock = 0;
    nombre = nullptr;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
    if (nombre != nullptr) delete nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Producto::GetNombre(char*n) const {
    if (nombre == nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

