/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   nota.cpp
 * Author: Danie
 * 
 * Created on 11 de junio de 2023, 12:19
 */

#include "nota.h"

nota::nota() {
    ciclo = codigo = notaa = 0;
    codcurso = nullptr;
}

nota::nota(const class nota& orig) {
    static int i=0;
    cout << "########" << i++ << endl;
    
    SetCodigo(orig.GetCodigo());
    SetCiclo(orig.GetCiclo());
    SetNota(orig.GetNota());
    char c[100];
    orig.GetCodcurso(c);
    SetCodcurso(c);
    
}

void nota::copiar(const class nota &orig) {
//    static int i=0;
//    cout << "########" << i++ << endl;
    
    SetCodigo(orig.GetCodigo());
    SetCiclo(orig.GetCiclo());
    SetNota(orig.GetNota());
    char c[100];
    orig.GetCodcurso(c);
    SetCodcurso(c);
}

nota::~nota() {
    delete codcurso;
}

void nota::SetNota(int nota) {
    this->notaa = nota;
}

int nota::GetNota() const {
    return notaa;
}

void nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int nota::GetCiclo() const {
    return ciclo;
}

void nota::SetCodcurso(char* codcurso2) {
    if (this->codcurso != nullptr) delete this->codcurso;
    this->codcurso = new char[strlen(codcurso2)+1];
    strcpy(this->codcurso, codcurso2);
}

void nota::GetCodcurso(char*n) const {
    if (codcurso == nullptr) n[0] = 0;
    else strcpy(n, codcurso);
}

void nota::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int nota::GetCodigo() const {
    return codigo;
}

