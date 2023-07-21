/* 
 * Archivo:   ArbolBBG.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:43 AM
 */

#ifndef ARBOLBBG_H
#define ARBOLBBG_H
#include <fstream>
#include "NodoArbolG.h"
using namespace std;

template <typename T>
class ArbolBBG {
private:

    NodoArbolG<T> *arbol;
    void imprime (NodoArbolG<T> *&nodo, ofstream &arch);   
    NodoArbolG<T> *buscar (NodoArbolG<T>*& nodo, int valor);
    void inserta (NodoArbolG<T> *&nodo, const T &data);
    void eliminar (NodoArbolG<T> *&nodo);

public:

    ArbolBBG();
    virtual ~ArbolBBG();
    void crear (const char *nombArch);
    void insertar (const T &data);
    void imprimir (ofstream &arch);
    void modificar (int valor, double modifica);

};

template <typename T>
ArbolBBG<T>::ArbolBBG() {
    arbol = nullptr;
}

template <typename T>
ArbolBBG<T>::~ArbolBBG() {
    this->eliminar(arbol);
}

template <typename T>
void ArbolBBG<T>::crear(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    T dato;
    while (1) {
        arch >> dato;
        if (arch.eof()) break;
        this->inserta(arbol,dato); // ok
    }
}

template <typename T>
void ArbolBBG<T>::inserta(NodoArbolG<T> *&nodo, const T &data) {
    if (nodo == nullptr) {
        NodoArbolG<T> *nuevo;
        nuevo = new NodoArbolG<T>;
        nuevo->dato = data; 
        nodo = nuevo;
        return;
    } else {
        if (nodo->dato > data) inserta(nodo->izq,data);
        else inserta(nodo->der,data); // ok
    }
}

template <typename T>
void ArbolBBG<T>::insertar(const T& data) {
    this->inserta(arbol,data);
}

template <typename T>
void ArbolBBG<T>::modificar(int valor, double modifica) {
    NodoArbolG<T> *nodo;
    nodo = buscar(arbol,valor);
    if (nodo != nullptr) nodo->dato += modifica; // ok
}

template <typename T>
NodoArbolG<T> *ArbolBBG<T>::buscar(NodoArbolG<T>*& nodo, int valor) {
    if (nodo == nullptr) return nullptr;
    if (nodo->dato == valor) return nodo;
    else if (nodo->dato > valor) return buscar(nodo->izq,valor);
    else return buscar(nodo->der,valor);
}

template <typename T>
void ArbolBBG<T>::imprimir(ofstream &arch) {
    this->imprime(arbol,arch);
}

template <typename T>
void ArbolBBG<T>::imprime(NodoArbolG<T>*& nodo, ofstream& arch) {
    if (nodo != nullptr) {
        imprime(nodo->izq,arch);
        arch << nodo->dato;
        imprime(nodo->der,arch);
    }
}

template <typename T>
void ArbolBBG<T>::eliminar(NodoArbolG<T>*& nodo) {
    if (nodo == nullptr) return;
    this->eliminar(nodo->izq);
    this->eliminar(nodo->der);
    delete nodo;
}

#endif /* ARBOLBBG_H */
