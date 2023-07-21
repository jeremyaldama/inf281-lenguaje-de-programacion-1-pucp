/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrativo.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:26
 */

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Usuario.h"

class Administrativo : public Usuario {
public:
    Administrativo();
    Administrativo(const Administrativo& orig);
    virtual ~Administrativo();
    void SetArea(const char* area);
    void GetArea(char*) const;
    void leer(ifstream&arch);
private:
    char* area;
};

#endif /* ADMINISTRATIVO_H */

