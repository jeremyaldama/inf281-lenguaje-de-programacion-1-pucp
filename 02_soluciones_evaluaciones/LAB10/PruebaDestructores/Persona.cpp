/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Persona.cpp
 * Author: Danie
 * 
 * Created on 25 de junio de 2023, 12:00
 */

#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

Persona::~Persona() {
//    if (nombre) delete nombre;
    nombre = new char[10];
    strcpy(nombre, "borrao");
    static int i = 0;
    cout << "eliminado " << i++ << endl;
}

void Persona::SetEdad(int edad) {
    this->edad = edad;
}

int Persona::GetEdad() const {
    return edad;
}

void Persona::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Persona::GetNombre(char *n) const {
    if (nombre) strcpy(n, nombre);
    else n[0] = 0;
}

