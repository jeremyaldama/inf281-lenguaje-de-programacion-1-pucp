/* 
 * Archivo:   Paciente.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de noviembre de 2020, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"

Paciente::Paciente() {
    nombre = nullptr;
}

Paciente::Paciente(const Paciente& orig) {
    this->SetFecha(orig.fecha);
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetEstado(orig.estado);
    this->SetPrima(orig.prima);
}

Paciente::~Paciente() {
    delete []nombre;
}

void Paciente::SetEstado(char estado) {
    this->estado = estado;
}

char Paciente::GetEstado() const {
    return estado;
}

void Paciente::SetPrima(double prima) {
    this->prima = prima;
}

double Paciente::GetPrima() const {
    return prima;
}

void Paciente::SetNombre(const char* pnombre) {
    if (nombre) delete []nombre;
    nombre = new char [strlen(pnombre)+1];
    strcpy(nombre,pnombre);
}

void Paciente::GetNombre(char *pnombre) const {
    if (!nombre) nombre[0] = '\0';
    strcpy(pnombre,nombre);
}

void Paciente::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Paciente::GetCodigo() const {
    return codigo;
}

void Paciente::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Paciente::GetFecha() const {
    return fecha;
}

ifstream& operator >> (ifstream& in, Paciente &paciente) {
    int cod;
    double p;
    char car, nomb[50], E;
    in >> E >> cod >> nomb >> p;
    paciente.SetCodigo(cod);
    paciente.SetEstado(E);
    paciente.SetNombre(nomb);
    paciente.SetPrima(p);
    return in;
}