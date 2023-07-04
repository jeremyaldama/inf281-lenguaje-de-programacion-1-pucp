/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 23:17
 */

#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
}

PedidoEspecial::PedidoEspecial(const PedidoEspecial& orig) {
}

PedidoEspecial::~PedidoEspecial() {
}

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(ifstream&arch) {
    char c;
    arch >> c >> descuento >> c;
    Pedido::lee(arch);
}

//void PedidoEspecial::operator =(const class Pedido&ped) {
//    *this Pedido::= ped;
////    descuento = ped
//}

void PedidoEspecial::imprime(ofstream&arch) {
    Pedido::imprime(arch);
    arch << "Descuento: " << descuento << '%' << endl;
}

void PedidoEspecial::exonerar() {
    cout << "Es pedido especial " << endl;
}