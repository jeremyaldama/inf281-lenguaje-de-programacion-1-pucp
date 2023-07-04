/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Danie
 *
 * Created on 25 de junio de 2023, 22:50
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
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
    bool operator<(const class Pedido&);
    void operator=(const class Pedido &);
private:
    int codigo;
    double cantidad;
    int fecha;
    double subTotal;
};

#endif /* PEDIDO_H */

