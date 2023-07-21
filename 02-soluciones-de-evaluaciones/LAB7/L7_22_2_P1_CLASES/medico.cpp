/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Danie
 * 
 * Created on 9 de junio de 2023, 0:24
 */

#include <iostream>
#include "medico.h"
#include <cstring>
using namespace std;

medico::medico() {
    codigo = 0;
    tarifa = 0.0;
    nombre = nullptr;
}

medico::medico(const medico& orig) {
}

medico::~medico() {
}

void medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double medico::GetTarifa() const {
    return tarifa;
}

void medico::SetNombre(char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void medico::GetNombre(char*nom) const {
    if (nombre == nullptr) nom[0] = 0;
    else strcpy(nom, nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

ifstream& operator >> (ifstream&arch, medico &med) {
    int codigo;
    char nombre[100];
    double tarifa;
    arch >> codigo;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nombre, 100, ',');
    arch >> tarifa;
    med.SetCodigo(codigo);
    med.SetNombre(nombre);
    med.SetTarifa(tarifa);
    return arch;
}