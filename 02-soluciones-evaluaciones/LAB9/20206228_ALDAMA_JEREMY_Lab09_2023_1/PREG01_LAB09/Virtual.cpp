/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:03 AM
 */

#include "Virtual.h"
#include "Alumno.h"

Virtual::Virtual() {
    total = 0.0;
    licencia = nullptr;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
    if (licencia) delete licencia;
}

void Virtual::lee(ifstream&arch) {
    Alumno::lee(arch);
    char lic[100];
    arch >> lic;
    setLicencia(lic);
}

void Virtual::setTotal(double total) {
    this->total = total;
}

double Virtual::getTotal() const {
    return total;
}

void Virtual::setLicencia(const char* cad) {
    if (licencia) delete licencia;
    licencia = new char[strlen(cad)+1];
    strcpy(licencia, cad);
}

void Virtual::getLicencia(char*cad) const {
    if (licencia) strcpy(cad, licencia);
    else cad[0] = 0;
}

void Virtual::imprime(ofstream&arch) {
    Alumno::imprime(arch);
    char cad[100];
    getLicencia(cad);
    arch << setw(12) << cad << right << setw(10) << Alumno::GetTotal() << endl;
}
