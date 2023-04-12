#include "funcion.h"

double operator ++(tregistro &notas, int b){
    double promedio = 0;
    for(int i = 0; i < notas.n; i++){
        promedio += notas.lab[i];
    }
    promedio /= notas.n;
    return promedio;
}