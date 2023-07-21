/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:28
 */

#include <vector>

#include "Lista.h"

Lista::Lista() {
    lfin = lini = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
    cout << endl << "Destructor Lista" << endl;
    class Nodo *p = lini, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void Lista::cargarLista(ifstream& arch) {
    class Pedido *ped;
    int codigo;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch.get();
        ped = new class Pedido;
        ped->SetCodigo(codigo);
        ped->leer(arch);

        insertar(ped);
    }
}

void Lista::insertar(class Pedido* ped) {
    class Nodo *p = lini, *ant = nullptr, *nuevo;

    nuevo = new class Nodo;
    nuevo->ped = ped;

    while (p) {
        if (p->compara(*nuevo)) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;

    if (ant) ant->sig = nuevo;
    else lini = nuevo;
    if (p == nullptr) lfin = nuevo;
}

void Lista::mostrarLista(ofstream& arch) {
    class Nodo *p = lini;
    arch << setprecision(2) << fixed;
    while (p) {
        p->ped->mostrarPedido(arch);
        p = p->sig;
    }
}

void Lista::actualiza(vector<NProductos>& prods) {
    class Nodo *p = lini->sig, *ant = lini;
    int prio;
    while (p) {
        prio = obtenerPrioridad(p->ped->GetCodigo(), prods);
        if (prio != -1) {
            p->ped->SetOrden(prio == 1 ? 1 : 0);
            if (prio == 1) {
                ant->sig = p->sig;
                p->sig = lini;
                lini = p;
                p = ant->sig;
                if (p == nullptr) lfin = ant;
            } else {
                ant = p;
                p = p->sig;
            }
        } else {
            ant = p;
            p = p->sig;
        }
    }
}

int Lista::obtenerPrioridad(int cod, vector<NProductos> &prods) {
    for (int i = 0; prods.size(); i++) {
        if (prods[i].obtenerCodigo() == cod) {
            return prods[i].obtenerPrioridad();
        }
    }
    return -1;
}
