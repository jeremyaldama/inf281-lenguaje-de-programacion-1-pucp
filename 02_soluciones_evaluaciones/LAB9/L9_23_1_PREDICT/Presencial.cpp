/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 23:00
 */

#include "Presencial.h"

Presencial::Presencial() {
    recargo = total = 0.0;
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

void Presencial::LeerAlumno(ifstream&arch) {
    Alumno::LeerAlumno(arch);
    double recarga;
    int escala;
    char c;
    arch >> recarga >> c >> escala;
    SetEscala(escala);
    SetRecargo(recarga);
}