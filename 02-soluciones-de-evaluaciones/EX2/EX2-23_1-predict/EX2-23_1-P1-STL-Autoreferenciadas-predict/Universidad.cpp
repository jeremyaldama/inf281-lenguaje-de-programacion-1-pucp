/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Universidad.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:43
 */

#include "Universidad.h"

Universidad::Universidad() {
}

Universidad::Universidad(const Universidad& orig) {
}

Universidad::~Universidad() {
}

void Universidad::abrirArchivoEscritura(ofstream& arch, const char* cad) {
    arch.open(cad, ios::out);
    
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void Universidad::abrirArchivoLectura(ifstream& arch, const char* cad) {
    arch.open(cad, ios::in);
    
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void Universidad::leerCursos(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    
    Curso curso;
    while (true) {
        curso.leer(arch);
        if (arch.eof()) break;
//        cout << curso.GetCreditos() << endl;
        cursos.push_back(curso);
    }
}

void Universidad::leerEscalas(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    
    Escala escala;
    while (true) {
        escala.leer(arch);
        if (arch.eof()) break;
        escalas.push_back(escala);
    }
    cout << escalas.size() << endl;
    for (int i=0; i<escalas.size(); i++) {
//        cout << escalas[i].GetCodigo() << endl;
    }
}

void Universidad::leerAlumnos(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    
    alumnos.cargarAlumnos(arch);
}

void Universidad::mostrarAlumnos(const char* cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);
    arch << setprecision(2) << fixed;
    alumnos.mostrarLista(arch);
}

void Universidad::cargarNotas(const char* cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    
    alumnos.cargarNotas(arch);
}

void Universidad::actualizarCostoCurso() {
    alumnos.actualizarCostos(cursos, escalas);
}
