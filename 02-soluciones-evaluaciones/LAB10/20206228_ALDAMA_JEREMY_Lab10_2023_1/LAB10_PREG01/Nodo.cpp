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
    der = izq = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

bool Nodo::compara(class Boleta& bol) {
    return dboleta.obtenerCodigo() > bol.obtenerCodigo();
}
