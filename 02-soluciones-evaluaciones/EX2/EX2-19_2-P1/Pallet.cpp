/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pallet.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 13:21
 */

#include "Pallet.h"

Pallet::Pallet() {
    id = nullptr;
}

Pallet::~Pallet() {
    if (id) delete id;
}

void Pallet::SetId(const char* id2) {
    if (id) delete id;
    id = new char[strlen(id2)+1];
    strcpy(id, id2);
}

void Pallet::GetId(char*n) const {
    if (!id) n[0] = 0;
    else strcpy(n, id);
}

void Pallet::lee(ifstream&arch) {
    char buff[4];
    arch.get(buff, 4);
    if (arch.eof()) return;
    id = new char[4];
    strcpy(id, buff);
}