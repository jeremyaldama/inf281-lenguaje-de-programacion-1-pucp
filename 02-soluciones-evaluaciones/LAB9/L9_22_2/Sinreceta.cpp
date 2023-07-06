/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Sinreceta.cpp
 * Author: Danie
 * 
 * Created on 20 de junio de 2023, 19:03
 */

#include "Sinreceta.h"

Sinreceta::Sinreceta() {
    dni = 0;
    nombre = nullptr;
}

Sinreceta::~Sinreceta() {
    if (nombre) delete nombre;
}

void Sinreceta::SetNombre(const char* n) {
    if (nombre) delete nombre;
    nombre = new char[strlen(n)+1];
    strcpy(nombre, n);
}

void Sinreceta::GetNombre(char*n) const {
    if (!nombre) n[0] = 0;
    else strcpy(n, nombre);
}

void Sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int Sinreceta::GetDni() const {
    return dni;
}

void Sinreceta::leemedicamento(int cod_medicamento, ifstream&arch) {
    Medicamento::leemedicamento(cod_medicamento, arch);
    
    int cod_doc, dni;
    char n[100], c;
    
    arch >> cod_doc >> c >> dni >> c >> n;
    cout << dni << "   " << n << endl;
    SetDni(dni);
    SetNombre(n);
}

void Sinreceta::imprimedicamento(ofstream&arch) {
    Medicamento::imprimedicamento(arch);
    char n[100];
    GetNombre(n);
    arch << right << setw(10) << GetDni() << setw(20) << n << endl;
}

void Sinreceta::aplicadescuento() {
    Medicamento::aplicadescuento();
    SetTotal(GetTotal()*1.1);
}