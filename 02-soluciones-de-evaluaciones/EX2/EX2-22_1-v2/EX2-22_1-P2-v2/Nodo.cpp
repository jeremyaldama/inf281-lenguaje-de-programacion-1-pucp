/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:26
 */

#include "Nodo.h"

Nodo::Nodo() {
    // ped no es necesario inicializarlo
//    ped = nullptr;
    sig = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    cout << "Se ejecuta destructor del nodo" << endl;
    if (ped) delete ped;
}

bool Nodo::compara(const class Nodo& nodo) {
    return ped->GetFecha() > nodo.ped->GetFecha();
}
