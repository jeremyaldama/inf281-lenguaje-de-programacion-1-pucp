/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:24
 */

#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
// Es probable que esta clase nos la den implementada
class Curso {
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetProfesor(const char* profesor);
    void GetProfesor(char*) const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    void leer(ifstream& arch);
    void operator=(const Curso& cur);
private:
    char* codigo;
    char* nombre;
    char* profesor;
    double creditos;
};

#endif /* CURSO_H */

