/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:03 AM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno {
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream&);
    void imprime(ofstream&arch);
    void actualizatotal(double precio);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

