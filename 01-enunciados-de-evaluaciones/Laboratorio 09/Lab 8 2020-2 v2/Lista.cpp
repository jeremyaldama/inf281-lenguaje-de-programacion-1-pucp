/* 
 * Archivo:   Lista.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 11:42 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    lista = nullptr;
}

Lista::~Lista() {
    Nodo *sale;
    while (lista) {
        sale = lista;
        lista = lista->next;
        delete sale;
    }
}

void Lista::crear(const char* nombArch) {
    ifstream arch(nombArch,ios::in); 
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int dni;
    char nombre[60], tipo;
    Paciente *dato;
    while (1) {
        arch >> dni;
        if (arch.eof()) break;
        arch.get();
        arch.getline(nombre,60,',');
        arch >> tipo; arch.get();
        if (tipo == 'E') {
            dato = new Emergencia;
            dato->SetDni(dni);
            dato->SetNombre(nombre);
            dato->lee(arch);
        } else if (tipo == 'A') {
            dato = new Ambulatorio;
            dato->SetDni(dni);
            dato->SetNombre(nombre);
            dato->lee(arch);
        } else {
            dato = new Urgencia;
            dato->SetDni(dni);
            dato->SetNombre(nombre);
            dato->lee(arch);
        }
        this->insertar(dato);
    }
}

void Lista::insertar(Paciente*& dato) {
    Nodo *p = lista, *ant = nullptr, *nuevo;
    nuevo = new Nodo;
    nuevo->paciente = dato;
    while (p) {
        if ((p->paciente)->getPrioridad() > dato->getPrioridad()) break;
        ant = p;
        p = p->next;
    }
    nuevo->next = p;
    if (ant != nullptr) ant->next = nuevo;
    else lista = nuevo;
}

void Lista::imprimir(const char* nombArch) {
    ofstream arch(nombArch,ios::out); 
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    arch.precision(2); arch << fixed;
    arch << setw(70) << "INSTITUTO DE SALUD SA" << endl;   
    Nodo *p = lista;
    int prio, prioPrev = 0;
    while (p) {
        prio = (p->paciente)->getPrioridad();
        if (prio != prioPrev) {
            if (prio == 1) {
                imprimeLinea('=',130,arch);
                arch << setw(70) << "PACIENTES ATENDIDOS POR EMERGENCIA" << endl;
                imprimeLinea('-',130,arch);
                arch << setw(10) << "DNI" << setw(20) << "Paciente"
                    << setw(40) << "Medico" << setw(25) << "Referencia" << endl;
            } else if (prio == 2) {
                imprimeLinea('=',130,arch);
                arch << setw(70) << "PACIENTES ATENDIDOS POR URGENCIA" << endl;
                imprimeLinea('-',130,arch);
                arch << setw(10) << "DNI" << setw(20) << "Paciente"
                    << setw(40) << "Medico" << setw(15) << "% por Seg" << setw(20) << "% por Urgencia" << endl;
            } else {
                imprimeLinea('=',130,arch);
                arch << setw(70) << "PACIENTES ATENDIDOS DE MANERA AMBULATORIA" << endl;
                imprimeLinea('-',130,arch);
                arch << setw(10) << "DNI" << setw(20) << "Paciente"
                    << setw(40) << "Medico" << setw(15) << "% por Seg" << endl;
            }
        }
        (p->paciente)->imprime(arch);
        p = p->next;
        prioPrev = prio;
    }
}

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
}