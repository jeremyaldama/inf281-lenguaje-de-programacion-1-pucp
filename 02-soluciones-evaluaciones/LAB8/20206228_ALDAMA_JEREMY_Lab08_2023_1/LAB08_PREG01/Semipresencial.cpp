/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:08 AM
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    descuento = total = 0;
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::asignar(double desc, int codigo, const char* nomb, 
        int escala) {
    SetCodigo(codigo);
    SetDescuento(desc);
    SetNombre(nomb);
    SetEscala(escala);
}

void Semipresencial::imprimir(ofstream&arch) {
    char n[100];
    GetNombre(n);
    arch << left << setw(20) << GetCodigo() << setw(60) << n << 
            setw(12) << GetEscala() << setw(20) << "" << Alumno::GetTotal() 
            << endl;
}
