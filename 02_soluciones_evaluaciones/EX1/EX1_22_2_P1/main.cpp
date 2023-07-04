/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 13 de mayo de 2023, 18:04
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int *med_Codigo, ***consultas_int;
    double *med_Precio;
    char **med_Descripcion, ***consultar_char;
    
    CargarMedicamentos(med_Codigo, med_Descripcion, med_Precio, 
            "Medicinas-Preg01.csv");
    PruebaDeCargaDeMedicamentos(med_Codigo, med_Descripcion, med_Precio,
            "PruebaMedicinas.txt");
    return 0;
}

