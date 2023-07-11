/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:06 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
public:
    void cargaescalas();
    void abrirArchivoLectura(ifstream&, const char*);
    void cargaalumnos();
    void imprimeboleta();
    void abrirArchivoEscritura(ofstream&, const char*);
    void imprimeLinea(ofstream&, char, int);
private:
    class Boleta lboleta[1000];
    class Escala lescala[100];
};

#endif /* TESORERIA_H */

