/* 
 * Archivo:   Cuenta.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 01:07 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Cuenta.h"

Cuenta::Cuenta() {
    cliente = nullptr;
    estado = nullptr;
    this->SetEstado("HABIL");
}

Cuenta::Cuenta(const Cuenta& orig) {
    cliente = nullptr;
    this->SetEstado("HABIL");
    *this = orig;
}

Cuenta::~Cuenta() {
    if (cliente != nullptr) delete []cliente;
}

void Cuenta::SetEstado(const char* p_estado) {
    if (estado) delete []estado;
    estado = new char [strlen(p_estado)+1];
    strcpy(estado,p_estado);
}

void Cuenta::GetEstado(char* p_estado) const {
    if (!estado) estado[0] = '\0';
    strcpy(p_estado,estado);
}

void Cuenta::SetSaldo(double saldo) {
    this->saldo = saldo;
}

double Cuenta::GetSaldo() const {
    return saldo;
}

void Cuenta::SetCliente(const char* nombre) {
    if (cliente) delete []cliente;
    cliente = new char [strlen(nombre)+1];
    strcpy(cliente,nombre);
}

void Cuenta::GetCliente(char* nombre) const {
    if (!cliente) cliente[0] = '\0';
    strcpy(nombre,cliente);
}

void Cuenta::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Cuenta::GetCodigo() const {
    return codigo;
}

void Cuenta::operator=(const Cuenta& orig) {
    char nombre[60], p_estado[60];
    orig.GetCliente(nombre);
    orig.GetEstado(p_estado);
    this->SetCodigo(orig.GetCodigo());
    this->SetSaldo(orig.GetSaldo());
    this->SetCliente(nombre);
    this->SetEstado(p_estado);
}

void Cuenta::operator+=(double valor) {
    this->SetSaldo(this->GetSaldo() + valor);
    if (this->GetSaldo() < 0) this->SetEstado("SOBREGIRADO");
    else this->SetEstado("HABIL");
}


bool Cuenta::operator>(const Cuenta& orig) {
    return this->GetCodigo() > orig.GetCodigo();
}

bool Cuenta::operator==(int valor) {
    return this->GetCodigo() == valor;
}

bool Cuenta::operator >(int valor) {
    return this->GetCodigo() > valor;
}

ifstream& operator >> (ifstream& arch, Cuenta &cuenta) {
    int cod;
    char nombre[60];
    double saldo;
    arch >> cod;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nombre,60,',');
    arch >> saldo;
    cuenta.SetCodigo(cod);
    cuenta.SetCliente(nombre);
    cuenta.SetSaldo(saldo);
    return arch;
}

ofstream& operator << (ofstream& arch, Cuenta &cuenta) {
    char nombre[60], estado[20];
    cuenta.GetCliente(nombre);
    cuenta.GetEstado(estado);
    arch << cuenta.GetCodigo() << setw(5) << " "
            << left << setw(45) << nombre
            << right << setw(10) << cuenta.GetSaldo()
            << setw(5) << " " << left << estado << right << endl;
}