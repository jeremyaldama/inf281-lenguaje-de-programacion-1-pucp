#include <iostream>
#include <iomanip>
#include "funciones_auxiliares.h"
using namespace std;

int main(){
    int temp, dd, mm, aa, licencia, codigo;
    char placa[20], tipo, cadena[20], nombre[100];
    double multa;

    while (1){
        cin >> licencia;
        if (cin.eof()) break;
        if (cin.fail()){
            cin.clear();
            cin >> placa;
            cout << endl << setw(10) << placa << "-";

            dd = mm = aa = 0;

            while(1){
                cin >> temp;
                if (cin.fail()){
                    cin.clear();
                    break;
                }
                else{
                    dd = mm;
                    mm = aa;
                    aa = temp;
                }
            }
            
            cout << setfill('0');
            if (dd == 0) cout << setw(2) << "--";
            else cout << setw(2) << dd;

            if (mm == 0) cout << "/" << setw(2) << "--";
            else cout << "/" << setw(2) << mm;
            cout << "/" << setw(4) << aa;
            cout << setfill(' ');
            cin >> tipo >> codigo >> cadena >> multa;
            cout << setw(5) << codigo;

            if (tipo == 'G')
                cout << setw(17) << "Grave" << setw(10) << "70";
            if (tipo == 'L')
                cout << setw(17) << "Leve" << setw(10) << "50";
            if (tipo == 'M')
                cout << setw(17) << "Muy grave" << setw(10) << "150";
            
        }
        else{
            cin >> nombre;
            cout << endl << endl << setw(20) << licencia << setw(50) << nombre << endl;
        }
    }
}