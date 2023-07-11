/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: cueva
 * 
 * Created on 12 de junio de 2022, 05:20 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Producto.h"

using namespace std;

Producto::Producto() {
    codprod=0;
    nombre=NULL;
    stock=0;
    
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}


void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::SetNombre(char* cad) { //modificado
    if(nombre!=NULL) delete[]nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}
void Producto::GetNombre(char *nom) const {
    strcpy(nom,nombre);
}


/*
459032,GELATINA DANY LIMON 125GR,24
422763,GALLETAS SUAVICREMAS FRESA 158GR,14
580927,TORTILLAS DE HARINA DEL HOGAR 22P. 840GR,6
 */
void Producto::leeprod(ifstream &arch){
    char cad[100],c;
    int num,stock;

    arch >>codprod;
    if(arch.eof()) return;
    arch.get();
    arch.getline(cad,100,',');
    SetNombre(cad);
    arch >> this->stock; 
    arch.get();
}

void Producto::imprimeprod(ofstream &arch){
    
    arch <<left<< setw(10) << codprod <<"  "<< setw(50)<< nombre << setw(10) <<stock <<endl;
}

int Producto::validastock(int num){
    
    if(num<=this->GetStock()) 
        return 1;
    return 0;    
}