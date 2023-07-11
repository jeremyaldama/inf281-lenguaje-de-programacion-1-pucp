/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 12:18
 */

#include "almacen.h"

almacen::almacen() {
}

almacen::almacen(const almacen& orig) {
}

almacen::~almacen() {
}

void almacen::abrirArchivoEscritura(ofstream& arch, const char* cad) {
    arch.open(cad, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void almacen::abrirArchivoLectura(ifstream& arch, const char* cad) {
    arch.open(cad, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void almacen::carga(int fecha_actual, const char*inspector) {
    ifstream arch;
    abrirArchivoLectura(arch, "lotes.csv");
    
    arbolalma.cargarArbol(arch, fecha_actual, inspector);
}

void almacen::imprime() {
    ofstream arch;
    abrirArchivoEscritura(arch, "ReporteAlmacen.txt");
    
    arbolalma.mostrarArbol(arch);
}

void almacen::actualiza(int fecha, const char* apellido) {
    arbolalma.actualizar(fecha, apellido);
}
