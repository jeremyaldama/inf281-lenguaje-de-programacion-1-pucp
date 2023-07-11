/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:05 AM
 */

#include "Boleta.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if (pboleta) delete pboleta;
}

void Boleta::lee(ifstream&arch, char tipo) {
    if (tipo == 'S') pboleta = new class Semipresencial;
    else if (tipo == 'P') pboleta = new class Presencial;
    else pboleta = new class Virtual;
    
    pboleta->lee(arch);
}

int Boleta::fin() {
    return pboleta ==  nullptr;
}

void Boleta::imprime(ofstream&arch) {
    pboleta->imprime(arch);
}

void Boleta::actualizaboleta(double valor) {
    pboleta->actualizatotal(valor);
}

int Boleta::ObtenerEscalaAlumno() {
    return pboleta->GetEscala();
}
