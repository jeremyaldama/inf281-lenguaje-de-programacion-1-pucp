#include <iostream>
#include <iomanip>
#include <cstring>
#define MAX_CAR_LIN 100
using namespace std;

void imprimir_linea(char car, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout.put(car);
    }
    cout << endl;
}

void formatear_nombre(char *nombre)
{
    for (int i = 1; nombre[i]; i++)
    {
        nombre[i] = nombre[i] - 'A' + 'a';
    }
}

void imprimir_cabecera_cliente()
{
    cout << left << setw(40) << "Cliente" << setw(30) << "CODIGO DE CUENTA"
         << setw(14) << "MONEDA"
         << "SALDO INICIAL" << endl;
}

void leer_imprimir_cliente(char &moneda, double &saldo)
{
    int codigo, lon = 0;
    char nombre[50];

    imprimir_linea('=', MAX_CAR_LIN);
    imprimir_cabecera_cliente();

    while (1)
    {
        cin >> codigo;
        if (cin.fail())
        {
            cin.clear();
            cin >> nombre;

            formatear_nombre(nombre);
            lon += strlen(nombre);
            cout << nombre << " ";
        }
        else
            break;
    }
    // pa la derecha
    cout << right << setw(45 - lon) << codigo;
    cin >> moneda >> saldo;
    if (moneda == '$')
        cout << setw(26) << "Dolar" << setw(12) << "$  ";
    else if (moneda == 'S')
        cout << setw(26) << "Soles" << setw(12) << "S  ";
    else
        cout << right << setw(26) << "Euros" << setw(12) << "&  ";
    cout << saldo << endl;
    imprimir_linea('=', MAX_CAR_LIN);
}

double actualizar_monto_a_moneda_cuenta(char moneda, char moneda_cuenta,
                                        double monto, double dolar_cambio,
                                        double euro_cambio)
{
    if (moneda_cuenta == 'S')
    {
        if (moneda == '$')
            return monto * dolar_cambio;
        else
            return monto * euro_cambio;
    }
    else if (moneda_cuenta == '$')
    {
        if (moneda == 'S')
            return monto / dolar_cambio;
        else
            return monto * euro_cambio / dolar_cambio;
    }
    else
    {
        if (moneda == 'S')
            return monto / euro_cambio;
        else
            return monto * dolar_cambio / euro_cambio;
    }
}

void imprimir_tipo_moneda(char moneda_cliente){
    cout << left;
    if (moneda_cliente == 'S')
        cout << setw(8) << "SOLES";
    else if (moneda_cliente == '$')
        cout << setw(8) << "DOLARES";
    else
        cout << setw(8) << "EUROS";
}

void imprimir_movimientos_fecha(int dd_pri, int mm, int aa, char moneda_cliente,
                                double retiro_total,
                                double deposito_total, double saldo_inicial,
                                double limite){
    cout << right << setfill('0') << setw(2) << dd_pri << "/" << setw(2) <<
    mm << "/" << setfill(' ') << left << setw(10) << aa;

    cout << moneda_cliente << right << setw(10) << retiro_total << setw(13) <<
    "" << moneda_cliente << setw(10) << deposito_total << setw(15) << "" <<
    moneda_cliente << setw(10) << saldo_inicial;

    cout << setw(10) << "";

    if (saldo_inicial < 0){
        cout << "SOBREGIRO";
    }
    else if (saldo_inicial < limite){
        cout << "BAJO EL MINIMO";
    }

    cout << endl;
}

void imprimir_cabecera_movimientos(char moneda_cliente)
{
    cout << left << setw(16) << "FECHA"
         << "RETIROS ";
    imprimir_tipo_moneda(moneda_cliente);

    cout << setw(8) << ""
         << "DEPOSITOS ";
    imprimir_tipo_moneda(moneda_cliente);

    cout << setw(8) << ""
         << "SALDO ";
    imprimir_tipo_moneda(moneda_cliente);

    cout << right << setw(18) << "OBSERVACION" << endl;
    imprimir_linea('-', MAX_CAR_LIN);
}

void sumar_montos_retiro_deposito(double &deposito_total, double &retiro_total,
                                  double &saldo_inicial, double monto, char tipo_mov,
                                  int &cantidad_retiros, int &cantidad_depositos)
{
    if (tipo_mov == 'D')
    {
        deposito_total += monto;
        saldo_inicial += monto;
        cantidad_depositos++;
    }
    if (tipo_mov == 'R')
    {
        retiro_total += monto;
        saldo_inicial -= monto;
        cantidad_retiros++;
    }
}

void imprimir_resumen(double cantidad_retiros, char moneda_cliente,
                      double suma_retiro_total, double cantidad_depositos,
                      double suma_deposito_total,
                      double saldo_inicial, double limite)
{
    imprimir_linea('=', MAX_CAR_LIN);
    cout << left << setw(30) << "CANTIDAD TOTAL DE RETIROS: " << 
    cantidad_retiros;
    cout << right << setw(25) << "TOTAL DE RETIROS: " << setw(8) << 
    moneda_cliente << setw(11) << suma_retiro_total << endl;

    cout << left << setw(30) << "CANTIDAD TOTAL DE DEPOSITOS: " << 
    cantidad_depositos;
    cout << right << setw(25) << "TOTAL DE DEPOSITOS: " << setw(8) << 
    moneda_cliente << setw(11) << suma_deposito_total << endl;

    cout << left << setw(22) << "SALDO FINAL: " << moneda_cliente << right <<
    setw(10) << saldo_inicial << setw(28) << "OBSERVACION FINAL: ";

    if (saldo_inicial < 0.0)
        cout << "CUENTA EN SOBREGIRO";
    else if (saldo_inicial < limite)
        cout << "CUENTA BAJO EL MINIMO";
    cout << endl;
}