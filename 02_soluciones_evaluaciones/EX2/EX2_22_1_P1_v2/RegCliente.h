/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegCliente.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 0:08
 */

#ifndef REGCLIENTE_H
#define REGCLIENTE_H
#include "Cliente.h"
#include "Pedido.h"
#include <iostream>
#include <list>

using namespace std;

class RegCliente {
public:
    RegCliente();
    RegCliente(const RegCliente& orig);
    virtual ~RegCliente();
    void leerCliente(ifstream&arch);
    void operator=(const class RegCliente&reg);
    void imprimirCliente(ofstream&arch);
    int obtenerDNI() const;
    void agregarPedido(const class Pedido&ped);
    double obtenerDescuento() const;
    void ordenar();
private:
    class Cliente cliente;
    list <class Pedido> pedidos;
};

#endif /* REGCLIENTE_H */

