/* 
 * Archivo:   Medico.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de noviembre de 2020, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Medico.h"

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
        fechas[i] = orig.fechas[i];
        pacientes[i] = orig.pacientes[i];
        prima[i] = orig.prima[i];
        estado[i] = orig.estado[i];
    }
}

Medico::~Medico() {
    delete []codigo;
    delete []nombre;
    delete []especialidad;
}

void Medico::SetIngresosS(double ingresosS) {
    this->ingresosS = ingresosS;
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

void Medico::GetNombre(char *pnombre) const {
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
    pacientes[numPac] = pac.GetCodigo();
    fechas[numPac] = pac.GetFecha();
    estado[numPac] = pac.GetEstado();
    prima[numPac] = pac.GetPrima();
    numPac++;
}

void Medico::operator *(int pfecha) {
    for (int i = 0; i < numPac; i++) {
        if (fechas[i] == pfecha && estado[i] == 'R') {
            estado[i] = 'A';
        }
    }
}

void Medico::operator -(int pfecha) {
    for (int i = 0; i < numPac; i++) {
        if (fechas[i] == pfecha && estado[i] == 'R') {
            estado[i] = 'E';
        } 
    }    
}

void Medico::operator ++() {
    double monto = 0, seguro = 0;
    for (int i = 0; i < numPac; i++) {
        if (estado[i] == 'A') {
            monto += (prima[i]/100)*tarifa;
            seguro += ((100-prima[i])/100)*tarifa;
        }
    }
    ingresosPac = monto;
    ingresosS = seguro;
}

void Medico::SetEstado(char estado, int pos) {
    this->estado[pos] = estado;
}

char Medico::GetEstado(int pos) const {
    return estado[pos];
}

void Medico::SetPrima(double prima, int pos) {
    this->prima[pos] = prima;
}

double Medico::GetPrima(int pos) const {
    return prima[pos];
}

void Medico::SetPacientes(int paciente, int pos) {
    this->pacientes[pos] = paciente;
}

int Medico::GetPacientes(int pos) const {
    return pacientes[pos];
}

void Medico::SetFechas(int fecha, int pos) {
    this->fechas[pos] = fecha;
}

int Medico::GetFechas(int pos) const {
    return fechas[pos];
}

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
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
    imprimirPacientesAtendidos(medico,out);
    imprimirPacientesPorAtender(medico,out);
    ++medico;
    out << endl << left << setw(40) << "Monto Total recibido por pacientes: " 
            << medico.GetIngresosPac()
            << endl << setw(40) << "Monto a solicitar al seguro: "
            << medico.GetIngresosS() << right << endl << endl << endl;
    return out;
}

void imprimirPacientesAtendidos(Medico &medico, ofstream& out) {
    imprimeLinea('=',100,out);
    out << "Pacientes Atendidos: " << endl;
    imprimeLinea('=',100,out);
    out << "No." << setw(18) << "Fecha"
            << setw(32) << "Paciente"
            << setw(20) << "Pago"
            << setw(25) << "Seguro" << endl;  
    int cont = 0;
    for (int i = 0; i < medico.GetNumPac(); i++) {
        if (medico.GetEstado(i) == 'A') { 
            out << setw(2) << cont+1 << ')' << setw(10) << " ";
            out.fill('0');
            out << setw(2) << (medico.GetFechas(i)%10000)%100 << '/' 
                  << setw(2) << (medico.GetFechas(i)%10000)/100 << '/'
                  << setw(4) << medico.GetFechas(i)/10000;
            out.fill(' ');
            out << setw(30) << medico.GetPacientes(i)
                    << setw(20) << (medico.GetPrima(i)/100)*medico.GetTarifa()
                    << setw(25) << ((100-medico.GetPrima(i))/100)*medico.GetTarifa() << endl;
            cont++;
        }       
    }
}

void imprimirPacientesPorAtender(Medico &medico, ofstream& out) {
    imprimeLinea('=',100,out);
    out << "Pacientes por atender: " << endl;
    imprimeLinea('=',100,out);
    out << "No." << setw(15) << "Fecha" << setw(32) << "Paciente" << endl;
    int cont = 0;
    for (int i = 0; i < medico.GetNumPac(); i++) {
        if (medico.GetEstado(i) == 'R') {
            out << setw(2) << cont+1 << ')' << setw(10) << " ";
            out.fill('0');
            out << setw(2) << (medico.GetFechas(i)%10000)%100 << '/' 
                  << setw(2) << (medico.GetFechas(i)%10000)/100;
            out.fill(' ');
            out << setw(30) << medico.GetPacientes(i) << endl;
            cont++;
        }       
    }
}