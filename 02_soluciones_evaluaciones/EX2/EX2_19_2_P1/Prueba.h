/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Prueba.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 12:38
 */

#ifndef PRUEBA_H
#define PRUEBA_H
#include "Cliente.h"
#include "PlCola.h"

class Prueba {
private:
    class PlCola<Cliente> cola;
public:
    void cargarCola(int &);
    void emiteReporte(int);
    int hmsASegundos(int, int, int);
    void imprimeEncabezados(ofstream&, int);
    void segundosAHMS(int, int&, int&, int&);
    void imprimeLinea(ofstream&, char, int);
};

#endif /* PRUEBA_H */

