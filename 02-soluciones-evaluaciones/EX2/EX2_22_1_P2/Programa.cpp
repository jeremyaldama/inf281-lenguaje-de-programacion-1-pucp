/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Programa.cpp
 * Author: Danie
 * 
 * Created on 28 de junio de 2023, 20:37
 */

#include "Programa.h"
#include "Categoria1.h"
#include "Categoria2.h"
#include "Categoria3.h"

void Programa::carga() {
    CargaProductos("Productos4.csv");
    CargaLista("Pedidos4.csv");
}

void Programa::abrirArchivoLectura(ifstream&arch, const char*nom) {
    arch.open(nom, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR " << nom;
        exit(1);
    }
}

void Programa::abrirArchivoEscritura(ofstream&arch, const char*nom) {
    arch.open(nom, ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR " << nom;
        exit(1);
    }
}

void Programa::CargaProductos(const char*nom) {
    ifstream arch;
    abrirArchivoLectura(arch, nom);
//    ofstream prueba;
//    abrirArchivoEscritura(prueba, "prueba.txt");
    class NProductos nodo;
    while (1) {
        nodo.leerProducto(arch);
        if (arch.eof()) break;
        vproductos.push_back(nodo);
    }
}

void Programa::CargaLista(const char*nom) {
    ifstream arch;
    abrirArchivoLectura(arch, nom);

    lpedidos.cargaLista(arch);
}

void Programa::actualiza() {
//    int cod_prods[500], prioridad[500];
    
    lpedidos.reordenar(vproductos);
}

void Programa::muestra() {
    ofstream arch;
    abrirArchivoEscritura(arch, "Reporte.txt");

    ImprimeProductos(arch);
    ImprimeLista(arch);
}

void Programa::ImprimeProductos(ofstream&arch) {
    // Esto se haria dentro de vector pero como la tad ya esta definida no se
    // puede y lo hacemos afuera
    for (NProductos prod : vproductos) {
        prod.imprime(arch);
    }
}

void Programa::ImprimeLista(ofstream&arch) {
    lpedidos.mostrarLista(arch);
}