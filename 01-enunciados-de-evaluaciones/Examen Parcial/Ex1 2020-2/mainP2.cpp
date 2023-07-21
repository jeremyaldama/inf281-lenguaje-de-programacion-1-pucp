/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de octubre de 2020, 08:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20202_Preg02.h"
using namespace std;

int main(int argc, char** argv) {
    char **clientes, ***strProductos;
    int ***intProductos;
    leerDatos(clientes,intProductos,strProductos);
    imprimirDatos(clientes,intProductos,strProductos);
    return (EXIT_SUCCESS);
}

