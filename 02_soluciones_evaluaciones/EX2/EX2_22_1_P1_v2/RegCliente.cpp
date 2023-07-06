/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 0:08
 */

#include "RegCliente.h"

RegCliente::RegCliente() {
}

RegCliente::RegCliente(const RegCliente& orig) {
    *this = orig;
}

void RegCliente::operator=(const RegCliente& reg) {
    cliente = reg.cliente;
}


RegCliente::~RegCliente() {
}

void RegCliente::leerCliente(ifstream& arch) {
    cliente.leerDatos(arch);
    
    char tipo = cliente.GetTipo();
    if (tipo == 'A') cliente.SetDescuento(23.5);
    else if (tipo == 'B') cliente.SetDescuento(16.8);
    else if (tipo == 'C') cliente.SetDescuento(8.3);
    else cliente.SetDescuento(0.0);
}

void RegCliente::imprimirCliente(ofstream&arch) {
    cliente.imprimirDatos(arch);
    
    for (list<class Pedido>::iterator it = pedidos.begin();
            it != pedidos.end(); it++) {
        it->imprimirDatos(arch);
    }
}

int RegCliente::obtenerDNI() const {
    return cliente.GetDni();
}

void RegCliente::agregarPedido(const class Pedido& ped) {
    pedidos.push_back(ped);
}

double RegCliente::obtenerDescuento() const {
    return cliente.GetDescuento();
}

void RegCliente::ordenar() {
    pedidos.sort();
}
