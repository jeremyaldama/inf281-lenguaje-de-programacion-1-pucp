/* 
 * File:   PilaConEnteros.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 1 de junio de 2023, 0:18
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H
#include <fstream>
using namespace std;

void* leenumero(ifstream&arch);

int cmpnumero(const void*a, const void*b);

#endif /* PILACONENTEROS_H */
