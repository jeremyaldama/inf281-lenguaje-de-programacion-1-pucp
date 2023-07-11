/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:18
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "Arbol.h"

class almacen {
public:
    almacen();
    almacen(const almacen& orig);
    virtual ~almacen();
    void abrirArchivoLectura(ifstream&arch, const char*cad);
    void abrirArchivoEscritura(ofstream&arch, const char*cad);
    void carga(int fecha_actual, const char*);
    void imprime();
    void actualiza(int fecha, const char* apellido);
private:
    class Arbol arbolalma; // se guardan todos los medicamentos 
};

#endif /* ALMACEN_H */

