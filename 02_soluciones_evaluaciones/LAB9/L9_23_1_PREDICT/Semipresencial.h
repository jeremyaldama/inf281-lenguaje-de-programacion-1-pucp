/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 23:02
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno {
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void LeerAlumno(ifstream&);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

