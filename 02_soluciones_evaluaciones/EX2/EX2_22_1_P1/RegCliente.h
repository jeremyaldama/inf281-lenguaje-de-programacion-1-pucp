/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   RegCliente.h
 * Author: Danie
 *
 * Created on 25 de junio de 2023, 22:56
 */

#ifndef REGCLIENTE_H
#define REGCLIENTE_H
#include "Pedido.h"
#include "Cliente.h"
#include <list>

class RegCliente {
public:
    void imprimirRegistro(ofstream&);
    void asignarCliente(const class Cliente &);
    void asignarPedidoACliente(const class Pedido&);
    int ObtenerDNI();
    void ordenarPedidos();
private:
    list<class Pedido> pedidos;
    class Cliente cliente;
};

#endif /* REGCLIENTE_H */

