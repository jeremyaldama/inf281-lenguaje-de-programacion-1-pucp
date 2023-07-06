/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Perdida.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 0:56
 */

#ifndef PERDIDA_H
#define PERDIDA_H
#include "Libro.h"

class Perdida : public Libro{
public:
    Perdida();
    Perdida(const Perdida& orig);
    virtual ~Perdida();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void Actualiza(const char*codigo, const char*titulo, 
            const char*autor, int aa, int cantidad, double precio, int num_lib,
            int dias, int fecha);
    void Imprimir(ofstream&);
private:
    double precio;
};

#endif /* PERDIDA_H */

