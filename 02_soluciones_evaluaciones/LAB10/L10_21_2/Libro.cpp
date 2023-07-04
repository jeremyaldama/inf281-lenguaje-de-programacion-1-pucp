/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Danie
 * 
 * Created on 23 de junio de 2023, 23:25
 */

#include "Libro.h"

Libro::Libro() {
    autor = codigo = titulo = nullptr;
}

Libro::Libro(const Libro& orig) {
    *this = orig;
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

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Libro::GetCantidad() const {
    return cantidad;
}

void Libro::SetAutor(const char* cad) {
    if (autor) delete autor;
    autor = new char[strlen(cad)+1];
    strcpy(autor, cad);
}

void Libro::GetAutor(char*n) const {
    if (autor) strcpy(n, autor);
    else n[0] = 0;
}

void Libro::SetTitulo(const char* cad) {
    if (titulo) delete titulo;
    titulo = new char[strlen(cad)+1];
    strcpy(titulo, cad);
}

void Libro::GetTitulo(char*n) const {
    if (titulo) strcpy(n, titulo);
    else n[0] = 0;
}

void Libro::SetCodigo(const char* cad) {
    if (codigo) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo, cad);
}

void Libro::GetCodigo(char*n) const {
    if (codigo) strcpy(n, codigo);
    else n[0] = 0;
}

void Libro::operator =(const class Libro&lib) {
    SetAnho(lib.anho);
    SetAutor(lib.autor);
    SetCantidad(lib.cantidad);
    SetCodigo(lib.codigo);
    SetPrecio(lib.precio);
    SetStock(lib.stock);
    SetTitulo(lib.titulo);
}

bool Libro::operator >(const class Libro&lib) {
    return strcmp(codigo, lib.codigo) > 0;
}

void Libro::actualiza() {
    if (stock > 0) stock--;
}

void operator >> (ifstream&arch, class Libro &lib) {
    char codigo[100];
    arch.getline(codigo, 100, ',');
    if (arch.eof()) return;
    char descripcion[100], autor[100], c;
    int anio, cant;
    double precio;
    arch.getline(descripcion, 100, ',');
    arch.getline(autor, 100, ',');
    arch >> anio >> c >> cant >> c >> precio;
    arch.get();
    
    lib.SetAnho(anio);
    lib.SetAutor(autor);
    lib.SetCantidad(cant);
    lib.SetCodigo(codigo);
    lib.SetPrecio(precio);
    lib.SetStock(cant);
    lib.SetTitulo(descripcion);
}

void operator << (ofstream&arch, class Libro &lib) {
    char codigo[100], titulo[100], autor[100];
    lib.GetCodigo(codigo);
    lib.GetAutor(autor);
    lib.GetTitulo(titulo);
    arch << "Codigo: " << codigo << endl;
    arch << "Titulo: " << titulo << endl;
    arch << "Cantidad: " << lib.GetCantidad() << endl;
    arch << "Stock: " << lib.GetStock() << endl;
}

