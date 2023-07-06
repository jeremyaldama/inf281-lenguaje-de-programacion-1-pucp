/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 9:53
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#ifndef MEDICO_H
#define MEDICO_H

class medico {
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetEspecialidad(char* especialidad);
    void GetEspecialidad(char*) const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void LeeMedico(ifstream&);
    void CopiaMedico(const class medico &);
private:
    int codigo;
    char *nombre;
    char *especialidad;
};

#endif /* MEDICO_H */

