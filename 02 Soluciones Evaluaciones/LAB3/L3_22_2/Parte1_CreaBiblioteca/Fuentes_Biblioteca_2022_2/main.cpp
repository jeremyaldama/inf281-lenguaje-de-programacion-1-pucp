/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 27 de abril de 2023, 18:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
#include "FuncionesSobrecargas.h"
#include "AperturaDeArchivos.h"

using namespace std;

int main(int argc, char** argv) {
//    struct StCita cita;
//    struct StMedico arregloMedico[3];
//    
////struct StCita{
////    int codigoDelMedico;
////    int fecha;  // Fecha en el formato AAAAMMDD
////    double tarifaPorConsulta;
////    char especialidad[50];   
////};
////struct StMedico{
////    int codigo;
////    char nombre[60];
////    double tarifaPoxConsulta;
////    char especialidad[50];
////};
//    cita.codigoDelMedico = 10;
//    arregloMedico[0].codigo = 10;
//    arregloMedico[1].codigo = 20;
//    arregloMedico[2].codigo = 0;
//     strcpy(arregloMedico[0].especialidad, "HOLA");
//    arregloMedico[0].tarifaPoxConsulta = 2.5;
//    cita <= arregloMedico;
//    cout << cita.especialidad << "#" << cita.tarifaPorConsulta;
    ifstream arch_med, arch_pac, arch_con;
    ofstream arch_rep;
    
    AperturaDeUnArchivoDeTextosParaLeer(arch_med, "MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(arch_pac, "PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(arch_con, "ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(arch_rep, "Reporte.txt");
    
    struct StMedico arregloMedico[5];
    // LECTURA
    struct StMedico med;
    cout << (arch_med >> med);
    cout << med.especialidad << endl;
    arregloMedico[0] = med;
    
    struct StPaciente pac;
    cout << (arch_pac >> pac);
    
    struct StCita cita;
    int dni;
    dni = arch_con >> cita;
    cout << "DNI PACIENTE: " << dni << endl;
    
    // BUSQUEDA
    // modificamos el codigo del medico de la cita leida con el codigo que
    // tenemos en el arreglo de medicos para que lo puedo encontrar
    arregloMedico[1].codigo = 0;
    cita.codigoDelMedico = 506117;
    cout << (cita <= arregloMedico) << endl;
    
    // AGREGACION
    pac += cita;
    
    // GASTOS
    ++pac;
    
    // IMPRESION
    arch_rep << pac;
    
    return 0;
}

