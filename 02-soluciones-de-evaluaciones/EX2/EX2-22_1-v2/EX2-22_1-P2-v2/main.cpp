/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 16:05
 */

#include <cstdlib>

using namespace std;
#include "Programa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    // nos van a dar lo que va en main?
    class Programa programa;
    programa.carga();
    programa.actualiza();
    programa.ordenarProductos();
    programa.muestra();
    cout << endl << "programa termina y elimina todo lo general " << endl;
    // aca se deberia empezar a eliminar los nodos pero no hay un destructor
    // de los nodos
    return 0;
}

