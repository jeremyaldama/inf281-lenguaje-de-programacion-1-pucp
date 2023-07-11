/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicina_Cantidad.h
 * Author: Danie
 *
 * Created on 7 de julio de 2023, 16:09
 */

#ifndef MEDICINA_CANTIDAD_H
#define MEDICINA_CANTIDAD_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Medicina_Cantidad {
public:
    Medicina_Cantidad();
    Medicina_Cantidad(const Medicina_Cantidad& orig);
    virtual ~Medicina_Cantidad();
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator=(const class Medicina_Cantidad&med_can);
    void imprimirMedicinaCantidad(ofstream&arch);
private:
    int codigo;
    int cantidad;
};

ifstream& operator>>(ifstream&arch, class Medicina_Cantidad&med_can);

#endif /* MEDICINA_CANTIDAD_H */

