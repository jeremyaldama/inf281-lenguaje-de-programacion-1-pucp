/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 0:44
 */

#include "Libro.h"

Libro::Libro() {
    anho = cantidad = precio = 0;
    autor = codigo = titulo = nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if (autor) delete autor;
    if (codigo) delete codigo;
    if (titulo) delete titulo;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetAnho(int anho) {
    this->anho = anho;
}

int Libro::GetAnho() const {
    return anho;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}

void Libro::SetAutor(const char* n) {
    if (autor) delete autor;
    autor = new char[strlen(n)+1];
    strcpy(autor, n);
}

void Libro::GetAutor(char *n) const {
    if (!autor) n[0] = 0;
    else strcpy(n, autor);
}

void Libro::SetTitulo(const char* n) {
    if (titulo) delete titulo;
    titulo = new char[strlen(n)+1];
    strcpy(titulo, n);
}

void Libro::GetTitulo(char*n) const {
    if (!titulo) n[0] = 0;
    else strcpy(n, titulo);
}

void Libro::SetCodigo(const char* c) {
    if (codigo) delete codigo;
    codigo = new char[strlen(c)+1];
    strcpy(codigo, c);
}

void Libro::GetCodigo(char*n) const {
    if (!codigo) n[0] = 0;
    else strcpy(n, codigo);
}

void Libro::AsignaCopia(const char*cod, const char*descrip, const char*autor, 
                    int aa, int cantidad, double precio, int zona, int num) {
    SetAnho(aa);
    SetAutor(autor);
    SetCantidad(cantidad);
    SetCodigo(cod);
    cout << codigo << endl;
    SetPrecio(precio);
    SetTitulo(descrip);
}

void Libro::Actualiza(const char*codigo, const char*titulo, 
            const char*autor, int aa, int cantidad, double precio, int num_lib,
            int dias, int fecha) {
    SetAnho(aa);
    SetAutor(autor);
    SetCantidad(cantidad);
    SetCodigo(codigo);
    SetPrecio(precio);
    SetTitulo(titulo);
}