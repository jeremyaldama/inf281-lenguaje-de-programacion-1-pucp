/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 24 de abril de 2023, 22:43
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Funciones.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream arch_clientes;
    AperturaDeUnArchivoDeTextosParaLeer(arch_clientes, "Clientes.txt");
    
    struct Estructura_ClienteRegistrado clientes[20];
    clientes[0].dni = 0;
    struct Estructura_ClienteRegistrado cliente;
    int i = 0;
    while (1){
        arch_clientes >> cliente;
        if (arch_clientes.eof()) break;
        clientes += cliente;
        i++;
    }
    
    for (int j = 0; j<i; j++){
        cout << left << setw(14) << clientes[j].dni << setw(60) <<
                clientes[j].nombre << setw(40) << clientes[j].categoria << endl;
    }
    
    ofstream rep;
    AperturaDeUnArchivoDeTextosParaEscribir(rep, "reporte.txt");
//    struct Estructura_PedidoRealizado{
//    char codigo[7];
//    double cantidad;
//    int fecha;   // Formato aaaammdd
    struct Estructura_PedidoRealizado pedido;
    strcpy(pedido.codigo, "HOLA");
    pedido.cantidad = 100;
    pedido.fecha = 20230425;
    clientes[0].pedidosRealizados[0] = pedido;
    strcpy(clientes[0].pedidosRealizados[1].codigo, "X");
    clientes[0].numeroDePedidos = 1;
    rep << clientes[0];
    return 0;
}
