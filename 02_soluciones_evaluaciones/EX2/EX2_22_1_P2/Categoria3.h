/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Categoria3.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:31
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H
#include "Producto.h"

class Categoria3 : public Producto {
public:
    Categoria3();
    Categoria3(const Categoria3& orig);
    virtual ~Categoria3();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream&);
    void imprime(ofstream&);
    int obtenerPrioridad();
private:
    int prioridad;
    double descuento;
};

#endif /* CATEGORIA3_H */

