/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 19 de abril de 2023, 23:11
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
using namespace std;

void LeerArchivos();
void ObtenerEspecialidad(char *nombre_medico, char*especialidad_medico);
void AgregarMedico(ofstream &arch, char*codigo_medico, char*nombre_medico);
void AgregarPaciente(ofstream &arch_pacientes, int dni_paciente,
        char*nombre_paciente, double gasto);
int VerificarSeEncuentraInt(int dni_paciente, const char*);
void AgregarMedicina(ofstream &arch_medicinas_bin, int codigo_medicamento,
        char*descripcion_medicamento, double precio_medicamento);
void AgregarMedicamentosConsulta(ofstream&arch_consultas, int codigo_medicamento);

void AgregarConsulta(ofstream &arch_consultas, int dni_paciente,
        char*codigo_medico_atiende, int dd, int mm, int aa,
        int cantidad_medicamentos);
void VerificarCreacion(const char*nombre_arch,
        const char*nombre_arch_out);
#endif /* FUNCIONES_H */
