#ifndef funcionesauxiliares_h
#define funcionesauxiliares_h

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

#endif

