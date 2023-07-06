/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 23:06
 */

#include "Tesoreria.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Presencial.h"

Tesoreria::Tesoreria() {
    pTesoreria = nullptr;
}

Tesoreria::~Tesoreria() {
    if (pTesoreria) delete pTesoreria;
}

void Tesoreria::leerAlumno(ifstream&arch, char modalidad) {
    if (modalidad == 'S') {
        pTesoreria = new class Semipresencial;
    } else if (modalidad == 'V') pTesoreria = new class Virtual;
    else pTesoreria = new class Presencial;
    
    pTesoreria->LeerAlumno(arch);
}