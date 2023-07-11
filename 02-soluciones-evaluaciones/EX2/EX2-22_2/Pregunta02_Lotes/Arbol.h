/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:16
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "vencido.h"
#include "activo.h"

class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    
    void cargarArbol(ifstream&arch, int, const char*cad);
    void insertarMedicamento(class medicamento *med);
    void mostrarArbol(ofstream&arch);
    void actualizar(int, const char*);
private:
    class Nodo *raiz; // ordenado por la fecha del lote de medicamentos, en caso sea igual sera determinado por el codigo del medicamento
    void insertarMedicamentoRecursivo(class Nodo *&raiz, medicamento *);
    void mostrarArbolRecursivo(ofstream&arch, class Nodo*raiz);
    void actualizarRecursivo(class Nodo*raiz, int fecha_actual, const char*inspector);
};

#endif /* ARBOL_H */

