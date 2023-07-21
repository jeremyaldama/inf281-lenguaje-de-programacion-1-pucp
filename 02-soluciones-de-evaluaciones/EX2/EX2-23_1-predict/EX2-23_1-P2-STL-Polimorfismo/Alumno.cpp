/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:00 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
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

void Alumno::GetNombre(char*cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream&arch) {
    char c, nom[100];
    arch >> codigo >> c;
    arch.getline(nom, 100, ',');
    arch >> escala >> c >> creditos >> c;
    SetNombre(nom);
    total = 0.0;
}

void Alumno::imprime(ofstream& arch) {
    arch << setprecision(2) << fixed;
    arch << left << setw(15) << codigo << setw(60) << nombre << setw(10) << 
            escala << setw(10) << creditos;
}

void Alumno::actualizatotal(double precio) {
    cout << creditos << endl;
    total = precio*creditos;
    cout << "total " << total << endl;
}
