/* 
 * File:   BibliotecaPilaGenerica.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 1 de junio de 2023, 0:18
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "BibliotecaPilaGenerica.h"

using namespace std;

void cargaarreglo(void*&arreglo, int (*cmp)(const void*, const void*), 
        void* (*lee)(ifstream&), const char *nom) {
    ifstream arch(nom, ios::in);
    
    void *reg, *aux[100];
    int i = 0;
    while (1) {
        reg = lee(arch);
        if (!reg) break;
        aux[i] = reg;
        i++;
    }
    void **p = aux;
    
    void **arr;
    arr = new void*[i+1];
    arr[i] = nullptr;
    for (int j=0; j<i; j++){
        arr[j] = aux[j];
    }
    qsort(arr, i, sizeof(int), cmp);
    arreglo = arr;
}

void cargapila(void*&pilaini, void*arreglo) {
    void **pila;
    pila = new void*[2]{};
    pila[1] = new int{};
    pilaini = pila;
    void **arr = (void**) arreglo;
    for (int i=0; arr[i]; i++) {
        push(pilaini, arr[i]);
        (*(int*)pila[1])++;
    }
}

void push(void*pila, void*dato) {
    void **aux = (void**)pila;
    void **nuevo = new void*[2]{};
    nuevo[1] = dato;
    nuevo[0] = aux[0];
    aux[0] = nuevo;
}

void GeneraPila(void*&pila) {
    void **aux = new void*[2]{};
    pila = aux;
}

void muevepila(void*pilaini, void*&pilafin) {
    GeneraPila(pilafin);
    void *aux;
    GeneraPila(aux);
    void **pila = (void**)pilaini;
    int n = *(int*)pila[1];
    Hanoi(n, pilaini, aux, pilafin);
}

void* pop(void*pilaini) {
   void **aux = (void**)pilaini, *dato = nullptr;
   if (aux[0]!=nullptr) {
        void **primero = (void**)aux[0];
        void **segundo = (void**)primero[0];
        aux[0] = segundo;
        dato = primero[1];
        delete primero;
   }
   return dato;
}

void Hanoi(int n, void*pilaini, void*aux, void*pilafin) {
    if (n == 0) {
        return;
    }
    Hanoi(n-1, pilaini, pilafin, aux);
    void *dato = pop(pilaini);
    push(pilafin, dato);
    Hanoi(n-1, aux, pilaini, pilafin);
}