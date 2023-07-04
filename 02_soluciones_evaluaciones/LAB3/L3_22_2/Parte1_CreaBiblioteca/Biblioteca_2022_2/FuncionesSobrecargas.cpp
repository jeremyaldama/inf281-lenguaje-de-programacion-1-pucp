/* 
 * File:   FuncionesSobrecargas.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 27 de abril de 2023, 18:13
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesSobrecargas.h"
#include "Estructuras.h"
using namespace std;

bool operator >>(ifstream&arch, struct StMedico &medico){
    arch >> medico.codigo;
    if (arch.eof()) return false;
    char aux[100];
    arch >> aux >> medico.tarifaPoxConsulta;
    int i, j;
    for (i = 0; aux[i]; i++){
        medico.nombre[i] = aux[i];
        if (aux[i+2] >= 'a' && aux[i+2] <= 'z'){
            medico.nombre[i] = 0;
            break;
        }
    }
    for (i=i+1, j=0; aux[i]; i++, j++) medico.especialidad[j] = aux[i];
    medico.especialidad[j] = 0;
    return true;
}

bool operator >>(ifstream&arch, struct StPaciente &paciente){
    arch >> paciente.dni;
    if (arch.eof()) return false;
    char aux[100];
    arch >> paciente.nombre >> paciente.telefono;
    for (int i=0; i<20; i++) paciente.citas[i] = {};
    paciente.numeroDeCitas = 0;
    paciente.totalGastado = 0.0;
    return true;
}

int operator >>(ifstream&arch, struct StCita &cita){
    int dni_paciente;
    arch >> dni_paciente;
    if (arch.eof()) return -1;
    int dd, mm, aa;
    char c;
    arch >> cita.codigoDelMedico >> dd >> c >> mm >> c >> aa;
    cita.fecha = dd + mm*100 + aa*10000;
    return dni_paciente;
}

bool operator <=(struct StCita &cita, struct StMedico *arregloMedico){
    for (int i=0; arregloMedico[i].codigo; i++)
        if (cita.codigoDelMedico == arregloMedico[i].codigo){
            int j;
            for (j=0; cita.especialidad[j] = arregloMedico[i].especialidad[j]; j++);
            cita.especialidad[j] = 0;
            cita.tarifaPorConsulta = arregloMedico[i].tarifaPoxConsulta;
            return true;
        }
    return false;
}

// le paso por referencia StCita para no ocupar mas memoria
void operator +=(struct StPaciente &paciente, const struct StCita &cita){
    paciente.citas[paciente.numeroDeCitas++] = cita;
}

void operator ++(struct StPaciente &paciente){
    for (int i=0; i<paciente.numeroDeCitas; i++){
        paciente.totalGastado += paciente.citas[i].tarifaPorConsulta;
    }
}

void operator <<(ofstream& arch, const struct StPaciente &paciente){
    arch << left << setw(15) << "DNI" << setw(50) << "NOMBRE" << "TELEFONO" << 
            endl;
    arch << setw(15) << paciente.dni << setw(50) << paciente.nombre <<
            paciente.telefono << endl;
    arch << "RELACION DE CITAS" << endl;
    int i=1;
    for (int i=0; i<paciente.numeroDeCitas; i++) {
        arch << setw(5) << i+1 << setw(12) << paciente.citas[i].fecha << setw(12) <<
                paciente.citas[i].codigoDelMedico << setw(20) << paciente.citas[i].especialidad <<
                paciente.citas[i].tarifaPorConsulta << endl;
    }
    arch << "MONTO TOTAL GASTADO: " << paciente.totalGastado << endl;
}