/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 6 de julio de 2023, 0:00
 */

// JEREMY DANIEL ALDAMA GIRALDO 20206228
#include <cstdlib>

using namespace std;
#include "Empresa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    class Empresa empresa;
    empresa.leerClientes("Clientes.csv");
    empresa.imprimirClientes("ReporteClientes.txt");
    empresa.leerPedidos("Pedidos.csv");
    empresa.ordenarPedidos();
    empresa.imprimirProductos("ReporteDeProductos.txt");
    empresa.imprimirClientes("ReporteDeClientes.txt");
    return 0;
}

