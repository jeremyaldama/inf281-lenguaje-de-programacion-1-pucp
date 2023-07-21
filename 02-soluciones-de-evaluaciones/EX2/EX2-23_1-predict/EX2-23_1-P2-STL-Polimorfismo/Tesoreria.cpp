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

    Nodo nodo;
    while (true) {
        nodo.leer(arch);
        if (arch.eof()) break;
        vectorBoleta.push_back(nodo);
    }
}

void Tesoreria::imprimeboleta() {
    ofstream arch;
    abrirAbrirEscritura(arch, "ReporteBoleta.txt");

    for (int i = 0; i < vectorBoleta.size(); i++) {
        vectorBoleta[i].imprimir(arch);
    }
}

void Tesoreria::actualizaboleta() {
    ifstream arch;
    abrirAbrirLectura(arch, "escalas.csv");
    llenarBoleta();
    int escala;
    double precio;
    for (int i = 0; i < vectorBoleta.size(); i++) {
        escala = vectorBoleta[i].obtenerEscala();
        precio = buscarPrecioEscala(escala);
        vectorBoleta[i].actualiza(precio);
    }
}

void Tesoreria::llenarBoleta() {
    ifstream arch;
    abrirAbrirLectura(arch, "escalas.csv");
    
    Escala esc;
    while (true) {
        esc.leerEscala(arch);
        if (arch.eof()) break;
        escalas.push_back(esc);
    }
}

double Tesoreria::buscarPrecioEscala(int codigo) {
    for (int i=0; i<escalas.size(); i++) {
        if (escalas[i].GetCodigo() == codigo) return escalas[i].GetPrecio();
    }
}
