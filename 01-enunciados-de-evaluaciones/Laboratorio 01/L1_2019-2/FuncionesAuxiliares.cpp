/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 20 de noviembre de 2020, 02:03 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 120
using namespace std;

void imprimeLinea (char car, int num) {
    for (int i = 0; i < num; i++) {
        cout.put(car);
    }
    cout << endl;
}

void leerCliente (double &saldoIni, char &moneda) {
    int codigo, lon = 0;
    char nombre[30];
    imprimeLinea('=',MAX_CAR);
    imprimeCabeceraCliente();
    while (1) { 
        cin >> codigo;
        if (cin.fail()) {
            cin.clear();
            cin >> nombre;
            minuscula(nombre);
            cout << nombre << " ";
            lon += strlen(nombre)+1;
        } else break;
    }
    cout << setw(60-lon) << " " << codigo;
    cin >> moneda >> saldoIni;   
    if (moneda == '$') cout << setw(15) << "Dolar";
    else if (moneda == 'S') cout << setw(15) << "Soles";
    else cout << setw(15) << "Euros";
    cout << setw(18) << saldoIni << endl;
    imprimeLinea('=',MAX_CAR);
    imprimeCabeceraMovimientos(moneda);
}

void imprimeCabeceraCliente() {
    cout << "CLIENTE"
            << setw(60) << "CODIGO DE CUENTA"
            << setw(15) << "MONEDA"
            << setw(20) << "SALDO INICIAL" << endl;
}

void minuscula (char *nombre) {
    int lon = strlen(nombre);
    for (int i = 0; i < lon; i++) {
        if (i != 0) {
            nombre[i] = tolower(nombre[i]);
        }
    }
}

void imprimeCabeceraMovimientos (char moneda) {
    cout << "FECHA" 
            << setw(25) << "RETIROS " << left;

    if (moneda == '$') cout << setw(15) << "DOLARES";
    else if (moneda == 'S') cout << setw(15) << "SOLES";
    else cout << setw(15) << "EUROS";

    cout << right << setw(20) << "DEPOSITOS " << left;

    if (moneda == '$') cout << setw(15) << "DOLARES";
    else if (moneda == 'S') cout << setw(15) << "SOLES";
    else cout << setw(15) << "EUROS"; 

    cout << right << setw(10) << "SALDO " << left;

    if (moneda == '$') cout << setw(15) << "DOLARES";
    else if (moneda == 'S') cout << setw(15) << "SOLES";
    else cout << setw(15) << "EUROS";  

    cout << right << setw(10) << "OBSERVACION" << endl;
    imprimeLinea('-',MAX_CAR);
}

void procesarMovimientos (double saldoIni, char moneda, double dolar, double euro) {
    int dd, mm, aa;
    char car;
    double subtotal_depositos, subtotal_retiros, saldo = saldoIni, total_depositos = 0, 
            total_retiros = 0, factor;
    int cantR = 0, cantD = 0;
    while (1) {
        cin >> dd;
        if (cin.eof()) break;
        if (cin.fail()) {
            cin.clear();
            break;
        } 
        cin >> car >> mm >> car >> aa;
        cout << setfill('0') << setw(2) << dd << "/" << setw(2) << mm << "/" 
                << setw(4) << aa << setfill(' ');
        subtotal_depositos = 0, subtotal_retiros = 0;
        procesarTransaccion(subtotal_depositos,subtotal_retiros,saldo,dolar,euro,
                moneda,cantR,cantD);
        total_depositos += subtotal_depositos, total_retiros += subtotal_retiros;
        saldo +=  subtotal_depositos-subtotal_retiros;
        cout << setw(15) << moneda << setw(10) << subtotal_retiros
                << setw(20) << moneda << setw(10) << subtotal_depositos
                << setw(20) << moneda << setw(10) << saldo;
        factor = hallar_factor(moneda,'$',dolar,euro);
        if (saldo >= 0 && saldo <= 1000*factor) 
            cout << setw(20) << "BAJO EL MINIMO";
        else if (saldo < 0) cout << setw(20) << "SOBREGIRO";
        cout << endl;
    }
    imprimirResumen(cantR,cantD,total_retiros,total_depositos,factor,saldo,moneda);
}

void procesarTransaccion (double &subtotal_depositos, double &subtotal_retiros, 
        double &saldo, double dolar, double euro, char moneda, int &cantR, int &cantD) {
    char simbolo, m, tipo;
    double monto, factor;
    while (cin.get() != '\n') {
        cin >> simbolo;
        if (cin.fail()) {
            cin.clear();
            break;
        } else {
            if (simbolo == 'R' || simbolo == 'D') {
                cin >> m >> monto; tipo = simbolo;
                factor = hallar_factor(moneda,m,dolar,euro);
                if (simbolo == 'R') {
                    subtotal_retiros += monto*factor;
                    cantR++;
                } else {
                    subtotal_depositos += monto*factor;
                    cantD++;
                }
            } else {
                cin >> monto;
                factor = hallar_factor(moneda,simbolo,dolar,euro);
                if (tipo == 'R') {
                    subtotal_retiros += monto*factor;
                } else {
                    subtotal_depositos += monto*factor;
                }
            }
        }
    }
}

double hallar_factor (char simbolo, char car, double dolar, double euro) {
    if (simbolo == 'S') {
        if (car == 'S') return 1;
        else if (car == '$') return dolar;
        else return euro;
    } else if (simbolo == '$') {
        if (car == 'S') return 1.0/dolar;
        else if (car == '$') return 1;
        else return euro/dolar;
    } else {
        if (car == 'S') return 1.0/euro;
        else if (car == '$') return dolar*1.0/euro;
        else return 1;
    }
}

void imprimirResumen (int cantR, int cantD, double total_retiros,double total_depositos,
        double factor, double saldo, char moneda) {
    imprimeLinea('=',MAX_CAR);
    cout << "RESUMEN:" << endl;
    cout << left << setw(40) << "CANTIDAD TOTAL DE RETIROS:"
            << setw(20) << cantR
            << setw(25) << "TOTAL DE RETIROS:"
            << setw(5) << moneda << setw(10) << total_retiros << endl;
    cout << setw(40) << "CANTIDAD TOTAL DE DEPOSITOS:"
            << setw(20) << cantD
            << setw(25) << "TOTAL DE DEPOSITOS:"
            << setw(5) << moneda << setw(10) << total_depositos << endl;
    cout << setw(20) << "SALDO FINAL:"
            << setw(5) << moneda
            << setw(35) << saldo
            << setw(25) << "OBSERVACION FINAL:";
    if (saldo >= 0 && saldo <= 1000*factor) 
        cout << setw(30) << "CUENTA BAJO EL MINIMO";
    else if (saldo < 0) cout << setw(30) << "CUENTA EN SOBREGIRO";
    cout << right << endl;
}