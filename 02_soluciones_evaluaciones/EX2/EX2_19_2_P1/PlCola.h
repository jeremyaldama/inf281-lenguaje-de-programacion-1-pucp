/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PlCola.h
 * Author: Danie
 *
 * Created on 14 de junio de 2023, 22:44
 */
#ifndef PLCOLA_H
#define PLCOLA_H
#include "PlNodoCola.h"

template <typename T>
class PlCola {
private:
    class PlNodoCola<T> *inicio;
    class PlNodoCola<T> *fin;
public:
    PlCola();
    virtual ~PlCola();
    void llegada(const T &);
    void atencion(T &);
    void mostrar(ofstream&);
    bool estaVacia(void);
};

template <typename T>
PlCola<T>::PlCola() {
    inicio = fin = nullptr;
}

template <typename T>
PlCola<T>::~PlCola() {
    class PlNodoCola<T> *sale;
    while (fin) {
        sale = fin;
        fin = fin->siguiente;
        delete sale;
    }
}

template <typename T>
void PlCola<T>::llegada(const T&dato) {
    class PlNodoCola<T> *nuevo;
    nuevo = new class PlNodoCola<T>;
    nuevo->dato = dato;
    if (inicio == nullptr) {
        inicio = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

template <typename T>
void PlCola<T>::atencion(T&dato) {
    class PlNodoCola<T> *sale;
    // atencion no puede ser llamada si esta vacia, sino la instruccion de
    // abajo haria que se caiga el programa
    dato = inicio->dato;
    sale = inicio;
    inicio = inicio->siguiente;
    // puede que sea el unico elemento de la cola
    delete sale;
    if (inicio == nullptr) fin = nullptr;
}

template <typename T>
bool PlCola<T>::estaVacia() {
    return fin == nullptr;
}

template <typename T>
void PlCola<T>::mostrar(ofstream&arch) {
    class PlNodoCola<T> *p = inicio;
    while (p) {
        arch << p->dato;
        arch << endl;
        p = p->siguiente;
    }
}

#endif /* PLCOLA_H */

