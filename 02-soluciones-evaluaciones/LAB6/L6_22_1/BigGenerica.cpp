/* 
 * File:   BigGenerica.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 23 de mayo de 2023, 19:13
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "BigGenerica.h"

using namespace std;

void creaarbol(void*&arbol, void*(*lee)(ifstream&), int(*cmp)(void*, void*),
        const char*nom) {
    ifstream arch(nom, ios::in);
    void *nodo;
    arbol = nullptr;

    while (1) {
        nodo = lee(arch);
        if (nodo == nullptr) break;
        void **p = (void**) nodo;
        cout << *(int*) (p[0]) << endl;
        insertanodo(arbol, cmp, nodo);
    }

}

void insertanodo(void*&arbol, int(*cmp)(void*, void*), void*nodo) {
    if (arbolvacio(arbol)) {
        arbol = nodo;
    } else {
        void **padre, **nodo_actual = (void**) arbol, **num = (void**) nodo;
        padre = nodo_actual;
        while (nodo_actual) {
            padre = nodo_actual;
            if (cmp(nodo_actual[0], num[0]) > 0) {
                nodo_actual = (void**) nodo_actual[1];
            } else {
                nodo_actual = (void**) nodo_actual[2];
            }
        }

        if (cmp(padre[0], num[0]) > 0) {
            padre[1] = nodo;
        } else {
            padre[2] = nodo;
            void **a = (void**) padre;
            void **i = (void**) padre[1];
            void **d = (void**) padre[2];
//            if (i && d)
//                cout << " NODO: " << *(int*) a[0] << " IZQ: " << *(int*)i[0] << " DER: " <<
//                    *(int*)d[0] << endl;
        }
    }
}

int arbolvacio(void*arbol) {
    return arbol == nullptr;
}

void muestraarbol(void*arb, void(*imprime)(ofstream&, void*), const char*nom) {
    ofstream arch(nom, ios::out);
    void **arbol = (void**) arb;
    enorden(arch, arbol, imprime);
}

void enorden(ofstream&arch, void**arbol, void(*imprime)(ofstream&, void*)) {
    if (arbol == nullptr) return;
    enorden(arch, (void**) arbol[1], imprime);
    imprime(arch, arbol[0]);
    enorden(arch, (void**) arbol[2], imprime);
}
