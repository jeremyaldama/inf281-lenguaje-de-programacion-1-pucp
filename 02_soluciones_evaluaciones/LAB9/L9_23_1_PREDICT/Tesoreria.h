/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 23:06
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Alumno.h"
#include "Escala.h"

class Tesoreria {
public:
    Tesoreria();
    virtual ~Tesoreria();
    void leerAlumno(ifstream&arch, char modalidad);
private:
    class Alumno *pTesoreria;
};

#endif /* TESORERIA_H */

