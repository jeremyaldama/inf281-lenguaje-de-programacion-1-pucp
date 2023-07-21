/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   main.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:01
 */

#include "BibGenerica.h"
#include "FunNumeros.h"
#include "FunPedidos.h"
using namespace std;

int main(int argc, char** argv) {
    void *arbol;
    creaarbol(arbol, leenumero, cmpnumero, "numeros.txt");
    muestraarbol(arbol, imprimenumero, "reporte.txt");
    
    creaarbol(arbol, leepedido, cmppedido, "pedidos2.csv");
    muestraarbol(arbol, imprimepedido, "reporteped.txt");
    
    return 0;
}