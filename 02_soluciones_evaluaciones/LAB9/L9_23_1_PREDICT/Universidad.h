/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Universidad.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 23:09
 */

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "Tesoreria.h"
#include "Escala.h"

class Universidad {
public:
    void cargaEscalas();
    void abrirArchivoLectura(ifstream&, const char*);
    void cargaEscala(ifstream&, int, int);
    void cargaAlumnos();
private:
    class Tesoreria ltesoreria[1000];
    class Escala lescala[100];
};

#endif /* UNIVERSIDAD_H */

