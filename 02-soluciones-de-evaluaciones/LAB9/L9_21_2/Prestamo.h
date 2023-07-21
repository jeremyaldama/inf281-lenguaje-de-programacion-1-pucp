/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Prestamo.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 0:55
 */

#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Libro.h"

class Prestamo : public Libro{
public:
    Prestamo();
    Prestamo(const Prestamo& orig);
    virtual ~Prestamo();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDias(int dias);
    int GetDias() const;
    void Actualiza(const char*codigo, const char*titulo, 
            const char*autor, int aa, int cantidad, double precio, int num_lib,
            int dias, int fecha);
    void Imprimir(ofstream&);
private:
    int dias;
    int fecha;
};

#endif /* PRESTAMO_H */

