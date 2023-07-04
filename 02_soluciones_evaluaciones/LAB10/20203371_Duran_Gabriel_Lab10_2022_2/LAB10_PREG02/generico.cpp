/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   generico.cpp
 * Author: alulab14
 * 
 * Created on 25 de noviembre de 2022, 08:05 AM
 */

#include <cstring>

#include "generico.h"

generico::generico() {
    pais=nullptr;
}


generico::~generico() {
    if(pais)delete pais;
}

void generico::SetPais(char* cad) {
    if(pais)delete pais;
    pais = new char [strlen(cad)+1];
    strcpy(pais,cad);
}

void generico::GetPais(char* cad) const {
    if(pais)strcpy(cad,pais);
    else cad[0]=0;
}

void generico::lee(ifstream& arch) {
    int cod,stok;
    char cad[100],c;
    double prec;
    arch>>cod>>c;
    arch.getline(cad,100,',');
    if(arch.eof())return;
    arch>>stok>>c>>prec>>c;
    SetNombre(cad);
    arch.getline(cad,100,'\n');
    SetCodigo(cod);
    SetPais(cad);
    SetPrecio(prec);
    SetStock(stok);
}

void generico::imprime(ofstream& arch) {
    char cad[100];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodigo()<<setw(50)<<left<<cad<<setw(10)<<right<<GetStock()
            <<setw(10)<<right<<GetPrecio();
    GetPais(cad);
    arch<<"  "<<setw(40)<<left<<cad<<endl;
}

void generico::actualiza() {
    return;
}




