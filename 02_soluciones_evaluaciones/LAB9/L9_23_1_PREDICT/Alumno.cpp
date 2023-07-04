/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 22:57
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = escala = total = 0;
    nombre = nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if (nombre) delete nombre;
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

void Alumno::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Alumno::GetNombre(char*n) const {
    if (nombre) strcpy(n, nombre);
    else n[0] = 0;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::LeerAlumno(ifstream&arch) {
    int codigo;
    char nombre[100], c;
    arch >> codigo >> c;
    arch.getline(nombre, 100, ',');
    cout << nombre << endl;
    SetCodigo(codigo);
    SetNombre(nombre);
}