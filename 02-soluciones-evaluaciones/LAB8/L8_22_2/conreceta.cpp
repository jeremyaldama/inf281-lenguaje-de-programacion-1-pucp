/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conreceta.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 9:54
 */

#include "conreceta.h"

conreceta::conreceta() {
    codmed = 0;
    especialidad = nullptr;
}

conreceta::conreceta(const conreceta& orig) {
}

conreceta::~conreceta() {
    delete especialidad;
}

void conreceta::SetEspecialidad(char* especialidad) {
    if (this->especialidad != nullptr) delete this->especialidad;
    this->especialidad = new char[strlen(especialidad)+1];
    strcpy(this->especialidad, especialidad);
}

void conreceta::GetEspecialidad(char*e) const {
    if (especialidad == nullptr) e[0] = 0;
    else strcpy(e, especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}


void conreceta::SetMedicamento(class medicamento &medicamento) {
//    nt codigo;
//    char* nombre;
//    int cantidad;
//    double precio;
//    // aaaammdd 
//    int fecha;
    SetCodigo(medicamento.GetCodigo());
    char n[100];
    medicamento.GetNombre(n);
    // aca es lo mismo si ponemos el ámbito medicamento o no
    // porque no hay dos SetNombre
    medicamento::SetNombre(n);
    
    SetCantidad(medicamento.GetCantidad());
    SetPrecio(medicamento.GetPrecio());
    SetFecha(medicamento.GetFecha());
}

void conreceta::copia(const class conreceta&conreceta) {
    SetCodmed(conreceta.GetCodmed());
    // FALTA ESPECIALIDAD
    SetCantidad(conreceta.GetCantidad());
    SetCodigo(conreceta.GetCodigo());
    SetCodmed(conreceta.GetCodmed());
    SetFecha(conreceta.GetFecha());
    char n[100];
    conreceta.GetNombre(n);
    SetNombre(n);
    SetPrecio(conreceta.GetPrecio());
    conreceta.GetEspecialidad(n);
    SetEspecialidad(n);
}