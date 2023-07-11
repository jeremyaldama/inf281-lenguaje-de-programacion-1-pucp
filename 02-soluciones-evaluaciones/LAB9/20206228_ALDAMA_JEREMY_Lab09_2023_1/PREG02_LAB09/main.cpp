/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 23 de junio de 2023, 08:53 AM
 */
// JEREMY DANIEL ALDAMA GIRALDO 20206228
#include <cstdlib>

using namespace std;
#include "Tesoreria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria OTeso;
    
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    return 0;
}

