/* 
 * Archivo:   Cuentas.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Cuentas.h"

Cuentas::Cuentas() {
    
}

Cuentas::~Cuentas() {

}

void Cuentas::leerCuentas(const char* nombArch) {
    arbClientes.crear(nombArch);
}

void Cuentas::leerTiposDeCambio(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int i = 0;
    Moneda moneda[100];
    while (1) {
        arch >> moneda[i];
        if (arch.eof()) break;       
        monedas[moneda[i].GetSimbolo()] = moneda[i];
        i++;
    }
}

void Cuentas::ejecutarMovimientos(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    int codigo;
    char simbolo, tipo;
    double monto, equivalente;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        while (arch.get() != '\n') {
            arch >> simbolo >> monto;
            arch.get(); arch >> tipo;
            Moneda moneda = monedas[simbolo];
            equivalente = moneda.GetEquivalencia();
            if (tipo == 'D') {
                arbClientes.modificar(codigo,monto*equivalente);
            } else {
                arbClientes.modificar(codigo,(-1)*monto*equivalente);
            }
        }
    }
}

void Cuentas::reporteDeCuentas(const char* nombArch, char car) {
    if (car == 'C') {
        ofstream arch(nombArch, ios::out);
        if (!arch) {
            cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
            exit(1);
        }
        arch.precision(2); arch << fixed;
        arch << setw(60) << "ESTADO DE CUENTAS" << endl;
        arch << setfill('=') << setw(100) << " " << setfill(' ') << endl;
        arch << setw(60) << "SALDO INICIAL DE LAS CUENTAS" << endl;
        arch << setfill('=') << setw(100) << " " << setfill(' ') << endl;
        arch << "Codigo" << setw(15) << "Cliente" 
                << setw(50) << "Saldo inicial"
                << setw(10) << "Estado" << endl;
        arch << setfill('-') << setw(100) << " " << setfill(' ') << endl;
        arbClientes.imprimir(arch);
    } else {
        ofstream arch(nombArch, ios::app);
        if (!arch) {
            cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
            exit(1);
        }
        arch.precision(2); arch << fixed;
        arch << setfill('=') << setw(100) << " " << setfill(' ') << endl;
        arch << setw(60) << "SALDO FINAL DE LAS CUENTAS" << endl;
        arch << setfill('=') << setw(100) << " " << setfill(' ') << endl;
        arch << "Codigo" << setw(15) << "Cliente" 
                << setw(50) << "Saldo final"
                << setw(10) << "Estado" << endl;
        arch << setfill('-') << setw(100) << " " << setfill(' ') << endl;
        arbClientes.imprimir(arch);
    }    
}