/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Universidad.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 23:09
 */

#include "Universidad.h"

void Universidad::abrirArchivoLectura(ifstream&arch, const char*nomb) {
    arch.open(nomb, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir " << nomb;
        exit(1);
    }
}

void Universidad::cargaEscalas() {
    ifstream arch;
    abrirArchivoLectura(arch, "escalas.csv");
    int escala, i = 0;
    while (1) {
        arch >> escala;
        if (arch.eof()) break;
        cargaEscala(arch, escala, i++);
    }
}

void Universidad::cargaEscala(ifstream&arch, int escala, int i) {
    arch.get();
    double precio;
    arch >> precio;
    lescala[i].SetCodigo(escala);
    lescala[i].SetPrecio(precio);
}

void Universidad::cargaAlumnos() {
    ifstream arch;
    abrirArchivoLectura(arch, "alumnos.csv");
    int i = 0;
    char modalidad, c;
    while (1) {
        arch >> modalidad;
        if (arch.eof()) break;
        arch >> c;
        ltesoreria[i++].leerAlumno(arch, modalidad);
    }
}

