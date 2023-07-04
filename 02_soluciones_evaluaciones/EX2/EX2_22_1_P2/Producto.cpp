/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:26
 */

#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
}

Producto::Producto(const Producto& orig) {
    nombre = nullptr;
    *this = orig;
}

Producto::~Producto() {
    if (nombre) delete nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Producto::GetNombre(char*cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::leer(ifstream&arch) {
    char nombre[100], c;
    arch >> codprod >> c;
    arch.getline(nombre, 100, ',');
    SetNombre(nombre);
    cout << nombre << endl;
    arch >> stock;
    cout << "stock: " << stock << endl;
}

void Producto::operator =(const class Producto&prod) {
    codprod = prod.codprod;
    stock = prod.stock;
    SetNombre(prod.nombre);
}

void Producto::imprime(ofstream&arch) {
    arch << right << setw(10) << codprod << setw(5) << "" << left <<
            setw(60) << nombre << setw(8) << stock;
}
