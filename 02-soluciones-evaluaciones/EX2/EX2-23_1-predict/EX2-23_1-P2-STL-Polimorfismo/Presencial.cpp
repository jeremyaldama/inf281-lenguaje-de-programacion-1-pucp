/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:03 AM
 */

#include "Presencial.h"

Presencial::Presencial() {
    total = 0.0;
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::lee(ifstream&arch) {
    Alumno::lee(arch);
    arch >> recargo;
    total = 0.0;
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << right << setw(19) << Alumno::GetTotal() << endl;
}

void Presencial::actualizatotal(double precio) {
    Alumno::actualizatotal(precio);
    cout << total << endl;
    total = Alumno::GetTotal() * recargo/100;
    Alumno::SetTotal(total + Alumno::GetTotal());
}
