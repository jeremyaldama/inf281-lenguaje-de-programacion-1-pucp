/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:24
 */

#include "Curso.h"

Curso::Curso() {
    codigo = nombre = profesor = nullptr;
}

Curso::Curso(const Curso& orig) {
    // es importante poner este nullptr
    codigo = nombre = profesor = nullptr;
    *this = orig;
}

Curso::~Curso() {
    if (codigo) delete codigo;
    if (nombre) delete nombre;
    if (profesor) delete profesor;
}

void Curso::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Curso::GetCreditos() const {
    return creditos;
}

void Curso::SetProfesor(const char* cad) {
    if (profesor) delete profesor;
    profesor = new char[strlen(cad)+1];
    strcpy(profesor, cad);
}

void Curso::GetProfesor(char* cad) const {
    if (profesor) strcpy(cad, profesor);
    else cad[0] = 0;
}

void Curso::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Curso::GetNombre(char *cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void Curso::SetCodigo(const char* cad) {
    if (codigo) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Curso::GetCodigo(char* cad) const {
    if (codigo) strcpy(cad, codigo);
    else cad[0] = 0;
}

void Curso::leer(ifstream& arch) {
    char cad[100], c;
    arch.getline(cad, 100, ',');
    if (arch.eof()) return;
    SetCodigo(cad);
    arch.getline(cad, 100, ',');
    SetNombre(cad);
    int basura;
    arch >> creditos >> c >> basura >> c;
    // si lo hicieramos arch >> cad;
    // faltaria leer el salto de linea
    arch.getline(cad, 100);
//    cout << cad << endl;
    SetProfesor(cad);
}

void Curso::operator=(const Curso& cur) {
    SetCodigo(cur.codigo);
    SetNombre(cur.nombre);
    SetProfesor(cur.profesor);
    creditos = cur.creditos;
}
