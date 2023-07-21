/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaSol.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:33
 */

#ifndef COLASOL_H
#define COLASOL_H

#include "NodoCola.h"
#include "Libro.h"


class ColaSol {
public:
    ColaSol();
    ColaSol(const ColaSol& orig);
    virtual ~ColaSol();
    
    void llenarCola(ifstream&arch);
    void mostrarCola(ofstream&arch);
    void atiende(vector<Libro> &libros);
private:
    NodoCola* ini;
    NodoCola* fincola;
    int n; // cantidad de solicitudes que tiene la cola
    bool hayStock(vector<Libro> &libros, const char* cad, int &);
};

#endif /* COLASOL_H */

