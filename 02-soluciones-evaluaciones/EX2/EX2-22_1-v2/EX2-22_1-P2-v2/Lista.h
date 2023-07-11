/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:28
 */

#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Nodo.h"
#include "NProductos.h"
#include <vector>

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void cargarLista(ifstream&arch);
    void insertar(class Pedido*ped);
    void mostrarLista(ofstream&arch);
    void actualiza(vector<NProductos> &prods);
    int obtenerPrioridad(int cod, vector<NProductos> &);
private:
    class Nodo *lini;
    class Nodo *lfin;
};

#endif /* LISTA_H */

