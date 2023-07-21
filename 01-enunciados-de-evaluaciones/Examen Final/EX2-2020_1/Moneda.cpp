/* 
 * Archivo:   Moneda.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:07 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Moneda.h"

Moneda::Moneda() {
    nombre = nullptr;
}

Moneda::Moneda(const Moneda& orig) {
    nombre = nullptr;
    *this = orig;
}

Moneda::~Moneda() {
    if (nombre != nullptr) delete []nombre;
}

void Moneda::SetNombre(const char* nomb) {
    if (nombre) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void Moneda::GetNombre(char* nomb) const {
    if (!nombre) nombre[0] = '\0';
    strcpy(nomb,nombre);
}

void Moneda::SetEquivalencia(double equivalencia) {
    this->equivalencia = equivalencia;
}

double Moneda::GetEquivalencia() const {
    return equivalencia;
}

void Moneda::SetSimbolo(char simbolo) {
    this->simbolo = simbolo;
}

char Moneda::GetSimbolo() const {
    return simbolo;
}

void Moneda::operator=(const Moneda& orig) {
    char nombre[60];
    orig.GetNombre(nombre);
    this->SetEquivalencia(orig.GetEquivalencia());
    this->SetSimbolo(orig.GetSimbolo());
    this->SetNombre(nombre);
}

ifstream& operator >> (ifstream& arch, Moneda &moneda) {
    char id, nombre[30];
    double eq;
    arch >> id;
    if (arch.eof()) return arch;
    arch.get();
    arch >> eq; arch.get();
    arch.getline(nombre,30,'\n');
    moneda.SetSimbolo(id);
    moneda.SetEquivalencia(eq);
    moneda.SetNombre(nombre);
}