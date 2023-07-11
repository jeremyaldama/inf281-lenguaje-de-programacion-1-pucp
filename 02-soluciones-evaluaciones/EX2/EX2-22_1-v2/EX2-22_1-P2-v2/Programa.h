/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.h
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:37
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "Lista.h"
#include "NProductos.h"
#include <vector>
#include <algorithm>

class Programa {
public:
    void abrirArchivoLectura(ifstream&arch, const char*cad);
    void abrirArchivoEscritura(ofstream&arch, const char*cad);
    void carga();
    void CargaProductos();
    void CargaLista();
    void muestra();
    void ImprimeProductos();
    void ImprimeLista();
    void actualiza();
    void ordenarProductos();
private:
    class Lista lpedidos;
    vector<NProductos> vproductos;
};

#endif /* PROGRAMA_H */

