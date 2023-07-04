/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaPallet.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 15:49
 */

#include "ListaPallet.h"

ListaPallet::ListaPallet() {
    lista = nullptr;
}

ListaPallet::~ListaPallet() {
    class NodoPallet*p = lista, *sale;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void ListaPallet::insertar(const char*id, const char*tipo) {
    class NodoPallet *p = lista, *ant = nullptr, *nuevo;
    nuevo = new class NodoPallet;
    int cmp = strcmp(tipo, "PE");
    char pId[10];
    
    if (cmp==0) nuevo->pallet = new PalletPE;
    else if (cmp<0) nuevo->pallet = new PalletEU;
    else nuevo->pallet = new PalletUS;
    
    nuevo->pallet->SetId(id);
    while (p) {
        p->pallet->GetId(pId);
        if (strcmp(pId, id)>0) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant) ant->sig = nuevo;
    else lista = nuevo;
}

void ListaPallet::leerDatos(ifstream&arch) {
    char id[10], tipo[10];
    while (1) {
        arch.getline(id, 10, ',');
        if (arch.eof()) return;
        arch.getline(tipo, 10);
        insertar(id, tipo);
    }
}

void ListaPallet:: imprimirDatos(ofstream&arch) {
    class NodoPallet *p = lista;
    while (p) {
        p->pallet->imprime(arch);
        p = p->sig;
    }
}

void ListaPallet::atenderDespacho(int&cant) {
    class NodoPallet *p = lista, *ant = nullptr, *sale;
    int peso;
    while (p && cant) {
        peso = p->pallet->peso();
        if (peso <= cant) {
            cant -= peso;
            sale = p;
            p = p->sig;
            if (ant == nullptr) lista = sale->sig;
            else ant->sig = sale->sig;
            delete sale;
        } else {
            ant = p;
            p = p->sig;
        }
    }
}