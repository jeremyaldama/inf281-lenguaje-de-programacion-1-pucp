/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   activo.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 12:06
 */

#include "activo.h"

activo::activo() {
    vendedor = nullptr;
}

activo::activo(const activo& orig) {
}

activo::~activo() {
    cout << "SE LIBERA MEDICAMENTO ACTIVO" << endl;
    if (vendedor) delete vendedor;
}

void activo::SetVendedor(const char* cad) {
    if (vendedor) delete vendedor;
    vendedor = new char[strlen(cad)+1];
    strcpy(vendedor, cad);
}

void activo::GetVendedor(char *cad) const {
    if (vendedor) strcpy(cad, vendedor);
    else cad[0] = 0;
}

void activo::SetPrecio(double precio) {
    this->precio = precio;
}

double activo::GetPrecio() const {
    return precio;
}

void activo::lee(ifstream& arch, const char* inspector, int fecha_baja) {
    medicamento::lee(arch, inspector, fecha_baja);
    char c, cad[100];
    arch.getline(cad, 100, ',');
    SetVendedor(cad);
    arch >> precio;
}

void activo::imprime(ofstream& arch) {
    medicamento::imprime(arch);
    arch << left << setw(20) << vendedor << right << setw(12) << precio << endl;
}

void activo::registrarDatos(int, const char* inspector) {
    return;
}
