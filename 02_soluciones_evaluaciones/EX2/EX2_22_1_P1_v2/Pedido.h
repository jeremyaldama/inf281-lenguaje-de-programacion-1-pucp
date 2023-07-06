/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 0:07
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
#include <iomanip>
using namespace std;

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetSubTotal(double subTotal);
    double GetSubTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(double cantidad);
    double GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    int leerDatos(ifstream&);
    void imprimirDatos(ofstream&);
    void operator=(const class Pedido&ped);
    bool operator<(const class Pedido&ped);
private:
    int codigo;
    double cantidad;
    int fecha;
    double subTotal;
};

#endif /* PEDIDO_H */

