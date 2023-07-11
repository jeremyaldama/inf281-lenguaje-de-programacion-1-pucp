/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:01 AM
 */

#include "Presencial.h"

Presencial::Presencial() {
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
    double recargo;
    arch >> recargo;
    SetRecargo(recargo);
}

void Presencial::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    arch << setw(12) << ""  << right << setw(10) << Alumno::GetTotal()<< endl;
}

void Presencial::actualizatotal(double valor) {
    Alumno::actualizatotal(valor);
    SetTotal(GetRecargo() / 100 * Alumno::GetTotal());
    Alumno::SetTotal(Alumno::GetTotal() + GetTotal());
}
