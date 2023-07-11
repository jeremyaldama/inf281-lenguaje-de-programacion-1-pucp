/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de junio de 2023, 08:02 AM
 */
// JEREMY DANIEL ALDAMA GIRALDO 20206228
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "arreglos_genericos.h"
#include "BibliotecaRegistro.h"
#include "listas_genericas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *arreglo_heroes, *lista_heroes;
    int cantidad_total_heroes;
    llenar_arreglo_heroes(arreglo_heroes, cantidad_total_heroes,
            leer_registro_heroe,
            "heroes_changelog_1223.csv");
    cout << "COMPARAMOS" << endl;
    qsort(arreglo_heroes, cantidad_total_heroes, sizeof(void*), 
            cmp_multicriterio_void);
    ofstream arch("prueba.txt", ios::out);
    void **heroes = (void**)arreglo_heroes;
    for (int i=0; i<cantidad_total_heroes; i++) {
        imprimir_registro_heroe(arch, heroes[i]);
    }
    
//    crear_lista_heroes(arreglo_heroes, lista_heroes, leer_heroe);
//    
//    imprimir_lista_heroes(lista_heroes, imprimir_registro_heroe);
//    eliminar_lista_heroes_repetidos(lista_heroes, eliminar_registro);
    return 0;
}

