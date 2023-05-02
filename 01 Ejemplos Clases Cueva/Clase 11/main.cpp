/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de abril de 2023, 9:04
 */

#include <iostream>
#include <iomanip>
#include "MetodoExacto.h"
using namespace std;

int main(int argc, char** argv) {
    char**cli_nombre, *cli_categoria;
    int *cli_dni;
    
    cargaclientes(cli_dni, cli_nombre, cli_categoria);
    imprimirclientes(cli_dni, cli_nombre, cli_categoria);
    return 0;
}

