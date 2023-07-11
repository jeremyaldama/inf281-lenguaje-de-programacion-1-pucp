/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.h
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:03 AM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno {
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void lee(ifstream&);
    void setTotal(double total);
    double getTotal() const;
    void setLicencia(const char* licencia);
    void getLicencia(char*) const;
    void imprime(ofstream&);
    void actualizatotal(double);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

