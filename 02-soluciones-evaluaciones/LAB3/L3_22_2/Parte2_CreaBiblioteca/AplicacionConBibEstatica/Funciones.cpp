/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 27 de abril de 2023, 23:34
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Funciones.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "FuncionesSobrecargas.h"
using namespace std;

void LeerMedicos(struct StMedico *medicos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "MedicosLab3.txt");
    int i = 0;
    struct StMedico medico;
    while (1){
        if (!(arch >> medico)) break;
        medicos[i] = medico;
        cout << "COD: " << medicos[i].codigo << endl;
        i++;
    }
    medicos[i].codigo = 0;
}

void LeerPacientes(struct StPaciente *pacientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "PacientesLab3.txt");
    int i=0;
    struct StPaciente paciente;
    while(1){
        if (!(arch >> paciente)) break;
        pacientes[i] = paciente;
        cout << paciente.dni << endl;
        i++;
    }
}

void LeerCitas(struct StMedico *medicos, struct StPaciente *pacientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, "ConsultasLab3.txt");
    struct StCita cita;
    int dni_paciente, indice_paciente;
    while (1){
        dni_paciente = arch >> cita;
        if (dni_paciente==-1) break;
        cout << "cod med. " << cita.codigoDelMedico << endl;
        cita <= medicos;
        
        indice_paciente = BuscarPaciente(pacientes, dni_paciente);
        if (indice_paciente!=-1){
            pacientes[indice_paciente] += cita;
        }
    }
}

int BuscarPaciente(struct StPaciente* pacientes, int dni_paciente){
    for (int i=0; pacientes[i].dni; i++)
        if (pacientes[i].dni == dni_paciente) return i;
    return -1;
}

void CalcularGastos(struct StPaciente*pacientes){
    for (int i=0; pacientes[i].dni; i++) ++pacientes[i];
}

void EmitirReporte(struct StPaciente*pacientes){
    cout << sizeof(struct StPaciente*) << endl;
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, "Reporte.txt");
    arch << endl;
    for (int i=0; pacientes[i].dni; i++){
        arch << pacientes[i];
        arch << endl;
    }
}