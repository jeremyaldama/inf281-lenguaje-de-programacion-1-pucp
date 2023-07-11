/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Promociones.cpp
 * Author: Danie
 * 
 * Created on 25 de junio de 2023, 0:05
 */

#include "Promociones.h"

void Promociones::abrirArchivoLectura(ifstream& arch, const char*cad) {
    arch.open(cad, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void Promociones::leepedidos() {
    ifstream arch;
    abrirArchivoLectura(arch, "pedidos5.csv");
    Lpedidos.crearLista(arch);
}

void Promociones::imprimepedidos() {
    ofstream arch;
    abrirArchivoEscritura(arch, "Reporte.txt");
    
    Lpedidos.mostrarLista(arch);
}

void Promociones::abrirArchivoEscritura(ofstream&arch, const char*nom) {
    arch.open(nom, ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << nom;
        exit(1);
    }
}

void Promociones::actualizapedidos() {
    ifstream arch;
    abrirArchivoLectura(arch, "promocion.csv");
    
    int cod, dd, mm, aa, fecha;
    char c;
    while (1) {
        arch >> cod;
        if (arch.eof()) break;
        arch >> c >> dd >> c >> mm >> c >> aa;
        fecha = dd + mm*100 + aa*10000;
        cout << fecha << endl;
        Lpedidos.actualiza(cod, fecha);
    }
}