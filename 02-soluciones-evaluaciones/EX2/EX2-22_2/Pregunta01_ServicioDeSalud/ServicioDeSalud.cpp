/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServicioDeSalud.cpp
 * Author: Danie
 * 
 * Created on 7 de julio de 2023, 16:16
 */

#include <map>

#include "ServicioDeSalud.h"

ServicioDeSalud::ServicioDeSalud() {
}

ServicioDeSalud::ServicioDeSalud(const ServicioDeSalud& orig) {
}

ServicioDeSalud::~ServicioDeSalud() {
}

void ServicioDeSalud::abrirArchivoEscritura(ofstream& arch, const char*cad) {
    arch.open(cad, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void ServicioDeSalud::abrirArchivoLectura(ifstream& arch, const char*cad) {
    arch.open(cad, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir " << cad;
        exit(1);
    }
}

void ServicioDeSalud::leerMedicinas(const char*cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);

    Medicina med;

    while (1) {
        arch >> med;
        if (arch.eof()) break;
        medicina[med.GetCodigo()] = med;
    }
}

void ServicioDeSalud::imprimirMedicinas(const char* cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);

    for (map<int, Medicina>::iterator it = medicina.begin();
            it != medicina.end(); it++) {
        arch << it->second;
    }
}

void ServicioDeSalud::leerConsultas(const char*cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);

    Paciente pac;
    Paciente_Medicina pac_med;
    list<Paciente_Medicina>::iterator itPaciente;
    int i = 0;
    while (true) {
        pac.leerPaciente(arch);
        if (arch.eof()) break;
        itPaciente = buscarPaciente(pac);
        if (itPaciente == paciente_medicina.end()) {
            // en caso el paciente sea nuevo
            pac_med.setPaciente(pac);
            cout << "HACE PUSH BACK " << endl;
//            pac_med.leerMedicinas(arch);
            cout << "TOTAL: " << pac_med.GetTotalDeGastos() << endl;
            paciente_medicina.push_back(pac_med);
            
            itPaciente = buscarPaciente(pac);
//            cout << "PACIENTE ENCONTRADO: " << itPaciente->GetTotalDeGastos() << endl;
//            cout << "dni: " << pac_med.obtenerDNI() << endl;
            itPaciente->leerMedicinas(arch);
//            cout << paciente_medicina.size() << endl;
        } else {
            // significa que ya hay un paciente con ese dni
            if (*itPaciente > pac) {
                pac_med.setPaciente(pac);
            }
            itPaciente->leerMedicinas(arch);
        }
    }
}

list<Paciente_Medicina>::iterator ServicioDeSalud::buscarPaciente(
        const Paciente& pac) {
    list<Paciente_Medicina>::iterator it;
    for (it = paciente_medicina.begin(); it != paciente_medicina.end(); it++) {
        if (it->obtenerDNI() == pac.getDni()) return it;
    }
    return paciente_medicina.end();
}

void ServicioDeSalud::imprimePacientes(const char* cad) {
    ofstream arch;
    abrirArchivoEscritura(arch, cad);
    
    for (list<Paciente_Medicina>::iterator it = paciente_medicina.begin();
            it != paciente_medicina.end(); it++) {
        it->imprimirPaciente(arch);
    }
}

void ServicioDeSalud::totalizar() {
    for (list<Paciente_Medicina>::iterator it = paciente_medicina.begin();
            it != paciente_medicina.end(); it++) {
        it->totalizar(medicina);
    }
}
