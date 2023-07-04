#ifndef sobrecarga_h
#define sobrecarga_h
#include "funcion.h"

double operator ++(tregistro &, int);
ostream &operator <<(ostream &salida, const tregistro &notas);
tregistro &operator +(tregistro &notas, const tregistro &curva);

#endif