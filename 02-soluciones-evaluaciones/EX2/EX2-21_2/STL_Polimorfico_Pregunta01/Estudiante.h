/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estudiante.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:30
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Usuario.h"

class Estudiante : public Usuario {
public:
    Estudiante();
    Estudiante(const Estudiante& orig);
    virtual ~Estudiante();
    void SetCelular(int celular);
    int GetCelular() const;
    void leer(ifstream&arch);
private:
    int celular;
};

#endif /* ESTUDIANTE_H */

