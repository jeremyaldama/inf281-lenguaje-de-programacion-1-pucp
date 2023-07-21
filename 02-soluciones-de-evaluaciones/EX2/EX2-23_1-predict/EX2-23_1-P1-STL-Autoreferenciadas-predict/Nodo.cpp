/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:36
 */

#include "Nodo.h"

Nodo::Nodo() {
    sig = ant = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    cout << "ELIMINA NODO" << endl;
}

bool Nodo::comparar(Nodo& nodo) {
    char nom1[100], nom2[100];
    alumno.obtenerNombre(nom1);
    nodo.alumno.obtenerNombre(nom2);
    return strcmp(nom1, nom2) > 0;
}
