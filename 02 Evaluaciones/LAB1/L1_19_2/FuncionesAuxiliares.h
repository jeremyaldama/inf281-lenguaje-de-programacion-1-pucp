/* 
 * File:   FuncionesAuxiliares.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 7 de diciembre de 2022, 22:27
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void ImprimeLinea (char car, int num) ;

void FormateaNombre(char *nombre);

void ImprimeCabeceraCliente();
void LeerCliente(char &moneda);

void ImprimirCabeceraTransacciones();
double ActualizarMontoAMonedaCuenta(char moneda, char moneda_cuenta,
                                    double monto, double dolar_cambio, 
                                    double euro_cambio);
void ProcesarMovimientos(double dolar_cambio, double euro_cambio,
                        char moneda_cuenta);

void ProcesarCliente(double dolar_cambio, double euro_cambio,
                     char moneda);

#endif /* FUNCIONESAUXILIARES_H */

