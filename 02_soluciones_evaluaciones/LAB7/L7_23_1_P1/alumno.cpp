/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   alumno.cpp
 * Author: Danie
 * 
 * Created on 11 de junio de 2023, 12:23
 */

#include "alumno.h"

alumno::alumno() {
    codigo = numaprobados = numcursos = numprimera = numsegunda = numtercera = 0;
    nombre = nullptr;
}

alumno::alumno(const alumno& orig) {
}

alumno::~alumno() {
}

//void alumno::SetLnotas(nota[] lnotas) {
//    this->lnotas = lnotas;
//}

const class nota* alumno::GetLnotas() const{return lnotas;}

void alumno::SetNumtercera(int numtercera) {
    this->numtercera = numtercera;
}

int alumno::GetNumtercera() const {
    return numtercera;
}

void alumno::SetNumsegunda(int numsegunda) {
    this->numsegunda = numsegunda;
}

int alumno::GetNumsegunda() const {
    return numsegunda;
}

void alumno::SetNumprimera(int numprimera) {
    this->numprimera = numprimera;
}

int alumno::GetNumprimera() const {
    return numprimera;
}

void alumno::SetNumaprobados(int numaprobados) {
    this->numaprobados = numaprobados;
}

int alumno::GetNumaprobados() const {
    return numaprobados;
}

void alumno::SetNumcursos(int numcursos) {
    this->numcursos = numcursos;
}

int alumno::GetNumcursos() const {
    return numcursos;
}

void alumno::SetNombre(char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void alumno::GetNombre(char*n) const {
    if (nombre == nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int alumno::GetCodigo() const {
    return codigo;
}

void alumno::operator += (class nota&grade) {
    int i;
    for (i=0; lnotas[i].GetCodigo(); i++);
    lnotas[i] = grade;
}

ifstream& operator >> (ifstream&arch, alumno &al) {
    int codigo;
    arch >> codigo;
    if (arch.eof()) return arch;
    char nombre[100], modalidad, c;
    int porcentaje, escala;
    arch >> c;
    arch.getline(nombre, 100, ',');
    arch >> c;
    al.SetCodigo(codigo);
    al.SetNombre(nombre);
    if (c == 'S') {
        arch >> c >> porcentaje >> c >> c >> escala;
    } else if (c == 'V') {
        arch >> c >> c >> escala;
    } else arch >>  escala;
    return arch;
}

ofstream& operator<<(ofstream&arch, alumno&al) {
    arch << "Codigo del Alumno: " << al.GetCodigo() << endl;
    char n[100];
    al.GetNombre(n);
    arch << "Nombre del Alumno: " << n << endl;
    arch << "Detalle de Cursos: " << endl;
    arch << "Cursados   " << "Aprobados   " << "1ra Vez   " << "2da Vez   " <<
            "3ra Vez" << endl;
    arch << right << setw(5) << al.GetNumcursos() << setw(11) << 
            al.GetNumaprobados() << setw(11) << al.GetNumprimera() << setw(11) <<
            al.GetNumsegunda() << setw(11) << al.GetNumtercera() << endl;
}