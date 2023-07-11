/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 23:21
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"

class Lista {
public:
    Lista();
    virtual ~Lista();
    void crearLista(ifstream&);
    void leer(ifstream&arch, int cod, class Pedido *&ped);
    void insertar(class Pedido &ped);
    void mostrarLista(ofstream&);
    void actualiza(int, int);
private:
    class Nodo *lini;
    class Nodo *lfin;
    void asignarTipoPedido(int cod, class Pedido *&nuevo);
};

#endif /* LISTA_H */

