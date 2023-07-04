/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ALibro.h
 * Author: Danie
 *
 * Created on 23 de junio de 2023, 23:33
 */

#ifndef ALIBRO_H
#define ALIBRO_H
#include "NLibro.h"

class ALibro {
public:
    ALibro();
    virtual ~ALibro();
    void elimina(class NLibro *arbol);
    void insertar(class Libro &);
    void mostrarEnOrden(ofstream&);
    void crear(ifstream&);
    void actualiza(const char*);
private:
    class NLibro *Raiz;
    void insertarR(class NLibro*&Raiz, const class Libro&lib);
    void mostrarEnOrdenR(ofstream&arch, class NLibro *arbol);
    void actualiza(class NLibro *Raiz, const char*cod);
};

#endif /* ALIBRO_H */

