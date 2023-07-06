/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   sinreceta.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 9:56
 */

#include "sinreceta.h"

sinreceta::sinreceta() {
    dni = 0;
    nombre = nullptr;
}

sinreceta::sinreceta(const sinreceta& orig) {
}

sinreceta::~sinreceta() {
    delete nombre;
}

void sinreceta::SetNombre(char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void sinreceta::GetNombre(char*n) const {
    if (nombre == nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int sinreceta::GetDni() const {
    return dni;
}

void sinreceta::SetMedicamento(const class medicamento&medicamento) {
//     codigo;
//    char* nombre;
//    int cantidad;
//    double precio;
//    // aaaammdd 
//    int fecha;
    SetCodigo(medicamento.GetCodigo());
    char n[100];
    medicamento.GetNombre(n);
    medicamento::SetNombre(n);
    
    SetCantidad(medicamento.GetCantidad());
    SetPrecio(medicamento.GetPrecio());
    SetFecha(medicamento.GetFecha());
}

void sinreceta::copia(const class sinreceta&sinreceta) {
    
    // FALTA ESPECIALIDAD
    SetCantidad(sinreceta.GetCantidad());
    SetCodigo(sinreceta.GetCodigo());
    SetDni(sinreceta.GetDni());
    SetFecha(sinreceta.GetFecha());
    SetPrecio(sinreceta.GetPrecio());
    char n[100];
    sinreceta.GetNombre(n);
    cout << n << endl;
    SetNombre(n);
    
    sinreceta.medicamento::GetNombre(n);
    medicamento::SetNombre(n);
}