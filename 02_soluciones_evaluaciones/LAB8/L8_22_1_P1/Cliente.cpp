/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 22:59
 */

#include "Cliente.h"

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    if (nombre != nullptr) delete nombre;
}

void Cliente::SetNombre(char* nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char*n) const {
    if (nombre== nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

