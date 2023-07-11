/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.cpp
 * Author: cueva
 * 
 * Created on 9 de julio de 2022, 09:36 PM
 */

#include "Categoria1.h"

Categoria1::Categoria1() {
    prioridad=0;
    minimo=0;
}

Categoria1::Categoria1(const Categoria1& orig) {
}

Categoria1::~Categoria1() {
}

void Categoria1::leeprod(ifstream&arch){
    char c;
    
    arch >>prioridad>>c>> minimo;
    arch.get();
    Producto::leeprod(arch);
}

void Categoria1::setMinimo(int minimo) {
    this->minimo = minimo;
}

int Categoria1::getMinimo() const {
    return minimo;
}

void Categoria1::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria1::getPrioridad() const {
    return prioridad;
}

void Categoria1::imprimeprod(ofstream& arch){
    Producto::imprimeprod(arch);
    arch << "Stock Minimo: " << minimo <<endl;
    arch << "Prioridad: " << prioridad << endl << endl;
}