/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:17
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#define MAX_CAR_LIN 62
using namespace std;

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetPorcentaje(int porcentaje);
    int GetPorcentaje() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetModalidad(char modalidad);
    char GetModalidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* ) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void leer(ifstream& arch);
    void imprimir(ofstream&arch);
    void operator=(const Alumno&alu);
    void imprimirLinea(ofstream&arch, char c, int n);
private:
    int codigo;
    char* nombre;
    char modalidad;
    int escala;
    int porcentaje; // si tiene
};

#endif /* ALUMNO_H */

