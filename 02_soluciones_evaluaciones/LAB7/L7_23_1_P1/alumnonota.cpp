/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   alumnonota.cpp
 * Author: Danie
 * 
 * Created on 11 de junio de 2023, 12:14
 */

#include <istream>

#include "alumnonota.h"

alumnonota::alumnonota() {
    codigo = ciclo = nota = 0;
    codcurso = nullptr;
}

alumnonota::alumnonota(const alumnonota& orig) {
}

alumnonota::~alumnonota() {
}

void alumnonota::SetNota(int nota) {
    this->nota = nota;
}

int alumnonota::GetNota() const {
    return nota;
}

void alumnonota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int alumnonota::GetCiclo() const {
    return ciclo;
}

void alumnonota::SetCodcurso(char* codcurso) {
    if (this->codcurso != nullptr) delete this->codcurso;
    this->codcurso = new char[strlen(codcurso)+1];
    strcpy(this->codcurso, codcurso);
}

void alumnonota::GetCodcurso(char *cad) const {
    if (codcurso == nullptr) cad[0] = 0;
    else strcpy(cad, codcurso);
}

void alumnonota::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int alumnonota::GetCodigo() const {
    return codigo;
}

void alumnonota::operator &(class nota &grade) {
    grade.SetCodcurso(codcurso);
    grade.SetCiclo(ciclo);
    grade.SetNota(nota);
}

ifstream& operator >>(ifstream&arch, alumnonota&al_nota) {
    int codigo;
    arch >> codigo;
    if (arch.eof()) return arch;
    char codigo_cur[100], c;
    arch >> c;
    arch.getline(codigo_cur, 100, ',');
    int ciclo, nota2;
    arch >> ciclo >> c >> nota2;
    al_nota.SetCiclo(ciclo);
    al_nota.SetCodcurso(codigo_cur);
    al_nota.SetNota(nota2);
    al_nota.SetCodigo(codigo);
    return arch;
}