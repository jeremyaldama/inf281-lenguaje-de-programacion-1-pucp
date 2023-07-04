#include "funcion.h"
#include <iostream>
using namespace std;

double operator ++(tregistro &notas, int b){
    double promedio = 0;
    for(int i = 0; i < notas.n; i++){
        promedio += notas.lab[i];
    }
    promedio /= notas.n;
    return promedio;
}

ostream &operator <<(ostream &salida, const tregistro &notas){
    salida << "Notas: ";
    for(int i = 0; i < notas.n; i++){
        salida << notas.lab[i] << " ";
    }
    salida << endl;
    return salida;
}

tregistro &operator +(tregistro &notas, const tregistro &curva){
    for(int i = 0; i < notas.n; i++){
        notas.lab[i] += curva.lab[i];
    }
    return notas;
} 