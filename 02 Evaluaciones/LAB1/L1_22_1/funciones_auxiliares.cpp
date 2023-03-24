#include <iostream>
#include <iomanip>
#include "funciones_auxiliares.h"
using namespace std;
#define MAX_CAR_LIN 154

void ImprimirLinea(char c, int n)
{
    cout << left << setfill(c) << setw(n) << "" << endl;
    cout << setfill(' ');
}

double calcular_descuento(char categoria, double descuento_a, 
                        double descuento_b, double descuento_c){
    if (categoria=='A') return descuento_a;
    else if (categoria=='B') return descuento_b;
    else if (categoria=='C') return descuento_c;
    else return 0;
}

void formatear_nombre(char *nombre){
    int n = calcular_longitud(nombre);
    if (nombre[n-2] == '-') nombre[n-2] = 0;
    for (int i = 0; nombre[i]; i++){
        if (nombre[i] == '/' || nombre[i] == '-' || nombre[i] == '_') 
            nombre[i] = ' ';
    }
}

int calcular_longitud(char *nombre){
    int i;
    for (i = 0; nombre[i]; i++){
    }
    return i;
}

void imprimir_cabecera_productos(){
    ImprimirLinea('-', MAX_CAR_LIN);
    cout << "PRODUCTOS ADQUIRIDOS:" << endl;
    cout << right << setw(13) << "CODIGO" <<
                    setw(15) << "DESCRIPCION" <<
                    setw(37) << "P.U." <<
                    setw(15) << "CANTIDAD" <<
                    setw(8) << "TOTAL" <<
                    setw(19) << "DESCUENTOS %" <<
                    setw(15) << "A PAGAR" <<
                    setw(15) << "DESCUENTO" <<
                    setw(12) << "FECHA" << endl;
    
    ImprimirLinea('-', MAX_CAR_LIN);
}

void imprimir_cabecera_clientes(){
    ImprimirLinea('=', MAX_CAR_LIN);
    cout << setfill(' ') << left << setw(15) << "DNI" <<
            setw(50) << "NOMBRE" <<
            setw(20) << "TELEFONO" <<
            setw(15) << "CATEGORIA" <<
            setw(15) << "DESCUENTO" << endl;
}