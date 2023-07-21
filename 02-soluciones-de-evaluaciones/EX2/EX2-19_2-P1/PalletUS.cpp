/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PalletUS.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 14:05
 */

#include "PalletUS.h"

void PalletUS::imprime(ofstream&arch) {
    char ident[5];
    GetId(ident);
    arch << ident << ',' << "US" << ',' << 40 << endl;
}

int PalletUS::peso() {
    return 40;
}

char PalletUS::tipo(void) {
    return 'U';
}