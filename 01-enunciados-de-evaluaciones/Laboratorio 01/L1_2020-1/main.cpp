/* 
 * Archivo:   main.cpp
 * Autor: Oscar DueÃ±as Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 2 de septiembre de 2020, 08:31 PM
 */

#include <iostream>
#include <iomanip>
#include "funcionesAux.h"
#define MAX_CAR 100
using namespace std;

int main(int argc, char** argv) {
    int dd, mm, aa, tipoMov, codProd, dato;
    double cant;
    char tienda[50], producto[30], unidad[10];
    char car;
    int signo;
    cout.precision(2);
    cout << fixed;
    cout << setw(50) << "REPORTE KARDEX" << endl;
    while (1) {
        cin >> dato;
        signo = 1;
        if (cin.eof()) break;
        if (dato > 31) {
            cin >> tienda;
            imprimeLinea('=',MAX_CAR);
            cout << left << setw(15) << dato 
                    << setw(20) << tienda << endl;
            imprimeLinea('=',100);
            cout << setw(15) << "FECHA" 
                    << setw(15) << "CODIGO" 
                    << setw(20) << "DECRIPCION" 
                    << "                            " 
                    << setw(15) << "CANTIDAD" 
                    << setw(15) << "UNIDAD" << endl;
            imprimeLinea('-',MAX_CAR);
            cin >> dato;
        }
        dd = dato;
        cin >> car >> mm >> car >> aa;
        cin >> tipoMov >> codProd >> producto >> cant;
        if (cin.fail()) {
            cin.clear();
            cant = 1;
        }
        cin >> unidad;
        if (tipoMov/100 == 5 || tipoMov/100 == 3) {
            cout.fill('0');
            cout << right << setw(2) << dd << "/" << setw(2) << mm << "/" << setw(4) << aa << left;
            cout << "     ";
            cout << right << setw(8) << codProd;
            cout.fill(' ');
            cout << "       " << left << setw(45) << producto;
            if (tipoMov/100 == 3) signo = -1;
            cout << right << setw(10) << cant*signo;
            cout << setw(15) << unidad << endl;
        }
    }
    return (EXIT_SUCCESS);
}