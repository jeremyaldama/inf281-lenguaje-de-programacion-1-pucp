/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 9:53
 */

#include "medico.h"

medico::medico() {
    codigo = 0;
    especialidad = nombre = nullptr;
}

medico::medico(const medico& orig) {
}

medico::~medico() {
    if (especialidad != nullptr) delete especialidad;
    if (nombre != nullptr) delete nombre;
}

void medico::SetEspecialidad(char* especialidad) {
    if (this->especialidad!=nullptr) delete this->especialidad;
    this->especialidad = new char[strlen(especialidad)+1];
    strcpy(this->especialidad, especialidad);
}

void medico::GetEspecialidad(char *n) const {
    if (especialidad == nullptr) n[0] = 0;
    else strcpy(n, especialidad);
}

void medico::SetNombre(char* n) {
    if (nombre!=nullptr) delete nombre;
    nombre = new char[strlen(n)+1];
    strcpy(nombre, n);
    
}

void medico::GetNombre(char *n) const {
    if (nombre != nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

void medico::LeeMedico(ifstream&arch) {
    int codigo;
    arch >> codigo;
    if (arch.eof()) return;
    char nombre[100], especialidad[100], c;
    arch >> c;
    arch.getline(nombre, 100, ',');
    arch >> especialidad;
    SetCodigo(codigo);
    SetEspecialidad(especialidad);
    SetNombre(nombre);
}

void medico::CopiaMedico(const class medico &med) {
    SetCodigo(med.GetCodigo());
    char esp[100];
    med.GetEspecialidad(esp);
    SetEspecialidad(esp);
    char nom[100];
    med.GetNombre(nom);
    SetNombre(nom);
}