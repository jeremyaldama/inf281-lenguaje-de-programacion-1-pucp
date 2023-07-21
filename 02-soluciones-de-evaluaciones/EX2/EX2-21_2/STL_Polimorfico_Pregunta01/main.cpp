/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:22
 */

#include <cstdlib>

using namespace std;
#include "Procesa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    
    pro.carga();
    pro.Atiende();
    pro.Imprime();
    return 0;
}

