/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// JEREMY DANIEL ALDAMA GIRALDO 20206228
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

void llenar_arreglo_heroes(void*&arreglo_heroes, int&cantidad_total_heroes,
        void*(*leer) (ifstream&), const char*nom) {
    ifstream arch(nom, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR heroes_changelog.csv" << endl;
        exit(1);
    }

    void *arreglo[500], *reg;
    int i = 0;
    while (1) {
        reg = leer(arch);
        if (!reg) break;
        arreglo[i] = reg;
        i++;
    }
    cantidad_total_heroes = i;
    void **aux = new void*[i + 1];
    aux[i] = nullptr;
    for (int j = 0; j < i; j++) {
        aux[j] = arreglo[j];
    }
    arreglo_heroes = aux;
}

int cmp_multicriterio_void(const void*i, const void*j) {
    void **ii = (void**)i;
    void **jj = (void**)j;
    
    void **ih = (void**)(*ii), **jh = (void**)(*jj);
    char *in = (char*)ih[1], *jn = (char*)jh[1];
    cout << in << "  " << jn << endl;
    int cmp = strcmp(in, jn);
    cout << "comp: " << cmp << endl;
    cout << "PUNTAJE: " <<  *(double*)ih[4] << "  " << *(double*)jh[4] << endl;
    if (cmp == 0) return (*(double*)ih[4] - *(double*)jh[4]);
    return cmp;
}