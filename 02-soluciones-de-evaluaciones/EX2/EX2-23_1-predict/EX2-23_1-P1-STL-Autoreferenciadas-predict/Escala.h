/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:12
 */

#ifndef ESCALA_H
#define ESCALA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Escala {
public:
    Escala(); 
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leer(ifstream& arch);
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

