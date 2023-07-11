/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 17:43
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Libro.h"
#include "RegistroUsuario.h"
#include <vector>

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    
    void abrirArchivoLectura(ifstream&arch, const char* cad);
    void abrirArchivoEscritura(ofstream&arch, const char* cad);
    
    void leeLibros(const char* cad);
    void imprimeLibros(const char* cad);
    void leerUsuarios(const char* cad);
    void leerPrestamos(const char* cad);
    void imprimeUsuarios(const char* cad);
    void imprimeSuspendidos(const char*nom, int dd, int mm, int aa);
    int buscarUsuario(int carne);
    void actualizarPrestados(const char* cad);
    
private:
    vector<Libro> libros;
    vector<RegistroUsuario> usuarios;
};

#endif /* BIBLIOTECA_H */

