/* 
 * Archivo:   Medico.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 26 de noviembre de 2020, 12:15 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Medico.h"
#include "FuncionesAuxiliares.h"

Medico::Medico() {
    codigo = nullptr;
    nombre = nullptr;
    especialidad = nullptr;
    ingresosPac = 0;
    ingresosS = 0;
    numPac = 0;
}

Medico::Medico(const Medico& orig) {
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetEspecialidad(orig.especialidad);
    this->SetIngresosPac(orig.ingresosPac);
    this->SetIngresosS(orig.ingresosS);
    this->SetNumPac(orig.numPac);
    for (int i = 0; i < orig.numPac; i++) {
        pacientes[i] = orig.pacientes[i];
    }
}

Medico::~Medico() {
    delete []codigo;
    delete []nombre;
    delete []especialidad;
}

void Medico::SetIngresosS(double inresosS) {
    this->ingresosS = inresosS;
}

double Medico::GetIngresosS() const {
    return ingresosS;
}

void Medico::SetIngresosPac(double ingresosPac) {
    this->ingresosPac = ingresosPac;
}

double Medico::GetIngresosPac() const {
    return ingresosPac;
}

void Medico::SetNumPac(int numPac) {
    this->numPac = numPac;
}

int Medico::GetNumPac() const {
    return numPac;
}

void Medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double Medico::GetTarifa() const {
    return tarifa;
}

void Medico::SetEspecialidad(const char* pespecialidad) {
    if (especialidad) delete []especialidad;
    especialidad = new char[strlen(pespecialidad)+1];
    strcpy(especialidad,pespecialidad);
}

void Medico::GetEspecialidad(char *pespecialidad) const {
    if (!especialidad) especialidad[0] = '\0';
    strcpy(pespecialidad,especialidad);
}

void Medico::SetNombre(const char* pnombre) {
    if (nombre) delete []nombre;
    nombre = new char [strlen(pnombre)+1];
    strcpy(nombre,pnombre);
}

void Medico::GetNombre(char* pnombre) const {
    if (!nombre) nombre[0] = '\0';
    strcpy(pnombre,nombre);
}

void Medico::SetCodigo(const char* pcodigo) {
    if (codigo) delete []codigo;
    codigo = new char [strlen(pcodigo)+1];
    strcpy(codigo,pcodigo);
}

void Medico::GetCodigo(char *pcodigo) const {
    if (!codigo) codigo[0] = '\0';
    strcpy(pcodigo,codigo);
}

ifstream& operator >> (ifstream& in, Medico &medico) {
    char cod[10], nomb[50], esp[20];
    double tar;
    in >> cod >> nomb >> esp >> tar;
    medico.SetCodigo(cod);
    medico.SetNombre(nomb);
    medico.SetEspecialidad(esp);
    medico.SetTarifa(tar);
    return in;
}

void Medico::operator +(const Paciente& pac) {
    pacientes[numPac] = pac;
    numPac++;
}

void Medico::operator +(int pfecha) {
    for (int i = 0; i < numPac; i++) {
        if (pacientes[i].GetFecha() == pfecha && pacientes[i].GetEstado() == 'R') {
            pacientes[i].SetEstado('A');
        }
    }
}

void Medico::operator -(int pfecha) {
    for (int i = 0; i < numPac; i++) {
        if (pacientes[i].GetFecha() == pfecha && pacientes[i].GetEstado() == 'R') {
            for (int j = i; j < numPac-1; j++) {               
                pacientes[i] = pacientes[i+1];                                   
            }
            numPac--;
        } 
    }    
}

void Medico::operator /(int pfecha) {
    for (int i = 0; i < numPac; i++) {
        if (pacientes[i].GetFecha() < pfecha && pacientes[i].GetEstado() == 'A') {
            for (int j = i; j < numPac-1; j++) {               
                pacientes[i] = pacientes[i+1];                                   
            }
            numPac--;
        } 
    }   
}

void Medico::operator ++() {
    double monto = 0, seguro = 0;
    for (int i = 0; i < numPac; i++) {
        monto += (pacientes[i].GetPrima()/100)*tarifa;
        seguro += ((100-pacientes[i].GetPrima())/100)*tarifa;
    }
    ingresosPac = monto;
    ingresosS = seguro;
}

void Medico::printPacientesAtendidos(ofstream &out) {
    imprimeLinea('=',100,out);
    out << "Pacientes Atendidos: " << endl;
    imprimeLinea('=',100,out);
    out << "No." << setw(18) << "Fecha"
            << setw(32) << "Paciente"
            << setw(20) << "Pago"
            << setw(25) << "Seguro" << endl;  
    int cont = 0;
    for (int i = 0; i < numPac; i++) {
        if (pacientes[i].GetEstado() == 'A') { 
            out << setw(2) << cont+1 << ')' << setw(10) << " ";
            out.fill('0');
            out << setw(2) << (pacientes[i].GetFecha()%10000)%100 << '/' 
                  << setw(2) << (pacientes[i].GetFecha()%10000)/100 << '/'
                  << setw(4) << pacientes[i].GetFecha()/10000;
            out.fill(' ');
            out << setw(30) << pacientes[i].GetCodigo()
                    << setw(20) << (pacientes[i].GetPrima()/100)*tarifa
                    << setw(25) << ((100-pacientes[i].GetPrima())/100)*tarifa << endl;
            cont++;
        }       
    }
}

void Medico::printPacientesPorAtender(ofstream &out) {
    imprimeLinea('=',100,out);
    out << "Pacientes por atender: " << endl;
    imprimeLinea('=',100,out);
    out << "No." << setw(15) << "Fecha" << setw(32) << "Paciente" << endl;
    int cont = 0;
    for (int i = 0; i < numPac; i++) {
        if (pacientes[i].GetEstado() == 'R') {
            out << setw(2) << cont+1 << ')' << setw(10) << " ";
            out.fill('0');
            out << setw(2) << (pacientes[i].GetFecha()%10000)%100 << '/' 
                  << setw(2) << (pacientes[i].GetFecha()%10000)/100;
            out.fill(' ');
            out << setw(30) << pacientes[i].GetCodigo() << endl;
            cont++;
        }       
    }
}

ofstream& operator << (ofstream& out, Medico &medico) {
    char nomb[50], cod[10], esp[20];
    medico.GetNombre(nomb);
    medico.GetCodigo(cod);
    medico.GetEspecialidad(esp);
    out << "Medico: " << nomb << endl
            << "Codigo: " << cod << endl
            << "Especialidad: " << esp << endl
            << "Honorarios por cita: " << medico.GetTarifa() << endl;
    medico.printPacientesAtendidos(out);
    medico.printPacientesPorAtender(out);
    ++medico;
    out << endl << left << setw(40) << "Monto Total recibido por pacientes: " 
            << medico.GetIngresosPac()
            << endl << setw(40) << "Monto a solicitar al seguro: "
            << medico.GetIngresosS() << right << endl << endl << endl;
    return out;
}

