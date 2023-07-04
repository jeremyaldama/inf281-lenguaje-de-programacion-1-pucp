/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   RegCliente.cpp
 * Author: Danie
 * 
 * Created on 25 de junio de 2023, 22:56
 */

#include "RegCliente.h"

void RegCliente::imprimirRegistro(ofstream&arch) {
    cliente.imprimirDatos(arch);

    for (Pedido i : pedidos) {
        i.imprimirDatos(arch);
    }
    arch << endl;
}

void RegCliente::asignarCliente(const class Cliente &cli) {
    cliente = cli;
}

void RegCliente::asignarPedidoACliente(const class Pedido&ped) {
    pedidos.push_back(ped);
}

int RegCliente::ObtenerDNI() {
    return cliente.GetDni();
}

void RegCliente::ordenarPedidos() {
    pedidos.sort();
}