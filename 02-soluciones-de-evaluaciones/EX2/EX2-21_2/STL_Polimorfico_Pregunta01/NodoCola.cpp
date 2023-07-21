/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:31
 */

#include "NodoCola.h"

NodoCola::NodoCola() {
    libsol = nullptr;
    sig = nullptr;
}

NodoCola::NodoCola(const NodoCola& orig) {
}

NodoCola::~NodoCola() {
}

void NodoCola::leer(ifstream& arch) {
    char cad[100];
    arch.get();
    arch.get();
    arch >> cad;
    setLibsol(cad);
}

void NodoCola::setCarne(int carne) {
    this->carne = carne;
}

int NodoCola::getCarne() const {
    return carne;
}

void NodoCola::setLibsol(const char* cad) {
    if (libsol) delete libsol;
    libsol = new char[strlen(cad)+1];
    strcpy(libsol, cad);
}

void NodoCola::getLibsol(char* cad) const {
    if (libsol) strcpy(cad, libsol);
    else cad[0] = 0;
}
