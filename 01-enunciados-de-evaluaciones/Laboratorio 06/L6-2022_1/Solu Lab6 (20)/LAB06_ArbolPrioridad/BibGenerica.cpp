/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   BibGenerica.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:03
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "BibGenerica.h"

enum Reg {IZQ,DATO,DER};

void creaarbol(void *&arbol, void*(*lee)(ifstream&),
        int (*comp)(const void*, const void*), const char *nomTxt){
    ifstream arch(nomTxt, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nomTxt << endl;
        exit(1);
    }
    
    void *dato;
    arbol = nullptr;
    
    while (1) {
        dato = lee(arch);
        if (dato == nullptr) break;
        insertanodo(arbol, dato, comp);
    }
}

int arbolvacio(void *arbol){
    return arbol == nullptr;
}

void insertanodo(void *&arbol, void *dato,
        int (*comp)(const void*, const void*)){
    void **ptRec = (void **) arbol;
    
    if(arbolvacio(arbol)){
        void **ptrNuevo = new void *[3]; // Nodo
        ptrNuevo[DATO] = dato;
        ptrNuevo[IZQ] = nullptr;
        ptrNuevo[DER] = nullptr;
        arbol = ptrNuevo;
        return;
    }
    
    if (comp(ptRec[DATO], dato) > 0){
        insertanodo(ptRec[IZQ], dato, comp);
    }else{
        insertanodo(ptRec[DER], dato, comp);
    }
}

void muestraarbol(void *arbol, void (*imprime)(void *, ofstream &), const char *nomTxt){
    ofstream arch(nomTxt, ios::out);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo" << nomTxt << endl;
        exit(1);
    }
    if(strcmp(nomTxt, "reporteped.txt") == 0){
        arch << left << setw(13) << "Fecha" << setw(10) << "DNI" <<
            setw(10) << "Codigo" << 
            setw(55) << "Descripcion del producto" << setw(10)<<"Cantidad" <<endl;
        for (int i = 0; i < 100; i++) arch << "=";
        arch << endl;
    }
    enorden(arbol, imprime, arch);
}

void enorden(void *arbol, void (*imprime)(void *, ofstream &), ofstream &arch){
    void **ptrRec = (void **) arbol;
    if(ptrRec){
        enorden(ptrRec[IZQ], imprime, arch);
        imprime(ptrRec[DATO], arch);
        enorden(ptrRec[DER], imprime, arch);
    }
}