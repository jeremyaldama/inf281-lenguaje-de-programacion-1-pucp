/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 1:01
 */

#include "Biblioteca.h"

void Biblioteca::GeneraCopias() {
    ifstream arch("libros2.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR libros2.csv";
        exit(1);
    }
    char codigo[100];
    int j = 0;

    while (1) {
        arch.getline(codigo, 100, ',');
        if (arch.eof()) break;
        LeerLibroDisponible(arch, codigo, j);
    }
}

void Biblioteca::LeerLibroDisponible(ifstream&arch, const char*codigo, int&j) {
    char descrip[100], autor[100], c;
    int aa, cantidad, zona;
    double precio;

    arch.getline(descrip, 100, ',');
    arch.getline(autor, 100, ',');
    arch >> aa >> c >> cantidad >> c >> precio >> c >> zona;
    arch.get();
    cout << descrip << endl;

    for (int i = 0; i < cantidad; i++) {
        llibros[j++].AsignaCopia(codigo, descrip, autor, aa, cantidad, precio,
                zona, i + 1);
    }
}

void Biblioteca::ActualizaLibros() {
    ifstream arch("RegistroDePrestamos2.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR RegistroDePrestamos2.csv";
        exit(1);
    }

    int dd, mm, aa, fecha, num_lib, dif_dias, ind_lib;
    char cod_lib[100], carnet[100], c;

    while (1) {
        arch.getline(carnet, 100, ',');
        if (arch.eof()) break;
        arch.getline(cod_lib, 100, ',');
        arch >> num_lib >> c >> dd >> c >> mm >> c >> aa;
        fecha = aa * 10000 + mm * 100 + dd;
        cout << "fecha:  " << fecha << endl;

        dif_dias = numeroDeDias(fecha, 20211115);
        cout << "dif: " << dif_dias << endl;
        
        ind_lib = BuscarIndiceLibro(cod_lib);
//        cout << ind_lib << " " << cod_lib << endl;
        if (ind_lib != -1) {
            if (dif_dias < 60) {
                // prestamo
                llibros[ind_lib+num_lib-1].Actualiza("Prestamo", dif_dias, fecha, num_lib);
            } else {
                // perdida
                llibros[ind_lib+num_lib-1].Actualiza("Perdida", dif_dias, fecha, num_lib);
            }
        }
    }
}

int Biblioteca::BuscarIndiceLibro(const char*cod_lib) {
    char n[100];
    for (int i = 0; !llibros[i].fin(); i++) {
        llibros[i].ObtenerCodigo(n);
        if (strcmp(cod_lib, n) == 0) return i;
    }
    return -1;
}

void Biblioteca::ImprimeCopias() {
    ofstream arch("Reporte.txt", ios::out);

    for (int i = 0; !llibros[i].fin();) {
        int num = llibros[i].ObtenerCantidad();
        llibros[i].imprimirCabecera(arch);
        for (int j = 0; j < num; i++, j++) {
            arch << right << setw(2) << j+1 << "   ";
            llibros[i].ImprimirCopia(arch);
        }
        arch << "---------------------------------------" << endl;
    }
}