/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Danie
 *
 * Created on 23 de junio de 2023, 23:25
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
    void SetStock(int stock);
    int GetStock() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAutor(const char* autor);
    void GetAutor(char*) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    bool operator >(const class Libro&);
    void operator =(const class Libro&);
    void actualiza();
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int stock;
    int anho;
    double precio;
};

void operator >> (ifstream&arch, class Libro &lib);
void operator << (ofstream&arch, class Libro &lib);

#endif /* LIBRO_H */

