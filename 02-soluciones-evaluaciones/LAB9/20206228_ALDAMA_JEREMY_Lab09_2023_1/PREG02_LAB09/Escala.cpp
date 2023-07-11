/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:01 AM
 */

#include "Escala.h"

Escala::Escala() {
    codigo = 0;
    precio = 0.0;
}

Escala::Escala(const Escala& orig) {
}

Escala::~Escala() {
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}

