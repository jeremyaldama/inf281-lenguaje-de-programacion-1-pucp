/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de octubre de 2020, 09:01 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20202_Preg01.h"
using namespace std;

int main(int argc, char** argv) {
    void *pedidos, *stock;
    leerDatos(pedidos,stock);
    atiende(pedidos,stock);
    imprimirDatos(pedidos);
    return (EXIT_SUCCESS);
}

