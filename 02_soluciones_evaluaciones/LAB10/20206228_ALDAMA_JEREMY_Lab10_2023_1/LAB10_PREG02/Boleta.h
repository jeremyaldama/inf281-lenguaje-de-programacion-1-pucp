/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:07 AM
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Presencial.h"

class Boleta {
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void operator=(class Boleta&);
    void leerAlumno(ifstream&);
    int obtenerEscala();
    int obtenerCodigo();
    void actualiza(double precio);
    void imprime(ofstream&arch);
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

