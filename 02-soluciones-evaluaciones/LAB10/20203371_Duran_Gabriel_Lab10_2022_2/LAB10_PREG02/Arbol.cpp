/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: alulab14
 * 
 * Created on 25 de noviembre de 2022, 08:10 AM
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz=nullptr;
}

Arbol::~Arbol() {
    borraArbol(raiz);
}

void Arbol::borraArbol(Nodo*& nodo) {
    if(nodo){
        borraArbol(nodo->der);
        borraArbol(nodo->izq);
        delete nodo;
    }
}


void Arbol::insertar(medicamento *&med) {
    insertarArbol(raiz,med);
}

void Arbol::insertarArbol(Nodo*& nodo, medicamento*& med) {
    if(nodo==nullptr){
        nodo = new class Nodo;
        nodo->med=med;
        return;
    }
    if(nodo->med->GetCodigo()<med->GetCodigo()){
        insertarArbol(nodo->der,med);
    }else insertarArbol(nodo->izq,med);
}


void Arbol::imprimir(ofstream &arch) {
    imprimeArbol(raiz,arch);
}

void Arbol::imprimeArbol(Nodo*& nodo, ofstream& arch) {
    if(nodo==nullptr)return;
    imprimeArbol(nodo->izq,arch);
    nodo->med->imprime(arch);
    imprimeArbol(nodo->der,arch);
}

void Arbol::actualiza(int cod) {
    actualizaArbol(raiz,cod);
}

void Arbol::actualizaArbol(Nodo*& nodo, int cod) {
    if(nodo==nullptr)return;
    actualizaArbol(nodo->izq,cod);
    if(nodo->med->GetCodigo()==cod){
        nodo->med->actualiza();
        return;
    }
    actualizaArbol(nodo->der,cod);
}







