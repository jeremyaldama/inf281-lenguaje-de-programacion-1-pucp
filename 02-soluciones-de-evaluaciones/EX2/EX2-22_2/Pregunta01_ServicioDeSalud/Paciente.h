/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.h
 * Author: Danie
 *
 * Created on 7 de julio de 2023, 22:10
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Paciente {
public:
    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    void leerPaciente(ifstream&arch);
    void operator = (const Paciente& orig);
    void imprimirPaciente(ofstream&arch);
    
    void setCodigoDelMedicoDeUltimaConsulta(const char* codigoDelMedicoDeUltimaConsulta);
    void getCodigoDelMedicoDeUltimaConsulta(char*cad) const;
    void setFechaUltimaConsulta(int fechaUltimaConsulta);
    int getFechaUltimaConsulta() const;
    void setNombre(const char* nombre);
    void getNombre(char *) const;
    void setDni(int dni);
    int getDni() const;
private:
    int dni;
    char *nombre;
    int fechaUltimaConsulta;
    char *codigoDelMedicoDeUltimaConsulta;
};

#endif /* PACIENTE_H */

