/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 23:02
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento = total = 0.0;
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

void Semipresencial::LeerAlumno(ifstream&arch) {
    Alumno::LeerAlumno(arch);
    double descuento;
    int escala;
    char c;
    arch >> descuento >> c >> escala;
    SetDescuento(descuento);
    SetEscala(escala);
}