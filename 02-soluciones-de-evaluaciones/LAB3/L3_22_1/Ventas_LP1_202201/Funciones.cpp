/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 25 de abril de 2023, 0:07
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Funciones.h"
#include "Estructuras.h"
using namespace std;

ifstream& operator >>(ifstream &arch, struct Estructura_ClienteRegistrado &cliente){
    int dni, telefono;
    char nombre[80], categoria;
    
    arch >> dni;
    if (arch.eof()) return arch;
    arch >> nombre >> telefono;
   
    int len = strlen(nombre);
    if (nombre[len-2] == '-'){
        categoria = nombre[len-1];
        nombre[len-2] = 0;
    }
    
    cliente.dni = dni;
    strcpy(cliente.nombre, nombre);
    if (categoria == 'A') strcpy(cliente.categoria, "Cliente muy frecuente");
    else if (categoria == 'B') strcpy(cliente.categoria, "Cliente frecuente");
    else if (categoria == 'C') strcpy(cliente.categoria, "Cliente ocasional");
    else strcpy(cliente.categoria, "Cliente nuevo");
    cliente.numeroDePedidos = cliente.montoTotalGastado = 0;
    return arch;
}

void operator +=(struct Estructura_ClienteRegistrado *clientes, 
        const struct Estructura_ClienteRegistrado cliente){
    int i;
    cout << clientes[0].dni << endl;
    for (i=0; clientes[i].dni; i++);
    clientes[i] = cliente;
    clientes[++i].dni = 0;
}

void operator +=(struct Estructura_ClienteRegistrado &cliente, 
        const struct Estructura_PedidoRealizado pedido){
    cliente.pedidosRealizados[cliente.numeroDePedidos++] = pedido;
    cliente.montoTotalGastado = 0.0;
}

void operator +=(struct Estructura_ProductosEnAlmacen *arreglo,
        const struct Estructura_ProductosEnAlmacen producto){
    int i;
    for (i=0; arreglo[i].codigo[0] != 'X' && arreglo[i].codigo[1] != 0; i++);
    arreglo[i] = producto;
    arreglo[++i].codigo[0] = 'X';
    arreglo[++i].codigo[1] = 0;    
}

void operator <<(ofstream &arch, struct Estructura_ClienteRegistrado cliente){
    arch << "PRUEBA" << endl;
    arch << "  " << left << setw(30) << "DNI" << "NOMBRE" << endl;
    arch << setw(12) << cliente.dni << cliente.nombre << endl;
    arch << cliente.categoria << endl;
    arch << setw(6) << "No." << setw(24) << "CODIGO" << setw(24) << 
            "CANTIDAD" << "FECHA" << endl;
    double total = 0.0;
    for (int i=0; i<cliente.numeroDePedidos; i++){
        int dd, mm, aa, fecha = cliente.pedidosRealizados[i].fecha;
        dd = fecha%100;
        mm = (fecha/100)%100;
        aa = fecha/10000;
        arch << i+1 << setw(5) << ')' << setw(24) << 
                cliente.pedidosRealizados[i].codigo << setw(22) <<
                cliente.pedidosRealizados[i].cantidad <<
                setfill('0') << setw(2) << right << 
                dd << '/' << setw(2) << mm << '/' << aa << setfill(' ') << 
                left << endl;
        total += cliente.pedidosRealizados[i].cantidad;
    }
    arch << "Monto total comprado: " << total << endl;
}