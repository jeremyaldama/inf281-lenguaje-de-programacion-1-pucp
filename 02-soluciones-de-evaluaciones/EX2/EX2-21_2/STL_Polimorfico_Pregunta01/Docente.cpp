/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:29
 */

#include "Docente.h"

Docente::Docente() {
}

Docente::Docente(const Docente& orig) {
}

Docente::~Docente() {
}

void Docente::SetAnexo(int anexo) {
    this->anexo = anexo;
}

int Docente::GetAnexo() const {
    return anexo;
}

void Docente::leer(ifstream& arch) {
    arch >> anexo;
}
