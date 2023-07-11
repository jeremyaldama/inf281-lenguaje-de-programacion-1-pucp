/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:09 AM
 */

#include "Virtual.h"

Virtual::Virtual() {
    total = 100;
    licencia = nullptr;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
    if (licencia != nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* n) {
    if (licencia != nullptr) delete licencia;
    licencia = new char[strlen(n) + 1];
    strcpy(licencia, n);
}

void Virtual::GetLicencia(char *n) const {
    if (licencia == nullptr) n[0] = 0;
    else strcpy(n, licencia);
}

void Virtual::asignar(const char *lic, int codigo, const char* nomb,
        int escala) {
    SetCodigo(codigo);
    SetLicencia(lic);
    SetNombre(nomb);
    SetEscala(escala);
}

void Virtual::imprimir(ofstream&arch) {
    char n[100];
    GetNombre(n);
    arch << left << setw(20) << GetCodigo() << setw(58) << n <<
            setw(10) << GetEscala() << setw(19);
    GetLicencia(n);
    arch << n << Alumno::GetTotal() << endl;
}
