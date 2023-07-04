/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Conreceta.cpp
 * Author: Danie
 * 
 * Created on 20 de junio de 2023, 18:57
 */

#include "Conreceta.h"

Conreceta::Conreceta() {
    codmed = 0;
    especialidad = nullptr;
}

Conreceta::~Conreceta() {
    if (especialidad) delete especialidad;
}

void Conreceta::SetEspecialidad(const char* n) {
    if (especialidad) delete especialidad;
    especialidad = new char[strlen(n)+1];
    strcpy(especialidad, n);
}

void Conreceta::GetEspecialidad(char *n) const {
    if (!especialidad) n[0] = 0;
    else strcpy(n, especialidad);
}

void Conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int Conreceta::GetCodmed() const {
    return codmed;
}

void Conreceta::leemedicamento(int cod_medicamento, ifstream&arch) {
    Medicamento::leemedicamento(cod_medicamento, arch);
    char c, n[100];
    int dni;
    arch >> codmed >> c >> dni >> c >> n;
    cout << dni << "   " << n << endl;
    ObtenerEspecialidad(GetCodmed(), n);
    SetEspecialidad(n);
}

void Conreceta::ObtenerEspecialidad(int cod_doc, char*n) {
    ifstream arch("medicos.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR medicos.csv";
        exit(1);
    }
    int codigo;
    char nombre[100], c;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        arch.getline(nombre, 100);
        if (codigo = cod_doc) {
            strcpy(n, nombre);
            break;
        }
    }
}

void Conreceta::imprimedicamento(ofstream&arch) {
    Medicamento::imprimedicamento(arch);
    char n[100];
    GetEspecialidad(n);
    arch << right << setw(10) << GetCodmed() << right << setw(20) << n << endl;
            
}

void Conreceta::aplicadescuento() {
    Medicamento::aplicadescuento();
    SetTotal(GetTotal()*1.05);
}