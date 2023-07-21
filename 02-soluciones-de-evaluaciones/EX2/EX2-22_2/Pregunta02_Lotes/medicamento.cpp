/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 12:05
 */

#include "medicamento.h"

medicamento::medicamento() {
    nombre = nullptr;
}

medicamento::medicamento(const medicamento& orig) {
}

medicamento::~medicamento() {
    cout << "SE LIBERA MEDICAMENTO" << endl;
    if (nombre) delete nombre;
}

void medicamento::SetEstado(int estado) {
    this->estado = estado;
}

int medicamento::GetEstado() const {
    return estado;
}

void medicamento::SetFechavenc(int fechavenc) {
    this->fechavenc = fechavenc;
}

int medicamento::GetFechavenc() const {
    return fechavenc;
}

void medicamento::SetStock(int stock) {
    this->stock = stock;
}

int medicamento::GetStock() const {
    return stock;
}

void medicamento::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void medicamento::GetNombre(char* cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

void medicamento::lee(ifstream&arch, const char*inspector, int fecha_baja) {
    char c, cad[100];
    
    arch >> codigo >> c;
    arch.getline(cad, 100, ',');
    SetNombre(cad);
    arch >> stock >> c;
}

void medicamento::imprime(ofstream& arch) {
    arch << left << setw(10) << fechavenc << setw(10) << codigo << 
            setw(50) << nombre << setw(10) << stock;    
}

void medicamento::registrarDatos(const medicamento& med, int, 
        const char* inspector) {
    codigo = med.codigo;
    estado = 0;
    fechavenc = med.fechavenc;
    SetNombre(med.nombre);
    stock = med.stock;
}
