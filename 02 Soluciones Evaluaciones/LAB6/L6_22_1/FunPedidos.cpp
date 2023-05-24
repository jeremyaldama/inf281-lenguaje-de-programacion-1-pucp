/* 
 * File:   FunPedidos.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 24 de mayo de 2023, 14:06
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "FunPedidos.h"

using namespace std;

void *leepedido(ifstream&arch) {
    int codigo, cantidad, dni_cliente, dd, mm, aa, fecha;
    char descripcion[100], c;
    arch >> codigo;
    if (arch.eof()) return nullptr;
    arch >> c;
    arch.getline(descripcion, 100, ',');
    arch >> cantidad >> c >> dni_cliente >> c >> dd >> c >> mm >> c >> aa;
    void **ped = new void*[5]{};
    ped[0] = new int{codigo};
    char *des = new char[strlen(descripcion)+1];
    strcpy(des, descripcion);
    ped[1] = des;
    ped[2] = new int{cantidad};
    ped[3] = new int{dni_cliente};
    fecha = dd+mm*100+aa*10000;
    ped[4] = new int{fecha};
    void **nodo = new void*[3]{};
    nodo[0] = ped;
    return nodo;
}

int cmppedido(void*i, void*j) {
    void **ped = (void**)i, **nodo = (void**)j;
    int suma_ped, suma_nodo;
    suma_ped = *(int*)ped[4];
    suma_nodo = *(int*)nodo[4];
    if (suma_ped == suma_nodo){
        return (*(int*)ped[3]) - (*(int*)nodo[3]);
    }
    else return suma_ped - suma_nodo;
}

void imprimepedido(ofstream&arch, void*n) {
    int dd, mm, aa;
    void **ped = (void**)n;
    int fecha = *(int*)ped[4];
    dd = fecha % 100; aa = fecha/10000; mm = (fecha%10000)/100;
    
    arch << right << setw(2) << setfill('0') << dd << "/" << setw(2) << mm <<
            "/" << setw(6) << left << setfill(' ') << aa << setw(15) <<
            *(int*)ped[3] << setw(10) << *(int*)ped[0] << setw(60) <<
            (char*)ped[1] << *(int*)ped[2] << endl;
}