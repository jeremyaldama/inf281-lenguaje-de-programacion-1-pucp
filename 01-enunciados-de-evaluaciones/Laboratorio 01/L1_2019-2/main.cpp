/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 20 de noviembre de 2020, 02:01 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
using namespace std;

int main(int argc, char** argv) {
    double euro,  dolar, saldoIni;
    char moneda;
    cout.precision(2); cout << fixed;
    cin >> dolar >> euro;
    cout << setw(60) << "ESTADO DE CUENTAS DEL BANCO ABCD" << endl;
    while (1) {
        if (cin.eof()) break;
        leerCliente(saldoIni,moneda);
        procesarMovimientos(saldoIni,moneda,dolar,euro);
    }
    return (EXIT_SUCCESS);
}
