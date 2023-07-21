/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PalletEU.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 15:36
 */

#include "PalletEU.h"

void PalletEU::imprime(ofstream&arch) {
    char ident[5];
    GetId(ident);
    arch << ident << ',' << "EU" << ',' << 50 << endl;
}

int PalletEU::peso() {
    return 50;
}

char PalletEU::tipo(void) {
    return 'E';
}