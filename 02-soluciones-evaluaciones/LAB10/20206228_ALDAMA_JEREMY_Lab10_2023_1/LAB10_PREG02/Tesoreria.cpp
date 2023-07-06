/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: alulab14
 * 
 * Created on 30 de junio de 2023, 08:11 AM
 */

#include "Tesoreria.h"

void Tesoreria::abrirAbrirLectura(ifstream&arch, const char*nom) {
    arch.open(nom, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR " << nom;
        exit(1);
    }
}

void Tesoreria::abrirAbrirEscritura(ofstream&arch, const char*nom) {
    arch.open(nom, ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR " << nom;
        exit(1);
    }
}

void Tesoreria::cargaalumnos() {
    ifstream arch;
    abrirAbrirLectura(arch, "Alumnos.csv");
    
    aboleta.llenarArbol(arch);
}

void Tesoreria::imprimeboleta() {
    ofstream arch;
    abrirAbrirEscritura(arch, "ReporteBoleta.txt");
    aboleta.mostrarArbol(arch);
}

void Tesoreria::actualizaboleta() {
    ifstream arch;
    abrirAbrirLectura(arch, "escalas.csv");
    aboleta.cargarEscalas(arch);
    aboleta.actualizaTotal();
}
