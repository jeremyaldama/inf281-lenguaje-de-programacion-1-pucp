/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 23:18
 */

#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
}

PedidoUsual::PedidoUsual(const PedidoUsual& orig) {
}

PedidoUsual::~PedidoUsual() {
}

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::lee(ifstream&arch) {
    char c;
    arch >> c >> descuento >> c >> flete >> c;
    Pedido::lee(arch);
}

void PedidoUsual::imprime(ofstream&arch) {
    Pedido::imprime(arch);
    arch << "Descuento: " << descuento << '%' <<  endl;
    arch << "Flete: " << flete << '%' << endl;
}

void PedidoUsual::exonerar() {
    cout << "Pedido usual exonerado" << endl;
    flete = 0.0;
}