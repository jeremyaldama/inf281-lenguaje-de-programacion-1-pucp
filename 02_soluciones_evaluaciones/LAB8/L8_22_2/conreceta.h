/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   conreceta.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 9:54
 */

#ifndef CONRECETA_H
#define CONRECETA_H
#include "medicamento.h"

class conreceta: public medicamento {
public:
    conreceta();
    conreceta(const conreceta& orig);
    virtual ~conreceta();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char*) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void SetMedicamento(class medicamento &);
    void copia(const class conreceta&);
private:
    int codmed;
    char* especialidad;
};

#endif /* CONRECETA_H */

