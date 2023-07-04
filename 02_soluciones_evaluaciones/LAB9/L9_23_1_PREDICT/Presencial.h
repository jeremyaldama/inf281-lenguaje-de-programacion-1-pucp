/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 23:00
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno {
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void LeerAlumno(ifstream&);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

