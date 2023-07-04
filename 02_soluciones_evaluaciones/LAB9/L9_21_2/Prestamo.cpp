/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Prestamo.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 0:55
 */

#include "Prestamo.h"

Prestamo::Prestamo() {
    dias = fecha = 0;
}

Prestamo::Prestamo(const Prestamo& orig) {
}

Prestamo::~Prestamo() {
}

void Prestamo::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Prestamo::GetFecha() const {
    return fecha;
}

void Prestamo::SetDias(int dias) {
    this->dias = dias;
}

int Prestamo::GetDias() const {
    return dias;
}

void Prestamo::Actualiza(const char*codigo, const char*titulo, 
            const char*autor, int aa, int cantidad, double precio, int num_lib,
            int dias, int fecha) {
    Libro::Actualiza(codigo, titulo, autor, aa, cantidad, precio, num_lib,
                    dias, fecha);
    SetDias(dias);
    SetFecha(fecha);
}

void Prestamo::Imprimir(ofstream&arch) {
    arch << left << setw(20) << "Prestamo Dias" << right << 
            setw(10) << GetDias() << endl;
}