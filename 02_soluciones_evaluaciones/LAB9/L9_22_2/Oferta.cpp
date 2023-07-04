/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Oferta.cpp
 * Author: Danie
 * 
 * Created on 20 de junio de 2023, 19:05
 */

#include "Oferta.h"

Oferta::Oferta() {
    poferta = nullptr;
}

Oferta::~Oferta() {
    if (poferta) {
        delete poferta;
    }
}

void Oferta::AsignaMedicamento(int cod_med, ifstream&arch) {
    if ((cod_med/10000)%2==0) {
        poferta = new class Conreceta;
    } else {
        poferta = new class Sinreceta;
    }
    poferta->leemedicamento(cod_med, arch);
}

void Oferta::imprimeMedicamento(ofstream&arch) {
    poferta->imprimedicamento(arch);
}

int Oferta::fin() {
    return poferta == nullptr;
}

void Oferta::aplicaDescuento() {
    poferta->aplicadescuento();
}