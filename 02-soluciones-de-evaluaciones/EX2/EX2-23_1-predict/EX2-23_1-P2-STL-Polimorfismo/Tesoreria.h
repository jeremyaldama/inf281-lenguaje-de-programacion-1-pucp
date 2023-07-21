/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: alulab14
 *
 * Created on 30 de junio de 2023, 08:11 AM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include <vector>

#include "Nodo.h"
#include "Escala.h"

class Tesoreria {
public:
    void abrirAbrirLectura(ifstream&arch, const char*nom);
    void abrirAbrirEscritura(ofstream&arch, const char*nom);
    void cargaalumnos();
    void imprimeboleta();
    void actualizaboleta();
    void llenarBoleta();
    double buscarPrecioEscala(int codigo);
private:
    vector<Nodo> vectorBoleta;
    vector<Escala> escalas;
};

#endif /* TESORERIA_H */

