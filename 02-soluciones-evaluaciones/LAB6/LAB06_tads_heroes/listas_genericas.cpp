/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "listas_genericas.h"

void crear_lista_heroes(void*arreglo_heroes, void*&lista_heroes, 
        void*(*leer_heroe)(void*, int )) {
    lista_heroes = nullptr;
    void**arreglo = (void**)arreglo_heroes, *reg;
    void **lista_aux = nullptr;
    void **siguiente;
    void *nodo;
    for (int i=0; arreglo[i]; i++) {
        reg = leer_heroe(arreglo_heroes, i);
        if (!reg) break;
        void**registro = (void**)reg;
    cout << setprecision(2) << fixed;
    cout << left << setw(15) << (char*)registro[1] << setw(10) << (char*)registro[2] <<
            setw(10) << (char*)registro[3] << setw(10) << *(double*)registro[4] <<
            *(int*)registro[0] << endl;
        nodo = CrearNodo(reg);
        InsertarNodo(lista_aux, nodo, siguiente);
    }
    lista_heroes = lista_aux;
}

void InsertarNodo(void**&lista_aux, void*nodo, void**&act) {
    if (lista_aux == nullptr) {
        lista_aux = (void**)nodo;
        act = (void**)lista_aux;
    } else {
        act[1] = nodo;
        act = (void**)nodo;
    }
}

void* CrearNodo(void*reg) {
    void **aux = new void*[2]{};
    aux[0] = reg;
    aux[1] = nullptr;
    return aux;
}

void*leer_heroe(void*arreglo_heroes, int i) {
    cout << ((void**)arreglo_heroes)[i]<< endl;
    return ((void**)arreglo_heroes)[i];
}

void imprimir_lista_heroes(void*lista_heroes, void(*imprimir_registro_heroe)
    (ofstream&, void*)) {
    ofstream arch("Reporte-Heroes.txt", ios::out);
    
    void**lista = (void**)lista_heroes;
    for (int i=0; lista; i++) {
        imprimir_registro_heroe(arch, lista[0]);
        lista = (void**)lista[1];
    }
}

void eliminar_lista_heroes_repetidos(void*&lista_heroes, 
        void(*eliminar_registro)(void*) ) {
    
}