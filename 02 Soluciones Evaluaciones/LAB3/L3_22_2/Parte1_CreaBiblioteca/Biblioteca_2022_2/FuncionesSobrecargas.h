/* 
 * File:   FuncionesSobrecargas.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 27 de abril de 2023, 18:13
 */

#ifndef FUNCIONESSOBRECARGAS_H
#define FUNCIONESSOBRECARGAS_H
#include <fstream>
using namespace std;

bool operator >>(ifstream&arch, struct StMedico &medico);

bool operator >>(ifstream&arch, struct StPaciente &paciente);

int operator >>(ifstream&arch, struct StCita &cita);

bool operator <=(struct StCita &cita, struct StMedico *arregloMedico);

// le paso por referencia StCita para no ocupar mas memoria
void operator +=(struct StPaciente &paciente, const struct StCita &cita);
void operator ++(struct StPaciente &paciente);

void operator <<(ofstream& arch, const struct StPaciente &paciente);

#endif /* FUNCIONESSOBRECARGAS_H */
