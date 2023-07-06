/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   alumnonota.h
 * Author: Danie
 *
 * Created on 11 de junio de 2023, 12:14
 */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "nota.h"

#ifndef ALUMNONOTA_H
#define ALUMNONOTA_H

class alumnonota {
public:
    alumnonota();
    alumnonota(const alumnonota& orig);
    virtual ~alumnonota();
    void SetNota(int nota);
    int GetNota() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetCodcurso(char* codcurso);
    void GetCodcurso(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator &(class nota&);
private:
    int codigo;
    char *codcurso;
    int ciclo;
    int nota;
};

ifstream& operator >>(ifstream&, alumnonota&);

#endif /* ALUMNONOTA_H */

