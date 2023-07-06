/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Persona.h
 * Author: Danie
 *
 * Created on 25 de junio de 2023, 12:00
 */

#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Persona {
public:
    Persona();
    virtual ~Persona();
    void SetEdad(int edad);
    int GetEdad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
private:
    char *nombre;
    int edad;
};

#endif /* PERSONA_H */

