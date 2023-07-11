/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrativo.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:26
 */

#include "Administrativo.h"

Administrativo::Administrativo() {
    area = nullptr;
}

Administrativo::Administrativo(const Administrativo& orig) {
}

Administrativo::~Administrativo() {
    if (area) delete area;
}

void Administrativo::SetArea(const char* cad) {
    if (area) delete area;
    area = new char[strlen(cad)+1];
    strcpy(area, cad);
}

void Administrativo::GetArea(char* cad) const {
    if (area) strcpy(cad, area);
    else cad[0] = 0;
}

void Administrativo::leer(ifstream& arch) {
    char cad[100];
    arch >> cad;
    SetArea(cad);
}
