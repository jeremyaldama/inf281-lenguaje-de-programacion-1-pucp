/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   FunNumeros.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:03
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "FunNumeros.h"

void * leenumero(ifstream &arch) {
    int dato, *d;
    
    arch >> dato;
    if (arch.eof()) return nullptr;
    
    d = new int;
    *d = dato;
    
    return d;
}

int cmpnumero(const void *d1, const void *d2) {
    int *dato1 = (int *) d1;
    int *dato2 = (int *) d2;
    
    return *dato1 - *dato2;
}

void imprimenumero(void *dato, ofstream &arch){
    int *aux = (int*) dato;
    arch << setw(10) << *aux <<endl;
}