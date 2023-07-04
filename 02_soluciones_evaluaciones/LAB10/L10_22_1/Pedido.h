/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 23:14
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void lee(ifstream&);
    virtual void imprime(ofstream&);
    int operator >(const class Pedido&);
    
    virtual void exonerar() = 0;
private:
    int codigo;
    char *nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
};

#endif /* PEDIDO_H */

