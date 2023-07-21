/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   nota.h
 * Author: Danie
 *
 * Created on 11 de junio de 2023, 12:19
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef NOTA_H
#define NOTA_H

class nota {
public:
    nota();
    nota(const class nota& orig);
    virtual ~nota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcurso(char* codcurso);
    void GetCodcurso(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    char *codcurso;
    int ciclo;
    int notaa;
};

#endif /* NOTA_H */

