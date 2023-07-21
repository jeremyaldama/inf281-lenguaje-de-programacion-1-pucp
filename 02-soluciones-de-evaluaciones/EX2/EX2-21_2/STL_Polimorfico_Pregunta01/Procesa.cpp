/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:34
 */

#include "Procesa.h"

Procesa::Procesa() {
}

Procesa::Procesa(const Procesa& orig) {
}

Procesa::~Procesa() {
}

void Procesa::abrirArchivoEscritura(ofstream& arch, const char* cad) {
    arch.open(cad, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << cad;
        exit(1);
    }
}

void Procesa::abrirArchivoLectura(ifstream& arch, const char* cad) {
    arch.open(cad, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << cad;
        exit(1);
    }
}

void Procesa::carga() {
    CargaLibros();
    CargaUsuarios();
    LeeSolicitudes();
}

void Procesa::CargaLibros() {
    ifstream arch;
    abrirArchivoLectura(arch, "Libros2.csv");
    
    class Libro lib;
    
    while (true) {
        lib.leelibros(arch);
        if (arch.eof()) break;
        llibros.push_back(lib);
    }
}

void Procesa::CargaUsuarios() {
    ifstream arch;
    abrirArchivoLectura(arch, "Usuarios2.csv");
    
    NUsuario nUsuario;
    
    while (true) {
        nUsuario.leerUsuario(arch);
        if (arch.eof()) break;
        vusuarios.push_back(nUsuario);
    }
}

void Procesa::LeeSolicitudes() {
    ifstream arch;
    abrirArchivoLectura(arch, "SolicitudDePrestamos2.csv");
    
    cola.llenarCola(arch);
}

void Procesa::Imprime() {
    ImprimeCola();
    ImprimeLibros();
}

void Procesa::ImprimeCola() {
    ofstream arch;
    abrirArchivoEscritura(arch, "ReporteCola.txt");
    
    cola.mostrarCola(arch);
}

void Procesa::Atiende() {
    cola.atiende(llibros);
}

void Procesa::ImprimeLibros() {
    ofstream arch;
    abrirArchivoEscritura(arch, "ReporteLibros.txt");
    for (int i=0; i<llibros.size(); i++) {
        llibros[i].imprimelibro(arch);
    }
}
