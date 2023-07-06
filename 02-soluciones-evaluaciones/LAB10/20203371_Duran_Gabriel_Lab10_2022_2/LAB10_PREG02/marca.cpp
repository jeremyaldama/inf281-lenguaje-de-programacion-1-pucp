/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   marca.cpp
 * Author: alulab14
 * 
 * Created on 25 de noviembre de 2022, 08:07 AM
 */

#include <cstring>

#include "marca.h"

marca::marca() {
    laboratorio=nullptr;
}

marca::~marca() {
    if(laboratorio)delete laboratorio;
}

void marca::SetLaboratorio(char* cad) {
    if(laboratorio)delete laboratorio;
    laboratorio = new char [strlen(cad)+1];
    strcpy(laboratorio,cad);
}

void marca::GetLaboratorio(char* cad) const {
    if(laboratorio)strcpy(cad,laboratorio);
    else cad[0]=0;
}

void marca::SetLote(int lote) {
    this->lote = lote;
}

int marca::GetLote() const {
    return lote;
}

void marca::lee(ifstream& arch) {
    int cod,stok,lote;
    char cad[100],c;
    double prec;
    arch>>cod>>c;
    arch.getline(cad,100,',');
    arch>>stok>>c>>prec>>c;
    if(arch.eof())return;
    SetNombre(cad);
    SetCodigo(cod);
    SetPrecio(prec);
    SetStock(stok);
    
    arch.getline(cad,100,',');
    arch>>lote;
    SetLaboratorio(cad);
    SetLote(lote);
}

void marca::imprime(ofstream& arch) {
    char cad[100];
    GetNombre(cad);
    arch<<setw(10)<<left<<GetCodigo()<<setw(50)<<left<<cad<<setw(10)<<right<<GetStock()
            <<setw(10)<<right<<GetPrecio();
    GetLaboratorio(cad);
    arch<<"  "<<setw(40)<<left<<cad<<left<<GetLote()<<endl;
}

void marca::actualiza() {
    SetPrecio(GetPrecio()*(1.2));
}



