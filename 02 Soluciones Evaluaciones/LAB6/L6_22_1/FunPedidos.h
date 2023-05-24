/* 
 * File:   FunPedidos.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 24 de mayo de 2023, 14:06
 */

#ifndef FUNPEDIDOS_H
#define FUNPEDIDOS_H
#include <fstream>
using namespace std;

void *leepedido(ifstream&arch) ;
int cmppedido(void*i, void*j);

void imprimepedido(ofstream&arch, void*n);

#endif /* FUNPEDIDOS_H */
