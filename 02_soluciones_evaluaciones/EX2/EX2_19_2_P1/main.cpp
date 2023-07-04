/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 14 de junio de 2023, 22:41
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "ListaProducto.h"

int main(int argc, char** argv) {
    //    ofstream arch("prueba.txt", ios::out);
    //    class PlCola<int> colaInt;
    //    colaInt.llegada(1);
    //    colaInt.llegada(2);
    //    colaInt.llegada(3);
    //    colaInt.llegada(4);
    //    colaInt.llegada(8);
    //    colaInt.mostrar(arch);
    //    int d;
    //    while (!colaInt.estaVacia()) {
    //        colaInt.atencion(d);
    //        cout << setw(4) << d;
    //    }

//    class Cliente cli;
//    ifstream arch("Banco-ClientesSeg.csv", ios::in);
//    if (!arch) {
//        cout << "NO SE PUDO ABRIR";
//        exit(1);
//    }
//    ofstream arch2("Prueba.txt", ios::out);
//    char aux[100];
//    arch.getline(aux, 100);
//    while (true) {
//        arch >> cli;
//        if (arch.eof()) break;
//        arch2 << cli;
//    }
//    class Prueba prueba;
//    int horaApertura;
//    prueba.cargarCola(horaApertura);
//    prueba.emiteReporte(horaApertura);
    class ListaProducto lista;
    lista.cargarCodigos("producto.csv");
    lista.cargarStock("stock.csv");
    lista.cargarPedidos("pedido.csv");
    lista.imprimirContenido("Rep.txt");
    return 0;
}

