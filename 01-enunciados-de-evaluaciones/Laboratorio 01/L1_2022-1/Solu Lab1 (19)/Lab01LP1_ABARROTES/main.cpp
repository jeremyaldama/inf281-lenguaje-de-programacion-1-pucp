/* 
 * Proyecto: Lab01LP1_ABARROTES
 * File:   main.cpp
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 8 de abril de 2022, 8:04
 */

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_CAR 140

#include "funcionesAuxiliares.h"

/*
 * Programa para poder ver la cantidad de productos y ganancias de una tienda
 */
int main(int argc, char** argv) {
    
    double porcA, porcB, porcC, dscto, cantidad, precUni, total, descuentoPago, pago,
            descuentoAnadido;
    char car, codProducto[8], codProductoEspecial[8], nombreCliente[50], descripcionProd[50],
            categCliente, nombreClienteMasDescuento[50], descripcionProductoEspacial[50];
    int dniCliente, telefonoCliente, dd, mm, aa, cantProductos=0;
    
    double mayorDescuento = -1;
    
    double totalPago = 0, totalDescuento = 0, totalProdEspecial=0;
    
    /*Impresion de la cabecera general*/
    cout << setw(40) << " " << "EMPRESA COMERCIALIZADORA DE ABARROTES" << endl;
    imprimirLinea('=', MAX_CAR);
    cout << "GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;
    imprimirLinea('=', MAX_CAR);
    
    cout << fixed << setprecision(2);
    
    cin >> car >> porcA >> car >> car >> porcB >> car >> car >> porcC >> car;
    cin >> codProductoEspecial;
    cin >> dniCliente >> nombreCliente >> telefonoCliente;
    categCliente = categoriaCliente(nombreCliente);
    
    calcularDescuentoCliente(dscto, categCliente, porcA, porcB, porcC);
    
    cambioPalabra(nombreCliente);
    imprimirCabeceraCliente(dniCliente, nombreCliente, telefonoCliente, categCliente, dscto);
    
    /*Iterativa para lectura y analisis de problema*/
    while(1){
        cin >> dniCliente;
        if(cin.eof()){
            imprimirLinea('-', MAX_CAR);
            cout << setw(6) << " " << "Total:" <<
                    right << setw(103) << totalPago <<
                    setw(8) << totalDescuento << endl;
            break;
        }
        
        //Si es que fallara en la lectura
        if(cin.fail()){
            cin.clear();
            
            cin >> codProducto >> descripcionProd;
            
            int siEs = 0;
            if(compararCadenas(codProducto, codProductoEspecial)){
                cambioPalabra(descripcionProd);
                copiarNombre(descripcionProd, descripcionProductoEspacial);
                siEs = 1;
            }
            
            cambioPalabra(descripcionProd);
            cin >> descuentoAnadido;
            
            if(cin.fail()){
                cin.clear();
                
                cin >> car >> descuentoAnadido >> cantidad;
            }else{
                cantidad = descuentoAnadido;
                descuentoAnadido = 0;
            }
            
            cin >> precUni;
            cin >> dd >> car >> mm >> car >> aa;
            cantProductos++;
            
            total = cantProductos*precUni;
            pago = total - (descuentoAnadido/100)*total;
            descuentoPago = (dscto/100)*pago;
            pago -= descuentoPago;
            descuentoPago = total-pago;
            
            totalPago += pago;
            totalDescuento += descuentoPago;
            
            if(siEs){
                totalProdEspecial += totalPago;
                siEs=0;
            }
            
            imprimirProducto(cantProductos, codProducto, descripcionProd, precUni, cantidad, total, 
                    descuentoAnadido, dscto, pago, descuentoPago);
            imprimirFecha(dd, mm, aa);
            cout << endl;
        }else{
            //Imprimimos el reporte, pues leemos un nuevo cliente
            imprimirLinea('-', MAX_CAR);
            cout << setw(6) << " " << "Total:" <<
                    right << setw(103) << totalPago <<
                    setw(8) << totalDescuento << endl;
            
            if(totalDescuento > mayorDescuento){
                mayorDescuento = totalDescuento;
                copiarNombre(nombreCliente, nombreClienteMasDescuento);
            }
            
            //Lectura del siguiente cliente
            cin >> nombreCliente >> telefonoCliente;
            categCliente = categoriaCliente(nombreCliente);
            calcularDescuentoCliente(dscto, categCliente, porcA, porcB, porcC);
            cambioPalabra(nombreCliente);
            imprimirCabeceraCliente(dniCliente, nombreCliente, telefonoCliente, categCliente, dscto);
            
            //actualizamos datos de cada cliente
            cantProductos=0;
            totalPago=0;
            totalDescuento=0;
        }
    }
    //Datos finales del reporte
    imprimirLinea('=', MAX_CAR);
    cout << "CLIENTE QUE RECIBIO MAS DESCUENTO:" << "   " << nombreClienteMasDescuento;
    cout << "        " << "DESCUENTO TOTAL:" << "    " << mayorDescuento << endl;
    
    cout << "PRODUCTO A VERIFICAR:  " << descripcionProductoEspacial << " [" << 
            codProductoEspecial << "]";
    cout << "    TOTAL INGRESADO POR EL PRODUCTO:" <<
            right << setw(8) << totalProdEspecial;
    return 0;
}
