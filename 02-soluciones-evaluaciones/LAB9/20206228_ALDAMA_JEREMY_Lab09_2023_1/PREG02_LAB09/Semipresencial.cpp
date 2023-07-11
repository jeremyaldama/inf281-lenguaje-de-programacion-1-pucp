/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:03 AM
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::lee(ifstream&arch) {
    Alumno::lee(arch);
    double descuento;
    arch >> descuento;
    SetDescuento(descuento);
}

void Semipresencial::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch << setw(12) << ""  << right << setw(10) << Alumno::GetTotal() << endl;
}

void Semipresencial::actualizatotal(double valor) {
    Alumno::actualizatotal(valor);
    SetTotal(GetDescuento() / 100 * Alumno::GetTotal());
    Alumno::SetTotal(Alumno::GetTotal() - GetTotal());
}