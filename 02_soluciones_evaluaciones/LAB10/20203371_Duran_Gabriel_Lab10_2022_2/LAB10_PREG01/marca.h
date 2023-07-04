/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   marca.h
 * Author: alulab14
 *
 * Created on 25 de noviembre de 2022, 08:07 AM
 */

#ifndef MARCA_H
#define MARCA_H

#include "medicamento.h"


class marca : public medicamento{
public:
    marca();
    virtual ~marca();
    void SetLaboratorio(char* laboratorio);
    void GetLaboratorio(char* cad) const;
    void SetLote(int lote);
    int GetLote() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
private:
    int lote;
    char *laboratorio;
};

#endif /* MARCA_H */

