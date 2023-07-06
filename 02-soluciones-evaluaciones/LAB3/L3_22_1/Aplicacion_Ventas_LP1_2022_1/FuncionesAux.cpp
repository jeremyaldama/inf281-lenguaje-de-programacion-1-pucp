/* 
 * File:   FuncionesAux.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 25 de abril de 2023, 20:20
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "FuncionesAux.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "Funciones.h"

using namespace std;

void LeerDatosClientes(struct Estructura_ClienteRegistrado *clientes){
    ifstream arch_clientes;
    AperturaDeUnArchivoDeTextosParaLeer(arch_clientes, "Clientes.txt");
    struct Estructura_ClienteRegistrado cliente;
//    clientes[0].dni = 0;
    for (int i=0; i<20; i++){
        cout << "DNI: " << clientes[i].dni << endl;
    }
    
    while(1){
        arch_clientes >> cliente;
        if (arch_clientes.eof()) break;
        clientes += cliente;
    }
}

void LeerPedidos(struct Estructura_ClienteRegistrado *clientes, 
        struct Estructura_ProductosEnAlmacen *productos){
    ifstream arch_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(arch_pedidos, "Pedidos.txt");
    struct Estructura_PedidoRealizado pedido;
    struct Estructura_ProductosEnAlmacen producto;
    char nombre[100], c;
    double descuento, precio_uni;
    int dni_cliente, dd, mm, aa, indice_cliente, indice_producto;
//    productos[0].codigo[0] = 'X';
//    productos[0].codigo[1] = 0;
    while (1){
        arch_pedidos >> pedido.codigo;
        if (arch_pedidos.eof()) break;
        arch_pedidos >> nombre;
        arch_pedidos >> pedido.cantidad;
        if (arch_pedidos.fail()){
            arch_pedidos.clear();
            arch_pedidos >> c >> descuento;
            arch_pedidos >> pedido.cantidad;
        }
        else descuento = 0.0;
        arch_pedidos >> precio_uni >> dni_cliente >> dd >> c >> mm >> c >> aa;
        indice_cliente = BuscarCliente(clientes, dni_cliente);
        pedido.fecha = dd + mm*100 + aa*10000;
        clientes[indice_cliente] += pedido;
        
        // Actualizamos el monto total gastado
        clientes[indice_cliente].montoTotalGastado += pedido.cantidad * 
                                                precio_uni * (1-descuento/100);
        indice_producto = BuscarProducto(productos, pedido.codigo);
        if (indice_producto==-1){
            CrearProducto(producto, pedido.codigo, nombre, precio_uni, 
                    descuento);
            
            productos += producto;
        }
    }
}

void CrearProducto(struct Estructura_ProductosEnAlmacen &producto, 
        char*codigo, char*descripcion, double precio_uni, double descuento){
    strcpy(producto.codigo, codigo);
    strcpy(producto.descripcion, descripcion);
    producto.descuento = descuento;
    producto.precioUnitario = precio_uni;
}

int BuscarProducto(struct Estructura_ProductosEnAlmacen *productos, 
        char*codigo){
    for (int i=0; productos[i].codigo[0]!='X' && productos[i].codigo[1]!=0; i++){
        if (strcmp(productos[i].codigo, codigo)==0) return 1;
    }
    return -1;
}

int BuscarCliente(struct Estructura_ClienteRegistrado *clientes, 
        int dni_cliente){
    for (int i=0; clientes[i].dni; i++){
        if (clientes[i].dni == dni_cliente) return i;
    }
    return -1;
}

void ImprimirReporte(struct Estructura_ClienteRegistrado *clientes, 
        struct Estructura_ProductosEnAlmacen *productos){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, "Reporte.txt");
    for (int i=0; clientes[i].dni; i++){
        arch << clientes[i];
    }
    
    for (int i=0; productos[i].codigo[1]!=0; i++){
        arch << i+1 << ')' << right << setw(15) << productos[i].codigo <<
                setw(40) << productos[i].descripcion << setw(20) <<
                productos[i].precioUnitario << setw(10) <<
                productos[i].descuento << endl;
    }
    arch << endl;
}