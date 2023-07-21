/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:17
 */

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    cout << "ELIMINA ALUMNO" << endl;
    if (nombre) delete nombre;
}

void Alumno::SetPorcentaje(int porcentaje) {
    this->porcentaje = porcentaje;
}

int Alumno::GetPorcentaje() const {
    return porcentaje;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetModalidad(char modalidad) {
    this->modalidad = modalidad;
}

char Alumno::GetModalidad() const {
    return modalidad;
}

void Alumno::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad) + 1];
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

void Alumno::leer(ifstream& arch) {
    arch >> codigo;
    //    cout << codigo << endl;
    if (arch.eof()) return;
    arch.get();
    char cad[100], mod;
    arch.getline(cad, 100, ',');
    // no olvidarse poner los set de cadenas
    SetNombre(cad);
    arch.get(mod);
    //    cout << mod << endl;
    if (mod == 'S') {
        modalidad = 'S';
        arch.get();
        arch >> porcentaje;
        arch.get();
        arch.get();
    } else if (mod == 'V') {
        modalidad = 'V';
        arch.get();
        arch.get();
    } else modalidad = 'P';
    arch >> escala;
    //    cout << nombre << endl;
    //    cout << escala << endl;
}

void Alumno::operator=(const Alumno& alu) {
    cout << "COPIA ALUMNO NO ALUMNO_CURSO" << endl;
    codigo = alu.codigo;
    escala = alu.escala;
    modalidad = alu.modalidad;
    SetNombre(alu.nombre);
    porcentaje = alu.porcentaje;
}

void Alumno::imprimir(ofstream& arch) {
    imprimirLinea(arch, '=', 62);
    arch << left << setw(10) << codigo << setw(40) << nombre << setw(5) <<
            modalidad << setw(5) << escala << porcentaje << endl;
    imprimirLinea(arch, '=', 62);
}

void Alumno::imprimirLinea(ofstream& arch, char c, int n) {
    for (int i = 0; i < n; i++) arch << c;
    arch << endl;
}
