/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 23:06
 */
#include "Producto.h"

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido : public Producto{
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetObs(const char* obs);
    void GetObs(char*) const;
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
    void AsignarProducto(int);
    void Copia(const class Pedido&);
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    char *obs;
};

#endif /* PEDIDO_H */

