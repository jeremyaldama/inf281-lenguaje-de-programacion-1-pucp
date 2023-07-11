/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistroUsuario.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 17:43
 */

#include "RegistroUsuario.h"

RegistroUsuario::RegistroUsuario() {
}

RegistroUsuario::RegistroUsuario(const RegistroUsuario& orig) {
    *this = orig;
}

RegistroUsuario::~RegistroUsuario() {
}

void RegistroUsuario::leerUsuario(ifstream& arch) {
    usuario.leeDatos(arch);
}

void RegistroUsuario::operator=(const RegistroUsuario& reg) {
    usuario = reg.usuario;
}

int RegistroUsuario::obtenerCodigo() const {
    return usuario.GetCodigo();
}

void RegistroUsuario::leerPrestamo(ifstream& arch) {
    RegistroPrestamo prestamo;
    prestamo.leeDatos(arch);
    prestamos.push_back(prestamo);
}

void RegistroUsuario::imprimirUsuarioPrestamos(ofstream& arch) {
    usuario.imprimeDatos(arch);

    for (int i = 0; i < prestamos.size(); i++) {
        prestamos[i].imprimeDatos(arch);
    }
}

void RegistroUsuario::obtenerCodigoUltimoPrestamo(char* cad) const {
    char cod[100];
    RegistroPrestamo reg = prestamos.back();
    reg.GetCodigoLibro(cod);
    strcpy(cad, cod);
}

void RegistroUsuario::leerPrestamo(ifstream& arch, vector<Libro> &libros) {
    RegistroPrestamo prestamo;
    prestamo.leeDatos(arch);
    prestamos.push_back(prestamo);
    
    char cad[100], cadBuscar[100];
    prestamo.GetCodigoLibro(cad);
    for (int i=0; i<libros.size(); i++) {
        libros[i].GetCodigo(cadBuscar);
        cout << cadBuscar << endl;
        if (strcmp(cad, cadBuscar) == 0)
            libros[i].SetPrestados(libros[i].GetPrestados()+1);
    }
        
}

void RegistroUsuario::imprimirSuspendido(ofstream& arch, int fecha) {
    for (int i=0; i<prestamos.size(); i++) {
        if (prestamos[i].numeroDeDias(fecha) > 7) {
            usuario.imprimeDatos(arch);
            return;
        }
    }
}
