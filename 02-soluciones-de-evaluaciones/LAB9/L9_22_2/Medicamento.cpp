/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Medicamento.cpp
 * Author: Danie
 * 
 * Created on 20 de junio de 2023, 18:55
 */

#include "Medicamento.h"

Medicamento::Medicamento() {
    codigo = 0;
    total = 0.0;
    nombre = nullptr;
}

Medicamento::~Medicamento() {
    if (nombre) delete nombre;
}

void Medicamento::SetTotal(double total) {
    this->total = total;
}

double Medicamento::GetTotal() const {
    return total;
}

void Medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Medicamento::GetFecha() const {
    return fecha;
}

void Medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double Medicamento::GetPrecio() const {
    return precio;
}

void Medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicamento::GetCantidad() const {
    return cantidad;
}

void Medicamento::SetNombre(const char* n) {
    if (nombre) delete nombre;
    nombre = new char[strlen(n) + 1];
    strcpy(nombre, n);
}

void Medicamento::GetNombre(char*n) const {
    if (!nombre) n[0] = 0;
    else strcpy(n, nombre);
}

void Medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamento::GetCodigo() const {
    return codigo;
}

void Medicamento::leemedicamento(int cod_medicamento, ifstream&arch) {
    int dd, mm, aa;
    char c;
    arch >> cantidad >> c >> dd >> c >> mm >> c >> aa >> c;
    cout << cantidad << " ";
    fecha = aa * 10000 + mm * 100 + dd;
    SetCodigo(cod_medicamento);
    
    char n[100];
    double precio = ObtenerNombrePrecio(cod_medicamento, n);
    SetPrecio(precio);
    SetNombre(n);
}

double Medicamento::ObtenerNombrePrecio(int cod_medicamento, char*n) {
    ifstream arch("medicamentos.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR medicamentos.csv";
        exit(1);
    }
    int codigo;
    double precio;
    char nombre[100], c;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch.get();
        arch.getline(nombre, 100, ',');
        arch >> precio;
        if (cod_medicamento == codigo) {
            strcpy(n, nombre);
            return precio;
        }
    }
}

void Medicamento::imprimedicamento(ofstream&arch) {
    int aa, dd, mm;
    aa = fecha / 10000;
    mm = (fecha / 100) % 100;
    dd = fecha % 100;

    arch << setprecision(2) << fixed;
    char n[100];
    GetNombre(n);
    arch << right << aa << '/' << setw(2) << setfill('0') << mm << '/' <<
            setw(2) << dd << setfill(' ') <<
            setw(7) << codigo << setw(2) << "" << left << setw(60) <<
            n << right << setw(2) << GetCantidad() << setw(7) << GetPrecio() <<
            setw(10) << GetTotal();
}

void Medicamento::aplicadescuento() {
    total = 0.9 * (cantidad * precio);
}