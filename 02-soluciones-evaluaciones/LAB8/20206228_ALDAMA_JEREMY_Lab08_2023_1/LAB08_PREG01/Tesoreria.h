/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: alulab14
 *
 * Created on 16 de junio de 2023, 08:14 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaescalas();
    void cargaalumnos();
    void actualiza(double);
    void actualizaPresencial(double);
    void actualizaSemipresencial(double);
    void actualizaVirtual(double);
    double BuscarPrecioEscala(int);
    void imprime();
    void imprimirLinea(ofstream&, char, int);
private:
    class Presencial lpresencial[1000];
    class Semipresencial lsemipresencial[1000];
    class Virtual lvirtual[1000];
    class Escala lescala[100];
};

#endif /* TESORERIA_H */

