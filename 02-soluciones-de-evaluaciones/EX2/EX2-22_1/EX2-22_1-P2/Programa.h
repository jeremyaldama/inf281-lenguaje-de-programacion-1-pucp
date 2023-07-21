/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Programa.h
 * Author: Danie
 *
 * Created on 28 de junio de 2023, 20:37
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "Lista.h"
#include "NProductos.h"
#include <vector>

class Programa {
public:
    void abrirArchivoLectura(ifstream&, const char*);
    void abrirArchivoEscritura(ofstream&, const char*);
    void carga();
    void actualiza();
    void muestra();
private:
    class Lista lpedidos;
    // se puede crear una copia del vector de NProductos y ya no romperia el
    // encapsulamiento?
    vector<NProductos> vproductos;
    
    void CargaProductos(const char*);
    void CargaLista(const char*);
    void ImprimeProductos(ofstream&);
    void ImprimeLista(ofstream&);
};

#endif /* PROGRAMA_H */

