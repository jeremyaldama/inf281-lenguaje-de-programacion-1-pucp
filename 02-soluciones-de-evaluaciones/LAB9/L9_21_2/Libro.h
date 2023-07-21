/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 0:44
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(const char* autor);
    void GetAutor(char*) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    virtual void AsignaCopia(const char*codigo, const char*descrip, const char*autor, 
                    int aa, int cantidad, double precio, int zona, int num);
    virtual void Actualiza(const char*codigo, const char*titulo, 
            const char*autor, int aa, int cantidad, double precio, int num_lib,
            int dias, int fecha);
    virtual void Imprimir(ofstream&) = 0;
    
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int anho;
    double precio;
};

#endif /* LIBRO_H */

