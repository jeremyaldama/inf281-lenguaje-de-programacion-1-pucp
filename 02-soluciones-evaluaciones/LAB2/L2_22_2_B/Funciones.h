/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 20 de abril de 2023, 21:10
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;

void CompletarGastoXPaciente();
void ActualizarPaciente(fstream &arch_pacientes_bin, int dni_paciente,
        double precio_total);
double BuscarPrecioMedicina(ifstream &arch_medicinas, int codigo_medicina);
void VerificarCreacion(const char*nombre_arch, 
        const char*nombre_arch_out);
#endif /* FUNCIONES_H */
