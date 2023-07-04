/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Conreceta.h
 * Author: Danie
 *
 * Created on 20 de junio de 2023, 18:57
 */

#ifndef CONRECETA_H
#define CONRECETA_H 
#include "Medicamento.h"
 
class Conreceta : public Medicamento{
public:
    Conreceta();
    virtual ~Conreceta();
    void SetEspecialidad(const char* especialidad);
    void GetEspecialidad(char*) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void leemedicamento(int cod_medicamento, ifstream&arch);
    void ObtenerEspecialidad(int, char*);
    void imprimedicamento(ofstream&arch);
    void aplicadescuento();
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

