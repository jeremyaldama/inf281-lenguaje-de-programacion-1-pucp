/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEventual.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 23:19
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H
#include "Pedido.h"

class PedidoEventual : public Pedido {
public:
    PedidoEventual();
    PedidoEventual(const PedidoEventual& orig);
    virtual ~PedidoEventual();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream&);
    void imprime(ofstream&);
    
    void exonerar();
private:
    double flete; 
};

#endif /* PEDIDOEVENTUAL_H */

