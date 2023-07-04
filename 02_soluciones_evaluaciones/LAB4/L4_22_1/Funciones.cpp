/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 3 de mayo de 2023, 19:51
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Funciones.h"
using namespace std;

// 71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO B,935441620

void CargaDeClientes(int* &cli_DNI, char** &cli_Nombre, char* &cli_Categoria) {
    ifstream arch("Clientes.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR CLIENTES.CSV" << endl;
        exit(1);
    }
    int dnis[100], i = 0, buf, n;
    char *nombres[100], nombre[100], categorias[100], c;
    while (1) {
        arch >> dnis[i];
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        n = strlen(nombre);
        categorias[i] = nombre[n - 1];
        nombre[n - 2] = 0;
        nombres[i] = new char[n + 1];
        strcpy(nombres[i], nombre);
        arch >> buf;
        i++;
    }
    cli_DNI = new int[i + 1] {
    };
    cli_Nombre = new char*[i];
    cli_Categoria = new char[i];
    for (int j = 0; j < i; j++) {
        cli_DNI[j] = dnis[j];
        cli_Nombre[j] = nombres[j];
        cli_Categoria[j] = categorias[j];
    }
}

void ReporteDeClientes(int* &cli_DNI, char** &cli_Nombre, char* &cli_Categoria) {
    ofstream arch("ReporteClientes.txt", ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR REPORTECLIENTES.TXT";
        exit(1);
    }
    arch << left;
    for (int i = 0; cli_DNI[i]; i++) {
        arch << setw(12) << cli_DNI[i] << setw(60) << cli_Nombre[i] <<
                cli_Categoria[i] << endl;
    }
}

void CargaDePedidosYProductos(int* &cli_DNI, int* &pro_Codigo,
        char** &pro_Descripcion, double* &pro_Descuento, double* &pro_Precio,
        int** &cli_CodigoProFechaPedido, double** &cli_CantidadPedido) {
    ifstream arch("Pedidos.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR PEDIDOS.CSV";
        exit(1);
    }
    int codigos[200] = {}, *codigos_fechas_pedds[100], i = 0,
            dd, mm, aa, fecha, dni, ind_prod, codigo, hay_descuento,
            ind_cli, ind_ped;
    char *descripciones[200], c, descripcion[200];
    double descuentos[200] = {}, precios[200], cantidad, descuento, precio,
            *cantidades_pedidos[100];
    
    for (int j=0; j<100; j++){
        codigos_fechas_pedds[j] = new int[200]{};
        cantidades_pedidos[j] = new double[100]{};
    }
    // codigo, descripcion, descuento(si tiene), cantidad, preciou, dnicli, fechaped
    // 397718,LECHE LALA SEMI DESLACTOSADA 1LT,1.78,16.98,71378466,26/10/2020
    // 793026,YOGHURT NATURAL LIGHT LALA 1KG,%4.7,5.54,25.86,32821689,19/04/2020
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(descripcion, 200, ',');
        arch >> cantidad;
        if (arch.fail()) {
            arch.clear();
            arch >> c >> descuento >> c >> cantidad >> c;
            hay_descuento = 1;
        } 
        else {
            arch >> c;
            hay_descuento = 0;
        }
        arch >> precio >> c >> dni >> c >> dd >> c >> mm >> c >> aa;
        fecha = dd+mm*100+aa*10000;
        ind_prod = BuscarIndice(codigos, codigo);
        ind_cli = BuscarIndice(cli_DNI, dni);
        if (ind_prod==-1){
            codigos[i] = codigo;
            descripciones[i] = new char[strlen(descripcion)+1];
            strcpy(descripciones[i], descripcion);
            if (hay_descuento) descuentos[i] = descuento;
            precios[i] = precio;
            i++;
        }
        AsignaPedidosAux(ind_cli, codigos_fechas_pedds, codigo, fecha,
                cantidades_pedidos, cantidad);
    }
    AsignaProductos(i, pro_Codigo, pro_Descripcion, pro_Descuento, pro_Precio,
            codigos, descripciones, descuentos, precios);
    AsignaPedidos(cli_DNI, cli_CodigoProFechaPedido, cli_CantidadPedido,
            codigos_fechas_pedds, cantidades_pedidos);
}

void AsignaPedidosAux(int ind_cli, int**codigos_fechas_pedds, 
        int codigo, int fecha, double**cantidades_pedidos, double cantidad){
    // codigos fechas pedidos
    int ind_ped;
    ind_ped = CalcularCantidad(codigos_fechas_pedds[ind_cli]);
    AsignaFechasYCodigo(codigos_fechas_pedds[ind_cli], ind_ped, codigo, fecha);
    // cantidad
    ind_ped = CalcularCantidad(cantidades_pedidos[ind_cli]);
    AsignaCantidad(cantidades_pedidos[ind_cli], ind_ped, cantidad);
}


void AsignaCantidad(double*cantidades_pedidos, int ind_ped, double cantidad){
    cantidades_pedidos[ind_ped] = cantidad;
}

void AsignaFechasYCodigo(int*codigos_fechas_pedds, int ind_ped, int codigo, 
        int fecha){
    codigos_fechas_pedds[ind_ped] = codigo;
    codigos_fechas_pedds[ind_ped+1] = fecha;
}

void AsignaProductos(int i, int* &pro_Codigo,
        char** &pro_Descripcion, double* &pro_Descuento, double* &pro_Precio,
        int*codigos, char**descripciones, double*descuentos, double*precios){
    pro_Codigo = new int[i+1]{};
    pro_Descripcion = new char*[i];
    pro_Descuento = new double[i];
    pro_Precio = new double[i];
    
    for (int j=0; j<i; j++){
        pro_Codigo[j] = codigos[j];
        pro_Descripcion[j] = descripciones[j];
        pro_Descuento[j] = descuentos[j];
        pro_Precio[j] = precios[j];
    }
}

void AsignaPedidos(int*cli_DNI, int**&cli_CodigoProFechaPedido, double**&cli_CantidadPedido,
            int**codigos_fechas_pedds, double**cantidades_pedidos){
    int cant_cli = CalcularCantidad(cli_DNI);
    cli_CodigoProFechaPedido = new int*[cant_cli];
    cli_CantidadPedido = new double*[cant_cli];
    int k;
    for (int j=0; j<cant_cli; j++){
        for (k=0; codigos_fechas_pedds[j][k]; k++);
        cli_CodigoProFechaPedido[j] = new int[k+1]{};
        for (k=0; cantidades_pedidos[j][k]; k++);
        cli_CantidadPedido[j] = new double[k+1]{};
        for (k=0; codigos_fechas_pedds[j][k]; k++)
            cli_CodigoProFechaPedido[j][k] = codigos_fechas_pedds[j][k];
        for (k=0; cantidades_pedidos[j][k]; k++)
            cli_CantidadPedido[j][k] = cantidades_pedidos[j][k];
        delete[] codigos_fechas_pedds[j];
        delete[] cantidades_pedidos[j];
    }
}

int CalcularCantidad(double*arr){
    int i;
    for (i=0; arr[i]; i++);
    return i;
}

int CalcularCantidad(int*arr){
    int i;
    for (i=0; arr[i]; i++);
    return i;
}

int BuscarIndice(int*codigos, int codigo){
    for (int i=0; codigos[i]; i++)
        if (codigos[i]==codigo) return i;
    return -1;
}

void ReporteDePedidosYProductos(int* &cli_DNI, int* &pro_Codigo,
        char** &pro_Descripcion, double* &pro_Descuento, double* &pro_Precio,
        int** &cli_CodigoProFechaPedido, double** &cli_CantidadPedido) {
    ofstream arch("ReporteDePedidosYProductos.txt", ios::out);
    if (!arch){
        cout << "NO SEP UDO ABRIR REPORTE.TXT";
        exit(1);
    }
    arch << left;
    arch << "CLIENTES: " << endl;
    
    for (int i=0; cli_DNI[i]; i++){
        arch << "DNI: " << cli_DNI[i] << endl;
        arch << "CODIGOS FECHA PEDIDOS: " << endl;
        for (int j=0; cli_CodigoProFechaPedido[i][j]; j+=2){
            arch << right << setw(15) << cli_CodigoProFechaPedido[i][j] <<
                    setw(15) << cli_CodigoProFechaPedido[i][j+1] << endl;
        }
        arch << "CANTIDADES PRECIOS" << endl;
        for (int j=0; cli_CantidadPedido[i][j]; j++){
            arch << setw(10) << cli_CantidadPedido[i][j] << endl;
        }
        arch << "========================================================"<< endl;
    }
    
    arch << endl << left << "PRODUCTOS: " << endl;
    for (int i=0; pro_Codigo[i]; i++){
        arch << setw(12) << pro_Codigo[i] << setw(60) << pro_Descripcion[i] <<
                setw(10) << pro_Descuento[i] << pro_Precio[i] << endl;
    }
}

void ReporteRelacionDePedidos(int*cli_DNI, char**cli_Nombre, char*cli_Categoria,
        int**cli_CodigoProFechaPedido, double**cli_CantidadPedido,
        int*pro_Codigo, char**pro_Descripcion, double*pro_Descuento,
        double*pro_Precio) {
    ofstream arch("PedidosPorCliente.txt",ios::out);
    if(!arch){
        cout << "No se puede abrir el archivo clientes";
        exit(1);    
    }
    
    
    arch<<fixed;
    arch.precision(2);
    arch<<setw(70)<<"EMPRESA COMERCIALIZADORA DE ABARRATOTES"<<endl;

    arch<<"GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;

    
    for(int i=0;cli_DNI[i];i++){
        arch<<endl<<right<<"DNI"<<setw(30)<<"NOMBRE"<<setw(50)<<"Categoria"<<endl;
        arch<<cli_DNI[i]<<"   "<<left<<setw(60)<<cli_Nombre[i]<<right<<setw(20)<<cli_Categoria[i]<<endl;
        arch<<"PRODUCTOS ADQUIRIDOS:"<<endl;

        arch<<setw(14)<<"codigo"<<setw(14)<<"Descripcion"<<setw(35)<<"P.U"<<setw(8)<<"cantidad"<<
                setw(10)<<"cantidad"<<setw(10)<<"total"<<setw(10)<<"descuento"<<setw(10)<<
                "A pagar"<<setw(10)<<"descuento"<<setw(10)<<"fecha"<<endl;

        int posProd=0;
        for(int j=0; cli_CantidadPedido[i][j]; j++){
            posProd=BuscarIndice(pro_Codigo,cli_CodigoProFechaPedido[i][j*2]);
            arch<<left<<setw(3)<<j+1<<")    "<<pro_Codigo[posProd]<<"    "<<
                    left<<setw(45)<<pro_Descripcion[posProd]<<setw(10)<<pro_Precio[posProd]
                    <<setw(10)<<cli_CantidadPedido[i][j]<<setw(10)<<
                    pro_Precio[posProd]*cli_CantidadPedido[i][j]<<setw(12)
                    <<pro_Precio[posProd]*cli_CantidadPedido[i][j]*pro_Descuento[posProd]/100<<
                    setw(12)<<pro_Precio[posProd]*cli_CantidadPedido[i][j]*(100-pro_Descuento[posProd])/100
                    <<setw(12)<<pro_Descuento[posProd]<<cli_CodigoProFechaPedido[i][j*2+1]<<endl;
        }
    }
}