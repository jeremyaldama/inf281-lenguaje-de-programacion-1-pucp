/* 
 * File:   MetodoPorIncrementos.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 11 de mayo de 2023, 14:14
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "MetodoPorIncrementos.h"
#define INCREMENTO 5

using namespace std;

// 51873364,Calixto/Erick,DY2694,DELICIA ARCA AQUINO,523.53,8/07/2022,11:45:44,12:49:11
// paciente, medico
// dni, nombre    -   codigo, nombre, tarifa, dd,mm,aa, hi,mi,si, hf,mf,sf

void cargarCitas(const char*nom_arch, char***&medicoDatos, double*&medicoTarifaHora,
        char****&citaPaciente, int**&citaCantidad, double***&citaTiempoYPago) {
    ifstream arch(nom_arch, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR ARCH";
        exit(1);
    }

    char codigo_medico[100], nombre_medico[100], dni_paciente[10],
            nombre_paciente[100], c;
    double tarifa_medico, horas, pago;
    int ind_med, dd, mm, aa, cap = 0, num_med = 0, hi, mi, si, hf, mf, sf,
            pacientes[100] = {}, cap_pac[100] = {}, ind_pac;
    medicoDatos = nullptr;
    int i = 0;
    while (1) {
        arch.getline(dni_paciente, 10, ',');
        if (arch.eof()) break;
        // LECTURA
        arch.getline(nombre_paciente, 100, ',');
        arch.getline(codigo_medico, 100, ',');
        arch.getline(nombre_medico, 100, ',');
        arch >> tarifa_medico >> c >> dd >> c >> mm >> c >> aa >>
                c >> hi >> c >> mi >> c >> si >> c >> hf >> c >> mf >> c >> sf;
        arch.get();
        horas = ((hf * 3600 + mf * 60 + sf) - (hi * 3600 + mi * 60 + si)) / 3600.0;
        pago = horas*tarifa_medico;
        if (num_med == cap) incrementarMedicos(medicoDatos, medicoTarifaHora,
                citaPaciente, citaCantidad, citaTiempoYPago, cap, num_med);
        ind_med = BuscarIndiceMedico(medicoDatos, codigo_medico);
        if (ind_med == -1) {
            medicoDatos[num_med - 1] = new char*[2];
            medicoTarifaHora[num_med - 1] = tarifa_medico;

            char **med = medicoDatos[num_med - 1];
            med[0] = CrearCadena(codigo_medico);
            med[1] = CrearCadena(nombre_medico);
            // 2 char 1 double 1 entero
            if (pacientes[num_med - 1] == cap_pac[num_med - 1])
                IncrementarPacientes(citaPaciente[num_med - 1], pacientes[num_med - 1],
                    cap_pac[num_med - 1], citaCantidad[num_med - 1],
                    citaTiempoYPago[num_med - 1]);

            ind_pac = BuscarIndicePaciente(citaPaciente[num_med - 1], dni_paciente);
            if (ind_pac == -1) {
                AsignarPaciente(citaPaciente[num_med - 1], dni_paciente, nombre_paciente,
                        pacientes[num_med - 1] - 1, citaCantidad[num_med - 1],
                        citaTiempoYPago[num_med - 1], horas, pago);
                pacientes[num_med - 1]++;
            } else {
                AsignarPaciente(citaPaciente[num_med - 1], 0, nombre_paciente,
                        pacientes[num_med - 1] - 1, citaCantidad[num_med - 1],
                        citaTiempoYPago[num_med - 1], horas, pago);
            }
            num_med++;
        } else {
            if (pacientes[ind_med] == cap_pac[ind_med])
                IncrementarPacientes(citaPaciente[ind_med], pacientes[ind_med],
                    cap_pac[ind_med], citaCantidad[ind_med],
                    citaTiempoYPago[ind_med]);

            ind_pac = BuscarIndicePaciente(citaPaciente[ind_med], dni_paciente);
            if (ind_pac == -1) {
                AsignarPaciente(citaPaciente[ind_med], dni_paciente, nombre_paciente,
                        pacientes[ind_med] - 1, citaCantidad[ind_med],
                        citaTiempoYPago[ind_med], horas, pago);

                pacientes[ind_med]++;
            } else {
                AsignarPaciente(citaPaciente[num_med - 1], 0, nombre_paciente,
                        ind_pac, citaCantidad[ind_med],
                        citaTiempoYPago[ind_med], horas, pago);
            }
        }
    }
}

int BuscarIndicePaciente(char***cita, char*dni_paciente) {
    for (int i = 0; cita[i]; i++) {
        char **datos = cita[i];
        if (strcmp(datos[0], dni_paciente) == 0) return i;
    }
    return -1;
}

void AsignarPaciente(char***&citaPaciente, char*dni_paciente,
        char*nombre_paciente, int pacientes, int*citaCantidad,
        double**citaTiempoYPago, double horas, double pago) {
    citaCantidad[pacientes]++;
    cout << pacientes << endl;

    if (dni_paciente) {
        citaPaciente[pacientes] = new char*[2];
        char**pac = citaPaciente[pacientes];
        pac[0] = CrearCadena(dni_paciente);
        pac[1] = CrearCadena(nombre_paciente);
    }
    if (citaCantidad[pacientes] > 1) {
        double*datos = citaTiempoYPago[pacientes];
        datos[0] += horas;
        datos[1] += pago;
    } else {
        citaTiempoYPago[pacientes] = new double[2] {
        };
        double*datos = citaTiempoYPago[pacientes];
        datos[0] += horas;
        datos[1] += pago;
    }
}

void IncrementarPacientes(char***&citas, int &pacientes, int &cap_pac,
        int*&citaCantidad, double**&citaTiempoYPago) {
    //    cout << pacientes << endl;
    cap_pac += INCREMENTO;
    if (citas == nullptr) {
        citas = new char**[cap_pac] {
        };
        citaCantidad = new int[cap_pac] {
        };
        citaTiempoYPago = new double*[cap_pac] {
        };
        pacientes = 1;
        //        for (int i=0; i<cap_pac; i++) cout << citas[i] << endl;
    } else {
        char***aux = new char**[cap_pac] {
        };
        int *aux2 = new int[cap_pac] {
        };
        double **aux3 = new double*[cap_pac] {
        };
        for (int i = 0; i < pacientes; i++) {
            aux[i] = citas[i];
            aux2[i] = citaCantidad[i];
            aux3[i] = citaTiempoYPago[i];
        }
        delete citas;
        delete citaCantidad;
        delete citaTiempoYPago;

        citas = aux;
        citaCantidad = aux2;
        citaTiempoYPago = aux3;
    }
}

char*CrearCadena(char*cad) {
    char *cad2;
    cad2 = new char[strlen(cad) + 1];
    strcpy(cad2, cad);
    return cad2;
}

int BuscarIndiceMedico(char***medicoDatos, char*codigo_medico) {
    for (int i = 0; medicoDatos[i]; i++) {
        char**datos = medicoDatos[i];
        if (strcmp(datos[0], codigo_medico) == 0) return i;
    }
    return -1;
}

void incrementarMedicos(char***&medicoDatos, double*&medicoTarifaHora,
        char****&citaPaciente, int**&citaCantidad, double***&citaTiempoYPago,
        int&cap, int &num_med) {
    cap += INCREMENTO;
    if (medicoDatos == nullptr) {
        medicoDatos = new char**[cap] {
        };
        medicoTarifaHora = new double[cap];
        citaPaciente = new char***[cap] {
        };
        citaCantidad = new int*[cap];
        citaTiempoYPago = new double**[cap];
        num_med = 1;
    } else {
        char ***aux = new char**[cap] {
        };
        double *aux2 = new double[cap];
        char ****aux3 = new char***[cap] {
        };
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