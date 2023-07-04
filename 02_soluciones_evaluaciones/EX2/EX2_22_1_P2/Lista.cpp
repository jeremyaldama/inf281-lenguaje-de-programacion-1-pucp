/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:35
 */

#include "Lista.h"

Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::cargaLista(ifstream&arch) {

    class Pedido *ped;
    // ESTO NO ES COMO EL VECTOR DE NODOS, DONDE TENIA QUE IR AL NODO A LEER
    int codigo;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        ped = new class Pedido;
        arch.get();
        ped->leerPedido(arch, codigo);

        insertar(ped);
    }
}

void Lista::insertar(class Pedido *ped) {
    class Nodo *p = lini, *ant = nullptr, *nuevo;
    nuevo = new class Nodo;
    nuevo->ped = ped;

    while (p) {
        if (p->ped->GetFecha() > ped->GetFecha()) break;
        ant = p;
        p = p->sig;
    }

    nuevo->sig = p;

    if (ant) ant->sig = nuevo;
    else lini = nuevo;
    if (p == nullptr) lfin = nuevo;
}

void Lista::reordenar(vector<NProductos> &productos) {
    Nodo *p = lini->sig, *ant = lini;
    int prioridad = -1;
    while (p) {
        prioridad = BuscarPrioridad(p->ped->GetCodigo(), productos);

        if (prioridad == 1) {
            p->ped->SetOrden(1);
            ant->sig = p->sig;
            p->sig = lini;
            lini = p;
            p = ant->sig;
            if (p == nullptr) lfin = ant;
        } else {
            p->ped->SetOrden(0);
            ant = p;
            p = p->sig;
        }
    }
}

int Lista::BuscarPrioridad(int codigo, vector<NProductos> &productos) {
    for (NProductos nodo : productos) {
        if (nodo.obtenerCodigo() == codigo) return nodo.obtenerPrioridad();
    }
    return -1;
}

void Lista::mostrarLista(ofstream&arch) {
    Nodo *p = lini;
    arch << endl;
    while (p) {
        p->ped->mostrarPedido(arch);
        p = p->sig;
    }
}