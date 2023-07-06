/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Promociones.h
 * Author: Danie
 *
 * Created on 25 de junio de 2023, 0:05
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H
#include "Lista.h"

class Promociones {
public:
    void abrirArchivoLectura(ifstream&, const char*);
    void abrirArchivoEscritura(ofstream&, const char*);
    void leepedidos();
    void imprimepedidos();
    void actualizapedidos();
private:
    class Lista Lpedidos;
};

#endif /* PROMOCIONES_H */

