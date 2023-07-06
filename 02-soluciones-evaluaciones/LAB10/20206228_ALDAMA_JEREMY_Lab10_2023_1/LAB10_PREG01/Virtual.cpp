/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:05 AM
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0.0;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
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

void Virtual::lee(ifstream& arch) {
    Alumno::lee(arch);
    char lic[100];
    arch >> lic;
    total = 0.0;
    SetLicencia(lic);
}

void Virtual::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch << setw(15) << licencia << total << endl;;
}
