#ifndef funcionesauxiliares_h
#define funcionesauxiliares_h


void ImprimirLinea(char c, int n);
void leer_imprimir_datos_cliente(double descuento_a, double descuento_b,
                                double descuento_c);
double calcular_descuento(char categoria, double, double descuento_b, double);
void formatear_nombre(char *nombre);
void leer_imprimir_producto(double descuento);
int calcular_longitud(char *nombre);
void imprimir_cabecera_productos();
void imprimir_cabecera_clientes();
#endif
