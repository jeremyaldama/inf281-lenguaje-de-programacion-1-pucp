/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Categoria2.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:31
 */

#ifndef CATEGORIA2_H
#define CATEGORIA2_H
#include "Producto.h"

class Categoria2 : public Producto {
public:
    Categoria2();
    Categoria2(const Categoria2& orig);
    virtual ~Categoria2();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream&arch);
    void imprime(ofstream&arch);
    int obtenerPrioridad();
private:
    int prioridad;
    double descuento;
};

#endif /* CATEGORIA2_H */

