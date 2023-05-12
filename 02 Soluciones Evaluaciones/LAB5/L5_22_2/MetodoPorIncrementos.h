/* 
 * File:   MetodoPorIncrementos.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 7 de mayo de 2023, 1:11
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

void cargarCitas(const char*nom_arch, char***&medicoDatos,
        double*&medicoTarifaHora, char****&citaPaciente, int**&citaCantidad,
        double***&citaTiempoYPago);
int BuscarIndicePaciente(char***cita, char*dni_paciente) ;
void IncrementarCitas(char****&citaPaciente, int i, int ind_med, int*&, double**&);

void AgregarCitaMedico(char*dni_paciente, char*nombre_paciente, int ind_med,
        char****&citaPaciente, int**citaCantidad, double***citaTiempoYPago);
int BuscarIndiceMedico(char***medicoDatos, char*codigo_medico);

void incrementarMedicos(char***&medicoDatos, char*codigo_medico,
        char*nombre_medico, int &cap, double*&medicoTarifaHora,
        char****&citaPaciente, int**&citaCantidad, double***&citaTiempoYPago,
        int &);
#endif /* METODOPORINCREMENTOS_H */
