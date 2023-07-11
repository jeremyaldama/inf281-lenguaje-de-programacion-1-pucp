/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: alulab14
 * 
 * Created on 23 de junio de 2023, 08:06 AM
 */

#include "Tesoreria.h"

void Tesoreria::abrirArchivoLectura(ifstream&arch, const char*nomb) {
    arch.open(nomb, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << nomb;
        exit(1);
    }
}

void Tesoreria::abrirArchivoEscritura(ofstream&arch, const char*cad) {
    arch.open(cad, ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}


void Tesoreria::cargaescalas() {
    ifstream arch;
    abrirArchivoLectura(arch, "escalas.csv");
    
    int codigo, i = 0;
    double valor;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch.get();
        arch >> valor;
        lescala[i].SetCodigo(codigo);
        lescala[i++].SetPrecio(valor);
    }
}

void Tesoreria::cargaalumnos() {
    ifstream arch;
    abrirArchivoLectura(arch, "Alumnos.csv");
    
    int i = 0;
    char tipo, c;
    while (1) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        lboleta[i++].lee(arch, tipo);
    }
}

void Tesoreria::imprimeboleta() {
    ofstream arch;
    
    arch << setprecision(2) << fixed;
    abrirArchivoEscritura(arch, "ReporteBoleta.txt");
    arch << left << setw(15) << "Codigo" << setw(58) << "Nombre" << setw(12) <<
            "Escala" << setw(12) << "Cred." << setw(16) << "Licencia" << 
            "Total" << endl;
    imprimeLinea(arch, '=', 120);
    for (int i = 0; !lboleta[i].fin(); i++) {
        lboleta[i].imprime(arch);
    }
}

void Tesoreria::imprimeLinea(ofstream&arch, char c, int n) {
    for (int i = 0; i < n; i++) {
        arch << c;
    }
    arch << endl;
}

