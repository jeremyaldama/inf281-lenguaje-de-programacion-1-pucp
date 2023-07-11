/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escala.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:03 AM
 */

#ifndef ESCALA_H
#define ESCALA_H
#include <iostream>
#include <fstream>
using namespace std;

class Escala {
public:
    Escala();
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerEscala(ifstream&arch);
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

