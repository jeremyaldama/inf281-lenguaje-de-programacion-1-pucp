/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 11:46
 */

#include "Biblioteca.h"

void Biblioteca::abrirArchivoLectura(ifstream&arch, const char*nomb) {
    arch.open(nomb, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << nomb;
        exit(1);
    }
}

void Biblioteca::abrirArchivoEscritura(ofstream&arch, const char*nomb) {
    arch.open(nomb, ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << nomb;
        exit(1);
    }
}

void Biblioteca::LeerLibros() {
    ifstream arch;
    abrirArchivoLectura(arch, "Libros.csv");
    
    AStock.crear(arch);
}

void Biblioteca::ImprimeLibros() {
    ofstream arch;
    abrirArchivoEscritura(arch, "Reporte.txt");
    
    AStock.mostrarEnOrden(arch);
}

void Biblioteca::ActualizaLibros() {
    ifstream arch;
    abrirArchivoLectura(arch, "RegistroDePrestamos.csv");
    
    char cad[100], c;
    int dd, mm, aa;
    
    while (1) {
        arch.getline(cad, 100, ',');
        if (arch.eof()) break;
        arch.getline(cad, 100, ',');
        arch >> dd >> c >> mm >> c >> aa;
        arch.get();
        AStock.actualiza(cad);
    }
}