/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:09
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetOrden(int orden);
    int GetOrden() const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leer(ifstream&arch);
    void mostrarPedido(ofstream&arch);
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    int orden; // 1=si, 0=no
};

#endif /* PEDIDO_H */

