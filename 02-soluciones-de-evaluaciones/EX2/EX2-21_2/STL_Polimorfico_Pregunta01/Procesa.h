/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:34
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <list>
#include <vector>
#include "Libro.h"
#include "ColaSol.h"
#include "NUsuario.h"

class Procesa {
public:
    Procesa();
    Procesa(const Procesa& orig);
    virtual ~Procesa();
    void abrirArchivoLectura(ifstream&arch, const char* cad);
    void abrirArchivoEscritura(ofstream&arch, const char* cad);
    
    void carga();
    void CargaLibros();
    void CargaUsuarios();
    void LeeSolicitudes();
    void Imprime();
    void ImprimeCola();
    void ImprimeLibros();
    void Atiende();
private:
    vector<Libro> llibros;
    ColaSol cola;
    vector<NUsuario> vusuarios;
};

#endif /* PROCESA_H */

