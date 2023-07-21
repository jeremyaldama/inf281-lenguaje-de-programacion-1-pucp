/* 
 * File:   funcionesAuxiliares.cpp
 * Author: Gianella Lope Sainz
 * 
 * Created on 8 de abril de 2022, 8:04
 */
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_CAR 140

#include "funcionesAuxiliares.h"

void imprimirFecha(int dd, int mm, int aa){
    cout << right << setfill('0') << 
            setw(2) << dd << '/' <<
            setw(2) << mm << '/' << 
            setw(4) << aa << setfill(' ');
} 

/*Función que crea cadenas de caracteres de cantVeces dependiendo del car recibido*/
void imprimirLinea(char car, int cantVeces){
    for(int i=0; i<cantVeces; i++) cout << car;
    cout << endl;
}
//Nos da la categoria del cliente si tuviese
char categoriaCliente(char *nombre){
    int cantLetras = cantidadLetras(nombre);
    char car;
    if(nombre[cantLetras-2] == '-'){
        car = nombre[cantLetras-1];
        nombre[cantLetras-2] = nombre[cantLetras];
    }else{
        car = '-';
    }
    return car;
}

//Cantidad de letras de una palara
int cantidadLetras(char *palabra){
    int i=0;
    while(palabra[i]){
        i++;
    }
    return i;
}

//Cambiamos los _
void cambioPalabra(char *palabra){
    int i=0;
    while(palabra[i]){
        if(palabra[i] == '_') palabra[i] = ' ';
        i++;
    }
}

//Impresion de la cabecera del clietne
void imprimirCabeceraCliente(int dniCliente, char *nombre, int telefono, char categoria, double descuento){
    imprimirLinea('=', MAX_CAR);
    cout << left << setw(12) << "DNI" <<
            setw(60) << "Nombre" <<
            setw(14) << "Telefono" <<
            setw(15) << "Categoria" <<
            "Descuento" << endl;
    imprimirLinea('=', MAX_CAR);
    
    cout << fixed << setprecision(1);
    cout << left << setw(12) << dniCliente <<
            setw(50) << nombre <<
            right << setw(19) << telefono <<
            setw(10) << categoria;
    cout << setw(15);
    if(descuento == 0){
        cout << "--.--";
    }else{
        cout << descuento;
    }
    cout << "%" << endl;
    imprimirLinea('-', MAX_CAR);
    cout << left << "PRODUCTOS ADQUIRIDOS:" << endl;
    
    cout << fixed << setprecision(2);
    imprimirLinea('-', MAX_CAR);
    cout << setw(6) << " " <<
            setw(10) << "Codigo" <<
            setw(53) << "Descripcion" <<
            setw(6) << "P.U." <<
            setw(9) << "Cantidad" <<
            setw(7) << "Total" <<
            setw(13) << "Descuentos" <<
            setw(4) << "%" <<
            setw(9) << "A Pagar" <<
            setw(12) << "Descuento" <<
            "Fecha" << endl;
    imprimirLinea('-', MAX_CAR);
}

void calcularDescuentoCliente(double &dscto, char categCliente, double porcA, double porcB, double porcC){
    if(categCliente == 'A'){
        dscto = porcA;
    }else if(categCliente == 'B'){
        dscto = porcB;
    }else if(categCliente == 'C'){
        dscto = porcC;
    }else{
        dscto = 0;
    }
}

//Impresion del producto
void imprimirProducto(int cantProductos, char *codProducto, char *descripcionProd, 
        double precUni, double cantidad, double total, 
        double descuentoAnadido, double dscto, double pago, double descuentoPago){
    cout << right << setw(3) << cantProductos <<
            setw(9) << codProducto <<
            setw(4) << " " <<
            left << setw(50) << descripcionProd <<
            right << setw(8) << precUni <<
            setw(8) << cantidad <<
            setw(8) << total;
    
    cout << setw(8);
    if(descuentoAnadido != 0) cout << descuentoAnadido;
    else cout << "--.--";
    
    cout << "|";
    
    cout << setw(8);
    if(descuentoAnadido != 0) cout << dscto;
    else cout << "--.--";
    
    cout << setw(8) << pago <<
            setw(8) << descuentoPago <<
            setw(5) << " ";
}

//Copiar de un caracter al otro
void copiarNombre(char *nombreCliente, char *nombreClienteMasDescuento){
    int i=0;
    while(nombreCliente[i]){
        nombreClienteMasDescuento[i] = nombreCliente[i];
        i++;
    }
    nombreClienteMasDescuento[i] = nombreCliente[i];
}

//Comparamos dos cdenas de caracteres
int compararCadenas(char *cadena1, char *cadena2){
    int i=0;
    while(cadena1[i]){
        if(cadena1[i] != cadena2[i]) return 0;
        i++;
    }
    return 1;
}