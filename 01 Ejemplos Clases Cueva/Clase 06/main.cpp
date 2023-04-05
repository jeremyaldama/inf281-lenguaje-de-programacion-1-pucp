/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 5 de abril de 2023, 10:22
 */

#include <iostream>
#include <iomanip>
#include "funciones.h"

using namespace std;

int main(int argc, char** argv) {
    genera_alumnos_bin();
    generar_consolidado();
    imprimir_consolidado();
    return 0;
}

