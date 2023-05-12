/* 
 * File:   MetodoPorIncrementos.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 11 de mayo de 2023, 14:14
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

void cargarCitas(const char*nom_arch, char***&medicoDatos, double*&medicoTarifaHora,
        char****&citaPaciente, int**&citaCantidad, double***&citaTiempoYPago);

void AsignarPaciente(char***&citaPaciente, char*dni_paciente,
        char*nombre_paciente, int pacientes, int*citaCantidad,
        double**citaTiempoYPago, double horas, double pago);
int BuscarIndicePaciente(char***cita, char*dni_paciente) ;

void IncrementarPacientes(char***&citas, int &pacientes, int &cap_pac,
        int*&citaCantidad, double**&citaTiempoYPago);
char*CrearCadena(char*cad);
int BuscarIndiceMedico(char***medicoDatos, char*codigo_medico);

void incrementarMedicos(char***&medicoDatos, double*&medicoTarifaHora,
        char****&citaPaciente, int**&citaCantidad, double***&citaTiempoYPago,
        int&cap, int &num_med);

#endif /* METODOPORINCREMENTOS_H */
