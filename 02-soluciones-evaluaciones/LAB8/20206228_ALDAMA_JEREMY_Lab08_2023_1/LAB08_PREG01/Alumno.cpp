/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:02 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = escala = total = 0;
    nombre = nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if (nombre != nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* n) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(n)+1];
    strcpy(nombre, n);
}

void Alumno::GetNombre(char*n) const {
    if (nombre == nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
