/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 20 de junio de 2023, 18:45
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Farmacia.h"

int main(int argc, char** argv) {
    Farmacia Pedidos;
    
    Pedidos.leerecetas();
    Pedidos.descuenta();
    Pedidos.imprimirrecetas();
    return 0;
}

