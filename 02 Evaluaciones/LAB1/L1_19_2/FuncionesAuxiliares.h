#ifndef funcionesauxiliares_h
#define funcionesauxiliares_h


void imprimir_linea(char, int);
void formatear_nombre(char *);
void imprimir_cabecera_cliente();
void leer_imprimir_cliente(char &, double &);
double actualizar_monto_a_moneda_cuenta(char , char ,
                                        double , double ,
                                        double );
void imprimir_tipo_moneda(char );
void imprimir_movimientos_fecha(int , int , int , char ,
                                double ,
                                double , double ,
                                double );
void imprimir_cabecera_movimientos(char );
void sumar_montos_retiro_deposito(double &, double &,
                                  double &, double , char ,
                                  int &, int &);
void imprimir_resumen(double , char ,
                      double , double ,
                      double ,
                      double , double );

#endif
