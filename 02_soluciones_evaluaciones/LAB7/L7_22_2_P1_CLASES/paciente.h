/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   paciente.h
 * Author: Danie
 *
 * Created on 9 de junio de 2023, 0:26
 */
#include "cita.h"

#ifndef PACIENTE_H
#define PACIENTE_H

class paciente {
public:
    paciente();
    paciente(const paciente& orig);
    virtual ~paciente();
private:
    int dni;
    char *nombre;
    cita lcitas[100];
    int telefono;
    double totalgastado;
};

#endif /* PACIENTE_H */

