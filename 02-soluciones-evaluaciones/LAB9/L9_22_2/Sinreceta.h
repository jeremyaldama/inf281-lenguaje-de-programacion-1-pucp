/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Sinreceta.h
 * Author: Danie
 *
 * Created on 20 de junio de 2023, 19:03
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include "Medicamento.h"

class Sinreceta : public Medicamento{
public:
    Sinreceta();
    virtual ~Sinreceta();
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void leemedicamento(int cod_medicamento, ifstream&arch);
    void imprimedicamento(ofstream&arch);
    void aplicadescuento();
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

