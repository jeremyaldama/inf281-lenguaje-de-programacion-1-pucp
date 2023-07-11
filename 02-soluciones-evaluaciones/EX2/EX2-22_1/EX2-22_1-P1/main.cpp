/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de junio de 2023, 22:38
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Empresa.h"

int main(int argc, char** argv) {
    class Empresa empresa;
    empresa.leerClientes("clientes.csv");
    empresa.imprimirClientes("PruebaClientes.txt");
    empresa.leerPedidos("Pedidos.csv");
    empresa.ordenarPedidos();
    empresa.imprimirProductos("ReporteDeProductos.txt");
    empresa.imprimirClientes("ReporteDeClientes.txt");
    return 0;
}

