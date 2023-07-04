/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 23:02
 */

#include "Virtual.h"

Virtual::Virtual() {
    total = 100.0;
    licencia = nullptr;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
    if (licencia) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if (licencia) delete licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia, cad);
}

void Virtual::GetLicencia(char*cad) const {
    if (licencia) strcpy(cad, licencia);
    else cad[0] = 0;
}

void Virtual::LeerAlumno(ifstream&arch) {
    Alumno::LeerAlumno(arch);
    char lic[100];
    arch.getline(lic, 100, ',');
    int escala;
    arch >> escala;
    SetLicencia(lic);
    SetEscala(escala);
}