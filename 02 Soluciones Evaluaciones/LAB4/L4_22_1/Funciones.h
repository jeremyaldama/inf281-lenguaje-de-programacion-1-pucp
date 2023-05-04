/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 3 de mayo de 2023, 19:51
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void CargaDeClientes(int* &cli_DNI, char** &cli_Nombre, char* &cli_Categoria);
void ReporteDeClientes(int* &cli_DNI, char** &cli_Nombre, char* &cli_Categoria);
void CargaDePedidosYProductos(int* &cli_DNI, int* &pro_Codigo,
        char** &pro_Descripcion, double* &pro_Descuento, double* &pro_Precio,
        int** &cli_CodigoProFechaPedido, double** &cli_CantidadPedido);

void ReporteDePedidosYProductos(int* &cli_DNI, int* &pro_Codigo,
        char** &pro_Descripcion, double* &pro_Descuento, double* &pro_Precio,
        int** &cli_CodigoProFechaPedido, double** &cli_CantidadPedido);

void ReporteRelacionDePedidos(int*cli_DNI, char**cli_Nombre, char*cli_Categoria,
        int**cli_CodigoProFechaPedido, double**cli_CantidadPedido,
        int*pro_Codigo, char**pro_Descripcion, double*pro_Descuento,
        double*pro_Precio);
int CalcularCantidad(int*arr);
int BuscarIndice(int*codigos, int codigo);
int CalcularCantidad(double*arr);
void AsignaPedidos(int*, int**&cli_CodigoProFechaPedido, double**&cli_CantidadPedido,
            int**codigos_fechas_pedds, double**cantidades_pedidos);
void AsignaProductos(int, int* &pro_Codigo,
        char** &pro_Descripcion, double* &pro_Descuento, double* &pro_Precio,
        int*codigos, char**descripciones, double*descuentos, double*precios);
void AsignaPedidosAux(int ind_cli, int**codigos_fechas_pedds, 
        int codigo, int fecha, double**cantidades_pedidos, double cantidad);
void ReporteRelacionDePedidos(int*cli_DNI, char**cli_Nombre, char*cli_Categoria,
        int**cli_CodigoProFechaPedido, double**cli_CantidadPedido,
        int*pro_Codigo, char**pro_Descripcion, double*pro_Descuento,
        double*pro_Precio);
#endif /* FUNCIONES_H */

