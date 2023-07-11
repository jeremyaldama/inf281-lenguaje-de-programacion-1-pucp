/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:07 AM
 */

#include "Boleta.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    
}

void Boleta::leerAlumno(ifstream&arch) {
    char tipo, c;
    arch >> tipo;
    if (arch.eof()) return;
    arch >> c;
    if (tipo == 'S') pboleta = new class Semipresencial;
    else if (tipo == 'P') pboleta = new class Presencial;
    else pboleta = new class Virtual;
    pboleta->lee(arch);
}

int Boleta::obtenerCodigo() {
    return pboleta->GetCodigo();
}

void Boleta::imprime(ofstream& arch) {
    pboleta->imprime(arch);
}

int Boleta::obtenerEscala() {
    pboleta->GetEscala();
}

void Boleta::actualiza(double precio) {
    pboleta->actualizatotal(precio);
}
