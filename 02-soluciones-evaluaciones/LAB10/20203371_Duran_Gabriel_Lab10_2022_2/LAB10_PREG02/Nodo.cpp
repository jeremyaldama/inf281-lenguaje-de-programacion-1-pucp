/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: alulab14
 * 
 * Created on 25 de noviembre de 2022, 08:09 AM
 */

#include "Nodo.h"

Nodo::Nodo() {
    der=nullptr;
    izq=nullptr;
    med=nullptr;
}

Nodo::~Nodo() {
    delete med;
}

