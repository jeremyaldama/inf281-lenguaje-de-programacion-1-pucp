/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoUsual.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 23:18
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include "Pedido.h"

class PedidoUsual : public Pedido {
public:
    PedidoUsual();
    PedidoUsual(const PedidoUsual& orig);
    virtual ~PedidoUsual();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream&);
    void imprime(ofstream&);
    
    void exonerar();
private:
    double descuento; 
    double flete;
};

#endif /* PEDIDOUSUAL_H */

