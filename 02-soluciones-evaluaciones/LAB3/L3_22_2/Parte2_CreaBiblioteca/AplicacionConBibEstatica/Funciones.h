/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 27 de abril de 2023, 23:34
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerMedicos(struct StMedico *medicos);
void LeerPacientes(struct StPaciente *pacientes);

void LeerCitas(struct StMedico *medicos, struct StPaciente *pacientes);

int BuscarPaciente(struct StPaciente* pacientes, int dni_paciente);
void CalcularGastos(struct StPaciente*pacientes);

void EmitirReporte(struct StPaciente*pacientes);

#endif /* FUNCIONES_H */
