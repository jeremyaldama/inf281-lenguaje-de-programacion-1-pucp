/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.h
 * Author: alulab14
 *
 * Created on 25 de noviembre de 2022, 08:11 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include <fstream>
using namespace std;
#include "Arbol.h"
class almacen {
public:
    void carga();
    void actualiza();
    void imprime();
    void leeMedicamento(medicamento *&med,ifstream &arch);
private:
    Arbol arbolalma;
};

#endif /* ALMACEN_H */

