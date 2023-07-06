/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 21 de junio de 2023, 13:41
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca bib;
    bib.GeneraCopias();
    bib.ActualizaLibros();
    bib.ImprimeCopias();
    return 0;
}

