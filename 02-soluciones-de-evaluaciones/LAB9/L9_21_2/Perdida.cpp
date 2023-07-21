/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Perdida.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 0:56
 */

#include "Perdida.h"

Perdida::Perdida() {
    precio = 0.0;
}

Perdida::Perdida(const Perdida& orig) {
}

Perdida::~Perdida() {
}

void Perdida::SetPrecio(double precio) {
    this->precio = precio;
}

double Perdida::GetPrecio() const {
    return precio;
}

void Perdida::Actualiza(const char*codigo, const char*titulo, 
            const char*autor, int aa, int cantidad, double precio, int num_lib,
            int dias, int fecha) {
    Libro::Actualiza(codigo, titulo, autor, aa, cantidad, precio, num_lib,
                    dias, fecha);
    SetPrecio(Libro::GetPrecio());
}

void Perdida::Imprimir(ofstream&arch) {
    arch << left << setw(20) << "Perdida" << setw(10) << "Precio: " << 
            right << setw(12) << GetPrecio() << endl;
}