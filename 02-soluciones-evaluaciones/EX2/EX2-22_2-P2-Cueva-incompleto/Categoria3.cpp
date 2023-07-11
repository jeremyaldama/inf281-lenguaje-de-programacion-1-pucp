/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.cpp
 * Author: cueva
 * 
 * Created on 9 de julio de 2022, 09:36 PM
 */

#include "Categoria3.h"

Categoria3::Categoria3() {
    prioridad=0;
    descuento=0;
}

Categoria3::Categoria3(const Categoria3& orig) {
}

Categoria3::~Categoria3() {
}

void Categoria3::leeprod(ifstream &arch){
    char c;
    
    arch >>prioridad>>c>> descuento;
    arch.get();
    Producto::leeprod(arch);    
}

void Categoria3::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria3::getDescuento() const {
    return descuento;
}

void Categoria3::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria3::getPrioridad() const {
    return prioridad;
}

void Categoria3::imprimeprod(ofstream& arch){
    Producto::imprimeprod(arch);
    arch << "Descuento: " << descuento <<endl;
    arch << "Prioridad: " << prioridad << endl << endl;
}