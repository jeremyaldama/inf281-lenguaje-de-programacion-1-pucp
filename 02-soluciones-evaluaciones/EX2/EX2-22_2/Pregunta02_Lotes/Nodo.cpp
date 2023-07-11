/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 12:14
 */

#include "Nodo.h"

Nodo::Nodo() {
    izq = der = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

bool Nodo::compararMedicamento(const medicamento& med_nuevo) {
    return (med->GetFechavenc() > med_nuevo.GetFechavenc()) || 
            ((med->GetFechavenc() == med_nuevo.GetFechavenc()) &&
            med->GetCodigo() > med_nuevo.GetCodigo());
}
