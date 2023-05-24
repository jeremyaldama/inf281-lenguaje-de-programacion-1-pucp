/* 
 * File:   FunNumeros.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 23 de mayo de 2023, 23:30
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "FunNumeros.h"

using namespace std;

void *leenumero(ifstream&arch) {
    int num;
    arch >> num;
    if (arch.eof()) return nullptr;
    void **num2 = new void*[3]{};
    num2[0] = new int{num};
    return num2;
}
int cmpnumero(void*i, void*j) {
    return *(int*)i - *(int*)j;
}

void imprimenumero(ofstream&arch, void*n) {
    arch << *(int*)n << endl;
}