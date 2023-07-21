/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 10 de julio de 2023, 21:50
 */

#include <cstdlib>

using namespace std;
#include "Tesoreria.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria boleta;
    boleta.cargaalumnos();
    boleta.actualizaboleta();
    boleta.imprimeboleta();
    return 0;
}

