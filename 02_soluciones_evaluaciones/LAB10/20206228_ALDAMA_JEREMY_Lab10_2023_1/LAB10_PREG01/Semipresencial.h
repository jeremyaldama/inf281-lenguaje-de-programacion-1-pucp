/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:04 AM
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
    void lee(ifstream&arch);
    void imprime(ofstream&arch);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

