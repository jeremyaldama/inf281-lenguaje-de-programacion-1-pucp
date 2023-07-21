/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   activo.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:06
 */

#ifndef ACTIVO_H
#define ACTIVO_H
#include "medicamento.h"

class activo : public medicamento {
public:
    // ver como funciona el metodo de creacion por defecto en su base
    activo();
    activo(const activo& orig);
    virtual ~activo();
    void SetVendedor(const char* vendedor);
    void GetVendedor(char*) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    
    void lee(ifstream&arch, const char* cad, int);
    void imprime(ofstream&arch);
    void registrarDatos(int, const char*inspector);
private:
    double precio;
    char *vendedor;
};

#endif /* ACTIVO_H */

