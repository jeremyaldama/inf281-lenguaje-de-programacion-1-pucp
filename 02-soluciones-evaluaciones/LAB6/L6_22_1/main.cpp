/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 23 de mayo de 2023, 19:05
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "BigGenerica.h"
#include "FunNumeros.h"
#include "FunPedidos.h"

int main(int argc, char** argv) {
    void *arbol;
    creaarbol(arbol, leenumero, cmpnumero, "numeros.txt");
    muestraarbol(arbol, imprimenumero, "reporte.txt");
    
    creaarbol(arbol, leepedido, cmppedido, "pedidos2.csv");
    muestraarbol(arbol, imprimepedido, "reporteped.txt");
    return 0;
}

