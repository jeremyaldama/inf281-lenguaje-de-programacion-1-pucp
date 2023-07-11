/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 16:36
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;

class Pedido {
private:
    int codigo;
    int cantidad;
public:
    Pedido();
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

ofstream& operator << (ofstream&, Pedido&);

#endif /* PEDIDO_H */

