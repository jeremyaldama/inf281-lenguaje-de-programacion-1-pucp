/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 23 de junio de 2023, 23:18
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Promociones.h"

int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();
    return 0;
}

