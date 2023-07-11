/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente_Medicina.cpp
 * Author: Danie
 * 
 * Created on 7 de julio de 2023, 16:09
 */

#include "Paciente_Medicina.h"
#include "Paciente.h"

Paciente_Medicina::Paciente_Medicina() {
    totalDeGastos = 0.0;
}

Paciente_Medicina::Paciente_Medicina(const Paciente_Medicina& orig) {
    *this = orig;
}

Paciente_Medicina::~Paciente_Medicina() {
}

void Paciente_Medicina::SetTotalDeGastos(double totalDeGastos) {
    this->totalDeGastos = totalDeGastos;
}

double Paciente_Medicina::GetTotalDeGastos() const {
    return totalDeGastos;
}

void Paciente_Medicina::totalizar(map<int, Medicina> med) {
    list<Medicina_Cantidad>::iterator it;
    for (it = medicina_cantidad.begin(); it != medicina_cantidad.end(); it++) {
        totalDeGastos += (med[it->GetCodigo()].GetPrecio());
    }
}

int Paciente_Medicina::obtenerDNI() const {
    return paciente.getDni();
}

void Paciente_Medicina::setPaciente(const Paciente& pac) {
    paciente = pac;
}

void Paciente_Medicina::leerMedicinas(ifstream& arch) {
    class Medicina_Cantidad med_can;
    list<Medicina_Cantidad>::iterator itMedCan;
    while (true) {
        arch >> med_can;
        cout << "cantidad: " << med_can.GetCantidad() << endl;
        
        itMedCan = buscarMedicina(med_can);
        if (itMedCan == medicina_cantidad.end()) {
            cout << "PUSH BACK DE MEDICINA " << endl;
            medicina_cantidad.push_back(med_can);
        } else {
            cout << "PUSH BACK DE MEDICINA 2 " << endl;
            itMedCan->SetCantidad(itMedCan->GetCantidad() +
                    med_can.GetCantidad());
        }
        
        if (arch.get() == '\n') break;
    }
}

list<Medicina_Cantidad>::iterator Paciente_Medicina::buscarMedicina(
        const Medicina_Cantidad& med) {
    list<Medicina_Cantidad>::iterator it;
    for (it = medicina_cantidad.begin(); it != medicina_cantidad.end(); it++) {
        cout << "reotnr algo it?" << endl;
        if (it->GetCodigo() == med.GetCodigo()) return it;
    }
    cout << "reotnr algo?" << endl;
    return medicina_cantidad.end();
}

bool Paciente_Medicina::operator>(const Paciente& pac) {
    return paciente.getFechaUltimaConsulta() > pac.getFechaUltimaConsulta();
}

void Paciente_Medicina::imprimirPaciente(ofstream& arch) {
    paciente.imprimirPaciente(arch);
    for (list<Medicina_Cantidad>::iterator it = medicina_cantidad.begin();
            it != medicina_cantidad.end(); it++) {
        it->imprimirMedicinaCantidad(arch);
    }
    arch << "TOTAL GASTOS: " << totalDeGastos << endl;
    arch << endl;
}

void Paciente_Medicina::operator=(const Paciente_Medicina& pac) {
    paciente = pac.paciente;
}