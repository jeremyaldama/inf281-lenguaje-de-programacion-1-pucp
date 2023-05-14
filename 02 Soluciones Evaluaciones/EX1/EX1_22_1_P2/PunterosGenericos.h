/* 
 * File:   PunterosGenericos.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 13 de mayo de 2023, 18:23
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
#include <fstream>
using namespace std;

void cargaproductos(void*&productos);

void*LeerProducto(ifstream&arch);
void cargapedidos(void*&pedidos) ;

void *LeerPedido(ifstream&arch);
void procesaclientes(void*productos, void*pedidos, void*&clientes) ;
void *LeerCliente(ifstream&arch, void*productos, void*pedidos);

void AsignarPedido(void*&cliente, void*productos, void*pedidos, int dni) ;
int BuscarActualizarStock(void*productos, int cod_prod, int can_ped,
        void*&buff, int fecha_ped, void*estado) ;

void AsignarPedido(void*&cliente, void*productos, void*pedidos, int dni);
#endif /* PUNTEROSGENERICOS_H */
