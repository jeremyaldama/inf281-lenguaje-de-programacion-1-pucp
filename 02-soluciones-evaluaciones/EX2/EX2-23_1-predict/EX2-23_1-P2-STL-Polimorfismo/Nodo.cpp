/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:08 AM
 */

#include "Nodo.h"

Nodo::Nodo() {
}

Nodo::~Nodo() {
}

int Nodo::compara(class Boleta& bol) {
    return dboleta.obtenerCodigo() > bol.obtenerCodigo();
}

int Nodo::obtenerEscala() {
    return dboleta.obtenerEscala();
}

void Nodo::leer(ifstream& arch) {
    dboleta.leerAlumno(arch);
}

void Nodo::imprimir(ofstream& arch) {
    dboleta.imprime(arch);
}

void Nodo::actualiza(double precio) {
    dboleta.actualiza(precio);
}
