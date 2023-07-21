/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Disponible.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 0:55
 */

#include "Disponible.h"

Disponible::Disponible() {
    zona = 0;
}

Disponible::Disponible(const Disponible& orig) {
}

Disponible::~Disponible() {
}

void Disponible::SetZona(int zona) {
    this->zona = zona;
}

int Disponible::GetZona() const {
    return zona;
}

void Disponible::AsignaCopia(const char*codigo, const char*descrip, const char*autor, 
                    int aa, int cantidad, double precio, int zona, int num) {
    Libro::AsignaCopia(codigo, descrip, autor, aa, cantidad, precio, zona, num);
    SetZona(zona);
}

void Disponible::Imprimir(ofstream&arch) {
    arch << left << setw(20) << "Disponible" << setw(10) << "Zona: " << 
            right << setw(12) << GetZona() << endl;
}