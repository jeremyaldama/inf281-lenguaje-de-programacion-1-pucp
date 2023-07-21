/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:41 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Cuentas.h"
using namespace std;

int main(int argc, char** argv) {
    Cuentas cuenta;
    cuenta.leerCuentas("Clientes.csv");
    cuenta.reporteDeCuentas("Reporte.txt",'C');
    cuenta.leerTiposDeCambio("TipoDeCambio.csv");
    cuenta.ejecutarMovimientos("Transacciones.csv");
    cuenta.reporteDeCuentas("Reporte.txt",'A');
    return (EXIT_SUCCESS);
}
