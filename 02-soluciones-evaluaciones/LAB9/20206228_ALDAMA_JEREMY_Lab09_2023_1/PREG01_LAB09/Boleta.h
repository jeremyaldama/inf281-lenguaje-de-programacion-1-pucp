/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:05 AM
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
#include "Virtual.h"
#include "Semipresencial.h"
#include "Presencial.h"

class Boleta {
public:
    Boleta();
    virtual ~Boleta();
    void lee(ifstream&, char);
    int fin();
    void imprime(ofstream&);
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

