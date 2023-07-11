/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 08:10 PM
 */
#include <iostream>
#include "Nodo.h"

using namespace std;

Nodo::Nodo() {
    sig=NULL;
}

Nodo::Nodo(const Nodo& orig) {
    this->ped = orig.ped;
}

Nodo::~Nodo() {
}

