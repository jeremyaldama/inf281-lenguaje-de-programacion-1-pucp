/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   generico.h
 * Author: alulab14
 *
 * Created on 25 de noviembre de 2022, 08:05 AM
 */

#ifndef GENERICO_H
#define GENERICO_H

#include "medicamento.h"


class generico : public medicamento{
public:
    generico();
    virtual ~generico();
    void SetPais(char* pais);
    void GetPais(char* cad) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    char *pais;
};

#endif /* GENERICO_H */

