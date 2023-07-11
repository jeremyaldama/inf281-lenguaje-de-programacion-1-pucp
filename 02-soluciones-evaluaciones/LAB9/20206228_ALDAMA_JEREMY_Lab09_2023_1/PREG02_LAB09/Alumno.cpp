/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 07:58 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = escala = 0;
    creditos = total = 0.0;
    nombre = nullptr;
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

void Alumno::GetNombre(char* cad) const {
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
    int codigo, escala;
    char nombre[100], c;
    double creditos;
    
    arch >> codigo >> c;
    arch.getline(nombre, 100, ',');
    arch >> escala >> c >> creditos >> c;
    SetCodigo(codigo);
    SetNombre(nombre);
    SetEscala(escala);
    SetCreditos(creditos);
}

void Alumno::imprime(ofstream& arch) {
    char cad[100];
    GetNombre(cad);
    arch << left << setw(15) << GetCodigo() << setw(60) << cad << setw(10) <<
            GetEscala() << setw(12) << GetCreditos();
}

void Alumno::actualizatotal(double valor) {
    SetTotal(valor * GetCreditos());
}
