/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 2 de mayo de 2023, 12:48
 */

#include <iostream>
#include <iomanip>
#include "MetodoDinamicoExacto.h"
using namespace std;

int main(int argc, char** argv) {
    char **med_Nombre, **med_Especialidad, **pac_Nombre;
    int *med_Codigo, *pac_Dni, **pac_Citas;
    double *med_Tarifa;
    
    lecturaDeMedicos("Medicos.csv", med_Codigo, med_Nombre, med_Especialidad,
            med_Tarifa);
    pruebaDeLecturaDeMedicos("ReporteDeMedicos.txt", med_Codigo, med_Nombre,
            med_Especialidad, med_Tarifa);
    
    lecturaDeCitas("Citas.csv", pac_Dni, pac_Nombre, pac_Citas);
    pruebaDeLecturaDeCitas("ReporteDeCitas.txt", pac_Dni, pac_Nombre,
            pac_Citas);
    
//    reporteDeIngresosMedicosYGastosDeLosPacientes(
//            "ReporteDeIngresosMedicos.txt", med_Codigo, med_Nombre, 
//            med_Especialidad, med_Tarifa, pac_Dni, pac_Nombre, pac_Citas);
    return 0;
}

