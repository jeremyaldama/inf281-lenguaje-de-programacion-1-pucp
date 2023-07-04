#include <iostream>
#include <iomanip>
#include "funciones_auxiliares.h"
#include <cstring>
using namespace std;
#define MAX_CAR_LIN 154

int main()
{
    double descuento_a, descuento_b, descuento_c;
    char c, codigo_verificar[10];
    cin >> c >> descuento_a >> c >> c >> descuento_b >> c >> c >> descuento_c 
    >> c;

    cin >> codigo_verificar;

    int dni, telefono, dd, mm, aa;
    char nombre[100], nombre_mas_descuento[100], categoria, descripcion[100],
        descripcion_producto_ver[100], codigo[10];
    double descuento_adicional, cantidad, precio_u, descuento_categoria,
            total_pagar = 0.0, total_descuento = 0.0, mayor_descuento = 0.0,
            total_producto_ver = 0.0;

    cout << right << setw(70) << "EMPRESA COMERCIALIZADORA DE ABARROTES" << endl;

    ImprimirLinea('=', MAX_CAR_LIN);

    cout << "GASTOS DE LOS CLIENTES REGISTRADOS:" << endl;

    cin >> dni >> nombre >> telefono;

    int size = calcular_longitud(nombre);
    descuento_categoria = calcular_descuento(nombre[size-2] == '-'? 
                                    nombre[size-1]:'0', 
                                    descuento_a, descuento_b, descuento_c);

    imprimir_cabecera_clientes();

    categoria = nombre[size-2] == '-'? nombre[size-1] : '-';

    formatear_nombre(nombre);
    cout << setw(15) << dni <<
            setw(50) << nombre <<
            setw(20) << telefono <<
            setw(15) << categoria <<
            setw(4) << descuento_categoria << "%" << endl;

    imprimir_cabecera_productos();

    int contador_productos = 0, primero = 1;
    while (1)
    {
        cin >> dni;

        if (cin.eof()) break;

        if (cin.fail()){
            cin.clear();

            cin >> codigo >> descripcion;
            
            cin >> cantidad;

            if (cin.fail()){
                cin.clear();
                cin >> c >> descuento_adicional >> cantidad >> precio_u >> dd 
                >> c >> mm >> c >> aa;
            }
            else{
                cin >> precio_u >> dd >> c >> mm >> c >> aa;
                descuento_adicional = 0.0;
            }

            contador_productos++;

            double total = precio_u * cantidad;
            double total_nuevo = total;

            formatear_nombre(descripcion);
            cout << setfill(' ') << right << setw(3) << contador_productos <<
                            setw(4) << "" << 
                            left << setw(10) << codigo <<
                            setw(42) << descripcion <<
                            right << setfill(' ') << setw(6) << precio_u <<
                            setfill(' ') <<
                            setw(7) << "" << setfill(' ') <<
                            setw(5) << cantidad <<
                            setw(5) << "" <<
                            fixed << setprecision(2) << setw(7) << total <<
                            setfill(' ');
            
            cout << setw(6) << "";
            (descuento_adicional > 0.0)? cout << setw(5) << 
            descuento_adicional : cout << setw(5) << "-.--";

            cout << "|";
            
            if (descuento_categoria == 0.0){
                cout << right << setw(6) << " -.--";
            }
            else
                cout << right << setw(6) << descuento_categoria;

            if (descuento_adicional > 0){
                total_nuevo = (100-descuento_adicional)/100 * total_nuevo;
            }
            if (descuento_categoria > 0){
                total_nuevo = (100-descuento_categoria)/100 * total_nuevo;
            }

            if (strcmp(codigo_verificar, codigo) == 0){
                if (primero){
                    strcpy(descripcion_producto_ver, descripcion);
                    primero = 0;
                }
                total_producto_ver += total_nuevo;
            }

            cout << right << setw(7) << "" << setw(8) << total_nuevo <<
            setw(7) << "" << setw(8) << total-total_nuevo;
            cout << setw(5) << "" << setfill('0') << setw(2) << dd << "/" <<
                    setw(2) << mm << "/" << setw(4) << aa << endl;

            total_pagar += total_nuevo;
            total_descuento += total-total_nuevo;
        }
        else{
            ImprimirLinea('-', MAX_CAR_LIN);
            cout << right << setw(13) << "TOTAL:" << setw(103) << "" <<
            setw(6) << total_pagar << setw(8) << "" << setw(7) <<
            total_descuento << endl;
            ImprimirLinea('=', MAX_CAR_LIN);
            cout << endl;

            if (total_descuento > mayor_descuento){
                mayor_descuento = total_descuento;
                strcpy(nombre_mas_descuento, nombre);
            }

            cin >> nombre >> telefono;
            contador_productos = 0;
            total_pagar = 0.0;
            total_descuento = 0.0;
            size = calcular_longitud(nombre);
            descuento_categoria = calcular_descuento(nombre[size-2] == '-'? 
                                    nombre[size-1] : '0', 
                                    descuento_a, descuento_b, descuento_c);

            imprimir_cabecera_clientes();
            categoria = nombre[size-2] == '-'? nombre[size-1] : '-';

            formatear_nombre(nombre);
            cout << setw(15) << dni <<
                    setw(50) << nombre <<
                    setw(20) << telefono <<
                    setw(15) << categoria;
            
            if (descuento_categoria > 0)
                cout << setw(4) << descuento_categoria << "%" << endl;
            else cout << setw(15) << "-.--%" << endl;
            
            imprimir_cabecera_productos();
        }
    }

    ImprimirLinea('=', MAX_CAR_LIN);
    cout << endl;
    ImprimirLinea('=', MAX_CAR_LIN);

    cout << "CLIENTE QUE RECIBIO MAS DESCUENTO: " << left << setw(50) <<
    nombre_mas_descuento << setfill(' ') << "DESCUENTO TOTAL: " <<
    mayor_descuento << endl;

    cout << "PRODUCTO A VERIFICAR: " << descripcion_producto_ver << " [" <<
    codigo_verificar << setw(31) << "]" <<
    "TOTAL INGRESADO POR EL PRODUCTO: " << total_producto_ver << endl;

    return 0;
}