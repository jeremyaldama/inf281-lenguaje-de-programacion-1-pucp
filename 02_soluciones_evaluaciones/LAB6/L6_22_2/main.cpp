/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 23 de mayo de 2023, 18:26
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"

int main(int argc, char** argv) {
    void *arreglo, *pilaini, *pilafin;
    cargaarreglo(arreglo, cmpnumero, leenumero, "Numeros.txt");
    void **p = (void**)arreglo;
    
    for (int i=0; p[i]; i++) {
        cout << *(int*)p[i] << endl;
    }
    
    cargapila(pilaini, arreglo);
    cout << "vamosss" << endl;
    void **pila = (void**)pilaini;
    cout << (*(int*)pila[1]) << endl;
    void **rec = (void**)pila[0];
    
    for (int i=0; rec; i++) {
        cout << *(int*)rec[1] << endl;
        rec = (void**)rec[0];
    }
    
    muevepila(pilaini, pilafin);
    return 0;
}

