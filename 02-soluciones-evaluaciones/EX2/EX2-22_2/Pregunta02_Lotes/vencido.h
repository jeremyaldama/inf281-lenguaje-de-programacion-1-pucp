/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vencido.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:12
 */

#ifndef VENCIDO_H
#define VENCIDO_H
#include "medicamento.h"

class vencido : public medicamento {
public:
    vencido();
    vencido(const vencido& orig);
    virtual ~vencido();
    void SetInspector(const char* inspector);
    void GetInspector(char*) const;
    void SetFechabaja(int fechabaja);
    int GetFechabaja() const;
    
    void lee(ifstream&arch, const char*cad, int);
    void imprime(ofstream&arch);
    void registrarDatos(const medicamento&med, int fecha, const char*inspector);
private:
    int fechabaja; // fecha de revision de los lotes y se pasan los med. de activos a vencidos
    char* inspector; // nombre del inspector que da de baja el medicamento
};

#endif /* VENCIDO_H */

