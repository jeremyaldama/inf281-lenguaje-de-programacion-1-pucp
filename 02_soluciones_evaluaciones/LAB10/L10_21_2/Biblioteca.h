/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Danie
 *
 * Created on 24 de junio de 2023, 11:46
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "ALibro.h"

class Biblioteca {
public:
    void LeerLibros();
    void ImprimeLibros();
    void abrirArchivoLectura(ifstream&arch, const char*nomb);
    void abrirArchivoEscritura(ofstream&arch, const char*nomb);
    void ActualizaLibros();
private:
    class ALibro AStock;
};

#endif /* BIBLIOTECA_H */

