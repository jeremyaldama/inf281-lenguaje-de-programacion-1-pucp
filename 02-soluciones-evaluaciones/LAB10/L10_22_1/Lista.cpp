/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 23:21
 */

#include "Lista.h"

Lista::Lista() {
    lfin = lini = nullptr;
}

Lista::~Lista() {
    Nodo *p = lini, *sale;
    
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void Lista::crearLista(ifstream&arch) {
    int codigo;
    class Pedido *ped;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        leer(arch, codigo, ped);
        insertar(*ped);
    }
}

void Lista::leer(ifstream&arch, int cod, class Pedido *&ped) {
    asignarTipoPedido(cod, ped);
    ped->SetCodigo(cod);
    ped->lee(arch);
}

void Lista::insertar(class Pedido &ped) {
    class Nodo *p = lini, *ant = nullptr, *nuevo;
    
    nuevo = new class Nodo;
    nuevo->ped = &ped;
    
    while (p) {
        if (*(p->ped) > ped) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    nuevo->ant = ant;
    
    if (ant) {
        ant->sig = nuevo;
    }
    else {
        lini = nuevo;
    }
    
    if (p == nullptr) lfin = nuevo;
    else p->ant = nuevo;
}

void Lista::asignarTipoPedido(int cod, class Pedido *&nuevo) {
    if (cod < 400000) nuevo = new class PedidoEspecial;
    else if (cod < 600000) nuevo = new class PedidoUsual;
    else nuevo = new class PedidoEventual;
}

void Lista::mostrarLista(ofstream&arch) {
    class Nodo *p = lini;
    
    while (p) {
        p->ped->imprime(arch);
        arch << endl;
        p = p->sig;
    }
    // Prueba del ultimo
    class Nodo *ult = lfin;
    ult->ped->imprime(arch);
}

void Lista::actualiza(int cod, int fecha) {
    class Nodo *p = lfin;
    
    while (p) {
        if (p->ped->GetDni() == cod && (p->ped->GetFecha() < fecha)) {
            p->ped->exonerar();
        }
        p = p->ant;
    }
}