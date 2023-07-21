/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 12 de junio de 2023, 22:59
 */

#include <iostream>
#include <iomanip>

#include "Tienda.h"
using namespace std;

int main(int argc, char** argv) {
    Tienda tien;
    
    tien.carga();
    tien.actualiza(20);
    tien.muestra();
    return 0;
}

