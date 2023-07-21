/* 
 * File:   FunNumeros.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 23 de mayo de 2023, 23:30
 */

#ifndef FUNNUMEROS_H
#define FUNNUMEROS_H
#include <fstream>
using namespace std;
void *leenumero(ifstream&arch) ;
int cmpnumero(void*i, void*j) ;

void imprimenumero(ofstream&arch, void*n);

#endif /* FUNNUMEROS_H */
