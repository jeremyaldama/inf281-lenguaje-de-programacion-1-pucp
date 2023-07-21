/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PalletPE.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 15:30
 */

#include "PalletPE.h"

void PalletPE::imprime(ofstream&arch) {
    char ident[5];
    GetId(ident);
    arch << ident << ',' << "PE" << ',' << 60 << endl;
}

int PalletPE::peso() {
    return 60;
}

char PalletPE::tipo(void) {
    return 'P';
}