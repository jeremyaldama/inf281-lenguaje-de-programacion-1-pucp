/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 13 de mayo de 2023, 18:22
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

int main(int argc, char** argv) {
    void *productos, *pedidos, *clientes;

    cargaproductos(productos);
    imprimeproductos(productos);

    cargapedidos(pedidos);
    imprimepedidos(pedidos);

//    void **registros = (void**) pedidos;
//    for (int i = 0; registros[i]; i++) {
//        void **registro = (void**) registros[i];
//        int dni = *(int*) registro[0];
//        cout << dni << endl;
//    }
    
    procesaclientes(productos,pedidos,clientes);
    imprimerepfinal(clientes);

    return 0;
}

