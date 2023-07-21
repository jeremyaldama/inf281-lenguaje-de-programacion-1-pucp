/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:10
 */

#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
}

Producto::Producto(const Producto& orig) {
}

void Producto::operator=(const Producto& prod) {
    cout << "psaa aca "<< endl;
    codprod = prod.codprod;
    SetNombre(prod.nombre);
    stock = prod.stock;
}

Producto::~Producto() {
    static int i = 0;
    cout << "producto eliminado " << ++i << endl;
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

void Producto::leer(ifstream& arch) {
    char c, nombre[100];
    arch >> codprod >> c;
    arch.getline(nombre, 100, ',');
    arch >> stock;
    SetNombre(nombre);
}

void Producto::imprime(ofstream& arch) {
    arch << left << setw(5) << " " << setw(10) << codprod << setw(50) << nombre <<
            setw(10) << stock;
}
