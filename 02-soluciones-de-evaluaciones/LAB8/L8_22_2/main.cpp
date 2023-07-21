/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 12 de junio de 2023, 9:50
 */

#include <iostream>
#include <iomanip>
#include "farmacia.h"

using namespace std;

int main(int argc, char** argv) {
    class farmacia ofarma;
    
    ofarma.cargamedico();
    ofarma.leerecetas();
    ofarma.imprimirrecetas();
    
    return 0;
}

