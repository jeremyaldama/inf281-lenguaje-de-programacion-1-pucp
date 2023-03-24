#include <iostream>
#include <iomanip>
#include <cstring>
#define MAX_CAR_LIN 100
using namespace std;

void ImprimeLinea(char car, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout.put(car);
    }
    cout << endl;
}

void FormateaNombre(char *nombre)
{
    for (int i = 1; nombre[i]; i++)
    {
        nombre[i] = nombre[i] - 'A' + 'a';
    }
}

void ImprimeCabeceraCliente()
{
    cout << left << setw(40) << "Cliente" << setw(30) << "CODIGO DE CUENTA"
         << setw(14) << "MONEDA"
         << "SALDO INICIAL" << endl;
}

void LeerCliente(char &moneda)
{
    int codigo, lon = 0;
    double saldo;
    char nombre[50];

    ImprimeLinea('=', MAX_CAR_LIN);
    ImprimeCabeceraCliente();

    while (1)
    {
        cin >> codigo;
        if (cin.fail())
        {
            cin.clear();
            cin >> nombre;

            FormateaNombre(nombre);
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
    ImprimeLinea('=', MAX_CAR_LIN);
}

void ImprimirCabeceraTransacciones()
{
    cout << left << setw(14) << "FECHA" << setw(25) << "RETIROS DOLARES"
         << setw(25) << "DEPOSITOS DOLARES" << setw(25) << "SALDO DOLARES"
         << "OBSERVACION" << endl;
    ImprimeLinea('-', MAX_CAR_LIN);
}

double ActualizarMontoAMonedaCuenta(char moneda, char moneda_cuenta,
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

void ProcesarMovimientos(double dolar_cambio, double euro_cambio,
                         char moneda_cuenta)
{
    char tipo, moneda;
    double monto, total_retirado = 0, total_depositado = 0;
    int fin = 0, siguiente = 0;

    cin >> tipo;
    while (1)
    {
        if (cin.eof())
            break;
        if (fin)
            break;

        while (1)
        {
            if (cin.eof())
            {
                cout << "ESO ES TODO " << endl;
                break;
            }
            if (cin.get() == '\n')
            {
                fin = 1;
                break;
            }
            cin >> moneda;
            if (moneda == 'D' || moneda == 'R')
                break;
            cin >> monto;

            if (moneda != moneda_cuenta)
            {
                monto = ActualizarMontoAMonedaCuenta(moneda, moneda_cuenta,
                                                     monto, dolar_cambio,
                                                     euro_cambio);
            }

            if (tipo == 'D')
            {
                total_depositado += monto;
            }
            else
            {
                total_retirado += monto;
            }
        }
        tipo = moneda;
    }

    cout << setw(20) << total_retirado << setw(20) << total_depositado << endl;
}

void ProcesarCliente(double dolar_cambio, double euro_cambio,
                     char moneda)
{
    ImprimirCabeceraTransacciones();
    int dd, mm, aa;
    char car;

    while (1)
    {
        cin >> dd;
        if (cin.eof())
        {
            cout << "ESO ES TODO" << endl;
            break;
        }
        if (cin.fail())
        {
            cin.clear();
            break;
        }
        cin >> car >> mm >> car >> aa;

        ProcesarMovimientos(dolar_cambio, euro_cambio, moneda);
    }
}