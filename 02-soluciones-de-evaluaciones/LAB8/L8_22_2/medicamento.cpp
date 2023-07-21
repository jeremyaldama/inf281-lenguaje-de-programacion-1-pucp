/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 9:54
 */

#include "medicamento.h"

medicamento::medicamento() {
    cantidad = codigo = fecha = precio = 0;
    nombre = nullptr;
}

medicamento::medicamento(const medicamento& orig) {
}

medicamento::~medicamento() {
    if (nombre != nullptr) delete nombre;
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::SetNombre(char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void medicamento::GetNombre(char*n) const {
    if (nombre == nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

void medicamento::BuscarMedicamento(int medicamento) {
    ifstream arch("medicamentos.csv", ios::in);
    int cod;
    char nombre[100], c;
    double precio;
    while (1) {
        arch >> cod;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        arch >> precio;
        
        if (cod == medicamento) {
            SetCodigo(cod);
            SetPrecio(precio);
            SetNombre(nombre);
            break;
        }
    }
}
