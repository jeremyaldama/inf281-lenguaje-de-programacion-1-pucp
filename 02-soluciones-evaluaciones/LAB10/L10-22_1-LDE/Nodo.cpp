/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 23:20
 */

#include "Nodo.h"

Nodo::Nodo() {
    ant = sig = nullptr;
}

Nodo::~Nodo() {
    cout << "LIBERA NODO " << endl;
//    if (ped) delete ped;
}
