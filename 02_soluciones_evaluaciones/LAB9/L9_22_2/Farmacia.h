/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Farmacia.h
 * Author: Danie
 *
 * Created on 20 de junio de 2023, 19:18
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "Oferta.h"

class Farmacia {
public:
    void leerecetas();
    void descuenta();
    void imprimirrecetas();
private:
    class Oferta loferta[1000];
};

#endif /* FARMACIA_H */

