/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   FunPedidos.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:03
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "FunPedidos.h"

void * leepedido(ifstream &arch){
    int c,*codigo, *dni, *cantidad;
    int dd, mm, aa, *fecha;
    char buff[100], *nombre, car;
    
    arch >> c;
    if(arch.eof()) return NULL;
    arch.get();
    
    codigo = new int;
    *codigo = c;
    
    arch.getline(buff, 100,',');
    nombre = new char[strlen(buff)+1];
    strcpy(nombre, buff);
    
    fecha = new int;
    cantidad = new int;
    dni = new int;
    
    arch >> *cantidad >> car >> *dni >> car >> dd >> car >> mm >> car >> aa;
    
    *fecha = dd+mm*100+aa*10000;
    
    void  **reg = new void*[5];
    reg[0] = codigo;
    reg[1] = nombre;
    reg[2] = cantidad;
    reg[3] = dni;
    reg[4] = fecha;
    
    return reg;
}

int cmppedido(const void *perI, const void *perJ) {
    void **pI = (void**) perI;
    void **pJ = (void**) perJ;
    
    int *fechaI = (int *) pI[4];
    int *fechaJ = (int *) pJ[4];
    
    if(*fechaI != *fechaJ){
        return *fechaI - *fechaJ;
    }else{
        int *dniI = (int *) pI[3];
        int *dniJ = (int *) pJ[3];
        return *dniI - *dniJ;
    }
}

// ----------------------------------------------------------------------------

void imprimepedido(void *reg, ofstream &arch){
    void **registro = (void**) reg; 
    int *codigo = (int*) (registro[0]);
    char *nombre =  (char*) (registro[1]);
    int *cantidad = (int*) (registro[2]);
    int *dni = (int*) (registro[3]);
    int *fecha = (int*) (registro[4]);

    imprimirFecha(arch, *fecha);
    arch << "   " << left << setw(10) << *dni <<
            setw(10) << *codigo << 
            setw(50)<<nombre<< right<< setw(10)<<*cantidad <<endl;
}

void imprimirFecha(ofstream &arch, int fecha){
    int dd, mm, aa;
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    aa = fecha/100;
    arch << right << setfill('0') << setw(2) << dd << "/" << 
            setw(2) << mm << "/" 
            << setw(4) << aa << setfill(' ');
}