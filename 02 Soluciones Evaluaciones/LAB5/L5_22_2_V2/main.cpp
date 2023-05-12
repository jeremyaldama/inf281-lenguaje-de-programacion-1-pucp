/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 11 de mayo de 2023, 14:14
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "MetodoPorIncrementos.h"

int main(int argc, char** argv) {
    char***medicoDatos, ****citaPaciente;
    int**citaCantidad;
    double*medicoTarifaHora, ***citaTiempoYPago;

    cargarCitas("Citas.csv", medicoDatos, medicoTarifaHora, citaPaciente,
            citaCantidad, citaTiempoYPago);
    ofstream arch("reporte.txt", ios::out);
    arch << setprecision(2) << fixed;
    for (int i=0; medicoDatos[i]; i++) {
        arch << left << setw(12) << medicoDatos[i][0] << setw(60) << 
                medicoDatos[i][1] << medicoTarifaHora[i] << endl;
        arch << "CITAS: " << endl;
        
        for (int j=0; citaPaciente[i][j]; j++){
            arch << right << setw(15) << citaPaciente[i][j][0] << 
                    "       " << left << setw(60) << citaPaciente[i][j][1] << 
                    setw(10) << citaCantidad[i][j] << setw(10) <<
                    citaTiempoYPago[i][j][0] << citaTiempoYPago[i][j][1] << endl;
        }
        arch << endl;
    }
    return 0;
}

