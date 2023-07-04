/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:34
 */

#include "Nodo.h"

Nodo::Nodo() {
    ped = nullptr;
    sig = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

int Nodo::obtenerCodigo() {
    return ped->GetCodigo();
}