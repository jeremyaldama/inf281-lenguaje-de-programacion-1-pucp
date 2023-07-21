/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 12:16
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::cargarArbol(ifstream& arch, int fecha_actual, 
        const char* cad) {
    medicamento *med;
    int fecha_vencimiento;
    
    while (true) {
        arch >> fecha_vencimiento;
        if (arch.eof()) break;
        arch.get();
        if (fecha_actual < fecha_vencimiento) med = new class vencido;
        else med = new class activo;
        med->SetEstado(fecha_actual < fecha_vencimiento? 0:1);
        med->SetFechavenc(fecha_vencimiento);
        med->lee(arch, cad, fecha_actual);
        insertarMedicamento(med);
    }
}

void Arbol::insertarMedicamento(medicamento* med) {
    insertarMedicamentoRecursivo(raiz, med);
}

void Arbol::insertarMedicamentoRecursivo(Nodo*& raiz, medicamento *med) {
    if (raiz == nullptr) {
        raiz = new class Nodo;
        raiz->med = med;
        return;
    }
    if (raiz->compararMedicamento(*med)) {
        insertarMedicamentoRecursivo(raiz->izq, med);
    } else insertarMedicamentoRecursivo(raiz->der, med);
}

void Arbol::mostrarArbol(ofstream& arch) {
    mostrarArbolRecursivo(arch, raiz);
}

void Arbol::mostrarArbolRecursivo(ofstream& arch, Nodo* raiz) {
    if (raiz) {
        mostrarArbolRecursivo(arch, raiz->izq);
        raiz->med->imprime(arch);
        mostrarArbolRecursivo(arch, raiz->der);
    }
}

void Arbol::actualizar(int fecha_actual, const char*inspector) {
    actualizarRecursivo(raiz, fecha_actual, inspector);
}

void Arbol::actualizarRecursivo(Nodo* raiz, int fecha_actual, 
        const char* inspector) {
    if (raiz) {
        actualizarRecursivo(raiz->izq, fecha_actual, inspector);
        if (raiz->med->GetFechavenc() < fecha_actual && 
                raiz->med->GetEstado()==1) {
            medicamento *nuevo_med = new class vencido;
            
            cout << raiz->med << endl;
            nuevo_med->registrarDatos(*raiz->med, fecha_actual, inspector);
            delete raiz->med;
            raiz->med = nuevo_med;
        }
        actualizarRecursivo(raiz->der, fecha_actual, inspector);
    }
}
