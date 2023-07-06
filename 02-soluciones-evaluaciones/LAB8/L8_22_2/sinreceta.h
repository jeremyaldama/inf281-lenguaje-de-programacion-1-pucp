/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   sinreceta.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 9:56
 */

#ifndef SINRECETA_H
#define SINRECETA_H
#include "medicamento.h"

class sinreceta: public medicamento {
public:
    sinreceta();
    sinreceta(const sinreceta& orig);
    virtual ~sinreceta();
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void SetMedicamento(const class medicamento&);
    void copia(const class sinreceta&);
private:
    // datos del paciente
    int dni;
    char* nombre;
};

#endif /* SINRECETA_H */

