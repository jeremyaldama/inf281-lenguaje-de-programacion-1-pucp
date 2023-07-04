/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 23:19
 */

#include "PedidoEventual.h"

PedidoEventual::PedidoEventual() {
}

PedidoEventual::PedidoEventual(const PedidoEventual& orig) {
}

PedidoEventual::~PedidoEventual() {
}

void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}

void PedidoEventual::lee(ifstream&arch) {
    char c;
    arch >> c >> flete >> c;
    Pedido::lee(arch);
}

void PedidoEventual::imprime(ofstream&arch) {
    Pedido::imprime(arch);
    arch << "Flete: " << flete << '%' << endl;
}

void PedidoEventual::exonerar() {
    cout << "Pedido eventual exonerado" << endl;
    flete = 0.0;
}