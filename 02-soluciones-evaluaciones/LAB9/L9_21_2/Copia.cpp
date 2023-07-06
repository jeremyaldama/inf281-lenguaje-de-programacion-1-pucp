/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Copia.cpp
 * Author: Danie
 * 
 * Created on 22 de junio de 2023, 0:50
 */

#include "Copia.h"

Copia::Copia() {
    numero = 0;
    Olibro = nullptr;
    estado = new char[strlen("Disponible") + 1];
    strcpy(estado, "Disponible");
}

Copia::Copia(const Copia& orig) {
}

Copia::~Copia() {
    if (estado) delete estado;
    // se tiene que hacer delete al puntero a la clase base?
    if (Olibro) delete Olibro;
}

void Copia::SetEstado(const char* n) {
    if (estado) delete estado;
    estado = new char[strlen(n) + 1];
    strcpy(estado, n);
}

void Copia::GetEstado(char *n) const {
    if (!estado) n[0] = 0;
    else strcpy(n, estado);
}

void Copia::SetNumero(int numero) {
    this->numero = numero;
}

int Copia::GetNumero() const {
    return numero;
}

void Copia::AsignaCopia(const char*codigo, const char*descrip, const char*autor,
        int aa, int cantidad, double precio, int zona, int numero) {
    SetNumero(numero);
    // todos ya tienen el estado "Disponible" al momento de ser creadas
    Olibro = new class Disponible;
    Olibro->AsignaCopia(codigo, descrip, autor, aa, cantidad, precio, zona,
            numero);
}

void Copia::ObtenerCodigo(char*n) {
    // no es necesario el if porque cada llibro tiene un Olibro
    Olibro->GetCodigo(n);
}

void Copia::Actualiza(const char*n, int dias, int fecha, int num_lib) {
    int aa, cantidad;
    double precio;
    char autor[100], codigo[100], titulo[100];
    aa = Olibro->GetAnho();
    Olibro->GetAutor(autor);
    cantidad = Olibro->GetCantidad();
    Olibro->GetCodigo(codigo);
    precio = Olibro->GetPrecio();
    Olibro->GetTitulo(titulo);
    
    delete Olibro;
    if (strcmp(n, "Perdida") == 0) {
        Olibro = new class Perdida;
    } else { // prestamo
        Olibro = new class Prestamo;
    }
    //virtual void AsignaCopia(const char*codigo, const char*descrip, const char*autor, 
//                    int aa, int cantidad, double precio, int zona, int num)
    Olibro->Actualiza(codigo, titulo, autor, aa, cantidad, precio, num_lib,
            dias, fecha);
}

void Copia::ImprimirCopia(ofstream&arch) {
    Olibro->Imprimir(arch);
}

int Copia::ObtenerCantidad() {
    return Olibro->GetCantidad();
}

int Copia::fin() {
    return Olibro == nullptr;
}

void Copia::imprimirCabecera(ofstream&arch) {
    char n[100];
    Olibro->GetCodigo(n);
    arch << "Codigo: " << n << endl;
    Olibro->GetTitulo(n);
    arch << "Titulo: " << n << endl;
    Olibro->GetAutor(n);
    arch << "Autor: " << n << endl;
    arch << "Cantidad: " << Olibro->GetCantidad() << endl;
    arch << " -------------------------------------------" << endl;
}