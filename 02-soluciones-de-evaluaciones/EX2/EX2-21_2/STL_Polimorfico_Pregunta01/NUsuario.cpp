/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUsuario.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:31
 */

#include "NUsuario.h"

NUsuario::NUsuario() {
}

NUsuario::NUsuario(const NUsuario& orig) {
}

NUsuario::~NUsuario() {
}

void NUsuario::leerUsuario(ifstream& arch) {
    int carne;
    arch >> carne;
    if (arch.eof()) return;
    char c, cad[100];
    arch >> c;
    if (c = 'A') pusuario = new class Administrativo;
    else if ( c == 'D') pusuario = new class Docente;
    else pusuario = new class Estudiante;
    arch >> c;
    arch.getline(cad, 100, ',');
    pusuario->SetNombre(cad);
    pusuario->leer(arch);
}
