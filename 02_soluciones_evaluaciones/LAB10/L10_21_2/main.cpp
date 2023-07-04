/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 23 de junio de 2023, 23:23
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca bib;
    
    bib.LeerLibros();
    bib.ActualizaLibros();
    bib.ImprimeLibros();
    return 0;
}

