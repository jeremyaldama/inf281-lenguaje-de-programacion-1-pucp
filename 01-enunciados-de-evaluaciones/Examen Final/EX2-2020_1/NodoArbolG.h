/* 
 * Archivo:   NodoArbolG.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:43 AM
 */

#ifndef NODOARBOLG_H
#define NODOARBOLG_H
#include <fstream>
#include "ArbolBBG.h"
using namespace std;

template <typename T> class ArbolBBG;
template <typename T>
class NodoArbolG {
private:

    T dato;
    NodoArbolG<T> *izq;
    NodoArbolG<T> *der;

public:

    NodoArbolG();
    friend class ArbolBBG<T>;

};

template <typename T>
NodoArbolG<T>::NodoArbolG() {
    izq = nullptr;
    der = nullptr;
}

#endif /* NODOARBOLG_H */
