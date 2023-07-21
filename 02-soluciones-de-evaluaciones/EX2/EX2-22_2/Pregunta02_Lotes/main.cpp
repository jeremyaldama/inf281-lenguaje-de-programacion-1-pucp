/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:04
 */
// JEREMY DANIEL ALDAMA GIRALDO 20206228
#include <cstdlib>

using namespace std;
#include "almacen.h"

/*
 * 
 */
int main(int argc, char** argv) {
    almacen alma;
    alma.carga(20220701, "CUEVA");
    alma.actualiza(20221129, "ALDAMA");
    alma.imprime();
    return 0;
}

