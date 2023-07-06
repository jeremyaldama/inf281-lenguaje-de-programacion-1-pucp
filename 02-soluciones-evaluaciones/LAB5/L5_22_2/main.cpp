/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 6 de mayo de 2023, 12:50
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "MetodoPorIncrementos.h"

using namespace std;

int main(int argc, char** argv) {
    char***medicoDatos, ****citaPaciente;
    int**citaCantidad;
    double*medicoTarifaHora, ***citaTiempoYPago;

    cargarCitas("Citas.csv", medicoDatos, medicoTarifaHora, citaPaciente,
            citaCantidad, citaTiempoYPago);
    cout << setprecision(2) << fixed;
    ofstream arch("reporte.txt", ios::out);
    for (int i=0; medicoDatos[i]; i++) {
        arch << left << setw(12) << medicoDatos[i][0] << setw(60) << 
                medicoDatos[i][1] << medicoTarifaHora[i] << endl;
//        arch << "CITAS: " << endl;
//        
//        for (int j=0; citaPaciente[i][j]; j++){
//            arch << right << setw(15) << citaPaciente[i][j][0] << 
//                    "       " << citaPaciente[i][j][1] << endl;
//        }
        arch << endl;
    }
//    pruebaDeCargaDeCitas("PruebaDeCargaDeCitas.txt", medicoDatos, medicoTarifaHora,
//            citaPaciente, citaCantidad, citaTiempoYPago);
//    ReporteDeCitasPorMedico("ReporteDeCitasPorMedico.txt", medicoDatos,
//            medicoTarifaHora, citaPaciente, citaCantidad, citaTiempoYPago);
    return 0;
}

