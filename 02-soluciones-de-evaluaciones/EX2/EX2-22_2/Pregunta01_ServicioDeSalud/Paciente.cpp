/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.cpp
 * Author: Danie
 * 
 * Created on 7 de julio de 2023, 22:10
 */

#include "Paciente.h"

//Paciente::Paciente() {
//}

//void Paciente::operator=(const Paciente& orig) {
//    dni = dni;
//    setNombre(orig.nombre);
//    fechaUltimaConsulta = orig.fechaUltimaConsulta;
//    setCodigoDelMedicoDeUltimaConsulta(orig.codigoDelMedicoDeUltimaConsulta);
//}

void Paciente::leerPaciente(ifstream& arch) {
    int dd, mm, aa;
    char c, cad[100];
    arch >> dd;
    if (arch.eof()) return;
    arch >> c >> mm >> c >> aa >> c >> dni >> c;
    fechaUltimaConsulta = dd+mm*100+aa*10000;
    arch.getline(cad, 100, ',');
    setNombre(cad);
    arch.getline(cad, 100, ',');
    setCodigoDelMedicoDeUltimaConsulta(cad);
    cout << "dni " << dni << endl;
}

void Paciente::imprimirPaciente(ofstream& arch) {
    arch << left << setw(10) << dni << setw(50) << nombre << 
            fechaUltimaConsulta << endl;
}

void Paciente::setCodigoDelMedicoDeUltimaConsulta(const char*cad) {
    if (codigoDelMedicoDeUltimaConsulta) delete codigoDelMedicoDeUltimaConsulta;
    codigoDelMedicoDeUltimaConsulta = new char[strlen(cad)+1];
    strcpy(codigoDelMedicoDeUltimaConsulta, cad);
}

void Paciente::getCodigoDelMedicoDeUltimaConsulta(char*cad) const {
    if (codigoDelMedicoDeUltimaConsulta) strcpy(cad, codigoDelMedicoDeUltimaConsulta);
    else cad[0] = 0;
}

void Paciente::setFechaUltimaConsulta(int fechaUltimaConsulta) {
    this->fechaUltimaConsulta = fechaUltimaConsulta;
}

int Paciente::getFechaUltimaConsulta() const {
    return fechaUltimaConsulta;
}

void Paciente::setNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Paciente::getNombre(char *cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void Paciente::setDni(int dni) {
    this->dni = dni;
}

int Paciente::getDni() const {
    return dni;
}

//Paciente::Paciente(const Paciente& orig) {
//}
//
//Paciente::~Paciente() {
//}

