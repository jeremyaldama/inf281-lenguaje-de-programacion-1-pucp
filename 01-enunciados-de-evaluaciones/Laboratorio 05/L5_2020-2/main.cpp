/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 16 de octubre de 2020, 08:01 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
using namespace std;

int main(int argc, char** argv) {
    char **codMed, **nombMed, ***nombPac;
    int **codPac, **veces;
    double *tarifas, **porcPac;
    leerMedicos(codMed,nombMed,tarifas);
    imprimirMedicos(codMed,nombMed,tarifas);
    leeAtenciones(codMed,codPac,nombPac,porcPac,veces);
    repDeIngresos(codMed,nombMed,tarifas,codPac,nombPac,porcPac,veces);
    return (EXIT_SUCCESS);
}

