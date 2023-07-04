/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 28 de junio de 2023, 11:05
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Programa.h"

int main(int argc, char** argv) {
    class Programa prog;
    prog.carga();
    prog.actualiza();
    prog.muestra();
    return 0;
}

