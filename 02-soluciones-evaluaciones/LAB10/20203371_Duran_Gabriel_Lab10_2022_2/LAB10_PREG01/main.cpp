/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 * Nombre: Gabriel Omar Durán Ruiz
 * Codigo: 20203371
 * Created on 25 de noviembre de 2022, 08:03 AM
 */

#include <cstdlib>

#include "almacen.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    almacen alma;
    alma.carga();
    alma.actualiza();
    alma.imprime();
    return 0;
}

