/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de noviembre de 2020, 11:47 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesLaboratorio07.h"
using namespace std;

int main(int argc, char** argv) {
    void *lpalets, *despachados;
    crealista(lpalets,leeRegistro,comparar);
    imprimelista(lpalets,imprimeRegistro);
    
    despacha(lpalets,despachados,argc,argv);
    imprimelista(lpalets,imprimeRegistro);
    imprimedespachados(despachados,imprimeRegistro);
    return (EXIT_SUCCESS);
}

