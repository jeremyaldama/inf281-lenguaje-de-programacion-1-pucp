/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Categoria1.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:30
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H
#include "Producto.h"

class Categoria1 : public Producto {
public:
    Categoria1();
    Categoria1(const Categoria1& orig);
    virtual ~Categoria1();
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream&);
    void imprime(ofstream&arch);
    int obtenerPrioridad();
private:
    int prioridad;
    int minimo;
};

#endif /* CATEGORIA1_H */

