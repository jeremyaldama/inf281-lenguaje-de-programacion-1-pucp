/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tienda.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 23:11
 */
#include "Cliente.h"
#include "Pedido.h"

#ifndef TIENDA_H
#define TIENDA_H

class Tienda {
public:
    Tienda();
    Tienda(const Tienda& orig);
    virtual ~Tienda();
    void carga();
    void CargaPedidos();
    void CargaClientes();
    void actualiza(int);
    int BuscarDescuento(int cod_buscar);
    void muestra();
private:
    class Pedido lpedidos[1000];
    class Cliente lclientes[1000];
};

#endif /* TIENDA_H */

