/* 
 * File:   MetodoPorIncrementos.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 7 de mayo de 2023, 1:11
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "MetodoPorIncrementos.h"

using namespace std;
#define INCREMENTO 5

void cargarCitas(const char*nom_arch, char***&medicoDatos,
        double*&medicoTarifaHora, char****&citaPaciente, int**&citaCantidad,
        double***&citaTiempoYPago) {
    ifstream arch(nom_arch, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR CITAS.CSV";
        exit(1);
    }
    // 51873364,Calixto/Erick,DY2694,DELICIA ARCA AQUINO,523.53,8/07/2022,11:45:44,12:49:11
    // paciente - medico - cita
    // dni, nombre - codigo, nombre, tarifaxhora - dd/mm/aa, hh:mm:ss, hh:mm:ss f
    char codigo_medico[100], nombre_medico[100], dni_paciente[10],
            nombre_paciente[100], c;
    double tarifa_medico;
    int ind_medico, dd, mm, aa, cap = 0, num_medicos = 0;
    medicoDatos = nullptr;
    while (1) {
        if (arch.peek() == '\n') arch.get();
        arch.getline(dni_paciente, 10, ',');
        if (arch.eof()) break;
        // LECTURA
        arch.getline(nombre_paciente, 100, ',');
        arch.getline(codigo_medico, 100, ',');
        arch.getline(nombre_medico, 100, ',');
        arch >> tarifa_medico >> c >> dd >> c >> mm >> c >> aa >>
                c >> dd >> c >> mm >> c >> aa >> c >> dd >> c >> mm >> c >> aa;
        if (num_medicos == cap) incrementarMedicos(medicoDatos, codigo_medico,
                nombre_medico, cap, medicoTarifaHora, citaPaciente,
                citaCantidad, citaTiempoYPago, num_medicos);

        ind_medico = BuscarIndiceMedico(medicoDatos, codigo_medico);
        if (ind_medico == -1) {
            medicoDatos[num_medicos-1] = new char*[2];
            medicoTarifaHora[num_medicos-1] = tarifa_medico;
            char **med = medicoDatos[num_medicos-1];
            med[0] = new char[strlen(codigo_medico) + 1];
            med[1] = new char[strlen(nombre_medico) + 1];
            strcpy(med[0], codigo_medico);
            strcpy(med[1], nombre_medico);
            // AGREGA CITA
//            citaPaciente[num_medicos] = new char**[INCREMENTO + 1] {
//            };
//            citaCantidad[num_medicos] = new int[INCREMENTO];
//            citaTiempoYPago[num_medicos] = new double*[INCREMENTO];
//
//            AgregarCitaMedico(dni_paciente, nombre_paciente, num_medicos,
//                    citaPaciente, citaCantidad, citaTiempoYPago);
            num_medicos++;
        } else {
//            char***citas = citaPaciente[ind_medico];
//            int i = 0;
//            for (i = 0; citas[i]; i++);
//            if (i % INCREMENTO == 0) IncrementarCitas(citaPaciente, i, ind_medico);
//            AgregarCitaMedico(dni_paciente, nombre_paciente, ind_medico,
//                    citaPaciente, citaCantidad, citaTiempoYPago);
        }
    }

}

void IncrementarCitas(char****&citaPaciente, int i, int ind_med) {
    i += INCREMENTO;
    char***citas = citaPaciente[ind_med];
    char ***aux = new char**[i + 1] {
    };
    for (int j = 0; citas[j]; j++) {
        aux[j] = citas[j];
    }
    citaPaciente[ind_med] = aux;
}

void AgregarCitaMedico(char*dni_paciente, char*nombre_paciente, int ind_med,
        char****&citaPaciente, int**citaCantidad, double***citaTiempoYPago) {
    char ***cita = citaPaciente[ind_med];
    int i;
    for (i = 0; cita[i]; i++);
    cita[i] = new char*[2];
    char **pac = cita[i];
    pac[0] = new char[strlen(dni_paciente) + 1];
    pac[1] = new char[strlen(nombre_paciente) + 1];
    cout << dni_paciente << nombre_paciente << endl;
    strcpy(pac[0], dni_paciente);
    strcpy(pac[1], nombre_paciente);
}

int BuscarIndiceMedico(char***medicoDatos, char*codigo_medico) {
    int i;
    for (i = 0; medicoDatos[i]; i++) {
        char **cod;
        cod = medicoDatos[i];
        if (strcmp(cod[0], codigo_medico) == 0) return i;
    }
    return -1;
}

void incrementarMedicos(char***&medicoDatos, char*codigo_medico,
        char*nombre_medico, int &cap, double*&medicoTarifaHora,
        char****&citaPaciente, int**&citaCantidad, double***&citaTiempoYPago,
        int& num_med) {
    cap += INCREMENTO;
    if (medicoDatos == nullptr) {
        medicoDatos = new char**[cap] {
        };
        medicoTarifaHora = new double[cap];
        citaPaciente = new char***[cap];
        citaCantidad = new int*[cap];
        citaTiempoYPago = new double**[cap];
        num_med = 1;
    } else {
        char ***aux = new char**[cap] {
        };
        double *aux2 = new double[cap];
        char ****aux3 = new char***[cap];
        int **aux4 = new int*[cap];
        double ***aux5 = new double**[cap];
        for (int i = 0; medicoDatos[i]; i++) {
            aux2[i] = medicoTarifaHora[i];
            aux[i] = medicoDatos[i];
            aux3[i] = citaPaciente[i];
            aux4[i] = citaCantidad[i];
            aux5[i] = citaTiempoYPago[i];
        }
        delete medicoTarifaHora;
        delete medicoDatos;
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        medicoDatos = aux;
        medicoTarifaHora = aux2;
        citaPaciente = aux3;
        citaCantidad = aux4;
        citaTiempoYPago = aux5;
    }

}

void pruebaDeCargaDeCitas(const char*nom_arch, char***medicoDatos,
        double*medicoTarifaHora, char***citaPaciente, int**citaCantidad,
        double***citaTiempoYPago) {

}

void ReporteDeCitasPorMedico(const char*nom_arch, char***medicoDatos,
        double*medicoTarifaHora, char***citaPaciente, int**citaCantidad,
        double***citaTiempoYPago) {

}