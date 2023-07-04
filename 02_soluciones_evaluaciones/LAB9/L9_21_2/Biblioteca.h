/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 1:01
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Copia.h"
#include "FuncionesFecha.h"

class Biblioteca {
public:
    void GeneraCopias();
    void LeerLibroDisponible(ifstream&arch, const char*codigo, int&);
    void ActualizaLibros();
    int BuscarIndiceLibro(const char*cod_lib);
    void ImprimeCopias();
private:
    class Copia llibros[1000];
};

#endif /* BIBLIOTECA_H */

