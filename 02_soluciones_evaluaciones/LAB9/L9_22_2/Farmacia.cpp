/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Farmacia.cpp
 * Author: Danie
 * 
 * Created on 20 de junio de 2023, 19:18
 */

#include "Farmacia.h"

void Farmacia::leerecetas() {
    ifstream arch("recetas2.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR recetas2.csv" << endl;
        exit(1);
    }
    
    int cod_med, i = 0;
    char c;
    
    while (1) {
        arch >> cod_med;
        if (arch.eof()) break;
        cout << cod_med << "  ";
        arch >> c;
        loferta[i].AsignaMedicamento(cod_med, arch);
        i++;
    }
}

void Farmacia::imprimirrecetas() {
    ofstream arch("ReporteRecetas.txt", ios::out);
    if (!arch) {
        cout << "ERROR: NO SE PUDO ABRIR ReporteRecetas.txt";
        exit(1);
    }
    
    for (int i=0; !loferta[i].fin(); i++) {
        loferta[i].imprimeMedicamento(arch);
    }
}

void Farmacia::descuenta() {
    for (int i=0; !loferta[i].fin(); i++) {
        loferta[i].aplicaDescuento();
    }
}