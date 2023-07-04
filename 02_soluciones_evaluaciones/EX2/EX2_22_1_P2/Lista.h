/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:35
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "NProductos.h"
#include <vector>

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void cargaLista(ifstream&arch);
    void insertar(class Pedido *ped);
    void reordenar(vector<NProductos> &productos);
    int BuscarPrioridad(int codigo, vector<NProductos> &productos);
    void mostrarLista(ofstream&);
private:
    // ordenada por fecha
    class Nodo *lini;
    class Nodo *lfin;
};

#endif /* LISTA_H */

