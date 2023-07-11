/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PlNodoCola.h
 * Author: Danie
 *
 * Created on 14 de junio de 2023, 22:41
 */


#ifndef PLNODOCOLA_H
#define PLNODOCOLA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PlCola.h"

// hace saber al compilador que PlCola existe y permite a la declaracion
// friend PlCola compilar
template <typename T> class PlCola;

template <typename T>
class PlNodoCola {
private:
    T dato;
    // el nodo siguiente también debe tener el mismo tipo que se le pasa
    // inicialmente
    class PlNodoCola<T> *siguiente;
public:
    PlNodoCola();
    friend class PlCola<T>;
};

template <typename T>
PlNodoCola<T>::PlNodoCola() {
    siguiente = nullptr;
}

#endif /* PLNODOCOLA_H */

