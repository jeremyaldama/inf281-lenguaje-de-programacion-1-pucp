/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEspecial.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 23:17
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H
#include "Pedido.h"

class PedidoEspecial : public Pedido {
public:
    PedidoEspecial();
    PedidoEspecial(const PedidoEspecial& orig);
    virtual ~PedidoEspecial();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream&);
//    void operator =(const class Pedido&);
    void imprime(ofstream&);
    
    void exonerar();
private:
    double descuento;
};

#endif /* PEDIDOESPECIAL_H */

