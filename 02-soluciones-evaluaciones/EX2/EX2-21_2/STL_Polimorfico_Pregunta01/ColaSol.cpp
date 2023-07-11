/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaSol.cpp
 * Author: Danie
 * 
 * Created on 8 de julio de 2023, 22:33
 */

#include <vector>

#include "ColaSol.h"

ColaSol::ColaSol() {
    ini = fincola = nullptr;
    n = 0;
}

ColaSol::ColaSol(const ColaSol& orig) {
}

ColaSol::~ColaSol() {
}

void ColaSol::llenarCola(ifstream& arch) {
    int carne;
    // probar como se destruye esto
    NodoCola *nCola;
    while (true) {
        arch >> carne;
        if (arch.eof()) break;
        nCola = new NodoCola;
        nCola->setCarne(carne);
        nCola->leer(arch);
        if (ini) fincola->sig = nCola;
        else ini = nCola;
        fincola = nCola;
        n++;
    }
}

void ColaSol::mostrarCola(ofstream& arch) {
    NodoCola *p = ini;

    while (p) {
        arch << left << setw(12) << p->carne << p->libsol << endl;
        p = p->sig;
    }
}

void ColaSol::atiende(vector<Libro>& libros) {
    NodoCola* p = ini, *sale;
    NodoCola* pfin = fincola;
    cout << "PRIMER FIN: " << pfin << endl;
    int i;
    while (p != pfin) {

        if (hayStock(libros, p->libsol, i)) {
            cout << "HAY STOCK" << endl;
            libros[i].SetStock(libros[i].GetStock()-1);
            sale = p;
            p = p->sig;
            ini = p;
            delete sale;
        } else {
            cout << "NO HAY" << endl;
            sale = p;
            p = p->sig;
            ini = p;
            fincola->sig = sale;
            sale->sig = nullptr;
            fincola = sale;
            cout << "FIN COLA: " << fincola << endl;;
        }
    }
    cout << "FIN>: " << pfin << endl;
}

bool ColaSol::hayStock(vector<Libro>& libros, const char* cad, int &i) {
    char codLibro[100];
    for (i = 0; i < libros.size(); i++) {
        libros[i].GetCodigo(codLibro);
        if (strcmp(codLibro, cad) == 0 && libros[i].GetStock()>0) return true;
    }
    return false;
}
