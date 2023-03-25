#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_LIN 100
using namespace std;

int main(int argc, char **argv){
    double dolar_cambio, euro_cambio, saldo_inicial;
    char moneda_cliente;
    cin >> dolar_cambio >> euro_cambio;
    cout << setprecision(2) << fixed;
    cout << "ESTADO DE CUENTAS DEL BANCO ABCD" << endl;

    while (1){
        if (cin.eof()) break;

        leer_imprimir_cliente(moneda_cliente, saldo_inicial);

        int dd, mm, aa, dd_pri, cantidad_retiros = 0, cantidad_depositos = 0;
        double monto, retiro_total = 0.0, deposito_total = 0.0,
                      suma_retiro_total = 0.0, suma_deposito_total = 0.0;
        char c, tipo_mov, tipo_moneda;

        cin >> dd_pri >> c >> mm >> c >> aa;
        double limite = actualizar_monto_a_moneda_cuenta('$', moneda_cliente,
                                                         1000, dolar_cambio, euro_cambio);

        imprimir_cabecera_movimientos(moneda_cliente);

        while (cin.get() != '\n'){
            cin >> dd;
            if (cin.eof()) break;

            if (cin.fail()){
                cin.clear();

                cin >> tipo_mov;
                while (cin.get() != '\n')
                {
                    cin >> tipo_moneda;

                    if (tipo_moneda == 'D' || tipo_moneda == 'R'){
                        tipo_mov = tipo_moneda;
                        continue;
                    }
                    else{
                        cin >> monto;
                        if (tipo_moneda != moneda_cliente){
                            monto = actualizar_monto_a_moneda_cuenta(tipo_moneda,
                                                                     moneda_cliente, monto, dolar_cambio, euro_cambio);
                        }
                        sumar_montos_retiro_deposito(deposito_total,
                                                     retiro_total, saldo_inicial,
                                                     monto, tipo_mov,
                                                     cantidad_retiros,
                                                     cantidad_depositos);
                    }
                }
            }
            else{
                imprimir_movimientos_fecha(dd_pri, mm, aa, moneda_cliente, retiro_total,
                                           deposito_total, saldo_inicial, limite);

                suma_retiro_total += retiro_total;
                suma_deposito_total += deposito_total;

                retiro_total = 0.0;
                deposito_total = 0.0;
                dd_pri = dd;
                cin >> c >> mm >> c >> aa;
            }
        }
        imprimir_movimientos_fecha(dd_pri, mm, aa, moneda_cliente, retiro_total,
                                   deposito_total, saldo_inicial, limite);

        imprimir_resumen(cantidad_retiros, moneda_cliente, suma_retiro_total,
                         cantidad_depositos, suma_deposito_total, saldo_inicial,
                         limite);

        cantidad_depositos = cantidad_retiros = 0;
        suma_deposito_total = suma_retiro_total = 0.0;
    }

    return 0;
}