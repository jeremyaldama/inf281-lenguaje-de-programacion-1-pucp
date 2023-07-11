/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:06 AM
 */

#include "Presencial.h"

Presencial::Presencial() {
    recargo = total = 0;
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::asignar(double recargo, int codigo, const char* nomb, 
        int escala) {
    SetCodigo(codigo);
    SetRecargo(recargo);
    SetNombre(nomb);
    SetEscala(escala);
}

void Presencial::imprimir(ofstream&arch) {
//    arch << left << setw(20) << "Codigo" << setw(60) << "Nombre" << setw(12) <<
//            "Escala" << setw(20) << "Licencia" << "Total" << endl;
    char n[100];
    GetNombre(n);
    arch << left << setw(20) << GetCodigo() << setw(60) << n << 
            setw(12) << GetEscala() << setw(20) << "" << Alumno::GetTotal() 
            << endl;
}
