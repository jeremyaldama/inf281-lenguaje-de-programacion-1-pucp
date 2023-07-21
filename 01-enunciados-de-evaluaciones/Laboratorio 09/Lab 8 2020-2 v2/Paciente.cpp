/* 
 * Archivo:   Paciente.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 10:54 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"

Paciente::Paciente() {
    nombre = nullptr;
    codMed = nullptr;
    dni = -1;
}

Paciente::Paciente(const Paciente& orig) {
    nombre = nullptr;
    codMed = nullptr;
    dni = -1;
    *this = orig;
}

Paciente::~Paciente() {
    if (nombre != nullptr) delete []nombre;
    if (codMed != nullptr) delete []codMed;
}

void Paciente::SetCodMed(const char* codM) {
    if (codMed) delete []codMed;
    codMed = new char [strlen(codM)+1];
    strcpy(codMed,codM);
}

void Paciente::GetCodMed(char* codM) const {
    if (!codMed) codMed[0] = '\0';
    strcpy(codM,codMed);
}

void Paciente::SetNombre(const char* nomb) {
    if (nombre) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Paciente::GetNombre(char* nomb) const {
    if (!nombre) nombre[0] = '\0';
    strcpy(nomb,nombre);
}

void Paciente::SetDni(int dni) {
    this->dni = dni;
}

int Paciente::GetDni() const {
    return dni;
}

void Paciente::operator=(const Paciente& paciente) {
    char nomb[60], codM[10];
    paciente.GetCodMed(codM);
    paciente.GetNombre(nomb);
    this->SetDni(paciente.GetDni());
    this->SetNombre(nomb);
    this->SetCodMed(codM);
}