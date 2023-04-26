/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de abril de 2023, 20:04
 */

#include <iostream>
#include <iomanip>
#include "Estructuras.h"
#include "FuncionesAux.h"

using namespace std;

int main(int argc, char** argv) {
    struct Estructura_ClienteRegistrado clientes[20];
    LeerDatosClientes(clientes);
    struct Estructura_ProductosEnAlmacen productos[100];
    LeerPedidos(clientes, productos);
    ImprimirReporte(clientes, productos);
    return 0;
}

