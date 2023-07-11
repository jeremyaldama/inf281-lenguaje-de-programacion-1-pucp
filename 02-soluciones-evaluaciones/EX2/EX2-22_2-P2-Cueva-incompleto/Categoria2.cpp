/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria2.cpp
 * Author: cueva
 * 
 * Created on 9 de julio de 2022, 09:36 PM
 */

#include "Categoria2.h"

Categoria2::Categoria2() {
    prioridad=0;
    descuento=0;
}

Categoria2::Categoria2(const Categoria2& orig) {
}

Categoria2::~Categoria2() {
}

void Categoria2::leeprod(ifstream&arch){
    char c;
    
    arch >>prioridad>>c>> descuento;
    arch.get();
    Producto::leeprod(arch);    
    
}

void Categoria2::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria2::getDescuento() const {
    return descuento;
}

void Categoria2::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria2::getPrioridad() const {
    return prioridad;
}

void Categoria2::imprimeprod(ofstream& arch){
    Producto::imprimeprod(arch);
    arch << "Descuento: " << descuento <<endl;
    arch << "Prioridad: " << prioridad << endl << endl;
}