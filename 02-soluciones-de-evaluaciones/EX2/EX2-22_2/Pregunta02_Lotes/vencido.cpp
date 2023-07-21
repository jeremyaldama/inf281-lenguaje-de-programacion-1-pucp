/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vencido.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 12:12
 */

#include "vencido.h"

vencido::vencido() {
    inspector = nullptr;
}

vencido::vencido(const vencido& orig) {
}

vencido::~vencido() {
    if (inspector) delete inspector;
}

void vencido::SetInspector(const char* cad) {
    if (inspector) delete inspector;
    inspector = new char[strlen(cad) + 1];
    strcpy(inspector, cad);
}

void vencido::GetInspector(char *cad) const {
    if (inspector) strcpy(cad, inspector);
    else cad[0] = 0;
}

void vencido::SetFechabaja(int fechabaja) {
    this->fechabaja = fechabaja;
}

int vencido::GetFechabaja() const {
    return fechabaja;
}

void vencido::lee(ifstream& arch, const char* inspector, int fecha_baja) {
    medicamento::lee(arch, inspector, fecha_baja);
    char c, cad[100];
    double precio;
    arch.getline(cad, 100, ',');
    SetInspector(inspector);
    arch >> precio;
    fechabaja = fecha_baja;
}

void vencido::imprime(ofstream& arch) {
    medicamento::imprime(arch);
    arch << left << setw(20) << inspector << right << setw(12) <<
            fechabaja << endl;
}

void vencido::registrarDatos(const medicamento& med, int fecha, 
        const char* inspector) {
    medicamento::registrarDatos(med, fecha, inspector);
    fechabaja = fecha;
    SetInspector(inspector);
}