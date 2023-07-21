/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estudiante.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:30
 */

#include "Estudiante.h"

Estudiante::Estudiante() {
}

Estudiante::Estudiante(const Estudiante& orig) {
}

Estudiante::~Estudiante() {
}

void Estudiante::SetCelular(int celular) {
    this->celular = celular;
}

int Estudiante::GetCelular() const {
    return celular;
}

void Estudiante::leer(ifstream& arch) {
    arch >> celular;
}
