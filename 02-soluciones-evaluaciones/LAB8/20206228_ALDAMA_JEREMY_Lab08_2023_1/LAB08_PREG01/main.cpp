/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 16 de junio de 2023, 08:02 AM
 */
// JEREMY DANIEL ALDAMA GIRALDO 20206228
#include <iostream>

using namespace std;
#include "Tesoreria.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    return 0;
}

