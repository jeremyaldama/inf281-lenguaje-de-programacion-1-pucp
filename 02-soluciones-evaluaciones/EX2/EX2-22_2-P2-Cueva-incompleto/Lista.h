/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: cueva
 *
 * Created on 26 de junio de 2022, 09:39 PM
 */
#include <fstream>
#include "Nodo.h"
#include "NProductos.h"
using namespace std;

#ifndef LISTA_H
#define LISTA_H

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void inserta(ifstream&);
    void muestra(ofstream&);
    void modifica(int,int);
    int ListaVacia();
    void cargalista();
    void imprimelista();

private:
    Nodo *lini;
    Nodo *lfin;
};

#endif /* LISTA_H */

