/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ListaPallet.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 15:49
 */

#ifndef LISTAPALLET_H
#define LISTAPALLET_H
#include "NodoPallet.h"

class ListaPallet {
private:
    class NodoPallet *lista;
public:
    ListaPallet();
    virtual ~ListaPallet();
    void insertar(const char*, const char*);
    void leerDatos(ifstream&);
    void imprimirDatos(ofstream&);
    void atenderDespacho(int &);
};

#endif /* LISTAPALLET_H */

