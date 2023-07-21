/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 17:43
 */

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::abrirArchivoEscritura(ofstream& arch, const char* cad) {
    arch.open(cad, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << cad;
        exit(1);
    }
}

void Biblioteca::abrirArchivoLectura(ifstream& arch, const char* cad) {
    arch.open(cad, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << cad;
        exit(1);
    }
}

void Biblioteca::leeLibros(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    
    Libro lib;
    
    while (true) {
        lib.leeDatos(arch);
        if (arch.eof()) break;
        libros.push_back(lib);
    }
}

void Biblioteca::imprimeLibros(const char* cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);
    for (int i=0; i<libros.size(); i++) {
        libros[i].imprimeDatos(arch);
    }
}

void Biblioteca::leerUsuarios(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    RegistroUsuario regUsuario;
    while (true) {
        regUsuario.leerUsuario(arch);
        if (arch.eof()) break;
        usuarios.push_back(regUsuario);
    }
}

void Biblioteca::leerPrestamos(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    
    int carne, i;
    char cod[100];
    while (true) {
        arch >> carne;
        if (arch.eof()) break;
        i = buscarUsuario(carne);
        arch.get();
        arch.get();
        
        usuarios[i].leerPrestamo(arch);  
        usuarios[i].obtenerCodigoUltimoPrestamo(cod);
        actualizarPrestados(cod);
        
//        usuarios[i].leerPrestamo(arch, libros);
    }
}

int Biblioteca::buscarUsuario(int carne) {
    for (int i=0; i<usuarios.size(); i++)
        if (usuarios[i].obtenerCodigo() == carne) return i;
    return -1;
}


void Biblioteca::imprimeUsuarios(const char* cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);
    
    for (int i = 0; i<usuarios.size(); i++) {
        usuarios[i].imprimirUsuarioPrestamos(arch);
    }
}

void Biblioteca::actualizarPrestados(const char* cad) {
    char cod[100];
    for (int i=0; i<libros.size(); i++) {
        libros[i].GetCodigo(cod);
        if (strcmp(cod, cad)==0) libros[i].SetPrestados(
                libros[i].GetPrestados()+1);
    }
}

void Biblioteca::imprimeSuspendidos(const char* nom, int dd, int mm, int aa) {
    ofstream arch;
    abrirArchivoEscritura(arch, nom);
    int fecha = dd+mm*100+aa*10000;
    for (int i=0; i<usuarios.size(); i++) {
        usuarios[i].imprimirSuspendido(arch, fecha);
    }
}
