/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicina_Cantidad.cpp
 * Author: Danie
 * 
 * Created on 7 de julio de 2023, 16:09
 */

#include "Medicina_Cantidad.h"

Medicina_Cantidad::Medicina_Cantidad() {
}

Medicina_Cantidad::Medicina_Cantidad(const Medicina_Cantidad& orig) {
    *this = orig;
}

Medicina_Cantidad::~Medicina_Cantidad() {
}

void Medicina_Cantidad::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicina_Cantidad::GetCantidad() const {
    return cantidad;
}

void Medicina_Cantidad::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicina_Cantidad::GetCodigo() const {
    return codigo;
}

void Medicina_Cantidad::operator=(const Medicina_Cantidad& med_can) {
    codigo = med_can.codigo;
    cantidad = med_can.cantidad;
}


ifstream& operator>>(ifstream&arch, class Medicina_Cantidad&med_can) {
    int cod, can;
    char c;
    arch >> cod >> c >> can;
    cout << "cod medicamento: " << cod << endl;
    med_can.SetCodigo(cod);
    med_can.SetCantidad(can);
    return arch;
}

void Medicina_Cantidad::imprimirMedicinaCantidad(ofstream& arch) {
    arch << setw(10) << codigo << cantidad << endl;
}
