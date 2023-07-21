/* 
 * File:   PilaConEnteros.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 1 de junio de 2023, 0:18
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "PilaConEnteros.h"

using namespace std;

void* leenumero(ifstream&arch) {
    int n;
    arch >> n;
    if (arch.eof()) return nullptr;
    void *dato;
    dato = new int{n};
    return dato;
}

int cmpnumero(const void*a, const void*b) {
    void**i = (void**)a, **j = (void**)b;
    
    return (*(int*)(*i))-(*(int*)(*j));
}
