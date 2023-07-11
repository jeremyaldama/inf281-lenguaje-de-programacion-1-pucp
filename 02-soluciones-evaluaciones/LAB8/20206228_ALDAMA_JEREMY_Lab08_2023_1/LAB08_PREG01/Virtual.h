/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: alulab14
 *
 * Created on 16 de junio de 2023, 08:09 AM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno{
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char *) const;
    void asignar(const char*, int, const char*, int);
    void imprimir(ofstream&);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

