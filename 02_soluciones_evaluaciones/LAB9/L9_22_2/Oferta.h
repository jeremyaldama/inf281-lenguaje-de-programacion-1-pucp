/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Oferta.h
 * Author: Danie
 *
 * Created on 20 de junio de 2023, 19:05
 */

#ifndef OFERTA_H
#define OFERTA_H
#include "Medicamento.h"
#include "Conreceta.h"
#include "Sinreceta.h"

class Oferta {
public:
    Oferta();
    virtual ~Oferta();
    void AsignaMedicamento(int cod_med, ifstream&arch);
    void imprimeMedicamento(ofstream&arch);
    void aplicaDescuento();
    int fin();
private:
    class Medicamento *poferta;
};

#endif /* OFERTA_H */

